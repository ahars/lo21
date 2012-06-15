/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.cpp
 */

#include "operateur.h"
#include "factoryConstante.h"

void Operateur::opSWAP(Pile & pile, int valeur1, int valeur2)
{
    if (valeur1 < (pile.getN() + 1) && valeur2 < (pile.getN() + 1) && valeur1 != valeur2)
    {
        if (pile.getN() > 1)
        {

        }
        else
        {
            QMessageBox m;
            m.setText("La pile ne contient pas 2 elements minimum.");
            m.exec();
        }
    }
    else
    {
        QMessageBox m;
        m.setText("Les arguments de la fonction sont faux.");
        m.exec();
    }
}

void Operateur::opSUM(Pile & pile)
{

}

void Operateur::opMEAN(Pile & pile)
{

}

void Operateur::opDUP(Pile & pile)
{

}

void Operateur::opDROP(Pile & pile)
{

}

void Operateur::opPlus(Pile & pile)
{

}

void Operateur::opDim(Pile & pile)
{

}

void Operateur::opMult(Pile & pile)
{

}

void Operateur::opDiv(Pile & pile)
{

}

void Operateur::opFact(Pile & pile)
{

}

void Operateur::opSin(Pile & pile)
{

}

void Operateur::opCos(Pile & pile)
{

}

void Operateur::opTan(Pile & pile)
{

}

void Operateur::opSinh(Pile & pile)
{

}

void Operateur::opCosh(Pile & pile)
{

}

void Operateur::opTanh(Pile & pile)
{

}

void Operateur::opLog(Pile & pile)
{

}

void Operateur::opLn(Pile & pile)
{

}
