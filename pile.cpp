/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: pile.cpp
 */

#include "pile.h"

// Constructeur.
Pile::Pile(const int maximum):
    max(maximum),
    n(0)
{
    tab = new QString[max];
}

// Destructeur.
Pile::~Pile()
{
    delete[] tab;
}

// Retourne TRUE si la pile est pleine.
bool Pile::pilePleine()
{
    if (n < max)
        return false;
    else
        return true;
}

// Retourne TRUE si la pile est vide.
bool Pile::pileVide()
{
    if (n == 0)
        return true;
    else
        return false;
}

// Empile un élément dans la pile.
void Pile::empiler(QString noeud)
{
    if (!pilePleine())
    {
        tab[n] = noeud;
        n++;
    }
}

// Dépile le dernier élément de la pile.
QString Pile::depiler()
{
    QString result;
    if (!pileVide())
    {
        result = tab[n-1];
        n--;
    }
    return result;
}