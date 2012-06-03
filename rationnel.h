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
    Rationnel(int item1, int item2): numerateur(item1), denominateur(item2){}
};

#endif // RATIONNEL_H
