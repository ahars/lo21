/*!
  * \file expression.h
  * \brief Fichier header de la classe Expression.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: expression.h
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "constante.h"

/*! \class Expression
  * \brief Classe permettant la gestion des constantes de type expression.
  * La classe permet de gérer les constantes de type expression.
  */
class Expression : public Constante
{
private:
    QString * expression;
    int n;

public:
    /*!
      * \brief Constructeur par défaut d'Expression.
      * Constructeur par défaut de la classe Expression
      */
    Expression(): n(0) { expression = new QString[100]; }

    /*!
      * \brief Destructeur d'Expression.
      * Destructeur de la classe Expression.
      */
    ~Expression() { delete[] expression; }

    /*!
      * \brief Méthode d'insertion dans la chaine de caractères de la classe Expression.
      * Méthode permettant d'inserer des éléments dans le string de la classe.
      * \param item
      */
    void insert(QString item) { expression[n++] = item; }

    /*!
      * \brief Getter du type de la classe Expression.
      *  Le getter renvoie la valeur du type de la classe Expression.
      * \return type de constante.
      */
    QString getType() const { return "expression"; }

    /*!
      * \brief Getter de l'expression de la classe.
      * Getter permettant de récupérer la valeur d'une chaine de caracères à un indice de la chaine.
      * \param i indice recherché.
      * \return expression trouvé à l'indice.
      */
    QString getExpression(const int i) const { return expression[i]; }

    /*!
      * \brief Getter du nombre d'éléments contenus dans la liste.
      * Getter permettant de savoir le nombre d'éléments de la liste.
      * \return n nombre d'éléments de la liste.
      */
    int getNombre() const { return n; }

    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }
};

#endif // EXPRESSION_H
