/*!
  * \file rationnel.h
  * \brief Fichier header de la classe Rationnel.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: rationnel.h
 */

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "noncomplexe.h"

/*! \class Rationnel
  * \brief Classe pour la gestion des constantes de type rationnel.
  * La classe permet de gérer toutes les constantes de type rationnel.
  */
class Rationnel: public NonComplexe
{
private:
    int numerateur;
    int denominateur;

public:
    /*!
      * \brief Constructeur de rationnel.
      * Constructeur de la classe Rationnel.
      * \param item1 valeur pour le numérateur.
      * \param item2 valeur pour le dénominateur.
      */
    Rationnel(int item1, int item2): numerateur(item1), denominateur(item2) {}

    /*!
      * \brief Getter de la valeur du numérateur de l'objet Rationnel.
      * Méthode permettant d'obtenir la valeur du numérateur de l'objet Rationnel.
      * \return Valeur du numérateur de l'objet Rationnel.
      */
    int getNumerateur() const { return numerateur; }

    /*!
      * \brief Getter de la valeur du dénominateur de l'objet Rationnel.
      * Méthode permettant d'obtenir la valeur du dénominateur de l'objet Rationnel.
      * \return Valeur du dénominateur de l'objet Rationnel.
      */
    int getDenominateur() const { return denominateur; }

    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }

    /*!
      * \brief Getter du type de l'objet Rationnel.
      * Méthode permettant d'obtenir la valeur du type de l'objet Rationnel.
      * \return Type de l'objet Rationnel.
      */
    QString getType() const { return "rationnel"; }
};

#endif // RATIONNEL_H

