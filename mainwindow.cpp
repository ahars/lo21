/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: mainwindow.cpp
 */

//    ui->listWidget->addItem("7");

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow * MainWindow::instanceUnique = 0;
Pile & pile = Pile::donneInstance();
FactoryConstante fac;

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
    {
        pile.libereInstance();
        delete instanceUnique;
    }
    instanceUnique = 0;
}

// Destructeur.
MainWindow::~MainWindow()
{
    pile.supprimerObservateurMW(this);
    if (instanceUnique != 0)
    {
        delete instanceUnique->ui;
        delete instanceUnique;
    }
}

// Constructeur.
MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    test(0),
    com(0),
    type("radian"),
    mode("entier")
{
    ui->setupUi(this);

    pile.ajouterObservateurMW(this);

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
    ui->buttonCLEAR->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));


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
    QObject::connect(ui->buttonPOW, SIGNAL(clicked()), this, SLOT(powPressed()));
    QObject::connect(ui->buttonMOD, SIGNAL(clicked()), this, SLOT(modPressed()));
    QObject::connect(ui->buttonSIGN, SIGNAL(clicked()), this, SLOT(signPressed()));
    QObject::connect(ui->buttonINV, SIGNAL(clicked()), this, SLOT(invPressed()));
    QObject::connect(ui->buttonSQRT, SIGNAL(clicked()), this, SLOT(sqrtPressed()));
    QObject::connect(ui->buttonSQR, SIGNAL(clicked()), this, SLOT(sqrPressed()));
    QObject::connect(ui->buttonCUBE, SIGNAL(clicked()), this, SLOT(cubePressed()));

    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    QObject::connect(ui->actionRad, SIGNAL(triggered()), this, SLOT(radSelected()));
    QObject::connect(ui->actionDeg, SIGNAL(triggered()), this, SLOT(degSelected()));
    QObject::connect(ui->actionEnt, SIGNAL(triggered()), this, SLOT(entierPressed()));
    QObject::connect(ui->actionRationnel, SIGNAL(triggered()), this, SLOT(rationnelPressed()));
    QObject::connect(ui->actionRe, SIGNAL(triggered()), this, SLOT(reelPressed()));
    QObject::connect(ui->actionOui, SIGNAL(triggered()), this, SLOT(complexePressed()));
    QObject::connect(ui->actionNon, SIGNAL(triggered()), this, SLOT(nonComplexePressed()));

}

void MainWindow::miseAJour()
{
    //ui->listWidget->clear();
/*    int i = 999;
    ui->listWidget->addItem("1 " + QString::number(i));
    ui->listWidget->addItem("2 " + QString::number(i));
    QString str;
    str.number(pile.getTab(0)->getEntier());
    ui->listWidget->addItem("3 ");

*/
/*    QMessageBox str;
    str.setText(QString::number(pile.getN()));
    str.exec();
    for (int j = 0; j < pile.getN(); j++)
    {
        if (pile.getTab(j)->getType() == "entier")
        {
            str.setText("plop");
            str.exec();
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getEntier(),10));
        }
        if (pile.getTab(j)->getType() == "rationnel")
        {
            QString res = QString::number(pile.getTab(j)->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getDenominateur(), 10);
            ui->listWidget->addItem(res);
        }
        if (pile.getTab(j)->getType() == "reel")
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getReel(), 'g', 10));

        if (pile.getTab(j)->getType() == "complexe")
        {
            QString res;

            //afficher partie reelle
            if (pile.getTab(j)->getPartieReelle()->getType() == "entier")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getEntier(), 10) + "$";

            if (pile.getTab(j)->getPartieReelle()->getType() == "reel")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getReel(), 'g', 10) + "$";

            if (pile.getTab(j)->getPartieReelle()->getType() == "rationnel")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getPartieReelle()->getDenominateur(), 10) + "$";

            //afficher partie virtuel
            if (pile.getTab(j)->getPartieImaginaire()->getType() == "entier")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getEntier(), 10);

            if (pile.getTab(j)->getPartieImaginaire()->getType() == "reel")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getReel(), 'g', 10);

            if (pile.getTab(j)->getPartieImaginaire()->getType() == "rationnel")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getPartieImaginaire()->getDenominateur(), 10);
        }
    }

*/
/*
    QMessageBox m;
//    m.setText(pile.toString(pile.getTab(1)));

    for (unsigned int i = pile.getN(); i > -1; i--)
    {
        m.setText("plop");
        m.exec();
    }

    for (unsigned int i = 0; i < pile.getN(); i++)
        ui->listWidget->addItem(pile.toString(pile.getTab(i)));
*/
}

