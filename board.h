#ifndef BOARD_H
#define BOARD_H

#include <QWidget>


class board : public QWidget
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void Move(int, int);

    int curX;
    int curY;
    int size;
};

#endif // BOARD_H
