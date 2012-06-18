/*!
  * \file type.h
  * \brief Fichier header de la classe Type.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: type.h
 */

#ifndef TYPE_H
#define TYPE_H

#include "constante.h"

/*! \class Type
  * \brief Classe pour avoir le type des constants.
  * La classe Type permet de récupérer le type des constants.
  */
class Type: public Constante
{
private:
    QString type;

public:
    /*!
      * \brief Constructeur par défaut de Type.
      * Constructeur par défaut de la classe Type.
      */
    Type(){}
};

#endif // TYPE_H
