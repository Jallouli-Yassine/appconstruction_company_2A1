#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(m->afficher());
    ui->nomLE->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->ReferenceLE_4->setValidator(new QIntValidator (0,999,this));
    ui->ReferenceLE_2->setValidator(new QIntValidator (0,9999,this));



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ButtonAjouter_2_clicked()
{
    QString reference=ui->ReferenceLE->text();
    QString nom=ui->nomLE->text();
    QString matricule=ui->MatriculeLE->text();
    QString idfournisseur="1";
    int quantite=ui->ReferenceLE_4->text().toInt();
    int prix=ui->ReferenceLE_2->text().toInt();
    int etat=1;
    materiel m(reference,nom,matricule,idfournisseur,quantite,prix,etat);
    bool test=m.ajouter();
    if(test)     {
         ui->tableView->setModel(m.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click to Cancel."), QMessageBox::Cancel);
    }     else
        QMessageBox::information(nullptr, QObject::tr("not OK"),
                                 QObject::tr("Ajout non effectué\n"
                                             "Click to Cancel."), QMessageBox::Cancel);

}

void MainWindow::on_ButtonSupprimer_clicked()
{

    QString reference=ui->lineEdit->text();

    bool test=m->supprimer(reference);

    if(test)
    {
        ui->tableView->setModel(m->afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectué\n"
                                             "Click Cancel to Exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("Suppression non effectué\n"
                                             "Click Cancel to Exit."),QMessageBox::Cancel);
}

void MainWindow::on_ButtonTri_clicked()
{
    ui->tableView->setModel(m->trie());
}

void MainWindow::on_ButtonAjouter_4_clicked()
{
    QString reference=ui->ReferenceLE->text();
    QString nom=ui->nomLE->text();
    QString matricule=ui->MatriculeLE->text();
    QString idfournisseur="1";
    int quantite=ui->ReferenceLE_4->text().toInt();
    int prix=ui->ReferenceLE_2->text().toInt();
    int etat=1;

   bool test =  m->modifier(reference,nom,matricule,idfournisseur,quantite,prix,etat);

    if(test){
        ui->tableView->setModel(m->afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("update effectué\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("update non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}
