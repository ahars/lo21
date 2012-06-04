/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: mainwindow.cpp
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow * MainWindow::instanceUnique = 0;

Pile * pile;

// Donne instance du Singleton.
MainWindow & MainWindow::donneInstance()
{
    if (instanceUnique == 0)
        instanceUnique = new MainWindow(0);
    return * instanceUnique;
}

// Libere instance du Singleton.
void MainWindow::libereInstance()
{
    if (instanceUnique != 0)
            delete instanceUnique;
    instanceUnique = 0;
}

// Destructeur.
MainWindow::~MainWindow()
{
    if (instanceUnique != 0)
    {
        delete instanceUnique->ui;
        delete instanceUnique;
    }
}

// Constructeur.
MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Création de la pile.
    pile = new Pile();

    // Raccourcis Clavier.
    ui->button0->setShortcut(QKeySequence(Qt::Key_0));
    ui->button1->setShortcut(QKeySequence(Qt::Key_1));
    ui->button2->setShortcut(QKeySequence(Qt::Key_2));
    ui->button3->setShortcut(QKeySequence(Qt::Key_3));
    ui->button4->setShortcut(QKeySequence(Qt::Key_4));
    ui->button5->setShortcut(QKeySequence(Qt::Key_5));
    ui->button6->setShortcut(QKeySequence(Qt::Key_6));
    ui->button7->setShortcut(QKeySequence(Qt::Key_7));
    ui->button8->setShortcut(QKeySequence(Qt::Key_8));
    ui->button9->setShortcut(QKeySequence(Qt::Key_9));
    ui->buttonPlus->setShortcut(QKeySequence(Qt::Key_Plus));
    ui->buttonDim->setShortcut(QKeySequence(Qt::Key_Minus));
    ui->buttonMulti->setShortcut(QKeySequence(Qt::Key_Asterisk));
    ui->buttonDiv->setShortcut(QKeySequence(Qt::Key_Slash));
    ui->buttonExpression->setShortcut(QKeySequence(Qt::Key_Apostrophe));
    ui->buttonSPACE->setShortcut(QKeySequence(Qt::Key_Space));
    ui->buttonEntrer->setShortcut(QKeySequence(Qt::Key_Return));
    ui->buttonFactoriel->setShortcut(QKeySequence(Qt::Key_Exclam));
    ui->buttonPoint->setShortcut(QKeySequence(Qt::Key_Period));
    ui->buttonDollar->setShortcut(QKeySequence(Qt::Key_Dollar));
    ui->buttonAnnuler->setShortcut(QKeySequence(Qt::Key_Delete));
    ui->actionQuit->setShortcut(QKeySequence(Qt::Key_Escape));
    ui->buttonRetablir->setShortcut(QKeySequence(Qt::Key_Backspace));
    ui->buttonAnnuler->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    ui->buttonRetablir->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    ui->buttonEVAL->setShortcut(QKeySequence(Qt::Key_Tab));


    // Connections.
    QObject::connect(ui->button0, SIGNAL(clicked()), this, SLOT(num0Pressed()));
    QObject::connect(ui->button1, SIGNAL(clicked()), this, SLOT(num1Pressed()));
    QObject::connect(ui->button2, SIGNAL(clicked()), this, SLOT(num2Pressed()));
    QObject::connect(ui->button3, SIGNAL(clicked()), this, SLOT(num3Pressed()));
    QObject::connect(ui->button4, SIGNAL(clicked()), this, SLOT(num4Pressed()));
    QObject::connect(ui->button5, SIGNAL(clicked()), this, SLOT(num5Pressed()));
    QObject::connect(ui->button6, SIGNAL(clicked()), this, SLOT(num6Pressed()));
    QObject::connect(ui->button7, SIGNAL(clicked()), this, SLOT(num7Pressed()));
    QObject::connect(ui->button8, SIGNAL(clicked()), this, SLOT(num8Pressed()));
    QObject::connect(ui->button9, SIGNAL(clicked()), this, SLOT(num9Pressed()));

    QObject::connect(ui->buttonRetablir, SIGNAL(clicked()), this, SLOT(retablirPressed()));
    QObject::connect(ui->buttonSPACE, SIGNAL(clicked()), this, SLOT(spacePressed()));
    QObject::connect(ui->buttonEntrer, SIGNAL(clicked()), this, SLOT(entrerPressed()));
    QObject::connect(ui->buttonAnnuler, SIGNAL(clicked()), this, SLOT(annulerPressed()));
    QObject::connect(ui->buttonCLEAR, SIGNAL(clicked()), this, SLOT(clearPressed()));
    QObject::connect(ui->buttonEVAL, SIGNAL(clicked()), this, SLOT(evalPressed()));

    QObject::connect(ui->buttonPoint, SIGNAL(clicked()), this, SLOT(pointPressed()));
    QObject::connect(ui->buttonExpression, SIGNAL(clicked()), this, SLOT(ExpressionPressed()));
    QObject::connect(ui->buttonDollar, SIGNAL(clicked()), this, SLOT(dollarPressed()));
    QObject::connect(ui->buttonPlus, SIGNAL(clicked()), this, SLOT(plusPressed()));
    QObject::connect(ui->buttonDim, SIGNAL(clicked()), this, SLOT(dimPressed()));
    QObject::connect(ui->buttonMulti, SIGNAL(clicked()), this, SLOT(multPressed()));
    QObject::connect(ui->buttonDiv, SIGNAL(clicked()), this, SLOT(divPressed()));
    QObject::connect(ui->buttonFactoriel, SIGNAL(clicked()), this, SLOT(factPressed()));
    QObject::connect(ui->buttonSin, SIGNAL(clicked()), this, SLOT(sinPressed()));
    QObject::connect(ui->buttonCos, SIGNAL(clicked()), this, SLOT(cosPressed()));
    QObject::connect(ui->buttonTan, SIGNAL(clicked()), this, SLOT(tanPressed()));
    QObject::connect(ui->buttonSinh, SIGNAL(clicked()), this, SLOT(sinhPressed()));
    QObject::connect(ui->buttonCosh, SIGNAL(clicked()), this, SLOT(coshPressed()));
    QObject::connect(ui->buttonTanh, SIGNAL(clicked()), this, SLOT(tanhPressed()));
    QObject::connect(ui->buttonLog, SIGNAL(clicked()), this, SLOT(logPressed()));
    QObject::connect(ui->buttonLn, SIGNAL(clicked()), this, SLOT(lnPressed()));
    QObject::connect(ui->buttonSWAP, SIGNAL(clicked()), this, SLOT(swapPressed()));
    QObject::connect(ui->buttonSUM, SIGNAL(clicked()), this, SLOT(sumPressed()));
    QObject::connect(ui->buttonMEAN, SIGNAL(clicked()), this, SLOT(meanPressed()));
    QObject::connect(ui->buttonDROP, SIGNAL(clicked()), this, SLOT(dropPressed()));
    QObject::connect(ui->buttonDUP, SIGNAL(clicked()), this, SLOT(dupPressed()));

    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    QObject::connect(ui->actionRad, SIGNAL(triggered()), this, SLOT(radSelected()));
    QObject::connect(ui->actionDeg, SIGNAL(triggered()), this, SLOT(degSelected()));
}

