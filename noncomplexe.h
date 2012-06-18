/*!
  * \file noncomplexe.h
  * \brief Fichier header de la classe NonComplexe.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: noncomplexe.h
 */

#ifndef NONCOMPLEXE_H
#define NONCOMPLEXE_H

#include "type.h"

/*! \class NonComplexe
  * \brief Classe pour la gestion des constantes de type non complexe.
  * La classe permet de gérer les constantes de type non complexe.
  */
class NonComplexe: public Type
{
private:

public:
    /*!
      * \brief Constructeur par défaut de NonComplexe.
      * Constructeur par défaut de la classe NonComplexe.
      */
    NonComplexe() {}
};

#endif // NONCOMPLEXE_H
