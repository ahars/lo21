/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.h
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QMessageBox>
#include <QString>
#include "pile.h"

class Operateur
{
private:
    QString type;   // type en radian ou degrès (initialisé en radian).

public:
    // Constructeur
    Operateur(): type("rad"){}

    // Getters et Setters.
    QString getType() const { return type; }
    void setType(const QString t){ type = t; }

    // Autres
    void opSWAP(Pile & pile, int valeur1 = 0, int valeur2 = 0);
    void opSUM(Pile & pile);
    void opMEAN(Pile & pile);
    void opDUP(Pile & pile);
    void opDROP(Pile & pile);
    void opPlus(Pile & pile);
    void opDim(Pile & pile);
    void opMult(Pile & pile);
    void opDiv(Pile & pile);
    void opFact(Pile & pile);
    void opSin(Pile & pile);
    void opCos(Pile & pile);
    void opTan(Pile & pile);
    void opSinh(Pile & pile);
    void opCosh(Pile & pile);
    void opTanh(Pile & pile);
    void opLog(Pile & pile);
    void opLn(Pile & pile);

};

#endif // OPERATEUR_H
