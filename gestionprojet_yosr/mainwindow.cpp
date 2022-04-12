#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include <QChar>
//PDF//
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
//PDF//put chart in widget qt
#include <QSqlRecord>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->verticalLayout_8->addWidget(ptmp->stat());
    ui->tableView->setModel(ptmp->afficher());
    ui->tableView_3->setModel(ptmp->afficher_C1());
    ui->tableView_4->setModel(ptmp->afficher_C2());
    ui->tableView_5->setModel(ptmp->afficher_C3());
    ui->tableView_2->setModel(ptmp->afficher_archive());
    ui->lineEdit_p->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_id->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_a->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")  ));
    int ret=A.connect_arduino();

        switch (ret) {
        case 0 :
            qDebug()<<"Arduino is available and connected to : "<<A.getarduino_port_name();
            break;

        case 1 :
            qDebug()<<"Arduino is available but not connected to : "<<A.getarduino_port_name();
            break;
        case -1 :
            qDebug()<<"Arduino is not available ";
            break;
        }

        data=A.read_from_arduino();
        qDebug()<<data;
        A.write_to_arduino("a");
        qDebug()<<data;




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
        delete ptmp->stat();
        ui->verticalLayout_8->addWidget(ptmp->stat());
        ui->tableView->setModel(ptmp->afficher());
        ui->tableView_3->setModel(ptmp->afficher_C1());
        ui->tableView_4->setModel(ptmp->afficher_C2());
        ui->tableView_5->setModel(ptmp->afficher_C3());
        ui->tableView_2->setModel(ptmp->afficher_archive());
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


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(ptmp->afficherrech(arg1));
    qDebug()<<arg1;
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->tableView->setModel(ptmp->affichertrie(index));
    qDebug()<<index;
}



void MainWindow::on_pushButton_2_clicked()
{
    QString localisation=ui->lineEdit_a->text();
    QString idarchitecte=ui->lineEdit_id->text();
    QString reference=ui->lineEdit_r->text();
    QString prix_totale=ui->lineEdit_p->text();
    QString date_start=ui->dateEdit->date().toString("MM-dd-yyyy");
    Projet p(localisation,idarchitecte,reference,prix_totale,date_start);
    bool test=p.ajouter();
    if(test)     {
        delete ptmp->stat();
        ui->verticalLayout_8->addWidget(ptmp->stat());
        ui->tableView->setModel(ptmp->afficher());
        ui->tableView_3->setModel(ptmp->afficher_C1());
        ui->tableView_4->setModel(ptmp->afficher_C2());
        ui->tableView_5->setModel(ptmp->afficher_C3());
        ui->tableView_2->setModel(ptmp->afficher_archive());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click to Cancel."), QMessageBox::Cancel);
    }     else
        QMessageBox::information(nullptr, QObject::tr("not OK"),
                                                QObject::tr("Ajout non effectué\n"
                                                            "Click to Cancel."), QMessageBox::Cancel);
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString value=ui->tableView->model()->data(index).toString();
                QSqlQuery qry;
                qry.prepare("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET WHERE IDPROJET='"+value+"'");
                if(qry.exec())
                {
                    while(qry.next())
                    {
                       ui->lineEdit_a->setText(qry.value(2).toString());
                       ui->lineEdit_id->setText(qry.value(3).toString());
                       ui->lineEdit_p->setText(qry.value(1).toString());
                       ui->lineEdit_r->setText(qry.value(4).toString());
                       ui->lineEdit_p_2->setText(qry.value(0).toString());
                    }
                }

}

