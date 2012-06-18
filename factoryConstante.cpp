/*!
 * \file factoryConstante.cpp
 * \author Jia Han & Antoine Hars
 * \brief Déclaration des méthodes de la classe FactoryConstante.
 * Ce fichier contient la déclaration des méthodes de la classe FactoryConstante.
 */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: factoryConstante.cpp
 */

#include "factoryConstante.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"

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
Constante * FactoryConstante::creeConstante(QString type, int item1, int item2, float item3, Constante * item4, Constante * item5, QString item6)
{
    if (type == "entier")
        return new Entier(item1);
    if (type == "reel")
        return new Reel(item3);
    if (type == "rationnel")
        return new Rationnel(item1, item2);
    if (type == "complexe")
        return new Complexe(item4, item5);
//    if (type == "expression")
  //      return new Expression(item6);
}
