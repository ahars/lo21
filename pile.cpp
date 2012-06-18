/*!
 * \file pile.cpp
 * \author Jia Han & Antoine Hars
 * \brief Déclaration des méthodes de la classe Pile.
 * Ce fichier contient la déclaration des méthodes de la classe Pile.
 */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: pile.cpp
 */

#include "pile.h"

Pile * Pile::instanceUnique = 0;

/*!
  * \brief Fonction d'instanciation d'une pile au moyen du Design Pattern Singleton.
  * Fonction de création de l'objet de la classe Pile.
  * \return Objet Pile instancié.
  */
Pile & Pile::donneInstance()
{
    if (instanceUnique == 0)
        instanceUnique = new Pile();
    return * instanceUnique;
}

/*!
  * \brief Fonction qui détruit l'objet pile.
  * Fonction de destruction d'un objet de la classe Pile.
  */
void Pile::libereInstance()
{
    if (instanceUnique != 0)
        delete instanceUnique;
    instanceUnique = 0;
}

/*!
  * \brief Constructeur par défaut de la pile.
  * Constructeur par défaut de la classe Pile.
  */
Pile::Pile():
    max(100),
    n(0)
{
    tab = new Constante * [max];
}

/*!
  * \brief Destructeur de Pile.
  * Destructeur de la classe Pile.
  */
Pile::~Pile()
{
    for (int i = 0; i < max; i++)
        delete tab[i];
    delete[] tab;
}

/*!
  * \brief Fonction qui teste le cas d'une pile pleine.
  * Fonction qui teste le nombre de places libres dans la pile.
  * \return Boolean true si la pile est pleine, sinon false.
  */
bool Pile::pilePleine()
{
   return n == 0;
}

/*!
  * \brief Fonction qui teste le cas d'une pile vide.
  * Fonction qui teste la présence d'un élément dans la pile.
  * \return Boolean true si la pile est vide sinon false.
  */
bool Pile::pileVide()
{
    return n == max;
}

/*!
  * \brief Fonction d'empilement d'une constante dans la Pile.
  * Fonction qui empile une constante de la classe Pile.
  * \param noeud Constante à empiler.
  */
void Pile::empiler(Constante * noeud)
{
    if (!pilePleine())
    {
        tab[n] = noeud;
        n++;
    }
}

/*!
  * \brief Fonction qui dépile un élément de la pile.
  * Fonction de dépilement d'un élément de la classe Pile.
  * \return Constante dépilée.
  */
Constante * Pile::depiler()
{
    Constante * result;
    if (!pileVide())
    {
        result = tab[n-1];
        n--;
    }
    return result;
}

/*!
  * \brief Fonction de notification d'un changement dans la pile du Design Pattern Observer.
  * Fonction qui envoie une notification aux objets en attente.
  */
void Pile::notifier()
{
    std::set<ObservateurMW *>::iterator it;
    for (it = obs.begin(); it != obs.end(); ++it)
        (* it)->miseAJour();
}

/*!
*  \brief Fonction permettant d'avoir une chaine de caratère décrivant la pile
*  \return Une chaine de caratère décrivant la pile
*/
std::string toString()
{
/*    QString s = "", res = "";
    if (!pileVide())
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (tab[j]->getType() == "entier")
                res = QString::number(tab[j]->getEntier(), 10);

            if (tab[j]->getType() == "rationnel")
                res = QString::number(tab[j]->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getDenominateur(), 10);

            if (tab[j]->getType() == "reel")
                res = QString::number(tab[j]->getReel(), 'g', 10);

            if (tab[j]->getType() == "complexe")
            {
                //afficher partie reel
                if (tab[j]->getPartieReelle()->getType() == "entier")
                    res = QString::number(tab[j]->getPartieReelle()->getEntier(), 10) + "$";

                if (tab[j]->getPartieReelle()->getType() == "reel")
                    res = QString::number(tab[j]->getPartieReelle()->getReel(), 'g', 10) + "$";

                if (tab[j]->getPartieReelle()->getType() == "rationnel")
                    res = QString::number(tab[j]->getPartieReelle()->getNumerateur(), 10) + "/" + QString::number(this.getTab(j)->getPartieReelle()->getDenominateur(), 10) + "$";

                //afficher partie virtuel
                if (tab[j]->getPartieImaginaire()->getType() == "entier")
                    res = QString::number(tab[j]->getPartieImaginaire()->getEntier(), 10);

                if (tab[j]->getPartieImaginaire()->getType() == "reel")
                    res = QString::number(tab[j]->getPartieImaginaire()->getReel(), 'g', 10);

                if (tab[j]->getPartieImaginaire()->getType() == "rationnel")
                    res = QString::number(tab[j]->getPartieImaginaire()->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getPartieImaginaire()->getDenominateur(), 10);
            }
            s += res;
            s += " ";
        }
    }
*/}



