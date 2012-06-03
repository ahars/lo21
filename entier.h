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
    // Constructeur.
    Entier(int item): entier(item){}

    // Getter et Setter.

    // Autres.

};

#endif // ENTIER_H
