/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: pile.h
 */

#ifndef PILE_H
#define PILE_H

#include <QString>
#include "factoryConstante.h"

class Pile
{

private:
    int max;
    int n;
    Constante ** tab;

public:
    Pile(const int maximum = 10);
    ~Pile();
    int getMax() const { return max; }
    int getN() const { return n; }
    Constante * getTab(const int i) const { return tab[i]; }
    void setTab(const int i, Constante * item) { tab[i] = item; }
    bool pilePleine();
    bool pileVide();
    void empiler(Constante * noeud);
    Constante * depiler();
};

#endif // PILE_H
