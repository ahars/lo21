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
    Reel(float item): reel(item){}
};

#endif // REEL_H
