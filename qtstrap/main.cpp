#include "main_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qtstrap::main_window wnd;
    wnd.show();

    return a.exec();
}
