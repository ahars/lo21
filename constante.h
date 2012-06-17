/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: constante.h
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QString>

class Constante
{
public:
    Constante() {}
    virtual QString getType() const = 0;
    virtual int getEntier() const = 0;
    virtual float getReel() const = 0;
    virtual int getNumerateur() const = 0;
    virtual int getDenominateur() const = 0;
    virtual Constante * getPartieReelle() const = 0;
    virtual Constante * getPartieImaginaire() const = 0;
};

#endif // CONSTANTE_H
