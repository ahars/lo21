/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: complexe.h
 */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include "constante.h"

class Complexe: public Type
{
private:
    Constante * partieReelle;
    Constante * partieImaginaire;

public:
    Complexe(Constante * item1, Constante * item2): partieReelle(item1), partieImaginaire(item2){}
};

#endif // COMPLEXE_H
