#include <QtGui>
#include <QRect>
#include <QDebug>
#include "board.h"

board::board(QWidget *parent) :
    QWidget(parent)
{
    //setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);
    //connect(QEvent, SIGNAL(), this, SLOT(ClickSlot()));
    curX = 0;
    curY = 0;
    size = 9;
}

void board::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
     case Qt::Key_Left:
         Move(curX - 1, curY);
         qDebug() << "keyPressEvent: Key_Left";
         break;
     case Qt::Key_Right:
         Move(curX + 1, curY);
         qDebug() << "keyPressEvent: Key_Right";
         break;
     case Qt::Key_Down:
         Move(curX, curY + 1);
         qDebug() << "keyPressEvent: Key_Down";
         break;
     case Qt::Key_Up:
         Move(curX, curY - 1);
         qDebug() << "keyPressEvent: Key_Up";
         break;
     case Qt::Key_Space:
         //dropDown();
         qDebug() << "keyPressEvent: Key_Space";
         break;
     default:
         qDebug() << "keyPressEvent: " << event->key();
         //QFrame::keyPressEvent(event);
     }
}

void board::Move(int x, int y)
{
    qDebug() << "keyPressEvent: " << QString::number(x) << ":" << QString::number(y);
    if (x < size && x >= 0 &&
        y < size && y >= 0)
    {
        curX = x;
        curY = y;
        update();
    }
}

void board::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    int stepX = width() / size;
    int stepY = height() / size;
    int step = qMin(stepX, stepY);

    int min = step/2;
    int maxX = width() - step/2;
    int maxY = height() - step/2;
    int max = qMin(maxX, maxY);

    //рисуем курсор
    QRect cursor(step * curX,step * curY,step,step);
    painter.drawRect(cursor);

    //рисуем сетку
    for (int x = min, y = min, i = 1; i <= size; x += step, y += step, ++i)
    {
        painter.save();
        painter.drawLine(QPoint(min, y), QPoint(max, y));
        painter.drawLine(QPoint(x, min), QPoint(x, max));
        painter.restore();
    }
}
