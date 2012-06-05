/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: mainwindow.cpp
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow * MainWindow::instanceUnique = 0;

Pile pile;
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
    QString value=ui->inputLine->text();
        QRegExp re("[ ]+");
        QStringList list = value.split(re);

        int i=0;

        while(i<list.count()){
            QRegExp ex("[']+"); //detecter s'il y a expression
            QStringList expression = list[i].split(ex);

            if(expression.count()>1&&expression[0]==""){//debut d'expression
                 list[i]=expression[1];
                 test=1;   //debut d'expression
            }

            if(expression.count()>1&&expression[1]==""){//fin d'expression
                 list[i]=expression[0];
                 expPile.insert(list[i]);
            }

            if(test==1){
                 expPile.insert(list[i]);
            }

            if(test==0&&list[i]!="SWAP"&&list[i]!="SUM"&&list[i]!="MEAN"&&list[i]!="DUP"&&
                    list[i]!="DROP"&&list[i]!="+"&&list[i]!="-"&&list[i]!="*"&&
                    list[i]!="/"&&list[i]!="!"&&list[i]!="sin"&&list[i]!="cos"&&
                    list[i]!="tan"&&list[i]!="sinh"&&list[i]!="cosh"&&list[i]!="tanh"&&
                    list[i]!="log"&&list[i]!="ln"&&list[i]!="INV"&&list[i]!="SQRT"&&
                    list[i]!="SQR"&&list[i]!="CUBE"&&list[i]!="POW"&&list[i]!="MOD"&&
                    list[i]!="SIGN"){

                //saisir reel,rationnelle,complexe ou entier
                QRegExp ra("[/]+");
                QStringList rationnelle = list[i].split(ra);
                QRegExp ree("[.]+");
                QStringList reel = list[i].split(ree);
                QRegExp co("[$]+");
                QStringList comp = list[i].split(co);

                //determiner s'il est complexe d'abord
                if(comp.count()>1){
                    //saisir un complexe, comp[0] est reel, comp[1] est virtuel

                    QStringList rationReel = comp[0].split(ra);//rationReel[0]/rationReel[1]
                    QStringList rationVir = comp[1].split(ra); //rationVir[0]/rationVir[1]

                    QStringList reelReel = comp[0].split(ree); //reelReel[0].reelReel[1]
                    QStringList reelVir = comp[1].split(ree);  //reelVir[0].reelVir[1]

                    Constante* comReel,* comVirtuel;

                    //complexe:pour le partie reel
                    if(rationReel.count()>1){
                        //saisir un rationnelle
                        int num=rationReel[0].toInt();//numerateur
                        int den=rationReel[1].toInt();//denominateur

                        //simplifier
                        int min=(num<=den?num:den);
                        for(int i=min;i>1;i--){
                            if(num%i==0&&den%i==0){
                                num/=i;
                                den/=i;
                            }
                        }
                        //empiler
                        comReel=fac.creeConstante("rationnelle",num,den);

                    }else
                        if(reelReel.count()>1){
                            //saisir un reel
                            comReel=fac.creeConstante("reel",0,0,comp[0].toFloat());

                        }else{
                                //saisir un entier
                                Constante *entier=fac.creeConstante("entier",comp[0].toInt());
                                comReel=entier;
                            }


                    //complexe:pour le partie virtuel
                    if(rationVir.count()>1){
                        //saisir un rationnelle
                        int num=rationVir[0].toInt();//numerateur
                        int den=rationVir[1].toInt();//denominateur

                        //simplifier
                        int min=(num<=den?num:den);
                        for(int i=min;i>1;i--){
                            if(num%i==0&&den%i==0){
                                num/=i;
                                den/=i;
                            }
                        }
                        //empiler
                        comVirtuel=fac.creeConstante("rationnelle",num,den);

                    }else
                        if(reelVir.count()>1){
                            //saisir un reel
                            comVirtuel=fac.creeConstante("reel",0,0,comp[1].toFloat());

                        }else{
                                //saisir un entier
                                Constante *entier=fac.creeConstante("entier",comp[1].toInt());
                                comVirtuel=entier;
                            }

                    Constante* complexe=fac.creeConstante("complexe",0,0,0,comReel,comVirtuel);
                    pile.empiler(complexe);

                }//saisir n'est pas complexe
                else{
                if(rationnelle.count()>1){
                    //saisir un rationnelle
                    int num=rationnelle[0].toInt();//numerateur
                    int den=rationnelle[1].toInt();//denominateur

                    //simplifier
                    int min=(num<=den?num:den);
                    for(int i=min;i>1;i--){
                        if(num%i==0&&den%i==0){
                            num/=i;
                            den/=i;
                        }
                    }
                    //empiler
                    Constante* ration=fac.creeConstante("rationnelle",num,den);
                    pile.empiler(ration);

                }else
                    if(reel.count()>1){
                        //saisir un reel
                        Constante* reelle=fac.creeConstante("reel",0,0,list[i].toFloat());
                        pile.empiler(reelle);

                    }else{
                            //saisir un entier
                            Constante* entier=fac.creeConstante("entier",list[i].toInt());
                            pile.empiler(entier);
                        }
             }
            }


       if(test==0) //quand test==0, il n'y a pas d'expression constante
       {
            if(list[i]=="SWAP"){
                //pour l'expression
                int val1=pile.getTab(pile.getN()-1)->getEntier();
                int val2=pile.getTab(pile.getN()-2)->getEntier();
                QString exp="SWAP d'elements num "+QString::number(val1,10)+" et num "+QString::number(val2,10)+" est:";
                ui->Express->setText(exp);

                //appeler la fonction
                opSWAP(pile, val1, val2);
            }
    /*
            if(list[i]=="SUM"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].getEntier();
                QString exp="Sum de premiers "+QString::number(val1,10)+" elements est:";
                ui->Express->setText(exp);

                //appeler la fonction
                //opSUM();
            }

            if(list[i]=="MEAN"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].getEntier();
                QString exp="MEAN de premiers "+QString::number(val1,10)+" elements est:";
                ui->Express->setText(exp);

                //appeler la fonction
                //opMEAN();
            }

            if(list[i]=="DUP"){
                //appeler la fonction
                //opDUP();

                //pour l'expression
                ui->Express->setText("DUP");
            }

            if(list[i]=="DROP"){
                //appeler la fonction
                //opDROP();

                //pour l'expression
                ui->Express->setText("DROP");
            }

            if(list[i]=="+"){
                //pour l'expression
                QString exp;
                if(stack->tab[stack->N-1].getType()=="entier"){
                     int val1=stack->tab[stack->N-1].getEntier();
                     int val2=stack->tab[stack->N-2].getEntier();
                     exp=QString::number(val2,10)+"+"+QString::number(val1,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="rationnelle"){
                     int num1=stack->tab[stack->N-1].getNumerateur();
                     int den1=stack->tab[stack->N-1].getDenominateur();
                     int num2=stack->tab[stack->N-2].getNumerateur();
                     int den2=stack->tab[stack->N-2].getDenominateur();
                     exp=QString::number(num1,10)+"/"+QString::number(den1,10)+"+"
                             +QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="reel"){
                     float val1=stack->tab[stack->N-1].getReel();
                     float val2=stack->tab[stack->N-2].getReel();
                     exp=QString::number(val2,'g',10)+"+"+QString::number(val1,'g',10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="complexe"){
                    float reel1=stack->tab[stack->N-1].getComReel();
                    float virtuel1=stack->tab[stack->N-1].getComVirtuel();
                    float reel2=stack->tab[stack->N-2].getComReel();
                    float virtuel2=stack->tab[stack->N-2].getComVirtuel();
                    exp=QString::number(reel1,'g',10)+"$"+QString::number(virtuel1,'g',10)+"+"
                            +QString::number(reel2,'g',10)+"$"+QString::number(virtuel2,'g',10)+"=";
                }

                ui->Express->setText(exp);

                //appeler la fonction
                //opPlus();
                }

            if(list[i]=="-"){
                //pour l'expression
                QString exp;
                if(stack->tab[stack->N-1].getType()=="entier"){
                     int val1=stack->tab[stack->N-1].getEntier();
                     int val2=stack->tab[stack->N-2].getEntier();
                     exp=QString::number(val2,10)+"-"+QString::number(val1,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="rationnelle"){
                     int num1=stack->tab[stack->N-1].getNumerateur();
                     int den1=stack->tab[stack->N-1].getDenominateur();
                     int num2=stack->tab[stack->N-2].getNumerateur();
                     int den2=stack->tab[stack->N-2].getDenominateur();
                     exp=QString::number(num1,10)+"/"+QString::number(den1,10)+"-"
                             +QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="reel"){
                     float val1=stack->tab[stack->N-1].getReel();
                     float val2=stack->tab[stack->N-2].getReel();
                     exp=QString::number(val2,'g',10)+"-"+QString::number(val1,'g',10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="complexe"){
                    float reel1=stack->tab[stack->N-1].getComReel();
                    float virtuel1=stack->tab[stack->N-1].getComVirtuel();
                    float reel2=stack->tab[stack->N-2].getComReel();
                    float virtuel2=stack->tab[stack->N-2].getComVirtuel();
                    exp=QString::number(reel1,'g',10)+"$"+QString::number(virtuel1,'g',10)+"-"
                            +QString::number(reel2,'g',10)+"$"+QString::number(virtuel2,'g',10)+"=";
                }
                ui->Express->setText(exp);

                //appeler la fonction
                //opDim();
                }

            if(list[i]=="*"){
                //pour l'expression
                QString exp;
                if(stack->tab[stack->N-1].getType()=="entier"){
                     int val1=stack->tab[stack->N-1].getEntier();
                     int val2=stack->tab[stack->N-2].getEntier();
                     exp=QString::number(val2,10)+"*"+QString::number(val1,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="rationnelle"){
                     int num1=stack->tab[stack->N-1].getNumerateur();
                     int den1=stack->tab[stack->N-1].getDenominateur();
                     int num2=stack->tab[stack->N-2].getNumerateur();
                     int den2=stack->tab[stack->N-2].getDenominateur();
                     exp=QString::number(num1,10)+"/"+QString::number(den1,10)+"*"
                             +QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="reel"){
                     float val1=stack->tab[stack->N-1].getReel();
                     float val2=stack->tab[stack->N-2].getReel();
                     exp=QString::number(val2,'g',10)+"*"+QString::number(val1,'g',10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="complexe"){
                    float reel1=stack->tab[stack->N-1].getComReel();
                    float virtuel1=stack->tab[stack->N-1].getComVirtuel();
                    float reel2=stack->tab[stack->N-2].getComReel();
                    float virtuel2=stack->tab[stack->N-2].getComVirtuel();
                    exp=QString::number(reel1,'g',10)+"$"+QString::number(virtuel1,'g',10)+"*"
                            +QString::number(reel2,'g',10)+"$"+QString::number(virtuel2,'g',10)+"=";
                }
                ui->Express->setText(exp);

                //appeler la fonction
                //opMult();
                }

            if(list[i]=="/"){
                //pour l'expression
                QString exp;
                if(stack->tab[stack->N-1].getType()=="entier"){
                     int val1=stack->tab[stack->N-1].getEntier();
                     int val2=stack->tab[stack->N-2].getEntier();
                     exp=QString::number(val2,10)+"/"+QString::number(val1,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="rationnelle"){
                     int num1=stack->tab[stack->N-1].getNumerateur();
                     int den1=stack->tab[stack->N-1].getDenominateur();
                     int num2=stack->tab[stack->N-2].getNumerateur();
                     int den2=stack->tab[stack->N-2].getDenominateur();
                     exp=QString::number(num1,10)+"/"+QString::number(den1,10)+" / "
                             +QString::number(num2,10)+"/"+QString::number(den2,10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="reel"){
                     float val1=stack->tab[stack->N-1].getReel();
                     float val2=stack->tab[stack->N-2].getReel();
                     exp=QString::number(val2,'g',10)+"/"+QString::number(val1,'g',10)+"=";
                }
                if(stack->tab[stack->N-1].getType()=="complexe"){
                    float reel1=stack->tab[stack->N-1].getComReel();
                    float virtuel1=stack->tab[stack->N-1].getComVirtuel();
                    float reel2=stack->tab[stack->N-2].getComReel();
                    float virtuel2=stack->tab[stack->N-2].getComVirtuel();
                    exp=QString::number(reel1,'g',10)+"$"+QString::number(virtuel1,'g',10)+"/"
                            +QString::number(reel2,'g',10)+"$"+QString::number(virtuel2,'g',10)+"=";
                }
                ui->Express->setText(exp);

                //appeler la fonction
                //opDiv();
            }

            if(list[i]=="!"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].getEntier();
                QString exp=QString::number(val1,10)+"!=";
                ui->Express->setText(exp);

                //appeler la fonction
                //opFact();
            }

            if(list[i]=="sin"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="sin"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opSin();
            }

            if(list[i]=="cos"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="cos"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opCos();

            }

            if(list[i]=="tan"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="tan"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opTan();
            }

            if(list[i]=="sinh"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="sinh"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opSinh();

                }

            if(list[i]=="cosh"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="cosh"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opCosh();

                }

            if(list[i]=="tanh"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="tanh"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opTanh();

            }

            if(list[i]=="log"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="log"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                oplog();
            }

            if(list[i]=="ln"){
                //pour l'expression
                int val1=stack->tab[stack->N-1].toInt();
                QString exp="ln"+QString::number(val1,'g',10)+"=";
                ui->Express->setText(exp);

                //appeler la fonction
                opln();
            }
            */
       }

        i++;

        }

        ui->listWidget->clear();

        for(int j=0;j<pile.getN();j++){
            if(pile.getTab(j)->getType()=="entier"){
                ui->listWidget->addItem(QString::number(pile.getTab(j)->getEntier(),10));
            }
            if(pile.getTab(j)->getType()=="rationnelle"){
                QString res=QString::number(pile.getTab(j)->getNumerateur(),10)+"/"+QString::number(pile.getTab(j)->getDenominateur(),10);
                ui->listWidget->addItem(res);
            }
            if(pile.getTab(j)->getType()=="reel"){
                ui->listWidget->addItem(QString::number(pile.getTab(j)->getReel(),'g',10));
            }
            if(pile.getTab(j)->getType()=="complexe"){
                QString res;
                //afficher partie reelle
                if(pile.getTab(j)->getPartieReelle()->getType()=="entier"){
                    res=QString::number(pile.getTab(j)->getPartieReelle()->getEntier(),10)+"$";
                }
                if(pile.getTab(j)->getPartieReelle()->getType()=="reel"){
                    res=QString::number(pile.getTab(j)->getPartieReelle()->getReel(),'g',10)+"$";
                }
                if(pile.getTab(j)->getPartieReelle()->getType()=="rationnelle"){
                    res=QString::number(pile.getTab(j)->getPartieReelle()->getNumerateur(),10)+"/"+QString::number(pile.getTab(j)->getPartieReelle()->getDenominateur(),10)+"$";
                }

                //afficher partie virtuel
                if(pile.getTab(j)->getPartieImaginaire()->getType()=="entier"){
                    res+=QString::number(pile.getTab(j)->getPartieImaginaire()->getEntier(),10);
                }
                if(pile.getTab(j)->getPartieImaginaire()->getType()=="reel"){
                    res+=QString::number(pile.getTab(j)->getPartieImaginaire()->getReel(),'g',10);
                }
                if(pile.getTab(j)->getPartieImaginaire()->getType()=="rationnelle"){
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
    for(int i = 0; i < pile.getN(); i++)
        pile.depiler();
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
