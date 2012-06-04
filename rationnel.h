/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: rationnel.h
 */

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "noncomplexe.h"

class Rationnel: public NonComplexe
{
private:
    int numerateur;
    int denominateur;

public:
    Rationnel(int item1, int item2): numerateur(item1), denominateur(item2) {}
    int getNumerateur() const { return numerateur; }
    int getDenominateur() const { return denominateur; }
    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }
    QString getType() const { return "rationnel"; }
};

#endif // RATIONNEL_H
