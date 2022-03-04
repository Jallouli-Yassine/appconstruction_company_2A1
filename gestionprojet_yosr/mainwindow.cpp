#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView->setModel(ptmp->afficher());
    ui->lineEdit_id->setValidator(new QIntValidator (0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_5_clicked()
{

    int id=ui->lineEdit_p_2->text().toInt();

    bool test=ptmp->supprimer(id);

    if(test)
    {
        ui->tableView->setModel(ptmp->afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectué\n"
                                             "Click Cancel to Exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("Suppression non effectué\n"
                                             "Click Cancel to Exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView->setModel(ptmp->afficher());
}


/*void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(ptmp->afficherrech(arg1.toInt()));
}*/



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->tableView->setModel(ptmp->affichertrie(index));
    qDebug()<<index;
}

void MainWindow::on_pushButtonU_clicked()
{
    QString localisation = ui->lineEdit_a->text();
    QString idarchitecte = ui->lineEdit_id->text();
    QString reference = ui->lineEdit_r->text();
    QString prix_totale = ui->lineEdit_p->text();
   bool test =  ptmp->modifier(localisation,idarchitecte,reference,prix_totale);

    if(test){
        ui->tableView->setModel(ptmp->afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("update effectué\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("update non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString localisation=ui->lineEdit_a->text();
    QString idarchitecte=ui->lineEdit_id->text();
    QString reference=ui->lineEdit_r->text();
    QString prix_totale=ui->lineEdit_p->text();
    Projet p(localisation,idarchitecte,reference,prix_totale);
    p.ajouter();
    bool test=p.ajouter();
    if(test)     {
         ui->tableView->setModel(ptmp->afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click to Cancel."), QMessageBox::Cancel);
    }     else
        QMessageBox::information(nullptr, QObject::tr("not OK"),
                                                QObject::tr("Ajout non effectué\n"
                                                            "Click to Cancel."), QMessageBox::Cancel);
}