// Appui sur le bouton ENTRER.
void MainWindow::entrerPressed()
{
    QString value = ui->inputLine->text();
    QRegExp re("[ ]+");
    QStringList list = value.split(re);

    int i = 0;

    while (i < list.count())
    {
        QRegExp ex("[']+"); //detecter s'il y a expression
        QStringList expression = list[i].split(ex);

        if (expression.count() > 1 && expression[0] == "")
        {
            //debut d'expression
             list[i] = expression[1];
             test = 1;   //debut d'expression
        }

        //fin d'expression
        if (expression.count() > 1 && expression[1] == "")
             list[i]=expression[0];

        if (test == 1)
             expPile.insert(list[i]);

        if (test == 0 && list[i] != "SWAP" && list[i] != "SUM" && list[i] != "MEAN" && list[i] != "DUP" &&
                list[i] != "DROP" && list[i] != "+" && list[i] != "-" && list[i] != "*" &&
                list[i] != "/" && list[i] != "!" && list[i] != "sin" && list[i] != "cos" &&
                list[i] != "tan" && list[i] != "sinh" && list[i] != "cosh" && list[i] != "tanh" &&
                list[i] != "log" && list[i] != "ln" && list[i] != "INV" && list[i] != "SQRT" &&
                list[i] != "SQR" && list[i] != "CUBE" && list[i] != "POW" && list[i] != "MOD" &&
                list[i] != "SIGN")
        {
            // saisir reel,rationnel,complexe ou entier
            QRegExp ra("[/]+");
            QStringList rationnelle = list[i].split(ra);
            QRegExp ree("[.]+");
            QStringList reel = list[i].split(ree);
            QRegExp co("[$]+");
            QStringList comp = list[i].split(co);

            // determiner s'il est complexe d'abord
            if (comp.count() > 1)
            {
                if (com == 0)
                {
                    // expression l'erreur
                    QMessageBox message;
                    message.setText("Vous avez saisi un complexe, erreur!");
                    message.exec();
                }
                else
                {
                    // saisir un complexe, comp[0] est reel, comp[1] est virtuel
                    QStringList rationReel = comp[0].split(ra);// rationReel[0] / rationReel[1]
                    QStringList rationVir = comp[1].split(ra); // rationVir[0] / rationVir[1]

                    QStringList reelReel = comp[0].split(ree); // reelReel[0].reelReel[1]
                    QStringList reelVir = comp[1].split(ree);  // reelVir[0].reelVir[1]

                    Constante* comReel,* comVirtuel;

                    // complexe:pour le partie reel
                    if (rationReel.count() > 1)
                    {
                        // saisir un rationnel
                        int num = rationReel[0].toInt(); // numerateur
                        int den = rationReel[1].toInt(); // denominateur

                        // simplifier
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }
                        // empiler
                        comReel = fac.creeConstante("rationnel", num, den);
                    }
                    else
                        if (reelReel.count() > 1)
                            comReel = fac.creeConstante("reel", 0, 0, comp[0].toFloat()); // saisir un reel
                        else
                        {
                                // saisir un entier
                                Constante * entier=fac.creeConstante("entier", comp[0].toInt());
                                comReel = entier;
                        }


                    // complexe:pour le partie virtuel
                    if (rationVir.count() > 1)
                    {
                        // saisir un rationnel
                        int num = rationVir[0].toInt(); //numerateur
                        int den = rationVir[1].toInt(); //denominateur

                        // simplifier
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }
                        // empiler
                        comVirtuel = fac.creeConstante("rationnel", num, den);
                    }
                    else
                        if (reelVir.count() > 1)
                            comVirtuel = fac.creeConstante("reel", 0, 0, comp[1].toFloat()); // saisir un reel
                        else
                        {
                            // saisir un entier
                            Constante * entier = fac.creeConstante("entier", comp[1].toInt());
                            comVirtuel = entier;
                        }

                    Constante * complexe = fac.creeConstante("complexe", 0, 0, 0, comReel, comVirtuel);
                    pile.empiler(complexe);
                }
            }
            // saisir n'est pas complexe
            else
            {
                if (rationnelle.count() > 1)
                {
                    if (mode != "ration")
                    {
                        // expression l'erreur
                        QMessageBox message;
                        message.setText("Vous avez saisi un rationnel, erreur!");
                        message.exec();
                    }
                    else
                    {
                        // saisir un rationnel
                        int num = rationnelle[0].toInt(); // numerateur
                        int den = rationnelle[1].toInt(); // denominateur

                        // simplifier
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }
                        // empiler
                        Constante * ration = fac.creeConstante("rationnel", num, den);
                        pile.empiler(ration);
                    }
                }
                else
                    if (reel.count() > 1)
                    {
                        if (mode != "reel")
                        {
                            // expression l'erreur
                            QMessageBox message;
                            message.setText("Vous avez saisi un reelle, erreur!");
                            message.exec();
                        }
                        else
                        {
                            // saisir un reel
                            Constante * reelle = fac.creeConstante("reel", 0, 0, list[i].toFloat());
                            pile.empiler(reelle);
                        }
                    }
                    else
                    {
                        if (mode != "entier")
                        {
                            // expression l'erreur
                            QMessageBox message;
                            message.setText("Vous avez saisi un entier, erreur!");
                            message.exec();
                        }
                        else
                        {
                            // saisir un entier
                            Constante * entier = fac.creeConstante("entier", list[i].toInt());
                            pile.empiler(entier);
                        }
                    }
            }
        }
        if (test == 0) // quand test==0, il n'y a pas d'expression constante
        {
            if (list[i] == "SWAP")
            {
                // pour l'expression
                int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                QString exp = "SWAP d'elements num " + QString::number(val1, 10) + " et num " + QString::number(val2, 10) + " est:";
                ui->Express->setText(exp);

                // appeler la fonction
                this->opSWAP(pile);
            }

            if (list[i] == "SUM")
            {
                // pour l'expression
                int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                QString exp = "Sum de premiers " + QString::number(val1, 10) + " elements est:";
                ui->Express->setText(exp);

                // appeler la fonction
                this->opSUM(pile, mode,com);
            }

            if (list[i] == "MEAN")
            {
                // pour l'expression
                int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                QString exp = "MEAN de premiers " + QString::number(val1, 10) + " elements est:";
                ui->Express->setText(exp);

                // appeler la fonction
                this->opMEAN(pile, mode, com);
            }

            if (list[i] == "DUP")
            {
                // appeler la fonction
                this->opDUP(pile);
                // pour l'expression
                ui->Express->setText("DUP");
            }

            if (list[i] == "DROP")
            {
                // appeler la fonction
                this->opDROP(pile);
                // pour l'expression
                ui->Express->setText("DROP");
            }

            if (list[i] == "+")
            {
                // pour l'expression
                QString exp;

                // val2
                if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                     exp = QString::number(val2, 10) + "+";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                     exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "+";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 2)->getReel();
                     exp = QString::number(val2, 'g', 10) + "+";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                        exp = QString::number(reel2, 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                        exp = QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                        exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "+";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "+";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "+";
                    }
                }
                //val1
                if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                     exp += QString::number(val2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                     exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 1)->getReel();
                     exp += QString::number(val2, 'g', 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                        exp += QString::number(reel2, 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                    }
                }
                ui->Express->setText(exp);
                // appeler la fonction
                this->opPlus(pile, mode, com);
            }
            if (list[i] == "-")
            {
                // pour l'expression
                QString exp;
                // val2
                if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                     exp = QString::number(val2, 10) + "-";
                }
                if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                     exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "-";
                }
                if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 2)->getReel();
                     exp = QString::number(val2, 'g', 10) + "-";
                }
                if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                        exp = QString::number(reel2, 10) + "$";
                    }
                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                        exp = QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                        exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "-";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "-";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "-";
                    }
                }

                // val1
                if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                     exp += QString::number(val2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                     exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 1)->getReel();
                     exp += QString::number(val2, 'g', 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                        exp += QString::number(reel2, 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                    }
                }
                ui->Express->setText(exp);

                // appeler la fonction
                this->opDim(pile, mode, com);
            }

            if (list[i] == "*")
            {
                // pour l'expression
                QString exp;
                // val2
                if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                     exp = QString::number(val2, 10) + "*";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                     exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "*";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 2)->getReel();
                     exp = QString::number(val2, 'g', 10) + "*";
                }

                if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                        exp = QString::number(reel2, 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                        exp = QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                        exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "*";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "*";
                    }

                    if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "*";
                    }
                }

                // val1
                if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                {
                     int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                     exp += QString::number(val2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                {
                     int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                     int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                     exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                {
                     float val2 = pile.getTab(pile.getN() - 1)->getReel();
                     exp += QString::number(val2, 'g', 10) + "=";
                }

                if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                {
                    // val2 partie reel
                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                        exp += QString::number(reel2, 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "$";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                    }

                    // val2 partie virtuel
                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                        exp += QString::number(reel2, 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                    {
                        int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                        exp += QString::number(reel2, 'g', 10) + "=";
                    }

                    if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                    {
                        int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                        int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                        exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                    }
                }
                ui->Express->setText(exp);

                // appeler la fonction
                this->opMult(pile, mode, com);
            }

        if(list[i]=="/"){
            //pour l'expression
            QString exp;
            //val2
            if(pile.getTab(pile.getN()-2)->getType()=="entier"){
                 int val2=pile.getTab(pile.getN()-2)->getEntier();
                 exp=QString::number(val2,10)+"/";
            }

            if(pile.getTab(pile.getN()-2)->getType()=="rationnel"){
                 int num2=pile.getTab(pile.getN()-2)->getNumerateur();
                 int den2=pile.getTab(pile.getN()-2)->getDenominateur();
                 exp=QString::number(num2,10)+"/"+QString::number(den2,10)+"/";
            }

            if(pile.getTab(pile.getN()-2)->getType()=="reel"){
                 float val2=pile.getTab(pile.getN()-2)->getReel();
                 exp=QString::number(val2,'g',10)+"/";
            }

            if(pile.getTab(pile.getN()-2)->getType()=="complexe"){
                //val2 partie reel
                if(pile.getTab(pile.getN()-2)->getPartieReelle()->getType()=="entier"){
                    int reel2=pile.getTab(pile.getN()-2)->getPartieReelle()->getEntier();
                    exp=QString::number(reel2,10)+"$";
                }

                if(pile.getTab(pile.getN()-2)->getPartieReelle()->getType()=="reel"){
                    int reel2=pile.getTab(pile.getN()-2)->getPartieReelle()->getReel();
                    exp=QString::number(reel2,'g',10)+"$";
                }

                if(pile.getTab(pile.getN()-2)->getPartieReelle()->getType()=="rationnel"){
                    int num2=pile.getTab(pile.getN()-2)->getPartieReelle()->getNumerateur();
                    int den2=pile.getTab(pile.getN()-2)->getPartieReelle()->getDenominateur();
                    exp=QString::number(num2,10)+"/"+QString::number(den2,10)+"$";
                }

                //val2 partie virtuel
                if(pile.getTab(pile.getN()-2)->getPartieImaginaire()->getType()=="entier"){
                    int reel2=pile.getTab(pile.getN()-2)->getPartieImaginaire()->getEntier();
                    exp+=QString::number(reel2,10)+"/";
                }

                if(pile.getTab(pile.getN()-2)->getPartieImaginaire()->getType()=="reel"){
                    int reel2=pile.getTab(pile.getN()-2)->getPartieImaginaire()->getReel();
                    exp+=QString::number(reel2,'g',10)+"/";
                }

                if(pile.getTab(pile.getN()-2)->getPartieImaginaire()->getType()=="rationnel"){
                    int num2=pile.getTab(pile.getN()-2)->getPartieImaginaire()->getNumerateur();
                    int den2=pile.getTab(pile.getN()-2)->getPartieImaginaire()->getDenominateur();
                    exp+=QString::number(num2,10)+"/"+QString::number(den2,10)+"/";
                }

            }

            //val1
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val2=pile.getTab(pile.getN()-1)->getEntier();
                 exp+=QString::number(val2,10)+"=";
            }

            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num2=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den2=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp+=QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
            }

            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val2=pile.getTab(pile.getN()-1)->getReel();
                 exp+=QString::number(val2,'g',10)+"=";
            }

            if(pile.getTab(pile.getN()-1)->getType()=="complexe"){
                //val2 partie reel
                if(pile.getTab(pile.getN()-1)->getPartieReelle()->getType()=="entier"){
                    int reel2=pile.getTab(pile.getN()-1)->getPartieReelle()->getEntier();
                    exp+=QString::number(reel2,10)+"$";
                }

                if(pile.getTab(pile.getN()-1)->getPartieReelle()->getType()=="reel"){
                    int reel2=pile.getTab(pile.getN()-1)->getPartieReelle()->getReel();
                    exp+=QString::number(reel2,'g',10)+"$";
                }

                if(pile.getTab(pile.getN()-1)->getPartieReelle()->getType()=="rationnel"){
                    int num2=pile.getTab(pile.getN()-1)->getPartieReelle()->getNumerateur();
                    int den2=pile.getTab(pile.getN()-1)->getPartieReelle()->getDenominateur();
                    exp+=QString::number(num2,10)+"/"+QString::number(den2,10)+"$";
                }

                //val2 partie virtuel
                if(pile.getTab(pile.getN()-1)->getPartieImaginaire()->getType()=="entier"){
                    int reel2=pile.getTab(pile.getN()-1)->getPartieImaginaire()->getEntier();
                    exp+=QString::number(reel2,10)+"=";
                }

                if(pile.getTab(pile.getN()-1)->getPartieImaginaire()->getType()=="reel"){
                    int reel2=pile.getTab(pile.getN()-1)->getPartieImaginaire()->getReel();
                    exp+=QString::number(reel2,'g',10)+"=";
                }

                if(pile.getTab(pile.getN()-1)->getPartieImaginaire()->getType()=="rationnel"){
                    int num2=pile.getTab(pile.getN()-1)->getPartieImaginaire()->getNumerateur();
                    int den2=pile.getTab(pile.getN()-1)->getPartieImaginaire()->getDenominateur();
                    exp+=QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
                }
            }
            ui->Express->setText(exp);

            //appeler la fonction
            this->opDiv(pile,mode,com);
        }

        if(list[i]=="!"){
            //pour l'expression
            int val1=pile.getTab(pile.getN()-1)->getEntier();
            QString exp=QString::number(val1,10)+"!=";
            ui->Express->setText(exp);

            //appeler la fonction
            this->opFact(pile);
        }

        if(list[i]=="sin"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="sin"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="sin"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="sin"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opSin(pile,type);
        }

        if(list[i]=="cos"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="cos"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="cos"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="cos"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opCos(pile,type);

        }

        if(list[i]=="tan"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="tan"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="tan"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="tan"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opTan(pile,type);
        }

        if(list[i]=="sinh"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="sinh"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="sinh"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="sinh"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opSinh(pile,type);

            }

        if(list[i]=="cosh"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="cosh"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="cosh"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="cosh"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opCosh(pile,type);

            }

        if(list[i]=="tanh"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="tanh"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="tanh"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="tanh"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opTanh(pile,type);

        }

        if(list[i]=="log"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="log"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="log"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="log"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opLog(pile);
        }

        if(list[i]=="ln"){
            //pour l'expression
            QString exp;
            if(pile.getTab(pile.getN()-1)->getType()=="entier"){
                 int val1=pile.getTab(pile.getN()-1)->getEntier();
                 exp="ln"+QString::number(val1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="rationnel"){
                 int num1=pile.getTab(pile.getN()-1)->getNumerateur();
                 int den1=pile.getTab(pile.getN()-1)->getDenominateur();
                 exp="ln"+QString::number(num1,10)+"/"+QString::number(den1,10)+"=";
            }
            if(pile.getTab(pile.getN()-1)->getType()=="reel"){
                 float val1=pile.getTab(pile.getN()-1)->getReel();
                 exp="ln"+QString::number(val1,'g',10)+"=";
            }

            ui->Express->setText(exp);

            //appeler la fonction
            this->opLn(pile);
        }

        if(list[i]=="POW"){
            //pour l'expression
            ui->Express->setText("POW");

            //appeler la fonction
            this->opPOW(pile,mode);

        }

        if(list[i]=="MOD"){
            //pour l'expression
            int val1=pile.getTab(pile.getN()-1)->getEntier();
            int val2=pile.getTab(pile.getN()-2)->getEntier();
            QString exp=QString::number(val2,10)+"%"+QString::number(val1,10)+"=";
            ui->Express->setText(exp);

            //appeler la fonction
            this->opMOD(pile);
        }

        if(list[i]=="SIGN"){
            //pour l'expression
            ui->Express->setText("SIGN");

            //appeler la fonction
            this->opSIGN(pile);
        }

        if(list[i]=="INV"){
            //pour l'expression
            ui->Express->setText("INV");

            //appeler la fonction
            this->opINV(pile);
        }

        if(list[i]=="SQRT"){
            //pour l'expression
            ui->Express->setText("SQRT");

            //appeler la fonction
            this->opSQRT(pile);
        }

        if(list[i]=="SQR"){
            //pour l'expression
            ui->Express->setText("SQR");

            //appeler la fonction
            this->opSQR(pile);
        }

        if(list[i]=="CUBE"){
            //pour l'expression
            ui->Express->setText("CUBE");

            //appeler la fonction
            this->opCUBE(pile);
        }

    }

    i++;

    }

    //afficher dans listWidget
    ui->listWidget->clear();

    for(int j=0;j<pile.getN();j++){
        if(pile.getTab(j)->getType()=="entier"){
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getEntier(),10));
        }
        if(pile.getTab(j)->getType()=="rationnel"){
            QString res=QString::number(pile.getTab(j)->getNumerateur(),10)+"/"+QString::number(pile.getTab(j)->getDenominateur(),10);
            ui->listWidget->addItem(res);
        }
        if(pile.getTab(j)->getType()=="reel"){
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getReel(),'g',10));
        }
        if(pile.getTab(j)->getType()=="complexe"){
            QString res;
            //afficher partie reel
            if(pile.getTab(j)->getPartieReelle()->getType()=="entier"){
                res=QString::number(pile.getTab(j)->getPartieReelle()->getEntier(),10)+"$";
            }
            if(pile.getTab(j)->getPartieReelle()->getType()=="reel"){
                res=QString::number(pile.getTab(j)->getPartieReelle()->getReel(),'g',10)+"$";
            }
            if(pile.getTab(j)->getPartieReelle()->getType()=="rationnel"){
                res=QString::number(pile.getTab(j)->getPartieReelle()->getNumerateur(),10)+"/"+QString::number(pile.getTab(j)->getPartieReelle()->getDenominateur(),10)+"$";
            }

            //afficher partie virtuel
            if(pile.getTab(j)->getPartieImaginaire()->getType()=="entier"){
                res+=QString::number(pile.getTab(j)->getPartieImaginaire()->getEntier(),10);
            }
            if(pile.getTab(j)->getPartieImaginaire()->getType()=="reel"){
                res+=QString::number(pile.getTab(j)->getPartieImaginaire()->getReel(),'g',10);
            }
            if(pile.getTab(j)->getPartieImaginaire()->getType()=="rationnel"){
                res+=QString::number(pile.getTab(j)->getPartieImaginaire()->getNumerateur(),10)+"/"+QString::number(pile.getTab(j)->getPartieImaginaire()->getDenominateur(),10);
            }

            ui->listWidget->addItem(res);
        }
    }

    ui->inputLine->setText("");
}

