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
    QString * tab;

public:

    // Constructeurs et Destructeurs.
    Pile(const int maximum = 10);
    ~Pile();

    // Getters et Setters.
    int getMax() const { return max; }
    int getN() const { return n; }

    // Autres.
    bool pilePleine();
    bool pileVide();
    void empiler(QString noeud);
    QString depiler();

};

#endif // PILE_H
