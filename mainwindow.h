/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: mainwindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "operateur.h"
#include "pile.h"
#include "expression.h"
#include "observateurMW.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Operateur, public ObservateurMW
{
    Q_OBJECT
    
private:
    QString type; // Radian ou degrès, initialisé à radian.
    QString mode; // Entier ou rationnel ou réel, initialisé à entier.
    int com; // Utilisation des complexes ou non, initialisé à 0 pour les non-complexes.
    Expression expPile; // Sauvegarde de l'expression.
    int test; // marque si c'est une expression et si c'est deja évalué, initialisé a 0.
    QString memoire;    // Pour la fonction rétablir.

    static MainWindow * instanceUnique;
    Ui::MainWindow *ui;
    Pile * pile;

    // Constructeurs et Destructeurs.
    MainWindow();
    MainWindow(const MainWindow &);
    explicit MainWindow(QWidget * parent = 0);
    virtual ~MainWindow();
    void operator=(const MainWindow &);

public:
    // Singleton.
    static MainWindow & donneInstance();
    static void libereInstance();

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
    void pointPressed();    // .
    void plusPressed();     // +
    void dimPressed();      // -
    void multPressed();     // *
    void divPressed();      // /
    void spacePressed();    // SPACE
    void about();           // Information sur ce projet.
    void entrerPressed();   // =
    void dollarPressed();   // $
    void ExpressionPressed();
    void retablirPressed(); // Rétablir
    void annulerPressed();  // Annuler
    void clearPressed();
    void factPressed();     // !
    void sinPressed();      // sin
    void cosPressed();      // cos
    void tanPressed();      // tan
    void sinhPressed();     // sinh
    void coshPressed();     // cosh
    void tanhPressed();     // tanh
    void logPressed();      // log
    void lnPressed();       // ln
    void swapPressed();     // SWAP num x et num y dans la pile.
    void sumPressed();      // Somme des x premiers éléments de la pile.
    void meanPressed();     // Moyenne des x premiers éléments de la pile.
    void dupPressed();      // Duplique le premier élément de la pile.
    void dropPressed();     // Supprime le premier élément de la pile.
    void radSelected();     // Basculer en radian.
    void degSelected();     // Basculer en degrès.
    void evalPressed();     // Évaluation d'une expression.

};

#endif // MAINWINDOW_H
