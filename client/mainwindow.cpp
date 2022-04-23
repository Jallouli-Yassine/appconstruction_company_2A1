#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QProcess>
#include "login2.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->verticalLayout->addWidget(c.stat());
    ui->tab_client_pdf->setModel(c.afficher());
    ui->tab_client_r->setModel(c.afficherrdv());
    ui->tab_client_2->setModel(c.afficher());
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

void MainWindow::on_tab_client_4_activated(const QModelIndex &index)
{
    QString value=ui->tab_client_4->model()->data(index).toString();
                QSqlQuery qry;
                qry.prepare("select * from CLIENT where IDCLIENT='"+value+"'");
                if(qry.exec())
                {
                    while(qry.next()){
                       ui->le_nom_2->setText(qry.value(0).toString());
                       ui->le_prenom_2->setText(qry.value(1).toString());
                       ui->le_id_2->setText(qry.value(2).toString());
                       ui->le_num_2->setText(qry.value(3).toString());
                       ui->le_email_2->setText(qry.value(4).toString());

                    }
                }
}

void MainWindow::on_pushButton_insertbutton_clicked()
{

QString id = ui->le_idr->text();
QString date = ui->date_rdv->text();

QSqlQuery qry;
qry.prepare("select DATERDV from RDV where DATERDV='"+date+"'");
if(qry.exec())
{
    QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                QObject::tr("il existe deja un rendez-vous\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else{
c.ajoutrdv(date,id);
}


}

void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter printer;

                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setOutputFileName("D:/2A1/client.pdf");

                       QPainter painter;
                       painter.begin(&printer);
                       QFont font("Times", 10, QFont::Bold);
                       QString nom=ui->tab_client_pdf->model()->data(ui->tab_client_pdf->model()->index(ui->tab_client_pdf->currentIndex().row(),0)).toString();
                       QString prenom=ui->tab_client_pdf->model()->data(ui->tab_client_pdf->model()->index(ui->tab_client_pdf->currentIndex().row(),1)).toString();
                       QString numero=ui->tab_client_pdf->model()->data(ui->tab_client_pdf->model()->index(ui->tab_client_pdf->currentIndex().row(),3)).toString();
                       QString email=ui->tab_client_pdf->model()->data(ui->tab_client_pdf->model()->index(ui->tab_client_pdf->currentIndex().row(),4)).toString();
                       QString DDN=ui->tab_client_pdf->model()->data(ui->tab_client_pdf->model()->index(ui->tab_client_pdf->currentIndex().row(),5)).toString();

                       font.setPixelSize(35);
                       painter.setFont(font);
                       painter.setPen(Qt::red);
                       painter.drawText(260,100,":");

                       font.setPixelSize(30);
                       painter.setFont(font);
                       painter.setPen(Qt::red);
                       painter.drawText(100,300,"nom :");
                       painter.drawText(100,400,"prenom :");

                       painter.drawText(100,500,"numero:");
                       painter.drawText(100,600,"email:");
                       painter.drawText(100,700,"date de naissance:");






                       font.setPixelSize(22);
                       painter.setFont(font);
                       painter.setPen(Qt::black);
                       painter.drawText(500,300,nom);
                       painter.drawText(500,400,prenom);
                       painter.drawText(500,500,numero);
                       painter.drawText(500,600,email);
                       painter.drawText(500,700,DDN);





                       if(painter.end())
                       {
                           QMessageBox::information(nullptr, QObject::tr("FICHE CLIENT "),
                                                    QObject::tr("fiche client GenerÃ©.\n"
                                                                "Click Ok to exit."), QMessageBox::Ok);
                       }
}


