#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <width.h>
namespace Ui {
class Widget;
}



typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;
typedef int32_t i32;



extern u8 console[console_width*console_height];




class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool inited = false;
    int font_height = 0;
    int font_width = 0;

    void init() {
        if (inited) return;
        inited = true;
        setFont(QFont("Monospace"));
        font_height = fontMetrics().height();
        font_width = fontMetrics().width(' ');
    }


    virtual void paintEvent(QPaintEvent *);

    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
