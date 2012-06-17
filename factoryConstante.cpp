/**
\file factoryConstante.cpp
\author Jia Han & Antoine Hars
\brief Déclaration des méthodes de la classe FactoryConstante

Ce fichier contient la déclaration des méthodes de la class FactoryConstante.

**/

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: factoryConstante.cpp
 */

#include "factoryConstante.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"

Constante * FactoryConstante::creeConstante(QString type, int item1, int item2, float item3, Constante * item4, Constante * item5)
{
    if (type == "entier")
        return new Entier(item1);
    if (type == "reel")
        return new Reel(item3);
    if (type == "rationnel")
        return new Rationnel(item1, item2);
    if (type == "complexe")
        return new Complexe(item4, item5);
}
