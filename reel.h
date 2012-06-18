/*!
  * \file reel.h
  * \brief Fichier header de la classe Reel.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: reel.h
 */

#ifndef REEL_H
#define REEL_H

#include "noncomplexe.h"

/*! \class Reel
  * \brief Classe pour la gestion des constantes de type réel.
  * La classe permet de gérer toutes les constantes de type réel.
  */
class Reel: public NonComplexe
{
private:
    float reel;

public:
    /*!
      * \brief Constructeur de Reel.
      * Constructeur de la classe Reel.
      * \param item la valeur à insérer dans l'objet Reel.
      * \return Objet de la classe Reel.
      */
    Reel(float item): reel(item) {}

    /*!
      * \brief Getter de la valeur de l'objet Reel.
      * Méthode permettant d'obtenir la valeur de l'objet Reel.
      * \return Valeur de l'objet Reel.
      */
    float getReel() const { return reel; }

    int getEntier() const { return 0; }
    int getNumerateur() const { return 0; }
    int getDenominateur() const { return 0; }
    Constante * getPartieReelle() const { return 0; }
    Constante * getPartieImaginaire() const { return 0; }

    /*!
      * \brief Getter du type de l'objet Reel.
      * Méthode permettant d'obtenir la valeur du type de l'objet Reel.
      * \return Type de l'objet Reel.
      */
    QString getType() const { return "reel"; }
};

#endif // REEL_H
