/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: factoryConstante.h
 */

#ifndef FACTORYCONSTANTE_H
#define FACTORYCONSTANTE_H

#include "constante.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"

class FactoryConstante
{
public:
    FactoryConstante() {}
    Constante * creeConstante(QString type, int item1 = 0, int item2 = 0, float item3 = 0, Constante * item4 = 0, Constante * item5 = 0);
};

#endif // FACTORYCONSTANTE_H
