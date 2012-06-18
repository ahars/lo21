/*!
  * \file operateur.h
  * \brief Fichier header de la classe Operateur.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: operateur.h
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QMessageBox>
#include "math.h"
#include "pile.h"

#define PI 3.14

/*! \class Operateur
  * \brief Classe pour la gestion de toutes les opérations sur les constantes.
  * La classe regroupe tous les opérateurs sur les constantes.
  */
class Operateur
{
public:
    /*!
      * \brief Constructeur d'Operateur
      * Constructeur de la classe Operateur.
      */
    Operateur(){}

    /*!
      * \brief Opérateur SWAP de Operateur.
      * Permutation de 2 éléments de la pile.
      * \param p La référence de la pile.
      */
    void opSWAP(Pile & p);

    /*!
      * \brief Opérateur SUM de Operateur.
      * Somme d'un nombre d'élements de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opSUM(Pile & p, QString mode, int com);

    /*!
      * \brief Opérateur MEAN de Operateur.
      * Moyenne d'un nombre d'éléments de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opMEAN(Pile & p, QString mode, int com);

    /*!
      * \brief Opérateur DUP de Operateur.
      * Duplication du premier élément de la pile.
      * \param p La référence de la pile.
      */
    void opDUP(Pile & p);

    /*!
      * \brief Opérateur DROP de Operateur.
      * Suppression du premier élément de la pile.
      * \param p La référence de la pile.
      */
    void opDROP(Pile & p);

    /*!
      * \brief Opérateur + de Operateur.
      * Calcul de l'addition de deux éléments de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opPlus(Pile & p, QString mode,int com);

    /*!
      * \brief Opérateur - de Operateur.
      * Calcul de la soustraction de deux éléments de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opDim(Pile & p, QString mode,int com);

    /*!
      * \brief Opérateur * de Operateur.
      * Calcul de la multiplication de deux éléments de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opMult(Pile & p, QString mode,int com);

    /*!
      * \brief Opérateur / de Operateur.
      * Calcul de la division de deux éléments de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      * \param com Le paramètre complexe à vrai ou faux.
      */
    void opDiv(Pile & p, QString mode,int com);

    /*!
      * \brief Opérateur ! de Operateur.
      * Calcul de la factoriel d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opFact(Pile & p);

    /*!
      * \brief Opérateur sin de Operateur.
      * Calcul du sinus d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opSin(Pile & p, QString type);

    /*!
      * \brief Opérateur cos de Operateur.
      * Calcul du cosinus d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opCos(Pile & p, QString type);

    /*!
      * \brief Opérateur tan de Operateur.
      * Calcul de la tangente d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opTan(Pile & p, QString type);

    /*!
      * \brief Opérateur sinh de Operateur.
      * Calcul du sinus hyperbolique d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opSinh(Pile & p, QString type);

    /*!
      * \brief Opérateur cosh de Operateur.
      * Calcul du cosinus hyperbolique d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opCosh(Pile & p, QString type);

    /*!
      * \brief Opérateur tanh de Operateur.
      * Calcul de la tangente hyperbolique d'un élément de la pile.
      * \param p La référence de la pile.
      * \param type Le type de constantes utilisé.
      */
    void opTanh(Pile & p, QString type);

    /*!
      * \brief Opérateur log de Operateur.
      * Calcul du logarithme d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opLog(Pile & p);

    /*!
      * \brief Opérateur ln de Operateur.
      * Calcul du logarithme népérien d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opLn(Pile & p);

    /*!
      * \brief Opérateur POW de Operateur.
      * Calcul de la puissance d'un élément de la pile par un second élément de la pile.
      * \param p La référence de la pile.
      * \param mode Le type de constantes utilisé.
      */
    void opPOW(Pile & p, QString mode);

    /*!
      * \brief Opérateur % de Operateur.
      * Calcul du modulo d'un élément de la pile par un autre élément de la pile.
      * \param p La référence de la pile.
      */
    void opMOD(Pile & p);

    /*!
      * \brief Opérateur SIGN de Operateur.
      * Inversion du signe d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opSIGN(Pile & p);

    /*!
      * \brief Opérateur INV de Operateur.
      * Calcul de l'inverse d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opINV(Pile & p);

    /*!
      * \brief Opérateur SQRT de Operateur.
      * Calcul de la racine carré d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opSQRT(Pile & p);

    /*!
      * \brief Opérateur SQR de Operateur.
      * Calcul du carré d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opSQR(Pile & p);

    /*!
      * \brief Opérateur CUBE de Operateur.
      * Calcul du cube d'un élément de la pile.
      * \param p La référence de la pile.
      */
    void opCUBE(Pile & p);
};

#endif // OPERATEUR_H
