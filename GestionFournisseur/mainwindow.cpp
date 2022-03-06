#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QDebug>
#include <QSqlQueryModel>
#include <qtablewidget.h>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //constructeur de linterface main window :
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tel->setValidator(new QIntValidator (0,99999999,this));
    ui->age->setValidator(new QIntValidator (0,99999999,this));
    ui->Ftable->setModel(F.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouterF_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    int tel = ui->tel->text().toInt();
    int age = ui->age->text().toInt();

    Fournisseur F(age,tel,nom,prenom,email);
    bool test = F.ajouterF();
    ui->Ftable->setModel(F.afficher());
    if(test){
        ui->Ftable->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("Ajout effectué\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("Ajout non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_deleteFbtn_clicked()
{
    int id = ui->deleteID->text().toInt();

        bool test =  F.supprimer(id);

          if(test){
              ui->Ftable->setModel(F.afficher());
              QMessageBox::information(nullptr, QObject::tr("OK"),
              QObject::tr("suppression effectué\n""Click to Cancel."),
                                       QMessageBox::Cancel);     }
          else         QMessageBox::critical(nullptr, QObject::tr("not OK"),
                       QObject::tr("suppression non effectué\n" "Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_LoadData_clicked()
{
   ui->Ftable->setModel(F.afficher());
}

void MainWindow::on_updateBTN_clicked()
{
    QString nom = ui->nomUpdate->text();
    //qDebug()<< nom ;
    QString prenom = ui->prenomUpdate->text();
    QString email = ui->emailUpdate->text();
    int tel = ui->telUpdate->text().toInt();
    int age = ui->ageUpdate->text().toInt();
    int id = ui->updateID->text().toInt();

   bool test =  F.modifier(id,nom,prenom,age,tel,email);

    if(test){
        ui->Ftable->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("update effectué\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("update non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_chercherID_clicked()
{
    QString id = ui->searchIDinput->text();
    ui->searchTable->setModel(F.chercher(id));
}

void MainWindow::on_triBTN_clicked()
{
    QString attribute = ui->attributeBox->currentText();
    QString croissance = ui->croissanceBox->currentText();
    ui->TriTable->setModel(F.trie(attribute,croissance));
}

void MainWindow::on_Ftable_activated(const QModelIndex &index)
{
    QString value=ui->Ftable->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from FOURNISSEUR where ID='"+value+"'");
            if(qry.exec())
            {
                while(qry.next()){
                   ui->nomUpdate->setText(qry.value(1).toString());
                   ui->prenomUpdate->setText(qry.value(2).toString());
                   ui->emailUpdate->setText(qry.value(5).toString());
                   ui->telUpdate->setText(qry.value(4).toString());
                   ui->ageUpdate->setText(qry.value(3).toString());
                   ui->updateID->setText(qry.value(0).toString());
                   ui->deleteID->setText(qry.value(0).toString());
                }
            }
}