// Évaluer une expression.
void MainWindow::evalPressed()
{
    test = 0;   // fin d'expression

    QString exp;
    // pour afficher l'expression
    for (int i = 0; i < expPile.getNombre(); i++)
        exp += expPile.getExpression(i) + " ";
    ui->Express->setText(exp);

    // pour calcule expression
    for (int i = 0; i < expPile.getNombre(); i++)
    {
        QString value = expPile.getExpression(i);
        if (value != "SWAP" && value != "SUM" && value != "MEAN" && value != "DUP" &&
                value != "DROP" && value != "+" && value != "-" && value != "*" &&
                value != "/" && value != "!" && value != "sin" && value != "cos" &&
                value != "tan" && value != "sinh" && value != "cosh" && value != "tanh" &&
                value != "log" && value != "ln" && value != "INV" && value != "SQRT" &&
                value != "SQR" && value != "CUBE" && value != "POW" && value != "MOD" &&
                value != "SIGN")
        {

            //saisir reel,rationnelle,complexe ou entier
            QRegExp ra("[/]+");
            QStringList rationnelle = value.split(ra);
            QRegExp ree("[.]+");
            QStringList reel = value.split(ree);
            QRegExp co("[$]+");
            QStringList comp = value.split(co);


            //determiner s'il est complexe d'abord
            if (comp.count() > 1)
            {
                //saisir un complexe, comp[0]est reel, comp[1] est virtuel

                QStringList rationReel = comp[0].split(ra);//rationReel[0]/rationReel[1]
                QStringList rationVir = comp[1].split(ra); //rationVir[0]/rationVir[1]

                QStringList reelReel = comp[0].split(ree); //reelReel[0].reelReel[1]
                QStringList reelVir = comp[1].split(ree);  //reelVir[0].reelVir[1]

                Constante* comReel,* comVirtuel;

                //complexe:pour le partie reel
                if (rationReel.count() > 1)
                {
                    //saisir un rationnelle
                    int num = rationReel[0].toInt();//numerateur
                    int den = rationReel[1].toInt();//denominateur

                    //simplifier
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    //empiler
                    comReel = fac.creeConstante("rationnel", num, den);

                }
                else
                {
                    if (reelReel.count() > 1)
                    {
                        //saisir un reel
                        comReel = fac.creeConstante("reel", 0, 0, comp[0].toFloat());

                    }
                    else
                    {
                        //saisir un entier
                        Constante * entier = fac.creeConstante("entier", comp[0].toInt());
                        comReel = entier;
                    }
                }

                //complexe:pour le partie virtuel
                if (rationVir.count() > 1)
                {
                    //saisir un rationnelle
                    int num = rationVir[0].toInt();//numerateur
                    int den = rationVir[1].toInt();//denominateur

                    //simplifier
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    //empiler
                    comVirtuel = fac.creeConstante("rationnel", num, den);

                }
                else
                {
                    if (reelVir.count() > 1)
                    {
                        //saisir un reel
                        comVirtuel = fac.creeConstante("reel", 0, 0, comp[1].toFloat());

                    }
                    else
                    {
                        //saisir un entier
                        Constante * entier = fac.creeConstante("entier", comp[1].toInt());
                        comVirtuel = entier;
                    }
                }
                Constante * complexe = fac.creeConstante("complexe", 0, 0, 0, comReel, comVirtuel);
                pile.empiler(complexe);

            }//saisir n'est pas complexe
            else
            {
                if (rationnelle.count() > 1)
                {
                    //saisir un rationnelle
                    int num = rationnelle[0].toInt();//numerateur
                    int den = rationnelle[1].toInt();//denominateur

                    //simplifier
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    //empiler
                    Constante * ration = fac.creeConstante("rationnel", num, den);
                    pile.empiler(ration);

                }
                else
                {
                    if (reel.count() > 1)
                    {
                        //saisir un reel
                        Constante * reelle = fac.creeConstante("reel", 0, 0, value.toFloat());
                        pile.empiler(reelle);
                    }
                    else
                    {
                        //saisir un entier
                        Constante * entier = fac.creeConstante("entier", value.toInt());
                        pile.empiler(entier);
                    }
                }
            }
        }
        else
        {
            if (value == "SWAP") this->opSWAP(pile);
            if (value == "SUM")  this->opSUM(pile, mode, com);
            if (value == "MEAN") this->opMEAN(pile, mode, com);
            if (value == "DUP")  this->opDUP(pile);
            if (value == "DROP") this->opDROP(pile);
            if (value == "+")    this->opPlus(pile, mode, com);
            if (value == "-")    this->opDim(pile, mode, com);
            if (value == "*")    this->opMult(pile, mode, com);
            if (value == "/")    this->opDiv(pile, mode, com);
            if (value == "!")    this->opFact(pile);
            if (value == "sin")  this->opSin(pile, type);
            if (value == "cos")  this->opCos(pile, type);
            if (value == "tan")  this->opTan(pile, type);
            if (value == "sinh") this->opSinh(pile, type);
            if (value == "cosh") this->opCosh(pile, type);
            if (value == "tanh") this->opTanh(pile, type);
            if (value == "log")  this->opLog(pile);
            if (value == "ln")   this->opLn(pile);
            if (value == "INV")  this->opINV(pile);
            if (value == "SQRT") this->opSQRT(pile);
            if (value == "SQR")  this->opSQR(pile);
            if (value == "CUBE") this->opCUBE(pile);
            if (value == "POW")  this->opPOW(pile, mode);
            if (value == "MOD")  this->opMOD(pile);
            if (value == "SIGN") this->opSIGN(pile);
        }
    }

    //afficher dans listWidget
    ui->listWidget->clear();

    for (int j = 0; j < pile.getN(); j++)
    {
        if (pile.getTab(j)->getType() == "entier")
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getEntier(), 10));

        if (pile.getTab(j)->getType() == "rationnel")
        {
            QString res = QString::number(pile.getTab(j)->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getDenominateur(), 10);
            ui->listWidget->addItem(res);
        }
        if (pile.getTab(j)->getType() == "reel")
            ui->listWidget->addItem(QString::number(pile.getTab(j)->getReel(), 'g', 10));

        if (pile.getTab(j)->getType() == "complexe")
        {
            QString res;
            //afficher partie reel
            if (pile.getTab(j)->getPartieReelle()->getType() == "entier")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getEntier(), 10) + "$";

            if (pile.getTab(j)->getPartieReelle()->getType() == "reel")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getReel(), 'g', 10) + "$";

            if (pile.getTab(j)->getPartieReelle()->getType() == "rationnel")
                res = QString::number(pile.getTab(j)->getPartieReelle()->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getPartieReelle()->getDenominateur(), 10) + "$";

            //afficher partie virtuel
            if (pile.getTab(j)->getPartieImaginaire()->getType() == "entier")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getEntier(), 10);

            if (pile.getTab(j)->getPartieImaginaire()->getType() == "reel")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getReel(), 'g', 10);

            if (pile.getTab(j)->getPartieImaginaire()->getType() == "rationnel")
                res += QString::number(pile.getTab(j)->getPartieImaginaire()->getNumerateur(), 10) + "/" + QString::number(pile.getTab(j)->getPartieImaginaire()->getDenominateur(), 10);


            ui->listWidget->addItem(res);
        }
    }
}

