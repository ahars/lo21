/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: reel.h
 */

#ifndef REEL_H
#define REEL_H

#include "noncomplexe.h"

class Reel: public NonComplexe
{
private:
    float reel;

public:
    Reel(float item): reel(item) {}
    float getReel() const { return reel; }
    int getEntier() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }
    QString getType() const { return "reel"; }
};

#endif // REEL_H
