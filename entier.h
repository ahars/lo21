/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: entier.h
 */

#ifndef ENTIER_H
#define ENTIER_H

#include "noncomplexe.h"

class Entier: public NonComplexe
{
private:
    int entier;

public:
    Entier() {}
    Entier(int item): entier(item) {}
    int getEntier() const { return entier; }
    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }
    QString getType() const { return "entier"; }
};

#endif // ENTIER_H
