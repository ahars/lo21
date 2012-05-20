/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Jiahan & Antoine Hars
 * File: mainwindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    static MainWindow * instanceUnique;
    Ui::MainWindow *ui;
    QString memoire;

    MainWindow();
    MainWindow(const MainWindow &);
    explicit MainWindow(QWidget * parent = 0);
    virtual ~MainWindow();
    void operator=(const MainWindow &);

public:
    static MainWindow & donneInstance();
    static void libereInstance();

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
    void pointPressed();   // .
    void plusPressed();    // +
    void dimPressed();     // -
    void multPressed();    // *
    void divPressed();     // /
    void spacePressed();   // SPACE
    void about();          // information sur ce projet
    void entrerPressed();  // =
    void DollarPressed();  // $
    void retablirPressed();// retablir
    void annulerPressed(); // annuler
    void factPressed();    // !
    void sinPressed();     // sin
    void cosPressed();     // cos
    void tanPressed();     // tan
    void sinhPressed();    // sinh
    void coshPressed();    // cosh
    void tanhPressed();    // tanh
    void logPressed();     // log
    void lnPressed();      // ln
    void swapPressed();    // SWAP num x et num y dans la pile.
    void sumPressed();     // somme des x premiers éléments de la pile.
    void meanPressed();    // moyenne des x premiers éléments de la pile.
    void dupPressed();     // duplique le premier élément de la pile.
    void dropPressed();    // supprime le premier élément de la pile.

};

#endif // MAINWINDOW_H
