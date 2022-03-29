#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include "qtablewidget.h"
#include<QObject>
#include<fstream>
#include<vector>
#include<QFileDialog>
#include<QPixmap>
#include<QPainter>
#include<QtSvg/QSvgRenderer>

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
    ui->le_cin->setValidator(new QIntValidator(100, 999999, this));
    ui->le_salaire->setValidator(new QIntValidator(100, 7000, this));

    ui->tabemp->setModel(E.afficher());

    ui->salaire_mod->setValidator(new QIntValidator(100, 7000, this));
    ui->cin_mod->setValidator(new QIntValidator(100, 999999, this));
    ui->role_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->name_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->prenom_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_role->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));



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

void MainWindow::on_chercher_clicked()
{
    ui->tabemp->setModel(E.chercher(ui->chercher_id->text()));

}



void MainWindow::on_tri_activated(const QString &arg1)
{
    QString attribute = ui->tri->currentText();
    ui->tabemp->setModel(E.tri(attribute));

}





void MainWindow::on_QR_clicked()
{
    if(ui->tabemp->currentIndex().row()==-1)
                    QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                             QObject::tr("Veuillez Choisir un client du Tableau.\n"
                                                         "Click Ok to exit."), QMessageBox::Ok);
                else
                {

    QString id=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),0)).toString();

    using namespace qrcodegen;
      // Create the QR Code object
      QrCode qr = QrCode::encodeText( id.toUtf8().data(), QrCode::Ecc::MEDIUM );
      qint32 sz = qr.getSize();
      QImage im(sz,sz, QImage::Format_RGB32);
        QRgb black = qRgb( 241, 196, 15);
        QRgb white = qRgb(255,255,255);
      for (int y = 0; y < sz; y++)
        for (int x = 0; x < sz; x++)
          im.setPixel(x,y,qr.getModule(x, y) ? black : white );
      ui->label_qr->setPixmap( QPixmap::fromImage(im.scaled(60,60,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
            }

}

void MainWindow::on_pdf_clicked()
{
    QPrinter printer;

                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("C:/qtpdf/employee.pdf");

               QPainter painter;
               painter.begin(&printer);
               QFont font("Times", 10, QFont::Bold);
               QString id=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),0)).toString();
               QString nom=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),2)).toString();
               QString prenom=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),3)).toString();
               QString cin=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),1)).toString();
               QString role=ui->tabemp->model()->data(ui->tabemp->model()->index(ui->tabemp->currentIndex().row(),5)).toString();


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
               painter.drawText(100,600,"CIN:");
               painter.drawText(100,700,"ROLE:");



               font.setPixelSize(22);
               painter.setFont(font);
               painter.setPen(Qt::black);
               painter.drawText(500,300,id);
               painter.drawText(500,400,nom);
               painter.drawText(500,500,prenom);
               painter.drawText(500,600,cin);
               painter.drawText(500,700,role);



               if(painter.end())
               {
                   QMessageBox::information(nullptr, QObject::tr("FICHE EMPLOYEE"),
                                            QObject::tr("Fichier employee Generé.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
               }

}

void MainWindow::on_tabemp_activated(const QModelIndex &index)
{
    QString id=ui->tabemp->model()->data(index).toString();
    E.calculeprime(id);
    ui->tabemp->setModel(E.afficher());

}
