/*!
 * \file mainwindow.cpp
 * \author Jia Han & Antoine Hars
 * \brief Déclaration des méthodes de la classe MainWindow.
 * Ce fichier contient la déclaration des méthodes de la classe MainWindow.
 */

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

/*!
  * \brief Méthode de MainWindow pour instancier le Design Pattern Singleton de MainWindow.
  * Méthode appelant le constructeur de la classe MainWindow.
  */
MainWindow & MainWindow::donneInstance()
{
    if (instanceUnique == 0)
        instanceUnique = new MainWindow(0);
    return * instanceUnique;
}

/*!
  * \brief Méthode de MainWindow pour détruire le Design Pattern Singleton de MainWindow.
  * Méthode appelant le destructeur de la classe MainWindow.
  */
void MainWindow::libereInstance()
{
    if (instanceUnique != 0)
    {
        pile.libereInstance();
        delete instanceUnique;
    }
    instanceUnique = 0;
}

/*!
  * \brief Destructeur de MainWindow.
  * Destructeur de la classe MainWindow.
  */
MainWindow::~MainWindow()
{
    pile.supprimerObservateurMW(this);
    if (instanceUnique != 0)
    {
        delete instanceUnique->ui;
        delete instanceUnique;
    }
}

/*!
  * \brief Constructeur de MainWindow.
  * Constructeur de la classe MainWindow.
  * \param parent correspond à l'adresse du parent.
  */
MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    test(0),
    com(false),
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

    QObject::connect(ui->buttonExpression, SIGNAL(clicked()), this, SLOT(expressionPressed()));

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

    LogSystem::add("Lancement de la calculatrice", 3);
    // Chargement du contexte de la Pile.
    //load();
}

/*!
  * \brief Méthode de MainWindow mettant à jour l'affichage de la Pile.
  * Méthode de la classe MainWindow qui affiche tous les éléments de la Pile.
  */
