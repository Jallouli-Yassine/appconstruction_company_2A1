#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include "qtablewidget.h"
#include<QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(100, 9999999, this));
    ui->le_salaire->setValidator(new QIntValidator(100, 7000, this));
    ui->tabemp->setModel(E.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    QString id=ui->le_id->text();
    int cin=ui->le_cin->text().toUInt();
    int nbh=0;

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString type=ui->le_role->text();

    float salaire=ui->le_salaire->text().toFloat();
    employee E(nom,prenom,type,id,nbh,cin,salaire);

    bool test=E.ajouter();
    if(test)
    {
        ui->tabemp->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("OK"),QObject::tr("Ajout non effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }







}

void MainWindow::on_supprimer_clicked()
{
    QString id =ui->supp_id->text();
    bool test=E.supprimer(id);
    if(test)
    {
        ui->tabemp->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Supprission effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("OK"),QObject::tr("Suppression non effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }



}



void MainWindow::on_modifier_clicked()
{

    QString id=ui->id_mod->text();
    int cin=ui->cin_mod->text().toUInt();

    QString nom=ui->name_mod->text();
    QString prenom=ui->prenom_mod->text();
    QString type=ui->role_mod->text();

    float salaire=ui->salaire_mod->text().toFloat();

    bool test=E.modifier(id,nom,prenom,type,cin,salaire);
    if(test)
    {
        ui->tabemp->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("OK"),QObject::tr("Modification non effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }





}
