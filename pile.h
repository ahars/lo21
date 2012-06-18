/*!
  * \file pile.h
  * \brief Fichier header de la classe Pile.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: pile.h
 */

#ifndef PILE_H
#define PILE_H

#include <QString>
#include <set>

#include "factoryConstante.h"
#include "observablePile.h"

/*! \class Pile
  * \brief Classe pour la gestion et le stockage de toutes les constantes.
  * La classe permet de stocker et de gérer toutes les constantes.
  */
class Pile: public ObservablePile
{
private:
    int max;
    int n;
    Constante ** tab;
    static Pile * instanceUnique;

    /*!
      * \brief Constructeur par défaut de Pile.
      * Constructeur par défaut de la class Pile.
      */
    Pile();

    /*!
      * \brief Constructeur par recopie de Pile.
      * Constructeur par recopie de la classe Pile.
      * \param Objet de la classe Pile
      */
    Pile(const Pile &);
    //explicit Pile(QWidget * parent = 0);

    /*!
      * \brief Destructeur de Pile.
      * Destructeur de la classe Pile.
      */
    virtual ~Pile();

    /*!
      * \brief Méthode de Pile pour l'opérateur = entre deux objets Pile.
      * Méthode de la classe Pile pour la copie avec l'opérateur = entre deux objets Pile.
      */
    void operator=(const Pile &);

public:
    /*!
      * \brief Méthode de Pile du Design Pattern Singleton pour créer un objet Pile.
      * Méthode de la classe Pile pour limiter le nombre d'instanciations de l'interface graphique.
      * \return Objet de la classe Pile.
      */
    static Pile & donneInstance();

    /*!
      * \brief Méthode de Pile du Design Pattern Singleton pour détruire un objet Pile.
      * Méthode de la classe Pile pour détruire une instanciation de l'interface graphique.
      */
    static void libereInstance();

    /*!
      * \brief Getter de la valeur de la capacité maximale de la pile.
      * Méthode permettant d'obtenir la valeur de la capacité maximale de la pile.
      * \return Valeur de la capacité maximale de la pile.
      */
    int getMax() const { return max; }

    /*!
      * \brief Getter de l'indice du dernier élément entré dans la pile.
      * Méthode permettant d'obtenir la valeur de l'indice du dernier élément entré dans la pile.
      * \return Valeur de l'indice du dernier élément entré dans la pile.
      */
    int getN() const { return n; }

    /*!
      * \brief Setter de l'indice du dernier élément entré dans la pile.
      * Méthode permettant de modifier la valeur de l'indice du dernier élément entré dans la pile.
      * \param Entier.
      */
    void setN(const int nb) { n = nb; }

    /*!
      * \brief Getter d'un élément de la pile de constantes.
      * Méthode pour obtenir un élément de la pile.
      * \param i Indice de l'élément dans la pile
      * \return Constante de la pile.
      */
    Constante * getTab(const int i) const { return tab[i]; }

    /*!
      * \brief Setter d'un élément de la pile de constantes.
      * Méthode pour modifier la valeur d'un élément de la pile.
      * \param i indice de l'élément à empiler.
      * \param item valeur de la constante à empiler.
      */
    void setTab(const int i, Constante * item) { tab[i] = item; }

    /*!
      * \brief Fonction qui teste le cas d'une pile pleine.
      * Fonction qui teste le nombre de places libres dans la pile.
      * \return Boolean true si la pile est pleine, sinon false.
      */
    bool pilePleine();

    /*!
      * \brief Fonction qui teste le cas d'une pile vide.
      * Fonction qui teste la présence d'un élément dans la pile.
      * \return Boolean true si la pile est vide sinon false.
      */
    bool pileVide();

    /*!
      * \brief Fonction d'empilement d'une constante dans la Pile.
      * Fonction qui empile une constante de la classe Pile.
      * \param noeud Constante à empiler.
      */
    void empiler(Constante * noeud);

    /*!
      * \brief Fonction qui dépile un élément de la pile.
      * Fonction de dépilement d'un élément de la classe Pile.
      * \return Constante dépilée.
      */
    Constante * depiler();

    /*!
      * \brief Fonction qui ajoute un observateur de type MainWindow.
      * Fonction qui ajoute un observateur de type MainWindow.
      * \param o Observateur MainWindow.
      */
    void ajouterObservateurMW(ObservateurMW * o) { obs.insert(o); }

    /*!
      * \brief Fonction qui supprime un observateur de type MainWindow.
      * Fonction qui supprime un observateur de type MainWindow.
      * \param o Observateur MainWindow.
      */
    void supprimerObservateurMW(ObservateurMW *o) { obs.erase(o); }

    /*!
      * \brief Fonction de notification d'un changement dans la pile du Design Pattern Observer.
      * Fonction qui envoie une notification aux objets en attente.
      */
    void notifier();
};

#endif // PILE_H
