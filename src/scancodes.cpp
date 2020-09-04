#ifndef F_CPU
#define F_CPU (16000000)
#endif

#include "scancodes.h"
/*
#       Reconstructed via infocmp from file: /usr/share/terminfo/a/ansi-mini
ansi-mini|any ansi terminal with pessimistic assumptions,
        am, xon,
        cols#80, lines#24,
        bel=^G, clear=\E[H\E[J, cr=^M, cud1=^J,
        cup=\E[%i%p1%d;%p2%dH, ed=\E[J, el=\E[K, home=\E[H, ind=^J,
#       Reconstructed via infocmp from file: /lib/terminfo/x/xterm
xterm|xterm-debian|X11 terminal emulator,
        am, bce, km, mc5i, mir, msgr, npc, xenl,
        colors#8, cols#80, it#8, lines#24, pairs#64,
        acsc=``aaffggiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~,
        bel=^G, blink=\E[5m, bold=\E[1m, cbt=\E[Z, civis=\E[?25l,
        clear=\E[H\E[2J, cnorm=\E[?12l\E[?25h, cr=^M,
        csr=\E[%i%p1%d;%p2%dr, cub=\E[%p1%dD, cub1=^H,
        cud=\E[%p1%dB, cud1=^J, cuf=\E[%p1%dC, cuf1=\E[C,
        cup=\E[%i%p1%d;%p2%dH, cuu=\E[%p1%dA, cuu1=\E[A,
        cvvis=\E[?12;25h, dch=\E[%p1%dP, dch1=\E[P, dim=\E[2m,
        dl=\E[%p1%dM, dl1=\E[M, ech=\E[%p1%dX, ed=\E[J, el=\E[K,
        el1=\E[1K, flash=\E[?5h$<100/>\E[?5l, home=\E[H,
        hpa=\E[%i%p1%dG, ht=^I, hts=\EH, ich=\E[%p1%d@,
        il=\E[%p1%dL, il1=\E[L, ind=^J, indn=\E[%p1%dS,
        invis=\E[8m, is2=\E[!p\E[?3;4l\E[4l\E>, kDC=\E[3;2~,
        kEND=\E[1;2F, kHOM=\E[1;2H, kIC=\E[2;2~, kLFT=\E[1;2D,
        kNXT=\E[6;2~, kPRV=\E[5;2~, kRIT=\E[1;2C, kb2=\EOE,
        kbs=\177, kcbt=\E[Z, kcub1=\EOD, kcud1=\EOB, kcuf1=\EOC,
        kcuu1=\EOA, kdch1=\E[3~, kend=\EOF, kent=\EOM, kf1=\EOP,
        kf10=\E[21~, kf11=\E[23~, kf12=\E[24~, kf13=\E[1;2P,
        kf14=\E[1;2Q, kf15=\E[1;2R, kf16=\E[1;2S, kf17=\E[15;2~,
        kf18=\E[17;2~, kf19=\E[18;2~, kf2=\EOQ, kf20=\E[19;2~,
        kf21=\E[20;2~, kf22=\E[21;2~, kf23=\E[23;2~,
        kf24=\E[24;2~, kf25=\E[1;5P, kf26=\E[1;5Q, kf27=\E[1;5R,
        kf28=\E[1;5S, kf29=\E[15;5~, kf3=\EOR, kf30=\E[17;5~,
        kf31=\E[18;5~, kf32=\E[19;5~, kf33=\E[20;5~,
        kf34=\E[21;5~, kf35=\E[23;5~, kf36=\E[24;5~,
        kf37=\E[1;6P, kf38=\E[1;6Q, kf39=\E[1;6R, kf4=\EOS,
        kf40=\E[1;6S, kf41=\E[15;6~, kf42=\E[17;6~,
        kf43=\E[18;6~, kf44=\E[19;6~, kf45=\E[20;6~,
        kf46=\E[21;6~, kf47=\E[23;6~, kf48=\E[24;6~,
        kf49=\E[1;3P, kf5=\E[15~, kf50=\E[1;3Q, kf51=\E[1;3R,
        kf52=\E[1;3S, kf53=\E[15;3~, kf54=\E[17;3~,
        kf55=\E[18;3~, kf56=\E[19;3~, kf57=\E[20;3~,
        kf58=\E[21;3~, kf59=\E[23;3~, kf6=\E[17~, kf60=\E[24;3~,
        kf61=\E[1;4P, kf62=\E[1;4Q, kf63=\E[1;4R, kf7=\E[18~,
        kf8=\E[19~, kf9=\E[20~, khome=\EOH, kich1=\E[2~,
        kind=\E[1;2B, kmous=\E[M, knp=\E[6~, kpp=\E[5~,
        kri=\E[1;2A, mc0=\E[i, mc4=\E[4i, mc5=\E[5i, meml=\El,
        memu=\Em, op=\E[39;49m, rc=\E8, rev=\E[7m, ri=\EM,
        rin=\E[%p1%dT, ritm=\E[23m, rmacs=\E(B, rmam=\E[?7l,
        rmcup=\E[?1049l, rmir=\E[4l, rmkx=\E[?1l\E>, rmso=\E[27m,
        rmul=\E[24m, rs1=\Ec, rs2=\E[!p\E[?3;4l\E[4l\E>, sc=\E7,
        setab=\E[4%p1%dm, setaf=\E[3%p1%dm,
        setb=\E[4%?%p1%{1}%=%t4%e%p1%{3}%=%t6%e%p1%{4}%=%t1%e%p1%{6}%=%t3%e%p1%d%;m,
        setf=\E[3%?%p1%{1}%=%t4%e%p1%{3}%=%t6%e%p1%{4}%=%t1%e%p1%{6}%=%t3%e%p1%d%;m,
        sgr=%?%p9%t\E(0%e\E(B%;\E[0%?%p6%t;1%;%?%p5%t;2%;%?%p2%t;4%;%?%p1%p3%|%t;7%;%?%p4%t;5%;%?%p7%t;8%;m,
        sgr0=\E(B\E[m, sitm=\E[3m, smacs=\E(0, smam=\E[?7h,
        smcup=\E[?1049h, smir=\E[4h, smkx=\E[?1h\E=, smso=\E[7m,
        smul=\E[4m, tbc=\E[3g, u6=\E[%i%d;%dR, u7=\E[6n,
        u8=\E[?1;2c, u9=\E[c, vpa=\E[%i%p1%dd,


f1 ^[OP   -- f2 ^[OQ   -- f3 ^[OR   -- f4 ^[OS -  - f5 ^[[15~ -- f6 ^[[17~
f7 ^[[18~ -- f8 ^[[19~ -- f9 ^[[20~ -- f10 ^[[21~ -- f11 ^[[23~ --

 L ^[[D  -- R  ^[[C  -- U ^[[A -- D ^[[B
PU ^[[5~ -- PD ^[[6~ -- H ^[[H -- E ^[[F -- D ^[[3~
*/