void MainWindow::on_pushButton_archive_clicked()
{
    QString localisation = ui->lineEdit_a->text();
    int idprojet = ui->lineEdit_p_2->text().toInt();
    QString idarchitecte = ui->lineEdit_id->text();
    QString reference = ui->lineEdit_r->text();
    QString prix_totale = ui->lineEdit_p->text();
   bool test =  ptmp->archiver(idprojet,localisation,idarchitecte,reference,prix_totale,1);
   ui->tableView->setModel(ptmp->afficher());
   ui->tableView_2->setModel(ptmp->afficher_archive());
    if(test){

        ui->verticalLayout_8->addWidget(ptmp->stat());
        ui->tableView->setModel(ptmp->afficher());
        ui->tableView_3->setModel(ptmp->afficher_C1());
        ui->tableView_4->setModel(ptmp->afficher_C2());
        ui->tableView_5->setModel(ptmp->afficher_C3());
        ui->tableView_2->setModel(ptmp->afficher_archive());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("Projet Archiver\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("Oups\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_pushremove_clicked()
{
    QString localisation = ui->lineEdit_a_3->text();
    int idprojet = ui->lineEdit_a_ID->text().toInt();
    QString idarchitecte = ui->lineEdit_id_3->text();
    QString reference = ui->lineEdit_r_3->text();
    QString prix_totale = ui->lineEdit_p_4->text();
   bool test =  ptmp->archiver_reverse(idprojet,localisation,idarchitecte,reference,prix_totale,0);
   ui->tableView->setModel(ptmp->afficher());
   ui->tableView_2->setModel(ptmp->afficher_archive());
    if(test){
        ui->verticalLayout_8->addWidget(ptmp->stat());
        ui->tableView->setModel(ptmp->afficher());
        ui->tableView_3->setModel(ptmp->afficher_C1());
        ui->tableView_4->setModel(ptmp->afficher_C2());
        ui->tableView_5->setModel(ptmp->afficher_C3());
        ui->tableView_2->setModel(ptmp->afficher_archive());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("Projet Archiver\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("Oups\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString value=ui->tableView_2->model()->data(index).toString();
                QSqlQuery qry;
                qry.prepare("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET WHERE IDPROJET='"+value+"'");
                if(qry.exec())
                {
                    while(qry.next())
                    {
                       ui->lineEdit_a_3->setText(qry.value(2).toString());
                       ui->lineEdit_id_3->setText(qry.value(3).toString());
                       ui->lineEdit_p_4->setText(qry.value(1).toString());
                       ui->lineEdit_r_3->setText(qry.value(4).toString());
                       ui->lineEdit_a_ID->setText(qry.value(0).toString());
                    }
                }
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString value=ui->tableView->model()->data(index).toString();

    qDebug()<<value;
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    qDebug()<<date;
}



void MainWindow::on_pushPDF_clicked()
{
    QPrinter printer;
                  printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setOutputFileName("C:/Users/ibert/OneDrive/Bureau/GitHub/xd.pdf");
                  QPainter painter;
                  painter.begin(&printer);
                  QFont font("Times", 10, QFont::Bold);
                  QFont font2("Times", 10, QFont::Bold);
                  int rows = ui->tableView_3->model()->rowCount();
                  int rows1 = ui->tableView_4->model()->rowCount();
                  int rows2 = ui->tableView_5->model()->rowCount();
                  int x = 0;
                  int y = 100;
                  //HEADER//
                  font.setPixelSize(20);
                  painter.setFont(font);
                  painter.setPen(Qt::black);
                  //HEADER END//

                  for (int i=0;i<rows;i++) {

                      QString id=ui->tableView_3->model()->data(ui->tableView_3->model()->index(i,0)).toString();
                      QString date=ui->tableView_3->model()->data(ui->tableView_3->model()->index(i,1)).toString();
                      painter.drawText(x+50,y+20,"This month project : ID : "+id+"/   Date : "+date);
                      y+=100;
                  }
                  for (int i=0;i<rows1;i++) {
                      QString id=ui->tableView_4->model()->data(ui->tableView_4->model()->index(i,0)).toString();
                      QString date=ui->tableView_4->model()->data(ui->tableView_4->model()->index(i,1)).toString();
                      painter.drawText(x+50,y+20,"Next month project : ID : "+id+"/   Date : "+date);
                      y+=100;
                  }
                  for (int i=0;i<rows2;i++) {
                      QString id=ui->tableView_5->model()->data(ui->tableView_5->model()->index(i,0)).toString();
                      QString date=ui->tableView_5->model()->data(ui->tableView_5->model()->index(i,1)).toString();
                      painter.drawText(x+50,y+20,"Next Year project : ID : "+id+"/   Date : "+date);
                      y+=100;
                  }



                  if(painter.end())
                  {
                      QMessageBox::information(nullptr, QObject::tr("FICHE PROJET"),
                                               QObject::tr("Fichier employee Generer.\n"
                                                           "Click Ok to exit."), QMessageBox::Ok);
                  }
}

void MainWindow::on_Chart_clicked()
{

}


void MainWindow::on_pushButton_on_clicked()
{
    A.write_to_arduino("1");
    qDebug()<<A.read_from_arduino();
}

void MainWindow::on_pushButton_off_clicked()
{
    A.write_to_arduino("0");
    qDebug()<<A.read_from_arduino();
}

void MainWindow::on_pushButton_plus_clicked()
{
    A.write_to_arduino("2");
    qDebug()<<A.read_from_arduino();
}

void MainWindow::on_pushButton_minus_clicked()
{
    A.write_to_arduino("3");
    qDebug()<<A.read_from_arduino();
}
