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
    tab = new Constante * [max];
}

// Destructeur.
Pile::~Pile()
{
    for (int i = 0; i < max; i++)
        delete tab[i];
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
void Pile::empiler(Constante * noeud)
{
    if (!pilePleine())
    {
        tab[n] = noeud;
        n++;
    }
}

// Dépile le dernier élément de la pile.
Constante * Pile::depiler()
{
    Constante * result;
    if (!pileVide())
    {
        result = tab[n-1];
        n--;
    }
    return result;
}

// Notifier à l'observateur.
void Pile::notifier()
{
    std::set<ObservateurMW *>::iterator it;
    for (it = obs.begin(); it != obs.end(); ++it)
        (* it)->miseAJour();
}


