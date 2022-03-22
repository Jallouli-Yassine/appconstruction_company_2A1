#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>

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
    QString reference=ui->ReferenceLE_3->text();
    QString nom=ui->nomLE_2->text();
    QString matricule=ui->MatriculeLE_2->text();
    QString idfournisseur="1";
    int quantite=ui->ReferenceLE_6->text().toInt();
    int prix=ui->ReferenceLE_5->text().toInt();
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

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString value=ui->tableView->model()->data(index).toString();
                QSqlQuery qry;
                qry.prepare("select * from MATERIEL where REFERENCE='"+value+"'");
                if(qry.exec())
                {
                    while(qry.next()){
                       ui->ReferenceLE_3->setText(qry.value(2).toString());
                       ui->nomLE_2->setText(qry.value(4).toString());
                       ui->MatriculeLE_2->setText(qry.value(3).toString());
                       ui->ReferenceLE_6->setText(qry.value(7).toString());
                       //ui->comboBox_3->setText(qry.value(3).toString());
                       ui->ReferenceLE_5->setText(qry.value(1).toString());

                    }
                }
}




void MainWindow::on_Buttonrecherche_clicked()
{
    QString rech= ui->recherche->text();

    ui->tableView->setModel(m->chercher(rech));
}

void MainWindow::on_PDF_clicked()
{
    QPrinter printer;

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setOutputFileName("C:/2A1/materielpdf/materiel.pdf");

                   QPainter painter;
                   painter.begin(&printer);
                   QFont font("Times", 10, QFont::Bold);
                   QString nom=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString();
                   QString referance=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString();
                   QString quantite=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString();
                   QString etat=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toString();
                   QString prix=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString();
                   QString matricule=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString();

                   font.setPixelSize(35);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(260,100,"Fiche Matériel");

                   font.setPixelSize(30);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(100,300,"Nom :");

                   painter.drawText(100,400,"Référence :");

                   painter.drawText(100,500,"Quantité:");
                   painter.drawText(100,600,"Etat:");
                   painter.drawText(100,700,"Prix:");
                   painter.drawText(100,800,"Matricule:");



                   font.setPixelSize(22);
                   painter.setFont(font);
                   painter.setPen(Qt::black);
                   painter.drawText(500,300,nom);
                   painter.drawText(500,400,referance);
                   painter.drawText(500,500,quantite);
                   painter.drawText(500,600,etat);
                   painter.drawText(500,700,prix);
                   painter.drawText(500,800,matricule);




                   if(painter.end())
                   {
                       QMessageBox::information(nullptr, QObject::tr("FICHE EMPLOYEE"),
                                                QObject::tr("Fichier employee GenerÃ©.\n"
                                                            "Click Ok to exit."), QMessageBox::Ok);
                   }
}