void MainWindow::miseAJour()
{
    //afficher dans listWidget
    ui->listWidget->clear();
    ui->listWidget->addItem("ff");
    ui->listWidget->addItem(QString::number(pile.getTab(pile.getN() - 1)->getEntier(), 10));
    for (int j = pile.getN() - 1; j >= 0; j--)
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

/*!
  * \brief Méthode de MainWindow qui effectue les calculs de la calculatrice.
  * Méthode de la classe MainWindow utilisé pour le traitement des Constantes.
  */
void MainWindow::entrerPressed()
{
    // Récupération de tous les éléments séparés par des espaces.
    QString value = ui->inputLine->text();
    QRegExp re("[ ]+");
    QStringList list = value.split(re);

    int i = 0;
    // Pour chaque élément de la liste de type QString que nous récupérons.
    while (i < list.count())
    {
        // Expression régulière pour la détection d'une expression.
        QRegExp ex("[']+");
        QStringList expression = list[i].split(ex);

        // Cas d'une expression.
        if (expression.count() > 1 && expression[0] == "")
        {
            // Début de l'expression
             list[i] = expression[1];
             test = 1;
        }

        // Fin de l'expression
        if (expression.count() > 1 && expression[1] == "")
             list[i] = expression[0];

        // Récupération du morceau de l'expression dans l'attribut de la classe MainWindow réservé aux expressions.
        if (test == 1)
             expPile.insert(list[i]);

        // Dans le cas où ce n'est pas une expression et qu'il n'y a pas d'opérateur dans l'inputLine.
        if (test == 0 && list[i] != "SWAP" && list[i] != "SUM" && list[i] != "MEAN" && list[i] != "DUP" &&
                list[i] != "DROP" && list[i] != "+" && list[i] != "-" && list[i] != "*" &&
                list[i] != "/" && list[i] != "!" && list[i] != "sin" && list[i] != "cos" &&
                list[i] != "tan" && list[i] != "sinh" && list[i] != "cosh" && list[i] != "tanh" &&
                list[i] != "log" && list[i] != "ln" && list[i] != "INV" && list[i] != "SQRT" &&
                list[i] != "SQR" && list[i] != "CUBE" && list[i] != "POW" && list[i] != "MOD" &&
                list[i] != "SIGN")
        {
            // Expressions régulières pour récupérer les rationnels, les réels et les complexes.
            QRegExp ra("[/]+");
            QStringList rationnelle = list[i].split(ra);
            QRegExp ree("[.]+");
            QStringList reel = list[i].split(ree);
            QRegExp co("[$]+");
            QStringList comp = list[i].split(co);

            // S'il y a un complexe.
            if (comp.count() > 1)
            {
                // L'option complexe est à non -> message d'erreur.
                if (com == 0)
                {
                    QMessageBox message;
                    message.setText("L'utilisation de complexes n'est pas autorisee.");
                    message.exec();
                }
                // L'option complexe est à oui.
                else
                {
                    // Récupération des parties Réelle et Imaginaire si elles sont de type réelles ou rationnelles.
                    // comp[0] = partie réelle.
                    // comp[1] = partie imaginaire.
                    QStringList rationReel = comp[0].split(ra);
                    QStringList rationVir = comp[1].split(ra);

                    QStringList reelReel = comp[0].split(ree);
                    QStringList reelVir = comp[1].split(ree);

                    Constante* comReel,* comVirtuel;

                    // Si la partie réelle du complexe est un rationnel.
                    if (rationReel.count() > 1)
                    {
                        // Récupération du rationnel.
                        int num = rationReel[0].toInt(); // Numérateur.
                        int den = rationReel[1].toInt(); // Dénominateur.

                        // Simplification.
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }
                        // Création de la constante contenant la partie réelle de type rationnel.
                        comReel = fac.creeConstante("rationnel", num, den);
                    }
                    // La partie réelle du complexe n'est pas un rationnel.
                    else
                    {
                        // Si la partie réelle du complexe est un réel.
                        if (reelReel.count() > 1)
                        {
                            // Création de la constante contenant la partie réelle de type réel.
                            comReel = fac.creeConstante("reel", 0, 0, comp[0].toFloat());
                        }
                        // La partie réelle du complexe est de type entier.
                        else
                        {
                            // Création de la constante contenant la partie réelle de type entier.
                            Constante * entier = fac.creeConstante("entier", comp[0].toInt());
                            comReel = entier;
                        }
                    }

                    // Si la partie imaginaire du complexe est un rationnel.
                    if (rationVir.count() > 1)
                    {
                        // Récupération du rationnel.
                        int num = rationVir[0].toInt(); // Numérateur.
                        int den = rationVir[1].toInt(); // Dénominateur.

                        // Simplification.
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }
                        // Création de la constante contenant la partie imaginaire de type rationnel.
                        comVirtuel = fac.creeConstante("rationnel", num, den);
                    }
                    // La partie imaginaire du complexe n'est pas un rationnel.
                    else
                    {
                        // Si la partie imaginaire du complexe est un réel.
                        if (reelVir.count() > 1)
                        {
                            // Création de la constante contenant la partie imaginaire de type réel.
                            comVirtuel = fac.creeConstante("reel", 0, 0, comp[1].toFloat());
                        }
                        // La partie imaginaire du complexe est de type entier.
                        else
                        {
                            // Création de la constante contenant la partie imaginaire de type entier.
                            Constante * entier = fac.creeConstante("entier", comp[1].toInt());
                            comVirtuel = entier;
                        }
                    }

                    // Création de la constante complexe contenant les parties réelles et imaginaires crées.
                    Constante * complexe = fac.creeConstante("complexe", 0, 0, 0, comReel, comVirtuel);

                    // On empile le complexe créé dans la pile.
                    pile.empiler(complexe);
                }
            }
            // S'il n'y a pas de complexe.
            else
            {
                // S'il y a un rationnel.
                if (rationnelle.count() > 1)
                {
                    // Mode rationnel non choisi.
                    if (mode != "rationnel")
                    {
                        QMessageBox message;
                        message.setText("Mode rationnel non selectionne.");
                        message.exec();
                    }
                    // Mode rationnel choisi.
                    else
                    {
                        // Récupération des éléments du rationnel.
                        int num = rationnelle[0].toInt(); // Numérateur
                        int den = rationnelle[1].toInt(); // Dénominateur

                        // Simplification.
                        int min = (num<=den ? num:den);
                        for (int i = min; i > 1; i--)
                        {
                            if (num%i == 0 && den%i == 0)
                            {
                                num /= i;
                                den /= i;
                            }
                        }

                        // Création de la constante rationnel avec le numérateur et le dénominateur.
                        Constante * ration = fac.creeConstante("rationnel", num, den);

                        // On empile le rationnel créé dans la pile.
                        pile.empiler(ration);
                    }
                }
                // S'il n'y a pas de rationnel.
                else
                {
                    // S'il y a un réel.
                    if (reel.count() > 1)
                    {
                        // Mode réel non choisi.
                        if (mode != "reel")
                        {
                            QMessageBox message;
                            message.setText("Mode reel non selectionne.");
                            message.exec();
                        }
                        // Mode réel choisi.
                        else
                        {
                            // Création de la constante contenant le réel.
                            Constante * reelle = fac.creeConstante("reel", 0, 0, list[i].toFloat());

                            // On empile le réel dans la pile.
                            pile.empiler(reelle);
                        }
                    }
                    // S'il n'y a pas de réel -> il y a un entier.
                    else
                    {
                        // Mode entier non choisi.
                        if (mode != "entier")
                        {
                            QMessageBox message;
                            message.setText("Mode entier non selectionne.");
                            message.exec();
                        }
                        // Mode entier choisi.
                        else
                        {
                            // Création de la constante contenant l'entier.
                            Constante * entier = fac.creeConstante("entier", list[i].toInt());

                            // On empile l'entier dans la pile.
                            pile.empiler(entier);
                        }
                    }
                }
            }
        }
        // Dans le cas où c'est une expression ou qu'il y a un opérateur dans l'inputLine.
        else
        {
            // Ce n'est pas une expression -> c'est un opérateur.
            if (test == 0)
            {
                // Opérateur SWAP.
                if (list[i] == "SWAP")
                {
                    // Le SWAP requiert 2 entiers présents dans la pile.
                    if (pile.getN() > 1 && pile.getTab(pile.getN() - 1)->getType() == "entier" &&
                         pile.getTab(pile.getN() - 2)->getType() == "entier")
                    {
                        int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                        int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                        QString exp = "SWAP pile(" + QString::number(val1, 10) + ") et pile(" + QString::number(val2, 10) + ") :";
                        ui->Express->setText(exp);

                        this->opSWAP(pile);
                    }
                    else
                    {
                        QMessageBox mSWAP;
                        mSWAP.setText("SWAP requiert 2 entiers.");
                        mSWAP.exec();
                    }
                }
                // Opérateur SUM.
                if (list[i] == "SUM")
                {
                    // Le SUM requiert 1 entier présent dans la pile.
                    if (!pile.pileVide() && pile.getTab(pile.getN() - 1)->getType() == "entier")
                    {
                        int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                        QString exp = "Sum de premiers " + QString::number(val1, 10) + " elements :";
                        ui->Express->setText(exp);

                        this->opSUM(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mSUM;
                        mSUM.setText("SUM requiert 1 entier.");
                        mSUM.exec();
                    }
                }
                // Opérateur MEAN.
                if (list[i] == "MEAN")
                {
                    if (!pile.pileVide() && pile.getTab(pile.getN() - 1)->getType() == "entier")
                    {
                        int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                        QString exp = "MEAN de premiers " + QString::number(val1, 10) + " elements :";
                        ui->Express->setText(exp);

                        this->opMEAN(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mMEAN;
                        mMEAN.setText("MEAN requiert 1 entier.");
                        mMEAN.exec();
                    }
                }
                // Opérateur DUP.
                if (list[i] == "DUP")
                {
                    if (!pile.pileVide())
                    {
                        this->opDUP(pile);
                        ui->Express->setText("DUP");
                    }
                    else
                    {
                        QMessageBox mDUP;
                        mDUP.setText("DUP requiert une pile non vide.");
                        mDUP.exec();
                    }
                }
                // Opérateur DROP.
                if (list[i] == "DROP")
                {
                    if (!pile.pileVide())
                    {
                        this->opDROP(pile);
                        ui->Express->setText("DROP");
                    }
                    else
                    {
                        QMessageBox mDROP;
                        mDROP.setText("DROP requiert une pile non vide.");
                        mDROP.exec();
                    }
                }
                // Opérateur factoriel.
                if (list[i] == "!")
                {
                    // Factoriel requiert un entier.
                    if (!pile.pileVide() && pile.getTab(pile.getN() - 1)->getType() == "entier")
                    {
                        int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                        QString exp = QString::number(val1, 10) + "!=";
                        ui->Express->setText(exp);

                        this->opFact(pile);
                    }
                    else
                    {
                        QMessageBox mFact;
                        mFact.setText("Factoriel requiert 1 entier.");
                        mFact.exec();
                    }
                }
                // Opérateur sin.
                if (list[i] == "sin")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "sin" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "sin" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "sin" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opSin(pile, type);
                    }
                    else
                    {
                        QMessageBox mSin;
                        mSin.setText("Sin requiert 1 constante.");
                        mSin.exec();
                    }
                }
                // Opérateur cos.
                if (list[i] == "cos")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "cos" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "cos" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "cos" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opCos(pile, type);
                    }
                    else
                    {
                        QMessageBox mCos;
                        mCos.setText("Cos requiert 1 constante.");
                        mCos.exec();
                    }
                }
                // Opérateur tan.
                if (list[i] == "tan")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "tan" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "tan" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "tan" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opTan(pile, type);
                    }
                    else
                    {
                        QMessageBox mTan;
                        mTan.setText("Tan requiert 1 constante.");
                        mTan.exec();
                    }
                }
                // Opérateur sinh.
                if (list[i] == "sinh")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "sinh" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "sinh" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "sinh" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opSinh(pile, type);
                    }
                    else
                    {
                        QMessageBox mSinh;
                        mSinh.setText("Sinh requiert 1 constante.");
                        mSinh.exec();
                    }
                }
                // Opérateur cosh.
                if (list[i] == "cosh")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "cosh" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "cosh" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "cosh" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opCosh(pile, type);
                    }
                    else
                    {
                        QMessageBox mCosh;
                        mCosh.setText("Cos requiert 1 constante.");
                        mCosh.exec();
                    }
                }
                // Opérateur tanh.
                if (list[i] == "tanh")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "tanh" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "tanh" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "tanh" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opTanh(pile, type);
                    }
                    else
                    {
                        QMessageBox mTanh;
                        mTanh.setText("Tanh requiert 1 constante.");
                        mTanh.exec();
                    }
                }
                // Opérateur log.
                if (list[i] == "log")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "log" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "log" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "log" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opLog(pile);
                    }
                    else
                    {
                        QMessageBox mLog;
                        mLog.setText("Log requiert 1 constante.");
                        mLog.exec();
                    }
                }
                // Opérateur ln.
                if (list[i] == "ln")
                {
                    if (!pile.pileVide())
                    {
                        QString exp;
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp = "ln" + QString::number(val1, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num1 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den1 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp = "ln" + QString::number(num1, 10) + "/" + QString::number(den1, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val1 = pile.getTab(pile.getN() - 1)->getReel();
                             exp = "ln" + QString::number(val1, 'g', 10) + "=";
                        }

                        ui->Express->setText(exp);

                        this->opLn(pile);
                    }
                    else
                    {
                        QMessageBox mLn;
                        mLn.setText("Ln requiert 1 constante.");
                        mLn.exec();
                    }
                }
                // Opérateur POW.
                if (list[i] == "POW")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("POW");

                        this->opPOW(pile, mode);
                    }
                    else
                    {
                        QMessageBox mPOW;
                        mPOW.setText("POW requiert 1 constante.");
                        mPOW.exec();
                    }
                }
                // Opérateur %.
                if (list[i] == "MOD")
                {
                    if (pile.getN() > 1 && pile.getTab(pile.getN() - 1)->getType() == "entier" &&
                         pile.getTab(pile.getN() - 2)->getType() == "entier")
                    {
                        int val1 = pile.getTab(pile.getN() - 1)->getEntier();
                        int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                        QString exp = QString::number(val2, 10) + "%" + QString::number(val1, 10) + "=";
                        ui->Express->setText(exp);

                        this->opMOD(pile);
                    }
                    else
                    {
                        QMessageBox mMOD;
                        mMOD.setText("MODULO requiert 2 entiers.");
                        mMOD.exec();
                    }
                }
                // Opérateur SIGN.
                if (list[i] == "SIGN")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("SIGN");

                        this->opSIGN(pile);
                    }
                    else
                    {
                        QMessageBox mSIGN;
                        mSIGN.setText("SIGN requiert 1 constante.");
                        mSIGN.exec();
                    }
                }
                // Opérateur INV.
                if (list[i] == "INV")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("INV");

                        this->opINV(pile);
                    }
                    else
                    {
                        QMessageBox mINV;
                        mINV.setText("INV requiert 1 constante.");
                        mINV.exec();
                    }
                }
                // Opérateur SQRT.
                if (list[i] == "SQRT")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("SQRT");

                        this->opSQRT(pile);
                    }
                    else
                    {
                        QMessageBox mSQRT;
                        mSQRT.setText("SQRT requiert 1 constante.");
                        mSQRT.exec();
                    }
                }
                // Opérateur SQR.
                if (list[i] == "SQR")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("SQR");

                        this->opSQR(pile);
                    }
                    else
                    {
                        QMessageBox mSQR;
                        mSQR.setText("SQR requiert 1 constante.");
                        mSQR.exec();
                    }
                }
                // Opérateur CUBE.
                if (list[i] == "CUBE")
                {
                    if (!pile.pileVide())
                    {
                        ui->Express->setText("CUBE");

                        this->opCUBE(pile);
                    }
                    else
                    {
                        QMessageBox mCUBE;
                        mCUBE.setText("CUBE requiert 1 constante.");
                        mCUBE.exec();
                    }
                }
                // Opérateur +.
                if (list[i] == "+")
                {
                    if (pile.getN() > 0)
                    {
                        QString exp;

                        // Cas de la première valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                             exp = QString::number(val2, 10) + "+";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                             exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "+";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 2)->getReel();
                             exp = QString::number(val2, 'g', 10) + "+";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                                exp = QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                                exp = QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                                exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "+";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "+";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "+";
                            }
                        }
                        // Cas de la deuxième valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp += QString::number(val2, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 1)->getReel();
                             exp += QString::number(val2, 'g', 10) + "=";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                                exp += QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "=";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "=";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                            }
                        }
                        ui->Express->setText(exp);

                        this->opPlus(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mPlus;
                        mPlus.setText("+ requiert 2 constantes.");
                        mPlus.exec();
                    }
                }
                // Opérateur -
                if (list[i] == "-")
                {
                    if (pile.getN() > 1)
                    {
                        QString exp;
                        // Cas de la première valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                             exp = QString::number(val2, 10) + "-";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                             exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "-";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 2)->getReel();
                             exp = QString::number(val2, 'g', 10) + "-";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                                exp = QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                                exp = QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                                exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "-";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "-";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "-";
                            }
                        }
                        // Cas de la deuxième valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp += QString::number(val2, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 1)->getReel();
                             exp += QString::number(val2, 'g', 10) + "=";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                                exp += QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "=";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "=";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                            }
                        }
                        ui->Express->setText(exp);

                        this->opDim(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mDim;
                        mDim.setText("- requiert 2 constantes.");
                        mDim.exec();
                    }
                }
                // Opérateur *
                if (list[i] == "*")
                {
                    if (pile.getN() > 1)
                    {
                        QString exp;

                        // Cas de la première valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                             exp = QString::number(val2, 10) + "*";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                             exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "*";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 2)->getReel();
                             exp = QString::number(val2, 'g', 10) + "*";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                                exp = QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                                exp = QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                                exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "*";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "*";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "*";
                            }
                        }
                        // Cas de la deuxième valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp += QString::number(val2, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 1)->getReel();
                             exp += QString::number(val2, 'g', 10) + "=";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                                exp += QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "=";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "=";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                            }
                        }
                        ui->Express->setText(exp);

                        this->opMult(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mMult;
                        mMult.setText("* requiert 2 constantes.");
                        mMult.exec();
                    }
                }
                // Opérateur /
                if(list[i]=="/")
                {
                    if (pile.getN() > 1)
                    {
                        QString exp;

                        // Cas de la première valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 2)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 2)->getEntier();
                             exp = QString::number(val2, 10) + "/";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 2)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 2)->getDenominateur();
                             exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "/";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 2)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 2)->getReel();
                             exp = QString::number(val2, 'g', 10) + "/";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 2)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getEntier();
                                exp = QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getReel();
                                exp = QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieReelle()->getDenominateur();
                                exp = QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "/";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "/";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 2)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "/";
                            }
                        }
                        // Cas de la deuxième valeur.
                        // Pour un entier.
                        if (pile.getTab(pile.getN() - 1)->getType() == "entier")
                        {
                             int val2 = pile.getTab(pile.getN() - 1)->getEntier();
                             exp += QString::number(val2, 10) + "=";
                        }
                        // Pour un rationnel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "rationnel")
                        {
                             int num2 = pile.getTab(pile.getN() - 1)->getNumerateur();
                             int den2 = pile.getTab(pile.getN() - 1)->getDenominateur();
                             exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                        }
                        // Pour un réel.
                        if (pile.getTab(pile.getN() - 1)->getType() == "reel")
                        {
                             float val2 = pile.getTab(pile.getN() - 1)->getReel();
                             exp += QString::number(val2, 'g', 10) + "=";
                        }
                        // Pour un complexe.
                        if (pile.getTab(pile.getN() - 1)->getType() == "complexe")
                        {
                            // Cas de la partie réelle.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getEntier();
                                exp += QString::number(reel2, 10) + "$";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "$";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieReelle()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieReelle()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "$";
                            }
                            // Cas de la partie imaginaire.
                            // Pour un entier.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "entier")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getEntier();
                                exp += QString::number(reel2, 10) + "=";
                            }
                            // Pour un réel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "reel")
                            {
                                int reel2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getReel();
                                exp += QString::number(reel2, 'g', 10) + "=";
                            }
                            // Pour un rationnel.
                            if (pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getType() == "rationnel")
                            {
                                int num2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getNumerateur();
                                int den2 = pile.getTab(pile.getN() - 1)->getPartieImaginaire()->getDenominateur();
                                exp += QString::number(num2, 10) + "/" + QString::number(den2, 10) + "=";
                            }
                        }
                        ui->Express->setText(exp);

                        this->opDiv(pile, mode, com);
                    }
                    else
                    {
                        QMessageBox mDiv;
                        mDiv.setText("/ requiert 2 constantes.");
                        mDiv.exec();
                    }
                }
            }
        }
        i++;
    }

    pile.notifier();
    ui->inputLine->setText("");
}

