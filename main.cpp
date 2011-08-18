
#include <QApplication>

#include "board.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    board goban;
#if defined(Q_OS_SYMBIAN)
    goban.showMaximized();
#else
    goban.show();
#endif
    return app.exec();
}
