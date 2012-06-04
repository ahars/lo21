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
    Complexe() {}
    Complexe(Constante * item1, Constante * item2): partieReelle(item1), partieImaginaire(item2) {}
    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return partieReelle; }
    Constante * getPartieImaginaire() const { return partieImaginaire; }
    QString getType() const { return "complexe"; }
};

#endif // COMPLEXE_H
