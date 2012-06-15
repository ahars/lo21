/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: observateurMW.h
 */

#ifndef OBSERVATEURMW_H
#define OBSERVATEURMW_H

#include "observablePile.h"

class ObservablePile;

class ObservateurMW
{
public:
    virtual void miseAJour() = 0;
};

#endif // OBSERVATEURMW_H