// Appui sur le bouton =.
void MainWindow::entrerPressed()
{

}

// Évaluer une expression.
void MainWindow::evalPressed()
{

}

// Appui sur le bouton retablir.
void MainWindow::retablirPressed()
{
    ui->inputLine->setText(memoire);
}

// Appui sur le bouton annuler.
void MainWindow::annulerPressed()
{

}

// Appui sur le bouton Clear.
void MainWindow::clearPressed()
{
    memoire = ui->inputLine->text();
    ui->inputLine->setText("");

    // Vider la pile.
    for(int i = 0; i < pile->getN(); i++)
        pile->depiler();
}

// Appui sur le bouton SWAP.
void MainWindow::swapPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"SWAP");
}

// Appui sur le bouton SUM.
void MainWindow::sumPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"SUM");
}

// Appui sur le bouton MEAN.
void MainWindow::meanPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"MEAN");
}

// Appui sur le bouton DUP.
void MainWindow::dupPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"DUP");
}

// Appui sur le bouton DROP.
void MainWindow::dropPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"DROP");
}

// Appui sur le bouton SPACE.
void MainWindow::spacePressed()
{
     ui->inputLine->setText(ui->inputLine->text()+" ");
}

// Appui sur le bouton $.
void MainWindow::dollarPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"$");
}

// Appui sur le bouton +.
void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"+");
}

// Appui sur le bouton -.
void MainWindow::dimPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"-");
}

// Appui sur le bouton *.
void MainWindow::multPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"*");
}

// Appui sur le bouton /.
void MainWindow::divPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"/");
}

// Appui sur le bouton '.
void MainWindow::ExpressionPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"'");
}

// Appui sur le bouton 0.
void MainWindow::num0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"0");
//    ui->listWidget->addItem("0");
}

// Appui sur le bouton 1.
void MainWindow::num1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"1");
//    ui->listWidget->addItem("1");
}

// Appui sur le bouton 2.
void MainWindow::num2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"2");
//    ui->listWidget->addItem("2");
}

// Appui sur le bouton 3.
void MainWindow::num3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"3");
//    ui->listWidget->addItem("3");

}

// Appui sur le bouton 4.
void MainWindow::num4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"4");
//    ui->listWidget->addItem("4");
}

// Appui sur le bouton 5.
void MainWindow::num5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"5");
//    ui->listWidget->addItem("5");
}

// Appui sur le bouton 6.
void MainWindow::num6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"6");
//    ui->listWidget->addItem("6");
}

// Appui sur le bouton 7.
void MainWindow::num7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"7");
//    ui->listWidget->addItem("7");
}

// Appui sur le bouton 8.
void MainWindow::num8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"8");
//    ui->listWidget->addItem("8");
}

// Appui sur le bouton 9.
void MainWindow::num9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"9");
//    ui->listWidget->addItem("9");
}

// Appui sur le bouton .
void MainWindow::pointPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+".");
}

// Appui sur le bouton !.
void MainWindow::factPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"!");
}

// Appui sur le bouton ABOUT du menu.
void MainWindow::about()
 {
    QMessageBox message;
    message.setText("UV: LO21\nSujet: Calculatrice en notation polonaise inversee.\nAuteurs: Han Jia & Antoine Hars.");
    message.exec();
 }

// Appui sur le bouton SIN.
void MainWindow::sinPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"sin");
}

// Appui sur le bouton COS.
void MainWindow::cosPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"cos");
}

// Appui sur le bouton TAN.
void MainWindow::tanPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"tan");
}

// Appui sur le bouton SINH.
void MainWindow::sinhPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"sinh");
}

// Appui sur le bouton COSH.
void MainWindow::coshPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"cosh");
}

// Appui sur le bouton TANH.
void MainWindow::tanhPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"tanh");
}

// Appui sur le bouton LOG.
void MainWindow::logPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"log");
}

// Appui sur le bouton LN.
void MainWindow::lnPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"ln");
}

// basculer en radian.
void MainWindow::radSelected()
{
    ui->RadouDeg->setText("rad");
    setType("rad");
}

// basculer en degrès.
void MainWindow::degSelected()
{
    ui->RadouDeg->setText("deg");
    setType("deg");
}
