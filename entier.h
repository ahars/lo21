/*!
  * \file entier.h
  * \brief Fichier header de la classe Entier.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: entier.h
 */

#ifndef ENTIER_H
#define ENTIER_H

#include "noncomplexe.h"

/*! \class Entier
  * \brief Classe permettant la gestion de constantes de type Entier.
  * La classe permet de gérer toutes les constantes de type Entier.
  */
class Entier: public NonComplexe
{
private:
    int entier;

public:
    /*!
      * \brief Constructeur par défaut de Constante'Entier.
      * Constructeur par défaut de la classe Entier.
      */
    Entier() {}

    /*!
      * \brief Constructeur de Entier.
      * Constructeur de la classe Entier.
      * \param item Valeur à entrer dans l'Entier.
      */
    Entier(int item): entier(item) {}

    /*!
      * \brief Getter de la valeur de l'objet Entier.
      * Méthode permettant d'obtenir la valeur de l'objet Entier.
      * \return Valeur de l'objet Entier.
      */
    int getEntier() const { return entier; }

    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }

    /*!
      * \brief Getter du type de l'objet Entier.
      * Méthode permettant d'obtenir la valeur du type de l'objet Entier.
      * \return Type de l'objet Entier.
      */
    QString getType() const { return "entier"; }
};

#endif // ENTIER_H
