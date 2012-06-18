/*!
  * \file factoryconstante.h
  * \brief Fichier header de la classe FactoryConstante.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: factoryConstante.h
 */

#ifndef FACTORYCONSTANTE_H
#define FACTORYCONSTANTE_H

#include "constante.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"

/*! \class FactoryConstante
  * \brief Classe permettant la gestion de l'instanciation des constantes.
  * La classe permet de gérer l'instanciation des constantes.
  */
class FactoryConstante
{
public:
    /*!
      * \brief Constructeur par défaut de FactoryConstante.
      * Constructeur par défaut de la classe FactoryConstante.
      */
    FactoryConstante() {}

    /*!
      * \brief Méthode de FactoryConstante pour la création des objets de constante en fonction du type recherché.
      * Constructeur de la classe MainWindow.
      * \param type
      * \param item1 Le contenu de l'entier à créer ou du numérateur du rationnel à créer.
      * \param item2 Le contenu du dénominateur du rationnel à créer.
      * \param item3 Le contenu du réel à créer.
      * \param item4 La partie réelle du complexe à créer.
      * \param item5 La partie imaginaire du complexe à créer.
      * \param item6 Le contenu de l'expression à créer.
      * \return un objet d'une classe fille de Constante.
      */
    Constante * creeConstante(QString type, int item1 = 0, int item2 = 0, float item3 = 0, Constante * item4 = 0, Constante * item5 = 0, QString item6 = "");
};

#endif // FACTORYCONSTANTE_H
