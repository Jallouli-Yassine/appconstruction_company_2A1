#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "architect.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQueryModel>
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
 #include <QPrintDialog>
#include <QFile>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <QAxObject>
#include <QAxWidget>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include<iostream>
#include <QApplication>
#include <QCoreApplication>
#include "smtp.cpp"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
     ui->verticalLayout->addWidget(A.stat());
    ui->id->setValidator(new QIntValidator(0,9999999, this));
    ui->ntel->setValidator(new QIntValidator(0,9999999, this));
    ui->nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
   ui->email->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,10}@[a-z]{1,4}\\.[a-z]{1,4}")  ));

ui->education->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::on_ajouter_clicked()
{

    int id=ui->id->text().toInt();
     QMessageBox msgBox;
    QString nom =ui->nom->text();
    QString prenom =ui->prenom->text();
    int ntel=ui->ntel->text().toInt();
    QString email =ui->email->text();
        QString etat =ui->comboBox->currentText();
    Architect A(id,nom,prenom,ntel,email,etat);

    if((ui->id->text().isEmpty())||(ui->nom->text().isEmpty())||(ui->prenom->text().isEmpty())||(ui->ntel->text().isEmpty())||(ui->email->text().isEmpty()))
    {
 msgBox.setText("echec:remplir tous les inputs ");

 msgBox.exec();
 return;
}
    bool test=A.ajouter();
    if(test)
    {

 msgBox.setText("ajouter succes");
}
    else
      msgBox.setText("echec d'ajouter ");
    msgBox.exec();
ui->education->setModel(A.afficher());
}

void MainWindow::on_supprimer_clicked()
{
    QMessageBox msgBox;

    A.setid(ui->idd->text().toInt());
   bool test=A.supprimer(A.getid());
   if(test)
     msgBox.setText("suppression succes");
   else
      msgBox.setText("Echec de suppression");
    msgBox.exec();
ui->education->setModel(A.afficher());
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox;

        int id = ui->id_2->text().toInt();
        QString nom = ui->nom_2->text();
        QString prenom = ui->prenom_2->text();
        int ntel = ui->ntel_2->text().toInt();
        QString email = ui->email_2->text();
         QString etat = ui->comboBox_2->currentText();
        bool test =  A.modifier(id,nom,prenom,ntel,email,etat);

        if(test)
          msgBox.setText("modifier succes");
        else
           msgBox.setText("Echec de modification");
         msgBox.exec();
     ui->education->setModel(A.afficher());
}


void MainWindow::on_pushButtonrechdech_2_clicked()
{
    QMessageBox msgBox;
        QString nom = ui->lineEdit_2->text();
      ui->education->setModel(A.chercher(nom));

}



/*void MainWindow::on_EnregistrerPB_3_clicked()
{
    QPrinter printer;

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setOutputFileName("C:/Users/Bayoudh Mohamed/Desktop/bouxhib/archittect.pdf");

                   QPainter painter;
                   painter.begin(&printer);
                   QFont font("Times", 10, QFont::Bold);
                   QString id=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),0)).toString();
                   QString nom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),1)).toString();
                   QString prenom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),2)).toString();
                   QString mail=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),4)).toString();
                   QString ntel=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),3)).toString();


                   font.setPixelSize(35);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(260,100,"Fiche employee");

                   font.setPixelSize(30);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(100,300,"ID :");

                   painter.drawText(100,400,"NOM :");

                   painter.drawText(100,500,"PRENOM:");
                   painter.drawText(100,600,"MAIL:");
                   painter.drawText(100,700,"NTEL:");



                   font.setPixelSize(22);
                   painter.setFont(font);
                   painter.setPen(Qt::black);
                   painter.drawText(500,300,id);
                   painter.drawText(500,400,nom);
                   painter.drawText(500,500,prenom);
                   painter.drawText(500,600,mail);
                   painter.drawText(500,700,ntel);



                   if(painter.end())
                   {
                       QMessageBox::information(nullptr, QObject::tr("FICHE EMPLOYEE"),
                                                QObject::tr("Fichier employee GenerÃ©.\n"
                                                            "Click Ok to exit."), QMessageBox::Ok);
                   }
}*/



