#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->tab_client->setModel(c.afficher());
    ui->tab_client_4->setModel(c.afficher());
ui->le_id->setValidator(new QIntValidator (1,99999999,this));
ui->le_id_2->setValidator(new QIntValidator (1,99999999,this));
ui->le_num->setValidator(new QIntValidator (20000000,99999999,this));
ui->le_num_2->setValidator(new QIntValidator (20000000,99999999,this));
ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
ui->le_nom_2->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
ui->le_prenom_2->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));

ui->le_email->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,19}@[a-z]{1,9}\\.[a-z]{1,4}")  ));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_b_ajouter_clicked()
{
    if ((ui->le_id->text().isEmpty()) || (ui->le_nom->text().isEmpty()) || (ui->le_prenom->text().isEmpty()) || (ui->le_num->text().isEmpty()) || (ui->le_email->text().isEmpty()) || (ui->le_DDN->text().isEmpty()) )
    {
        QMessageBox::critical(this, tr("Erreur"), tr(" IL FAUT REMPLIRE TOUT LES CHAMPS !!!"));
    }
else {
    QString nom=ui->le_nom->text();
    int num=ui->le_num->text().toInt();
    int id=ui->le_id->text().toInt();

    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    QString DDN=ui->le_DDN->text();

    Client c(num,id,nom,prenom,email,DDN);
    c.ajoute();}



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



void MainWindow::on_pb_trienom_clicked()
{
    ui->tab_client->setModel(c.affichenom());

}

void MainWindow::on_pb_trie_prenom_clicked()
{
    ui->tab_client->setModel(c.afficheprenom());

}

void MainWindow::on_pb_tri_id_clicked()
{
    ui->tab_client->setModel(c.afficheid());

}



void MainWindow::on_cherch_textChanged(const QString &arg1)
{QString cherche= ui->cherch->text();

    ui->tab_client_3->setModel(c.rechercheid(cherche));

}

void MainWindow::on_cherch_2_returnPressed()
{

}

void MainWindow::on_b_ajouter_2_clicked()
{
    if ((ui->le_id_2->text().isEmpty()) && (ui->le_nom_2->text().isEmpty()) && (ui->le_prenom_2->text().isEmpty()) && (ui->le_num_2->text().isEmpty()) && (ui->le_email_2->text().isEmpty()) && (ui->le_DDN_2->text().isEmpty()) )
    {
        QMessageBox::critical(this, tr("Erreur"), tr(" IL FAUT REMPLIRE TOUT LES CHAMPS !!!"));
    }
    else {
    QString nom=ui->le_nom_2->text();
    int num=ui->le_num_2->text().toInt();
    int id=ui->le_id_2->text().toInt();

    QString prenom=ui->le_prenom_2->text();
    QString email=ui->le_email_2->text();
    QString DDN=ui->le_DDN_2->text();

    Client c(num,id,nom,prenom,email,DDN);
    c.modifier(num,id,nom,prenom,email,DDN);
    ui->tab_client_4->setModel(c.afficher());
    }
}
