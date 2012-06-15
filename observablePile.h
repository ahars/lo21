/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: observablePile.h
 */

#ifndef OBSERVABLEPILE_H
#define OBSERVABLEPILE_H

#include "observateurMW.h"
#include <set>

class ObservateurMW;

class ObservablePile
{
protected:
    std::set<ObservateurMW *> obs;
public:
    virtual void ajouterObservateurMW(ObservateurMW * o) = 0;
    virtual void supprimerObservateurMW(ObservateurMW * o) = 0;
    virtual void notifier() = 0;
};

#endif // OBSERVABLEPILE_H
