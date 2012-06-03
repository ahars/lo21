/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.h
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QString>

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
    void opSWAP();
    void opSUM();
    void opMEAN();
    void opDUP();
    void opDROP();
    void opPlus();
    void opDim();
    void opMult();
    void opDiv();
    void opFact();
    void opSin();
    void opCos();
    void opTan();
    void opSinh();
    void opCosh();
    void opTanh();
    void opLog();
    void opLn();

};

#endif // OPERATEUR_H
