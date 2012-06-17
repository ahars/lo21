/**
\file main.cpp
\author Jia Han & Antoine Hars
\brief Instanciation de la calculatrice

Ce fichier contient la déclaration de la fonction main pour l'instanciation de l'interface graphique.

**/

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

//! Fonction main.\n
//! Instancie l'interface graphique de la calculatrice.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow & w = MainWindow::donneInstance();
    w.show();

    return a.exec();
    w.libereInstance();
}