// Appui sur le bouton retablir.
void MainWindow::retablirPressed()
{
    ui->inputLine->setText(memoire);
}

// Appui sur le bouton annuler.
void MainWindow::annulerPressed()
{
    memoire=ui->inputLine->text();
    ui->inputLine->setText("");
}

// Appui sur le bouton Clear.
void MainWindow::clearPressed()
{
    ui->inputLine->setText("");

    for (int i = 0; i < pile.getN(); i++)
        pile.depiler();  //vider la pile
}

// Appui sur le bouton SWAP.
void MainWindow::swapPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SWAP");
}

// Appui sur le bouton SUM.
void MainWindow::sumPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SUM");
}

// Appui sur le bouton MEAN.
void MainWindow::meanPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "MEAN");
}

// Appui sur le bouton DUP.
void MainWindow::dupPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "DUP");
}

// Appui sur le bouton DROP.
void MainWindow::dropPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "DROP");
}

// Appui sur le bouton SPACE.
void MainWindow::spacePressed()
{
     ui->inputLine->setText(ui->inputLine->text() + " ");
}

// Appui sur le bouton $.
void MainWindow::dollarPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "$");
}

// Appui sur le bouton +.
void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "+");
}

// Appui sur le bouton -.
void MainWindow::dimPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "-");
}