/*!
  * \brief Méthode de MainWindow pour évaluer une expression.
  * Méthode de la classe MainWindow pour évaluer tous les éléments d'une expression.
  */
void MainWindow::evalPressed()
{
    test = 0;

    QString exp, value;

    // Affichage de l'expression.
    for (int i = 0; i < expPile.getNombre(); i++)
        exp += expPile.getExpression(i) + " ";
    ui->Express->setText(exp);

    // Log.
    QString log = "Evaluation de l'expression : " + exp;
    LogSystem::add(log, 0);

    // Pour chaque élément de l'expression.
    for (int i = 0; i < expPile.getNombre(); i++)
    {
        value = expPile.getExpression(i);

        // Cas d'une constante.
        if (value != "SWAP" && value != "SUM" && value != "MEAN" && value != "DUP" &&
                value != "DROP" && value != "+" && value != "-" && value != "*" &&
                value != "/" && value != "!" && value != "sin" && value != "cos" &&
                value != "tan" && value != "sinh" && value != "cosh" && value != "tanh" &&
                value != "log" && value != "ln" && value != "INV" && value != "SQRT" &&
                value != "SQR" && value != "CUBE" && value != "POW" && value != "MOD" &&
                value != "SIGN")
        {
            // Expressions régulières pour ressortir les rationnels, les réels, les complexes et les entiers.
            QRegExp ra("[/]+");
            QStringList rationnelle = value.split(ra);
            QRegExp ree("[.]+");
            QStringList reel = value.split(ree);
            QRegExp co("[$]+");
            QStringList comp = value.split(co);

            // Si la constante est de type complexe.
            if (comp.count() > 1)
            {
                // Récupération des parties Réelle et Imaginaire si elles sont de type réelles ou rationnelles.
                // comp[0] = partie réelle.
                // comp[1] = partie imaginaire.
                QStringList rationReel = comp[0].split(ra);//rationReel[0]/rationReel[1]
                QStringList rationVir = comp[1].split(ra); //rationVir[0]/rationVir[1]

                QStringList reelReel = comp[0].split(ree); //reelReel[0].reelReel[1]
                QStringList reelVir = comp[1].split(ree);  //reelVir[0].reelVir[1]

                Constante* comReel,* comVirtuel;

                // Cas de la partie réelle du complexe.
                // La partie réelle du complexe est de type rationnel.
                if (rationReel.count() > 1)
                {
                    // Instanciation du numérateur et du dénominateur.
                    int num = rationReel[0].toInt(); // Numérateur.
                    int den = rationReel[1].toInt(); // Dénominateur.

                    // Simplification.
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    // Création de la constante de la partie réelle de type rationnel du complexe.
                    comReel = fac.creeConstante("rationnel", num, den);
                }
                // La partie réelle du complexe n'est pas de type rationnel.
                else
                {
                    // La partie réelle du complexe est de type réel.
                    if (reelReel.count() > 1)
                    {
                        // Création de la constante de la partie réelle de type réel du complexe.
                        comReel = fac.creeConstante("reel", 0, 0, comp[0].toFloat());
                    }
                    // La partie réelle du complexe est de type entier.
                    else
                    {
                        // Création de la constante de la partie réelle de type entier du complexe.
                        Constante * entier = fac.creeConstante("entier", comp[0].toInt());
                        comReel = entier;
                    }
                }
                // Cas de la partie imaginaire du complexe.
                // La partie imaginaire du complexe est de type rationnel.
                if (rationVir.count() > 1)
                {
                    // Instanciation du numérateur et du dénominateur.
                    int num = rationVir[0].toInt(); // Numérateur.
                    int den = rationVir[1].toInt(); // Dénominateur.

                    // Simplification.
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    // Création de la constante de la partie imaginaire de type rationnel du complexe.
                    comVirtuel = fac.creeConstante("rationnel", num, den);
                }
                // La partie imaginaire du complexe n'est pas de type rationnel.
                else
                {
                    // La partie imaginaire du complexe est de type réel.
                    if (reelVir.count() > 1)
                    {
                        // Création de la constante de la partie imaginaire de type réel du complexe.
                        comVirtuel = fac.creeConstante("reel", 0, 0, comp[1].toFloat());
                    }
                    // La partie imaginaire du complexe est de type entier.
                    else
                    {
                        // Création de la constante de la partie imaginaire de type entier du complexe.
                        Constante * entier = fac.creeConstante("entier", comp[1].toInt());
                        comVirtuel = entier;
                    }
                }
                // Création de la constante de type complexe contenant les parties réelles et imaginaires.
                Constante * complexe = fac.creeConstante("complexe", 0, 0, 0, comReel, comVirtuel);
                // On empile le complexe dans la pile.
                pile.empiler(complexe);
            }
            // Cas d'un non complexe.
            else
            {
                // Cas d'un rationnel.
                if (rationnelle.count() > 1)
                {
                    // Instanciation du numérateur et du dénominateur du rationnel.
                    int num = rationnelle[0].toInt();
                    int den = rationnelle[1].toInt();

                    // Simplification.
                    int min = (num<=den ? num:den);
                    for (int i = min; i > 1; i--)
                    {
                        if (num%i == 0 && den%i == 0)
                        {
                            num /= i;
                            den /= i;
                        }
                    }
                    // Création de la constante de type rationnel.
                    Constante * ration = fac.creeConstante("rationnel", num, den);
                    // On empile le rationnel dans la pile.
                    pile.empiler(ration);
                }
                // Cas d'un non rationnel.
                else
                {
                    // Cas d'un réel.
                    if (reel.count() > 1)
                    {
                        // Création de la constante de type réel.
                        Constante * reelle = fac.creeConstante("reel", 0, 0, value.toFloat());
                        // On empile le réel dans la pile.
                        pile.empiler(reelle);
                    }
                    // Cas d'un entier.
                    else
                    {
                        // Création de la constante de type entier.
                        Constante * entier = fac.creeConstante("entier", value.toInt());
                        // On empile l'entier dans la pile.
                        pile.empiler(entier);
                    }
                }
            }
        }
        // Cas d'un opérateur.
        else
        {
            if (value == "SWAP")
                this->opSWAP(pile);
            if (value == "SUM")
                this->opSUM(pile, mode, com);
            if (value == "MEAN")
                this->opMEAN(pile, mode, com);
            if (value == "DUP")
                this->opDUP(pile);
            if (value == "DROP")
                this->opDROP(pile);
            if (value == "+")
                this->opPlus(pile, mode, com);
            if (value == "-")
                this->opDim(pile, mode, com);
            if (value == "*")
                this->opMult(pile, mode, com);
            if (value == "/")
                this->opDiv(pile, mode, com);
            if (value == "!")
                this->opFact(pile);
            if (value == "sin")
                this->opSin(pile, type);
            if (value == "cos")
                this->opCos(pile, type);
            if (value == "tan")
                this->opTan(pile, type);
            if (value == "sinh")
                this->opSinh(pile, type);
            if (value == "cosh")
                this->opCosh(pile, type);
            if (value == "tanh")
                this->opTanh(pile, type);
            if (value == "log")
                this->opLog(pile);
            if (value == "ln")
                this->opLn(pile);
            if (value == "INV")
                this->opINV(pile);
            if (value == "SQRT")
                this->opSQRT(pile);
            if (value == "SQR")
                this->opSQR(pile);
            if (value == "CUBE")
                this->opCUBE(pile);
            if (value == "POW")
                this->opPOW(pile, mode);
            if (value == "MOD")
                this->opMOD(pile);
            if (value == "SIGN")
                this->opSIGN(pile);
        }
    }
    pile.notifier();
}

