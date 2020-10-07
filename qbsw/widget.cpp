#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>

#include <QDebug>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


#define INLINE inline


// u8 kb_received;
u8 uart_received;
u8 console_cursor_row, console_cursor_col;
u8 console_top_row;
u8 term_status, term_csi1, term_csi2;
u8 background;
#define tx_buf_len 16
volatile u8 tx_buf[tx_buf_len];
volatile u8 tx_buf_start, tx_buf_end;
struct Options
{
    u8 local_mode:1;
    u8 settings_mode:1;
    u8 print_unknown_keys:1;
    u8 print_all_keys:1;
} volatile options;


u16 line = 0;
u8 current_screen_row;
u8 current_char_row;
volatile u8 settings_pos;

#define TS_NORMAL 0
#define TS_ESCAPE 1
#define TS_CSI 2
#define TS_CSI2 3
#define TS_VT52_Y1 4
#define TS_VT52_Y2 5
#define TS_DEC_PRIVATE 6


unsigned char screen_scanline[console_width + 1];
u8 console[console_width*console_height];

u8 kb_flags;
u8 kb_last_byte;
u8 kb_bit_no;
u8 kb_updates;
bool kb_prev_clk, kb_prev_data;
bool kb_parity;
bool kb_prev_up, kb_prev_ext;
bool kb_shifted, kb_ctrled;


void clear_console_line(unsigned char* console_line, unsigned char value) {
    for (u8 a=0;a<console_width;a++){
        console_line[a]=value;
    }
}

static INLINE void increase_row(u8& row) {
    row++;
    if (row==console_height) {
        row=0;
    }
}


static INLINE void decrease_row(u8& row) {
    if (row==0) {
        row = console_height - 1;
    } else {
        row--;
    }
}


static void term_handle_ch_normal(u8 ch){
    ch = ch & ~128;
    if (ch=='\r') {
        console_cursor_col = 0;
        return;
    }

    if (ch==8 || ch == 127) {
        if (console_cursor_col>0) {
            console_cursor_col--;
            console[console_cursor_row*console_width+console_cursor_col] = ' ';
        }
        return;
    }
    if (ch=='\n') {
        increase_row(console_cursor_row);
        if (console_cursor_row==console_top_row) {
#if 0
            for (u8 a=0;a<console_width;a++){
                console[console_top_row*console_width+a] = 0;
            }
#else
            clear_console_line(&console[console_top_row*console_width],  ' ');
#endif
            increase_row(console_top_row);
        }
        return;
    }

    if (ch == '\b') {
        return;
    }
    if (ch < 32) {
        // Other non-printable character
        // Ignore it
        return;
    }
    if (ch == ' ' && background) {
        ch = 127;
    }
    //if (ch >= 128) {
    //    // Non-ANSI characters, ignore it
    //    return;
    //}
    console[console_cursor_row*console_width+console_cursor_col] = ch;
    console_cursor_col++;
    if (console_cursor_col>=console_width){
        console_cursor_col=0;
        term_handle_ch_normal('\n');
    }
}

/*
mach|Mach Console,
        am, km,
        cols#80, it#8, lines#25,
        bel=^G, blink=\E[5m, bold=\E[1m, clear=\Ec, cr=^M,
        cub=\E[%p1%dD, cub1=^H, cud=\E[%p1%dB, cud1=^J,
        cuf=\E[%p1%dC, cuf1=\E[C, cup=\E[%i%p1%d;%p2%dH,
        cuu=\E[%p1%dA, cuu1=\E[A, dl=\E[%p1%dM, dl1=\E[M, ed=\E[J,
        el=\E[K, home=\E[H, ht=^I, il=\E[%p1%dL, il1=\E[L, ind=^J,
        kbs=\177, kcub1=\E[D, kcud1=\E[B, kcuf1=\E[C, kcuu1=\E[A,
        kdch1=\E[9, kend=\E[Y, kf1=\EOP, kf10=\EOY, kf2=\EOQ,
        kf3=\EOR, kf4=\EOS, kf5=\EOT, kf6=\EOU, kf7=\EOV, kf8=\EOW,
        kf9=\EOX, khome=\E[H, kich1=\E[@, kll=\E[F, knp=\E[U,
        kpp=\E[V, rev=\E[7m, rmso=\E[0m, rmul=\E[24m, sgr0=\E[0m,
        smso=\E[7m, smul=\E[4m,

#       Reconstructed via infocmp from file: /lib/terminfo/v/vt52
vt52|dec vt52,
        cols#80, it#8, lines#24,
        acsc=+h.k0affggolpnqprrss, bel=^G, clear=\EH\EJ, cr=^M,
        cub1=\ED, cud1=\EB, cuf1=\EC,
        cup=\EY%p1%' '%+%c%p2%' '%+%c, cuu1=\EA, ed=\EJ, el=\EK,
        home=\EH, ht=^I, ind=^J, kbs=^H, kcub1=\ED, kcud1=\EB,
        kcuf1=\EC, kcuu1=\EA, nel=^M^J, ri=\EI, rmacs=\EG, smacs=\EF,

*/
static INLINE void term_handle_ch_escape(u8 ch) {
    if (ch == 'A') {        // vt52 cuu, cursor_up
        increase_row(console_cursor_row);
    } else if (ch == 'B') { // vt52 cud, cursor_down
        decrease_row(console_cursor_row);
    } else if (ch == 'C') { // vt52 cuf, cursor_right
        if (console_cursor_col<console_width-1) {
            console_cursor_col++;
        }
    } else if (ch == 'D') { // vt52 cub, cursor_left
        if (console_cursor_col!=0) {
            console_cursor_col--;
        }
    } else if (ch == 'Y') { // vt52 position cursor
        term_status = TS_VT52_Y1;
    }
}