void MainWindow::on_pdf_clicked()
{
    QPrinter printer;
                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setOutputFileName("C:/Users/Bayoudh Mohamed/Desktop/bouxhib/archittect.pdf");
                   QPainter painter;
                   painter.begin(&printer);
                   QFont font("Times", 10, QFont::Bold);
                   QString id=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),0)).toString();
                   QString nom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),1)).toString();
                   QString prenom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),2)).toString();
                   QString ntel=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),3)).toString();
                   QString mail=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),4)).toString();
                    QString etat=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),5)).toString();
                   font.setPixelSize(35);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(260,100,"Fiche employee");
                   font.setPixelSize(30);
                   painter.setFont(font);
                   painter.setPen(Qt::red);
                   painter.drawText(100,300,"ID :");
                   painter.drawText(100,400,"NOM :");
                   painter.drawText(100,500,"PRENOM:");
                   painter.drawText(100,600,"MAIL:");
                   painter.drawText(100,700,"NTEL:");
                   painter.drawText(100,800,"ETAT:");
                   font.setPixelSize(22);
                   painter.setFont(font);
                   painter.setPen(Qt::black);
                   painter.drawText(500,300,id);
                   painter.drawText(500,400,nom);
                   painter.drawText(500,500,prenom);
                   painter.drawText(500,600,mail);
                   painter.drawText(500,700,ntel);
                   painter.drawText(500,800,etat);
                   if(painter.end())
                   {
                       QMessageBox::information(nullptr, QObject::tr("FICHE EMPLOYEE"),
                                                QObject::tr("Fichier employee GenerÃ©.\n"
                                                            "Click Ok to exit."), QMessageBox::Ok);
                   }
}

void MainWindow::on_excel_clicked()
{
    QAxObject* excel = new QAxObject("Excel.Application", 0);
    excel->dynamicCall("SetVisible(bool)", true);
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", "C:/Users/Bayoudh Mohamed/Desktop/bouxhib/a.xlsx");
    QAxObject* worksheet = workbook->querySubObject("Worksheets(int)", 1);
    QAxObject* usedrange = worksheet->querySubObject("UsedRange");
    QAxObject* rows = usedrange->querySubObject("Rows");
    QAxObject* columns = usedrange->querySubObject("Columns");

    QString id=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),0)).toString();
    QString nom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),1)).toString();
    QString prenom=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),2)).toString();
      QString ntel=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),3)).toString();
    QString mail=ui->education->model()->data(ui->education->model()->index(ui->education->currentIndex().row(),4)).toString();
    QAxObject* cell;

            cell = excel->querySubObject("Cells(Int, Int)", 1, 1);

            QVariant cellValue = cell->dynamicCall("value");
            qDebug() << cellValue.toString();
            cell->setProperty("Value", "ID");

     cell = excel->querySubObject("Cells(Int, Int)", 1, 2);
     cell->setProperty("Value", "NOM");
     cell = excel->querySubObject("Cells(Int, Int)", 1, 3);
     cell->setProperty("Value", "PRENOM");
     cell = excel->querySubObject("Cells(Int, Int)", 1, 4);
     cell->setProperty("Value", "NTEL");
     cell = excel->querySubObject("Cells(Int, Int)", 1, 5);
     cell->setProperty("Value", "MAIL");
     cell = excel->querySubObject("Cells(Int, Int)", 2, 1);
     cell->setProperty("Value", id);
     cell = excel->querySubObject("Cells(Int, Int)", 2, 2);
     cell->setProperty("Value", nom);
     cell = excel->querySubObject("Cells(Int, Int)", 2, 3);
     cell->setProperty("Value",prenom);
     cell = excel->querySubObject("Cells(Int, Int)", 2, 4);
     cell->setProperty("Value", ntel);
     cell = excel->querySubObject("Cells(Int, Int)", 2, 5);
     cell->setProperty("Value", mail);

}


void MainWindow::on_pushButtonAfficherDech_2_clicked()
{
    QString attribute = ui->comboBox_tripar_2->currentText();
    QString croissance = ui->comboBox_typetri_2->currentText();
   // qDebug()<< attribute ;
 //   qDebug()<< croissance ;
    ui->education->setModel(A.trie(attribute,croissance));
}