// Appui sur le bouton *.
void MainWindow::multPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "*");
}

// Appui sur le bouton /.
void MainWindow::divPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "/");
}

// Appui sur le bouton '.
void MainWindow::expressionPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "'");
}

// Appui sur le bouton 0.
void MainWindow::num0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "0");
}

// Appui sur le bouton 1.
void MainWindow::num1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "1");
}

// Appui sur le bouton 2.
void MainWindow::num2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "2");
}

// Appui sur le bouton 3.
void MainWindow::num3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "3");
}

// Appui sur le bouton 4.
void MainWindow::num4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "4");
}

// Appui sur le bouton 5.
void MainWindow::num5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "5");
}

// Appui sur le bouton 6.
void MainWindow::num6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "6");
}

// Appui sur le bouton 7.
void MainWindow::num7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "7");
}

// Appui sur le bouton 8.
void MainWindow::num8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "8");
}

// Appui sur le bouton 9.
void MainWindow::num9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "9");
}

// Appui sur le bouton .
void MainWindow::pointPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + ".");
}

// Appui sur le bouton !.
void MainWindow::factPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "!");
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
    ui->inputLine->setText(ui->inputLine->text() + "sin");
}

// Appui sur le bouton COS.
void MainWindow::cosPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "cos");
}

// Appui sur le bouton TAN.
void MainWindow::tanPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "tan");
}

