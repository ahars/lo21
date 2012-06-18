/*!
  * \file constante.h
  * \brief Fichier header de la classe Constante
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: constante.h
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QString>

/*! \class Constante
  * \brief Classe permettant de gérer toutes les données de la Pile.
  * La classe permet la gestion du type des données de la Pile
  */
class Constante
{
public:
    /*!
      * \brief Constructeur par défaut de Constante.
      * Constructeur par défaut de la classe Constante.
      */
    Constante() {}

    /*!
      * \brief Getter du type de l'objet Constante.
      * Méthode permettant d'obtenir la valeur du type de l'objet Constante.
      * \return Type de l'objet Constante.
      */
    virtual QString getType() const = 0;

    /*!
      * \brief
      *
      * \param
      * \return
      */
    virtual int getEntier() const = 0;

    /*!
      * \brief Getter de la valeur de l'objet Reel.
      * Méthode permettant d'obtenir la valeur de l'objet Reel.
      * \return Valeur de l'objet Reel.
      */
    virtual float getReel() const = 0;

    /*!
      * \brief Getter de la valeur du numérateur de l'objet Rationnel.
      * Méthode permettant d'obtenir la valeur du numérateur de l'objet Rationnel.
      * \return Valeur du numérateur de l'objet Rationnel.
      */
    virtual int getNumerateur() const = 0;

    /*!
      * \brief Getter de la valeur du dénominateur de l'objet Rationnel.
      * Méthode permettant d'obtenir la valeur du dénominateur de l'objet Rationnel.
      * \return Valeur du dénominateur de l'objet Rationnel.
      */
    virtual int getDenominateur() const = 0;

    /*!
      * \brief Getter de la partie réelle du complexe.
      * Getter permettant d'obtenir la valeur de la partie réelle du complexe.
      * \return Objet Constante correspondant à la partie réelle du complexe.
      */
    virtual Constante * getPartieReelle() const = 0;

    /*!
      * \brief Getter de la partie imaginaire du complexe.
      * Getter permettant d'obtenir la valeur de la partie imaginaire du complexe.
      * \return Objet Constante correspondant à la partie imaginaire du complexe.
      */
    virtual Constante * getPartieImaginaire() const = 0;
};

#endif // CONSTANTE_H