static INLINE void term_handle_ch_csi(u8 ch) {
    if (ch == 'H') {
        if (term_csi1 == 0) term_csi1 = 1;
        if (term_csi2 == 0) term_csi2 = 1;

        console_cursor_row = term_csi1 - 1;
        console_cursor_col = term_csi2 - 1;

        console_cursor_row = (console_cursor_row + console_top_row) % console_height;

        if (console_cursor_col>=console_width) {
            console_cursor_col = console_width - 1;
        }
    } else if (ch == 'J') {
        clear_console_line(&console[0], ' ');
        for (u8 a=1;a<console_height;a++) {
            console[a*console_width] = 0;
        }
    } else if (ch == 'A') { // vt100 cuu, cursor_up
        increase_row(console_cursor_row);
    } else if (ch == 'B') { // vt100 cud, cursor_down
        decrease_row(console_cursor_row);
    } else if (ch == 'C') { // vt100 cuf, cursor_right
        if (console_cursor_col<console_width-1) {
            console_cursor_col++;
        }
    } else if (ch == 'D') { // vt100 cub, cursor_left
        if (console_cursor_col!=0) {
            console_cursor_col--;
        }
    } else if (ch == 'm') {
        if (40 <= term_csi1 && term_csi1 < 49 ) {
            background = 1;
        } else if (term_csi1 == 0) {
            background = 0;
        }

    } else if (ch == '?') {
        term_status = TS_DEC_PRIVATE;
    }
    term_csi1 = 0;
    term_csi2 = 0;
}

static INLINE void term_handle_ch(u8 ch){
    if (term_status == TS_NORMAL) {
        if (ch=='\e') {
            term_status = TS_ESCAPE;
        } else {
            term_handle_ch_normal(ch);
        }
    } else if (term_status == TS_ESCAPE) {
        if (ch=='[') {
            term_status = TS_CSI;
        } else {
            term_handle_ch_escape(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_CSI) {
        if (ch==';') {
            term_status = TS_CSI2;
        } else if ('0' <= ch && ch <= '9') {
            term_csi1 = term_csi1*10 + ch - '0';
        } else {
            term_handle_ch_csi(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_CSI2) {
        if ('0' <= ch && ch <= '9') {
            term_csi2 = term_csi2*10 + ch - '0';
        } else {
            term_handle_ch_csi(ch);
            term_status = TS_NORMAL;
        }
    } else if (term_status == TS_VT52_Y1) {
        term_csi1 = ch - ' ';
        term_status = TS_VT52_Y2;
    } else if (term_status == TS_VT52_Y2) {
        term_csi2 = ch - ' ';
        term_handle_ch_csi('H');
        term_status = TS_NORMAL;
    } else if (term_status == TS_DEC_PRIVATE) {
        if (ch==';') {
        } else if ('0' <= ch && ch <= '9') {
        } else {
            term_status = TS_NORMAL;
        }
    }
}



void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e->text() << e->nativeScanCode();

    if (e->text().size() == 1) {
        term_handle_ch(e->text().at(0).toAscii());
    }
    update();
}

void Widget::keyReleaseEvent(QKeyEvent *)
{

}

void Widget::paintEvent(QPaintEvent *) {
    init();
    QPainter p(this);

    QString str;
    p.fillRect(0,0,font_width*console_width,font_height*console_height, Qt::black);
    p.setBackground(Qt::black);
    p.setPen(Qt::yellow);

    for (u8 a=0;a<console_height;a++) {
        for (u8 b=0;b<console_width;b++) {
            str.append((char)console[b+a*console_width] ?: ' ');
        }
        str.append('\n');

    }
    p.drawText(0,0,width(),height(),0,str,0);
    p.setPen(Qt::green);

    p.drawText(console_cursor_col*font_width,
               console_cursor_row*font_height,
               width(),height(),0,"_",0);

}
