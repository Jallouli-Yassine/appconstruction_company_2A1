#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tab_client->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    int num=ui->le_num->text().toInt();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    QString DDN=ui->le_DDN->text();

    Client c(num,nom,prenom,email,DDN);
    c.ajoute();



}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tab_client->setModel(c.afficher());

}

void MainWindow::on_pb_supp_clicked()
{
    Client c1;
    QString id =ui->le_id_supp->text();
    bool test=c1.supprimer(id);
    if(test)
    {
        ui->tab_client->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("SUPRIMER EFFECTUER"),
                    QObject::tr("votre element à ete supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("SUPRIMER NON EFFECTUER"),
                    QObject::tr("votre element n'est pas ete supprimer .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
