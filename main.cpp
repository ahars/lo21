/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Jiahan & Antoine Hars
 * File: main.cpp
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow & w = MainWindow::donneInstance();
    w.show();

    //w.libereInstance();

    return a.exec();
}