/*!
  * \brief Méthode de MainWindow pour recharger les éléments de la ligne de commande.
  * Méthode de la classe MainWindow pour recharger la ligne de commande effacée.
  */
void MainWindow::retablirPressed()
{
    ui->inputLine->setText(memoire);
    LogSystem::add("Retablir", 0);
}

/*!
  * \brief Méthode de MainWindow pour effacer les éléments de la ligne de commande.
  * Méthode de la classe MainWindow pour effacer la ligne de commande effacée.
  */
void MainWindow::annulerPressed()
{
    memoire=ui->inputLine->text();
    ui->inputLine->setText("");
    LogSystem::add("Annuler.", 0);
}

/*!
  * \brief Méthode de MainWindow pour effacer la ligne de commande et la pile.
  * Méthode de la classe MainWindow pour effacer les données de la calculatrice.
  */
void MainWindow::clearPressed()
{
    ui->inputLine->setText("");

    for (int i = 0; i < pile.getN(); i++)
        pile.depiler();  //vider la pile
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur SWAP à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur SWAP.
  */
void MainWindow::swapPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SWAP");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur SUM à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur SUM.
  */
void MainWindow::sumPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SUM");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur MEAN à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur MEAN.
  */
void MainWindow::meanPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "MEAN");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur DUP à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur DUP.
  */
