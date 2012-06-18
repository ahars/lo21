/*!
  * \file mainwindow.h
  * \brief Fichier header de la classe MainWindow.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: mainwindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>

#include "operateur.h"
#include "pile.h"
#include "expression.h"
#include "observateurMW.h"
#include "logSystem.h"

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
  * \brief Classe permettant de créer une calculatrice.
  * La classe MainWindow permet de créer l'interface graphique de la calculatrice et d'effectuer les opérations sur les constantes de la pile.
  */
class MainWindow : public QMainWindow, public Operateur, public ObservateurMW
{
    Q_OBJECT
    
private:
    QString type; // Radian ou degrès, initialisé à radian.
    QString mode; // Entier ou rationnel ou réel, initialisé à entier.
    bool com; // Utilisation des complexes ou non, initialisé à false pour les non-complexes.
    Expression expPile; // Sauvegarde de l'expression.
    int test; // marque si c'est une expression et si c'est deja évalué, initialisé a 0.
    QString memoire;    // Pour la fonction rétablir.

    static MainWindow * instanceUnique;
    Ui::MainWindow * ui;

    // Constructeurs et Destructeurs.
    /*!
      * \brief Constructeur par défaut de MainWindow.
      * Constructeur par défaut de la class MainWindow.
      */
    MainWindow();

    /*!
      * \brief Constructeur par recopie de MainWindow.
      * Constructeur par recopie de la classe MainWindow.
      * \param Objet de la classe MainWindow.
      */
    MainWindow(const MainWindow &);

    /*!
      * \brief Constructeur  de MainWindow à partir d'un QWidget
      * Constructeur à partir d'un QWidget.
      * \param parent correspondant à l'adresse de l'objet parent.
      */
    explicit MainWindow(QWidget * parent = 0);

    /*!
      * \brief Destructeur de MainWindow.
      * Destructeur de la classe MainWindow.
      */
    virtual ~MainWindow();

    /*!
      * \brief Méthode de MainWindow pour l'opérateur = entre deux objets MainWindow.
      * Méthode de la classe MainWindow pour la copie avec l'opérateur = entre deux objets MainWindow.
      */
    void operator=(const MainWindow &);

public:
    /*!
      * \brief Méthode de MainWindow du Design Pattern Singleton pour créer un objet MainWindow.
      * Méthode de la classe MainWindow pour limiter le nombre d'instanciations de l'interface graphique.
      * \return Objet de la classe MainWindow.
      */
    // Singleton.
    static MainWindow & donneInstance();

    /*!
      * \brief Méthode de MainWindow du Design Pattern Singleton pour détruire un objet MainWindow.
      * Méthode de la classe MainWindow pour détruire une instanciation de l'interface graphique.
      */
    static void libereInstance();

    /*!
      * \brief Méthode de MainWindow du Design Pattern Observer entre Pile et MainWindow.
      * Méthode de la classe MainWindow pour afficher tous les changements de la Pile.
      */
    // Observer.
    void miseAJour();

private slots:
    void num0Pressed();
    void num1Pressed();
    void num2Pressed();
    void num3Pressed();
    void num4Pressed();
    void num5Pressed();
    void num6Pressed();
    void num7Pressed();
    void num8Pressed();
    void num9Pressed();
    void pointPressed();        // .
    void plusPressed();         // +
    void dimPressed();          // -
    void multPressed();         // *
    void divPressed();          // /
    void dollarPressed();       // $
    void spacePressed();        // SPACE
    void about();               // Information sur ce projet.
    void entrerPressed();       // =
    void clearPressed();        // Clear.
    void annulerPressed();      // Annuler
    void retablirPressed();     // Rétablir
    void factPressed();         // !
    void sinPressed();          // sin
    void cosPressed();          // cos
    void tanPressed();          // tan
    void sinhPressed();         // sinh
    void coshPressed();         // cosh
    void tanhPressed();         // tanh
    void logPressed();          // log
    void lnPressed();           // ln
    void swapPressed();         // SWAP num x et num y dans la pile.
    void sumPressed();          // Somme des x premiers éléments de la pile.
    void meanPressed();         // Moyenne des x premiers éléments de la pile.
    void dupPressed();          // Duplique le premier élément de la pile.
    void dropPressed();         // Supprime le premier élément de la pile.
    void radSelected();         // Basculer en radian.
    void degSelected();         // Basculer en degrès.
    void entierPressed();       // Changer le type en entier.
    void rationnelPressed();    // Changer le type en rationnel.
    void reelPressed();         // Changer le type en réel.
    void complexePressed();     // Changer le type en non complexe.
    void nonComplexePressed();  // Changer le type en non complexe.
    void expressionPressed();   // '
    void evalPressed();         // Évaluation d'une expression.
    void powPressed();          // POW
    void modPressed();          // %
    void signPressed();         // SIGN
    void invPressed();          // INV
    void sqrtPressed();         // SQRT
    void sqrPressed();          // SQR
    void cubePressed();         // CUBE

};

#endif // MAINWINDOW_H
