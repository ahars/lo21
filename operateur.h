/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.h
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QMessageBox>
#include "math.h"
#include "pile.h"

#define PI 3.14

class Operateur
{
public:
    Operateur(){}
    void opSWAP(Pile & p);  //fonction SWAP
    void opSUM(Pile & p, QString mode, int com);   //fonction SUM
    void opMEAN(Pile & p, QString mode, int com);  //fonction MEAN
    void opDUP(Pile & p);   //fonction DUP
    void opDROP(Pile & p);  //fonction DROP
    void opPlus(Pile & p, QString mode,int com);  //fonction +
    void opDim(Pile & p, QString mode,int com);   //fonction -
    void opMult(Pile & p, QString mode,int com);  //fonction *
    void opDiv(Pile & p, QString mode,int com);   //fonction diviser /
    void opFact(Pile & p);  //fonction factoriel !
    void opSin(Pile & p, QString type);   //fonction sin
    void opCos(Pile & p, QString type);   //fonction cos
    void opTan(Pile & p, QString type);   //fonction tan
    void opSinh(Pile & p, QString type);  //fonction sinh
    void opCosh(Pile & p, QString type);  //fonction cosh
    void opTanh(Pile & p, QString type);  //fonction tanh
    void opLog(Pile & p);   //fonction log
    void opLn(Pile & p);    //fonction ln
    void opPOW(Pile & p, QString mode);   //fonction POW
    void opMOD(Pile & p);   //fonction MOD
    void opSIGN(Pile & p);  //fonction SIGN
    void opINV(Pile & p);   //fonction INV
    void opSQRT(Pile & p);  //fonction SQRT
    void opSQR(Pile & p);   //fonction SQR
    void opCUBE(Pile & p);  //fonction CUBE
};

#endif // OPERATEUR_H