void MainWindow::dupPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "DUP");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur DROP à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur DROP.
  */
void MainWindow::dropPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "DROP");
}

/*!
  * \brief Méthode de MainWindow pour ajouter un espace à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter un espace.
  */
void MainWindow::spacePressed()
{
     ui->inputLine->setText(ui->inputLine->text() + " ");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le symbole $ à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le symbole des complexes.
  */
void MainWindow::dollarPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "$");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur + à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur addition.
  */
void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "+");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur - à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur soustraction.
  */
void MainWindow::dimPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "-");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur * à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur multiplication.
  */
void MainWindow::multPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "*");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur / à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur division.
  */
void MainWindow::divPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "/");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'apostrophe à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'apostrophe.
  */
void MainWindow::expressionPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "'");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 0 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 0.
  */
void MainWindow::num0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "0");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 1 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 1.
  */
void MainWindow::num1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "1");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 2 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 2.
  */
void MainWindow::num2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "2");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 9 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 9.
  */
void MainWindow::num3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "3");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 4 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 4.
  */
void MainWindow::num4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "4");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 5 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 5.
  */
void MainWindow::num5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "5");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 6 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 6.
  */
void MainWindow::num6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "6");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 7 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 7.
  */
void MainWindow::num7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "7");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 8 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 8.
  */
