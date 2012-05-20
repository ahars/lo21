/* LO21 - projet
 * Calculatrice à notation polonaise inversée
 * Auteurs:
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructeur MainWindow.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect butttons numero avec les slots
    QObject::connect(ui->button0,SIGNAL(clicked()),this,SLOT(num0Pressed()));
    QObject::connect(ui->button1,SIGNAL(clicked()),this,SLOT(num1Pressed()));
    QObject::connect(ui->button2,SIGNAL(clicked()),this,SLOT(num2Pressed()));
    QObject::connect(ui->button3,SIGNAL(clicked()),this,SLOT(num3Pressed()));
    QObject::connect(ui->button4,SIGNAL(clicked()),this,SLOT(num4Pressed()));
    QObject::connect(ui->button5,SIGNAL(clicked()),this,SLOT(num5Pressed()));
    QObject::connect(ui->button6,SIGNAL(clicked()),this,SLOT(num6Pressed()));
    QObject::connect(ui->button7,SIGNAL(clicked()),this,SLOT(num7Pressed()));
    QObject::connect(ui->button8,SIGNAL(clicked()),this,SLOT(num8Pressed()));
    QObject::connect(ui->button9,SIGNAL(clicked()),this,SLOT(num9Pressed()));

    QObject::connect(ui->buttonPoint,SIGNAL(clicked()),this,SLOT(pointPressed()));
    QObject::connect(ui->buttonCLEAR,SIGNAL(clicked()),this,SLOT(clearPressed()));
    QObject::connect(ui->buttonRetablir,SIGNAL(clicked()),this,SLOT(retablirPressed()));
    QObject::connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(about()));
    QObject::connect(ui->buttonPlus,SIGNAL(clicked()),this,SLOT(plusPressed()));
    QObject::connect(ui->buttonDim,SIGNAL(clicked()),this,SLOT(dimPressed()));
    QObject::connect(ui->buttonMulti,SIGNAL(clicked()),this,SLOT(multPressed()));
    QObject::connect(ui->buttonDiv,SIGNAL(clicked()),this,SLOT(divPressed()));
    QObject::connect(ui->buttonSPACE,SIGNAL(clicked()),this,SLOT(spacePressed()));
    QObject::connect(ui->buttonEntrer,SIGNAL(clicked()),this,SLOT(entrerPressed()));
    QObject::connect(ui->buttonFactoriel,SIGNAL(clicked()),this,SLOT(factPressed()));
    QObject::connect(ui->buttonSin,SIGNAL(clicked()),this,SLOT(sinPressed()));
    QObject::connect(ui->buttonCos,SIGNAL(clicked()),this,SLOT(cosPressed()));
    QObject::connect(ui->buttonTan,SIGNAL(clicked()),this,SLOT(tanPressed()));
    QObject::connect(ui->buttonSinh,SIGNAL(clicked()),this,SLOT(sinhPressed()));
    QObject::connect(ui->buttonCosh,SIGNAL(clicked()),this,SLOT(coshPressed()));
    QObject::connect(ui->buttonTanh,SIGNAL(clicked()),this,SLOT(tanhPressed()));
    QObject::connect(ui->buttonLog,SIGNAL(clicked()),this,SLOT(logPressed()));
    QObject::connect(ui->buttonLn,SIGNAL(clicked()),this,SLOT(lnPressed()));
    QObject::connect(ui->buttonSWAP,SIGNAL(clicked()),this,SLOT(swapPressed()));
    QObject::connect(ui->buttonSUM,SIGNAL(clicked()),this,SLOT(sumPressed()));
    QObject::connect(ui->buttonMEAN,SIGNAL(clicked()),this,SLOT(meanPressed()));
    QObject::connect(ui->buttonDROP,SIGNAL(clicked()),this,SLOT(dropPressed()));
    QObject::connect(ui->buttonDUP,SIGNAL(clicked()),this,SLOT(dupPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::swapPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"SWAP");
}

void MainWindow::sumPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"SUM");
}

void MainWindow::meanPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"MEAN");
}

void MainWindow::dupPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"DUP");
}

void MainWindow::dropPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"DROP");
}

void MainWindow::entrerPressed()
{

}

void MainWindow::spacePressed()
{
     ui->inputLine->setText(ui->inputLine->text()+" ");
}

void MainWindow::clearPressed()
{

}

void MainWindow::retablirPressed()
{
    ui->inputLine->setText(memoire);
}

void MainWindow::plusPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"+");
}

void MainWindow::dimPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"-");
}

void MainWindow::multPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"*");
}

void MainWindow::divPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"/");
}

void MainWindow::num0Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"0");
//    ui->listWidget->addItem("0");
}

void MainWindow::num1Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"1");
//    ui->listWidget->addItem("1");
}

void MainWindow::num2Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"2");
//    ui->listWidget->addItem("2");
}

void MainWindow::num3Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"3");
//    ui->listWidget->addItem("3");

}

void MainWindow::num4Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"4");
//    ui->listWidget->addItem("4");
}

void MainWindow::num5Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"5");
//    ui->listWidget->addItem("5");
}

void MainWindow::num6Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"6");
//    ui->listWidget->addItem("6");
}

void MainWindow::num7Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"7");
//    ui->listWidget->addItem("7");
}

void MainWindow::num8Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"8");
//    ui->listWidget->addItem("8");
}

void MainWindow::num9Pressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"9");
//    ui->listWidget->addItem("9");
}

void MainWindow::pointPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+".");
}

void MainWindow::factPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"!");
}

void MainWindow::about()
 {
    QMessageBox message;
    message.setText("LO21_projet,ecrire par Han et Antoine");
    message.exec();
 }

void MainWindow::sinPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"sin");
}

void MainWindow::cosPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"cos");
}

void MainWindow::tanPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"tan");
}

void MainWindow::sinhPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"sinh");
}

void MainWindow::coshPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"cosh");
}

void MainWindow::tanhPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"tanh");
}

void MainWindow::logPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"log");
}

void MainWindow::lnPressed()
{
    ui->inputLine->setText(ui->inputLine->text()+"ln");
}




