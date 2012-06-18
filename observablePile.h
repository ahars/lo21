/*!
  * \file observablePile.h
  * \brief Fichier header de la classe ObservablePile.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: observablePile.h
 */

#ifndef OBSERVABLEPILE_H
#define OBSERVABLEPILE_H

#include "observateurMW.h"
#include <set>

class ObservateurMW;

/*! \class ObservablePile
  * \brief Classe pour la gestion du Design Pattern Observer.
  * La classe permet de gérer l'observation de l'ObservablePile.
  */
class ObservablePile
{
protected:
    std::set<ObservateurMW *> obs;

public:
    /*!
      * \brief Fonction qui ajoute un observateur de type MainWindow.
      * Fonction qui ajoute un observateur de type MainWindow.
      * \param o Observateur MainWindow.
      */
    virtual void ajouterObservateurMW(ObservateurMW * o) = 0;

    /*!
      * \brief Fonction qui supprime un observateur de type MainWindow.
      * Fonction qui supprime un observateur de type MainWindow.
      * \param o Observateur MainWindow.
      */
    virtual void supprimerObservateurMW(ObservateurMW * o) = 0;

    /*!
      * \brief Fonction de notification d'un changement dans la pile du Design Pattern Observer.
      * Fonction qui envoie une notification aux objets en attente.
      */
    virtual void notifier() = 0;
};

#endif // OBSERVABLEPILE_H