const u8 PROGMEM scancodes[] = {
    '?', // 0x0
    BSW_F9, // 0x1
    '?', // 0x2
    BSW_F5, // 0x3
    BSW_F3, // 0x4
    BSW_F1, // 0x5
    BSW_F2, // 0x6
    BSW_F12, // 0x7
    '?', // 0x8
    BSW_F10, // 0x9
    BSW_F8, // 0xa
    BSW_F6, // 0xb
    BSW_F4, // 0xc
    '\t', // 0xd
    '`', // 0xe
    '?', // 0xf
    '?', // 0x10
    '?', // 0x11
    '?', // 0x12
    '?', // 0x13
    '?', // 0x14
    'q', // 0x15
    '1', // 0x16
    '?', // 0x17
    '?', // 0x18
    '?', // 0x19
    'z', // 0x1a
    's', // 0x1b
    'a', // 0x1c
    'w', // 0x1d
    '2', // 0x1e
    BSW_WINKEYL, // 0x1f // Extended!
    '?', // 0x20
    'c', // 0x21
    'x', // 0x22
    'd', // 0x23
    'e', // 0x24
    '4', // 0x25
    '3', // 0x26
    BSW_WINKEYR, // 0x27
    '?', // 0x28
    ' ', // 0x29
    'v', // 0x2a
    'f', // 0x2b
    't', // 0x2c
    'r', // 0x2d
    '5', // 0x2e
    BSW_MENU, // 0x2f
    '?', // 0x30
    'n', // 0x31
    'b', // 0x32
    'h', // 0x33
    'g', // 0x34
    'y', // 0x35
    '6', // 0x36
    '?', // 0x37
    '?', // 0x38
    '?', // 0x39
    'm', // 0x3a
    'j', // 0x3b
    'u', // 0x3c
    '7', // 0x3d
    '8', // 0x3e
    '?', // 0x3f
    '?', // 0x40
    ',', // 0x41
    'k', // 0x42
    'i', // 0x43
    'o', // 0x44
    '0', // 0x45
    '9', // 0x46
    '?', // 0x47
    '?', // 0x48
    '.', // 0x49
    '/', // 0x4a
    'l', // 0x4b
    ';', // 0x4c
    'p', // 0x4d
    '-', // 0x4e
    '?', // 0x4f
    '?', // 0x50
    '?', // 0x51
    '\'', // 0x52
    '?', // 0x53
    '[', // 0x54
    '=', // 0x55
    '?', // 0x56
    '?', // 0x57
    BSW_CAPSLOCK, // 0x58
    '?', // 0x59
    '\n', // 0x5a // Enter
    ']', // 0x5b
    '?', // 0x5c
    '\\', // 0x5d
    '?', // 0x5e
    '?', // 0x5f
    '?', // 0x60
    '?', // 0x61
    '?', // 0x62
    '?', // 0x63
    '?', // 0x64
    '?', // 0x65
    127, // 0x66
    '?', // 0x67
    '?', // 0x68
    '1', // 0x69
    '?', // 0x6a
    '4', // 0x6b // numpad
    '7', // 0x6c // numpad
    '4', // 0x6d // numpad
    '?', // 0x6e
    '?', // 0x6f
    '0', // 0x70 // numpad
    '.', // 0x71
    '2', // 0x72 // numpad
    '5', // 0x73 // numpad
    '6', // 0x74 // numpad
    '8', // 0x75 // numpad
    '\e', // 0x76
    BSW_NUMLOCK, // 0x77
    BSW_F11, // 0x78
    '+', // 0x79 // numpad
    '3', // 0x7a  // numpad
    '-', // 0x7b // numpad
    '*', // 0x7c // numpad
    '9', // 0x7d // numpad
    BSW_SCROLLLOCK, // 0x7e
    '?', // 0x7f
    '?', // 0x80
    '?', // 0x81
    '?', // 0x82
    BSW_F7, // 0x83
    '?', // 0x84
    '?', // 0x85
    '?', // 0x86
    '?', // 0x87
    '?', // 0x88
    '?', // 0x89
    '?', // 0x8a
    '?', // 0x8b
    '?', // 0x8c
    '?', // 0x8d
    '?', // 0x8e
    '?', // 0x8f
    '?', // 0x90
    '?', // 0x91
    '?', // 0x92
    '?', // 0x93
    '?', // 0x94
    '?', // 0x95
    '?', // 0x96
    '?', // 0x97
    '?', // 0x98
    '?', // 0x99
    '?', // 0x9a
    '?', // 0x9b
    '?', // 0x9c
    '?', // 0x9d
    '?', // 0x9e
    '?', // 0x9f
    '?', // 0xa0
    '?', // 0xa1
    '?', // 0xa2
    '?', // 0xa3
    '?', // 0xa4
    '?', // 0xa5
    '?', // 0xa6
    '?', // 0xa7
    '?', // 0xa8
    '?', // 0xa9
    '?', // 0xaa
    '?', // 0xab
    '?', // 0xac
    '?', // 0xad
    '?', // 0xae
    '?', // 0xaf
    '?', // 0xb0
    '?', // 0xb1
    '?', // 0xb2
    '?', // 0xb3
    '?', // 0xb4
    '?', // 0xb5
    '?', // 0xb6
    '?', // 0xb7
    '?', // 0xb8
    '?', // 0xb9
    '?', // 0xba
    '?', // 0xbb
    '?', // 0xbc
    '?', // 0xbd
    '?', // 0xbe
    '?', // 0xbf
    '?', // 0xc0
    '?', // 0xc1
    '?', // 0xc2
    '?', // 0xc3
    '?', // 0xc4
    '?', // 0xc5
    '?', // 0xc6
    '?', // 0xc7
    '?', // 0xc8
    '?', // 0xc9
    '?', // 0xca
    '?', // 0xcb
    '?', // 0xcc
    '?', // 0xcd
    '?', // 0xce
    '?', // 0xcf
    '?', // 0xd0
    '?', // 0xd1
    '?', // 0xd2
    '?', // 0xd3
    '?', // 0xd4
    '?', // 0xd5
    '?', // 0xd6
    '?', // 0xd7
    '?', // 0xd8
    '?', // 0xd9
    '?', // 0xda
    '?', // 0xdb
    '?', // 0xdc
    '?', // 0xdd
    '?', // 0xde
    '?', // 0xdf
    '?', // 0xe0
    '?', // 0xe1
    '?', // 0xe2
    '?', // 0xe3
    '?', // 0xe4
    '?', // 0xe5
    '?', // 0xe6
    '?', // 0xe7
    '?', // 0xe8
    '?', // 0xe9
    '?', // 0xea
    '?', // 0xeb
    '?', // 0xec
    '?', // 0xed
    '?', // 0xee
    '?', // 0xef
    '?', // 0xf0
    '?', // 0xf1
    '?', // 0xf2
    '?', // 0xf3
    '?', // 0xf4
    '?', // 0xf5
    '?', // 0xf6
    '?', // 0xf7
    '?', // 0xf8
    '?', // 0xf9
    '?', // 0xfa
    '?', // 0xfb
    '?', // 0xfc
    '?', // 0xfd
    '?', // 0xfe
    '?', // 0xff
//----------------------------------------------------------------------------
// Shifted characters
    '?', // 0x0
    '?', // 0x1
    '?', // 0x2
    '?', // 0x3
    '?', // 0x4
    '?', // 0x5
    '?', // 0x6
    '?', // 0x7
    '?', // 0x8
    '?', // 0x9
    '?', // 0xa
    '?', // 0xb
    '?', // 0xc
    '\t', // 0xd
    '~', // 0xe
    '?', // 0xf
    '?', // 0x10
    '?', // 0x11
    '?', // 0x12
    '?', // 0x13
    '?', // 0x14
    'Q', // 0x15
    '!', // 0x16
    '?', // 0x17
    '?', // 0x18
    '?', // 0x19
    'Z', // 0x1a
    'S', // 0x1b
    'A', // 0x1c
    'W', // 0x1d
    '@', // 0x1e
    BSW_WINKEYL, // 0x1f
    '?', // 0x20
    'C', // 0x21
    'X', // 0x22
    'D', // 0x23
    'E', // 0x24
    '$', // 0x25
    '#', // 0x26
    BSW_WINKEYR, // 0x27
    '?', // 0x28
    ' ', // 0x29
    'V', // 0x2a
    'F', // 0x2b
    'T', // 0x2c
    'R', // 0x2d
    '%', // 0x2e
    BSW_MENU, // 0x2f
    '?', // 0x30
    'N', // 0x31
    'B', // 0x32
    'H', // 0x33
    'G', // 0x34
    'Y', // 0x35
    '^', // 0x36
    '?', // 0x37
    '?', // 0x38
    '?', // 0x39
    'M', // 0x3a
    'J', // 0x3b
    'U', // 0x3c
    '&', // 0x3d
    '*', // 0x3e
    '?', // 0x3f
    '?', // 0x40
    '<', // 0x41
    'K', // 0x42
    'I', // 0x43
    'O', // 0x44
    ')', // 0x45
    '(', // 0x46
    '?', // 0x47
    '?', // 0x48
    '>', // 0x49
    '?', // 0x4a Really "?"
    'L', // 0x4b
    ':', // 0x4c
    'P', // 0x4d
    '_', // 0x4e
    '?', // 0x4f
    '?', // 0x50
    '?', // 0x51
    '"', // 0x52
    '?', // 0x53
    '{', // 0x54
    '+', // 0x55
    '?', // 0x56
    '?', // 0x57
    BSW_CAPSLOCK, // 0x58 shifted
    '?', // 0x59
    '\n', // 0x5a // Shift-Enter
    '}', // 0x5b
    '?', // 0x5c
    '|', // 0x5d
    '?', // 0x5e
    '?', // 0x5f
    '?', // 0x60
    '?', // 0x61
    '?', // 0x62
    '?', // 0x63
    '?', // 0x64
    '?', // 0x65
    127, // 0x66
    '?', // 0x67
    '?', // 0x68
    '?', // 0x69
    '?', // 0x6a
    '?', // 0x6b
    '?', // 0x6c
    '?', // 0x6d
    '?', // 0x6e
    '?', // 0x6f
    '?', // 0x70
    '?', // 0x71
    '?', // 0x72
    '?', // 0x73
    '?', // 0x74
    '?', // 0x75
    '\e', // 0x76
    BSW_NUMLOCK, // 0x77 //shifted
    '?', // 0x78
    '+', // 0x79
    '?', // 0x7a
    '-', // 0x7b
    '*', // 0x7c
    '?', // 0x7d
    BSW_SCROLLLOCK, // 0x7e // shifted
    '?', // 0x7f
    '?', // 0x80
    '?', // 0x81
    '?', // 0x82
    '?', // 0x83
    '?', // 0x84
    '?', // 0x85
    '?', // 0x86
    '?', // 0x87
    '?', // 0x88
    '?', // 0x89
    '?', // 0x8a
    '?', // 0x8b
    '?', // 0x8c
    '?', // 0x8d
    '?', // 0x8e
    '?', // 0x8f
    '?', // 0x90
    '?', // 0x91
    '?', // 0x92
    '?', // 0x93
    '?', // 0x94
    '?', // 0x95
    '?', // 0x96
    '?', // 0x97
    '?', // 0x98
    '?', // 0x99
    '?', // 0x9a
    '?', // 0x9b
    '?', // 0x9c
    '?', // 0x9d
    '?', // 0x9e
    '?', // 0x9f
    '?', // 0xa0
    '?', // 0xa1
    '?', // 0xa2
    '?', // 0xa3
    '?', // 0xa4
    '?', // 0xa5
    '?', // 0xa6
    '?', // 0xa7
    '?', // 0xa8
    '?', // 0xa9
    '?', // 0xaa
    '?', // 0xab
    '?', // 0xac
    '?', // 0xad
    '?', // 0xae
    '?', // 0xaf
    '?', // 0xb0
    '?', // 0xb1
    '?', // 0xb2
    '?', // 0xb3
    '?', // 0xb4
    '?', // 0xb5
    '?', // 0xb6
    '?', // 0xb7
    '?', // 0xb8
    '?', // 0xb9
    '?', // 0xba
    '?', // 0xbb
    '?', // 0xbc
    '?', // 0xbd
    '?', // 0xbe
    '?', // 0xbf
    '?', // 0xc0
    '?', // 0xc1
    '?', // 0xc2
    '?', // 0xc3
    '?', // 0xc4
    '?', // 0xc5
    '?', // 0xc6
    '?', // 0xc7
    '?', // 0xc8
    '?', // 0xc9
    '?', // 0xca
    '?', // 0xcb
    '?', // 0xcc
    '?', // 0xcd
    '?', // 0xce
    '?', // 0xcf
    '?', // 0xd0
    '?', // 0xd1
    '?', // 0xd2
    '?', // 0xd3
    '?', // 0xd4
    '?', // 0xd5
    '?', // 0xd6
    '?', // 0xd7
    '?', // 0xd8
    '?', // 0xd9
    '?', // 0xda
    '?', // 0xdb
    '?', // 0xdc
    '?', // 0xdd
    '?', // 0xde
    '?', // 0xdf
    '?', // 0xe0
    '?', // 0xe1
    '?', // 0xe2
    '?', // 0xe3
    '?', // 0xe4
    '?', // 0xe5
    '?', // 0xe6
    '?', // 0xe7
    '?', // 0xe8
    '?', // 0xe9
    '?', // 0xea
    '?', // 0xeb
    '?', // 0xec
    '?', // 0xed
    '?', // 0xee
    '?', // 0xef
    '?', // 0xf0
    '?', // 0xf1
    '?', // 0xf2
    '?', // 0xf3
    '?', // 0xf4
    '?', // 0xf5
    '?', // 0xf6
    '?', // 0xf7
    '?', // 0xf8
    '?', // 0xf9
    '?', // 0xfa
    '?', // 0xfb
    '?', // 0xfc
    '?', // 0xfd
    '?', // 0xfe
};