void MainWindow::num8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "8");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le chiffre 9 à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le chiffre 9.
  */
void MainWindow::num9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "9");
}

/*!
  * \brief Méthode de MainWindow pour ajouter le point à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter le point.
  */
void MainWindow::pointPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + ".");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur ! à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur factoriel.
  */
void MainWindow::factPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "!");
}

/*!
  * \brief Méthode de MainWindow pour afficher les informations générales de la calculatrice.
  * Méthode de la classe MainWindow pour afficher le nom du projet et ses auteurs.
  */
void MainWindow::about()
 {
    QMessageBox message;
    message.setText("UV: LO21\nSujet: Calculatrice en notation polonaise inversee.\nAuteurs: Han Jia & Antoine Hars.");
    message.exec();
 }

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur sin à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur sin.
  */
void MainWindow::sinPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "sin");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur cos à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur cos.
  */
void MainWindow::cosPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "cos");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur tan à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur tan.
  */
void MainWindow::tanPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "tan");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur sinh à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur sinh.
  */
void MainWindow::sinhPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "sinh");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur cosh à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur cosh.
  */
void MainWindow::coshPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "cosh");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur tanh à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur tanh.
  */
void MainWindow::tanhPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "tanh");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur log à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur log.
  */
