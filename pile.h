/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: pile.h
 */

#ifndef PILE_H
#define PILE_H

#include <QString>

class Pile
{

private:
    int max;
    int n;
    QString * tab;

public:
    Pile(const int maximum = 10);
    ~Pile();
    bool pilePleine();
    bool pileVide();
    void empiler(QString noeud);
    QString depiler();

};

#endif // PILE_H