// Appui sur le bouton SINH.
void MainWindow::sinhPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "sinh");
}

// Appui sur le bouton COSH.
void MainWindow::coshPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "cosh");
}

// Appui sur le bouton TANH.
void MainWindow::tanhPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "tanh");
}

// Appui sur le bouton LOG.
void MainWindow::logPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "log");
}

// Appui sur le bouton LN.
void MainWindow::lnPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "ln");
}

// basculer en radian.
void MainWindow::radSelected()
{
    ui->RadouDeg->setText("radian");
    type = "radian";
}

// basculer en degrès.
void MainWindow::degSelected()
{
    ui->RadouDeg->setText("degres");
    type = "degres";
}

void MainWindow::cubePressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "CUBE");
}

void MainWindow::sqrPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SQR");
}

void MainWindow::sqrtPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SQRT");
}

void MainWindow::invPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "INV");
}

void MainWindow::signPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SIGN");
}

void MainWindow::modPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "%");
}

void MainWindow::powPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "POW");
}

void MainWindow::nonComplexePressed()
{
    ui->comOuiNon->setText("non");
}

void MainWindow::complexePressed()
{
    ui->comOuiNon->setText("oui");
}

void MainWindow::reelPressed()
{
    ui->mode->setText("reel");
    mode = "reel";
}

void MainWindow::rationnelPressed()
{
    ui->mode->setText("rationnel");
    mode = "rationnel";
}

void MainWindow::entierPressed()
{
    ui->mode->setText("entier");
    mode = "entier";
}