void MainWindow::logPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "log");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur ln à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur ln.
  */
void MainWindow::lnPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "ln");
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type radian est choisi.
  * Méthode de la classe MainWindow pour rajouter le type radian.
  */
void MainWindow::radSelected()
{
    ui->RadouDeg->setText("radian");
    type = "radian";
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type degrès est choisi.
  * Méthode de la classe MainWindow pour rajouter le type degrès.
  */
void MainWindow::degSelected()
{
    ui->RadouDeg->setText("degres");
    type = "degres";
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur CUBE à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur CUBE.
  */
void MainWindow::cubePressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "CUBE");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur SQR à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur SQR.
  */
void MainWindow::sqrPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SQR");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur SQRT à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur SQRT.
  */
void MainWindow::sqrtPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SQRT");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur INV à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur INV.
  */
void MainWindow::invPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "INV");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur SIGN à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur SIGN.
  */
void MainWindow::signPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "SIGN");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur % à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur modulo.
  */
void MainWindow::modPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "%");
}

/*!
  * \brief Méthode de MainWindow pour ajouter l'opérateur POW à la ligne de commande.
  * Méthode de la classe MainWindow pour rajouter l'opérateur POW.
  */
void MainWindow::powPressed()
{
    ui->inputLine->setText(ui->inputLine->text() + "POW");
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type non complexe est choisi.
  * Méthode de la classe MainWindow pour choisir le type non complexe.
  */
void MainWindow::nonComplexePressed()
{
    ui->comOuiNon->setText("non");
    com = false;
    LogSystem::add("Mode non complexe choisi.", 0);
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type complexe est choisi.
  * Méthode de la classe MainWindow pour choisir le type complexe.
  */
void MainWindow::complexePressed()
{
    ui->comOuiNon->setText("oui");
    com = true;
    LogSystem::add("Mode complexe choisi.", 0);
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type réel est choisi.
  * Méthode de la classe MainWindow pour choisir le type réel.
  */
void MainWindow::reelPressed()
{
    ui->mode->setText("reel");
    mode = "reel";
    LogSystem::add("Mode reel choisi.", 0);
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type rationnel est choisi.
  * Méthode de la classe MainWindow pour choisir le type rationnel.
  */
void MainWindow::rationnelPressed()
{
    ui->mode->setText("rationnel");
    mode = "rationnel";
    LogSystem::add("Mode rationnel choisi.", 0);
}

/*!
  * \brief Méthode de MainWindow pour spécifier que le type entier est choisi.
  * Méthode de la classe MainWindow pour choisir le type entier.
  */
void MainWindow::entierPressed()
{
    ui->mode->setText("entier");
    mode = "entier";
    LogSystem::add("Mode entier choisi.", 0);
}

/*!
 *  \brief Fonction qui permet de sauvgarder le contexte de la calculatrice.
 *   Fonction qui permet de sauvgarder le contexte de la calculatrice.
 */
void MainWindow::save()
{
    LogSystem::add("sauvegarde du contexte", 1);
/*    QFile fichier("contexte.dat");
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream flux(& fichier);
    std::string s2 = pile.toString();
    QString s = s2.c_str();
    flux << s << "\n";
    flux << ui->listWidget->text() << "\n";
    fichier.close();
*/}

/*!
 *  \brief Fonction qui permet de charger le contexte de la calculatrice.
 *   Fonction qui permet de charger le contexte de la calculatrice.
 */
void MainWindow::load()
{
    LogSystem::add("chargement du contexte", 1);
/*    QFile fichier("contexte.dat");
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream flux(& fichier);

    QString s = flux.readLine();
    ui->listWidget->setText(s);
    evalPressed();
    ui->listWidget->setText(flux.readLine());

    fichier.close();
*/}
