/*!
  * \file complexe.h
  * \brief Fichier header de la classe Complexe.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: complexe.h
 */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include "constante.h"

/*! \class Complexe
  * \brief Classe permettant la gestion de toutes les constantes de type complexe.
  * La classe permet de gérer toutes les constantes de type complexe.
  */
class Complexe: public Type
{
private:
    Constante * partieReelle;
    Constante * partieImaginaire;

public:
    /*!
      * \brief Constructeur par défaut de Complexe.
      * Constructeur par défaut de la classe Complexe.
      */
    Complexe() {}

    /*!
      * \brief Constructeur de la classe Complexe.
      * Constructeur de la classe Complexe.
      * \param item1 valeur de la partie réelle.
      * \param item2 valeur de la partie imaginaire.
      * \return Objet Complexe
      */
    Complexe(Constante * item1, Constante * item2): partieReelle(item1), partieImaginaire(item2) {}

    int getEntier() const { return 0; }
    float getReel() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }

    /*!
      * \brief Getter de la partie réelle du complexe.
      * Getter permettant d'obtenir la valeur de la partie réelle du complexe.
      * \return Objet Constante correspondant à la partie réelle du complexe.
      */
    Constante * getPartieReelle() const { return partieReelle; }

    /*!
      * \brief Getter de la partie imaginaire du complexe.
      * Getter permettant d'obtenir la valeur de la partie imaginaire du complexe.
      * \return Objet Constante correspondant à la partie imaginaire du complexe.
      */
    Constante * getPartieImaginaire() const { return partieImaginaire; }

    /*!
      * \brief Getter du type de l'objet Complexe.
      * Méthode permettant d'obtenir la valeur du type de l'objet Complexe.
      * \return Type de l'objet Complexe.
      */
    QString getType() const { return "complexe"; }
};

#endif // COMPLEXE_H
