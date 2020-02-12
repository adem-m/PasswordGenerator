#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWindow fenetre;
    fenetre.show();

    return a.exec();
}
