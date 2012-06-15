/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Jiahan & Antoine Hars
 * File: main.cpp
 */

#include <QtGui/QApplication>

#include "complexe.h"
#include "constante.h"
#include "entier.h"
#include "expression.h"
#include "factoryConstante.h"
#include "mainwindow.h"
#include "noncomplexe.h"
#include "operateur.h"
#include "pile.h"
#include "rationnel.h"
#include "reel.h"
#include "type.h"
#include "observablePile.h"
#include "observateurMW.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow & w = MainWindow::donneInstance();
    w.show();

    return a.exec();
    w.libereInstance();
}
