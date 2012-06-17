/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: expression.h
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"

class Expression : public Constante
{
private:
    QString * expression;
    int n;

public:
    Expression(): n(0) { expression = new QString[100]; }
    ~Expression() { delete[] expression; }
    void insert(QString item) { expression[n++] = item; }
    QString getType() const { return "expression"; }
    QString getExpression(const int i) const { return expression[i]; }
    int getNombre() const { return n; }
    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }
};

#endif // EXPRESSION_H
