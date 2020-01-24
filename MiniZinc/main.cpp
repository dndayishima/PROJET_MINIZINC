#include "minizinc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MiniZinc w;
    w.show();

    return a.exec();
}
