/*!
  * \file observateurMW.h
  * \brief Fichier header de la classe observateurMW.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: observateurMW.h
 */

#ifndef OBSERVATEURMW_H
#define OBSERVATEURMW_H

#include "observablePile.h"

class ObservablePile;

/*! \class ObservateurMW
  * \brief Classe pour la gestion du Design Pattern Observer.
  * La classe permet de gérer l'observation de la pile.
  */
class ObservateurMW
{
public:
    /*!
      * \brief Méthode de l'ObservateurMW du Design Pattern Observer entre Pile et MainWindow.
      * Méthode de la classe ObservateurMW pour afficher tous les changements de l'ObservablePile.
      */
    virtual void miseAJour() = 0;
};

#endif // OBSERVATEURMW_H
