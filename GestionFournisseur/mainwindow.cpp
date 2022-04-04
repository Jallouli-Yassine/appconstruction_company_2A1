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
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QProcess>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //constructeur de linterface main window :
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(F.stat());


    ui->tel->setValidator(new QIntValidator (0,99999999,this));
    ui->age->setValidator(new QIntValidator (0,100,this));
    ui->nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->email->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,10}@[a-z]{1,10}\\.[a-z]{1,4}")));

    ui->telUpdate->setValidator(new QIntValidator (0,99999999,this));
    ui->ageUpdate->setValidator(new QIntValidator (0,100,this));
    ui->nomUpdate->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->prenomUpdate->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->emailUpdate ->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,10}@[a-z]{1,10}\\.[a-z]{1,4}")));
    ui->updateID->setValidator(new QIntValidator (0,99999,this));
    ui->deleteID->setValidator(new QIntValidator (0,99999,this));
    ui->searchNameInput->setValidator(new QRegExpValidator(QRegExp("[A-z]*")));

    ui->Ftable->setModel(F.afficher());
    ui->Freview->setModel(F.afficher());
    ui->tabFacture->setModel(F.afficherFacture());
    //ui->Freview->setModel();
}


MainWindow::~MainWindow()
{
    delete ui;
}

///ajouter fournisseur
void MainWindow::on_ajouterF_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    QString telcheck = ui->tel->text();
    QString agecheck = ui->age->text();
    int tel = ui->tel->text().toInt();
    int age = ui->age->text().toInt();

    if(nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || telcheck.isEmpty() || agecheck.isEmpty())
    {
        QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                         QObject::tr("remplir tout les champs\n""Click to Cancel."), QMessageBox::Cancel);
    }else
    {
        Fournisseur F(age,tel,nom,prenom,email);
        bool test = F.ajouterF();


        if(test){
 ui->Freview->setModel(F.afficher());
            ui->Ftable->setModel(F.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Ajout effectué\n""Click to Cancel."),
                                     QMessageBox::Cancel);     }
        else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                     QObject::tr("Ajout non effectué\n""Click to Cancel."), QMessageBox::Cancel);
    }
}

///donner table fournisseur -> inputs
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

///supprimer fournisseur
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

///afficher table fournisseur
void MainWindow::on_LoadData_clicked()
{
   ui->Ftable->setModel(F.afficher());
}

///modifer fournisseur
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

///chercher fournisseurs
void MainWindow::on_chercherID_clicked()
{
    QString name = ui->searchNameInput->text();
    ui->searchTable->setModel(F.chercher(name));
}

///trie
void MainWindow::on_triBTN_clicked()
{
    QString attribute = ui->attributeBox->currentText();
    QString croissance = ui->croissanceBox->currentText();
    ui->TriTable->setModel(F.trie(attribute,croissance));
}

///vider la table fournisseur
void MainWindow::on_deleteAll_clicked()
{
    bool test = F.deleteAll();

    if(test){
        ui->Ftable->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("la table est vide !\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("suppression non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

///id fournisseur from table to input + afficher leur unique materielle dans tabMaterielle
void MainWindow::on_Freview_activated(const QModelIndex &index)
{
    QString value=ui->Freview->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from FOURNISSEUR where ID='"+value+"'");
            if(qry.exec())
            {
                while(qry.next()){
                   ui->reviewFID->setText(qry.value(0).toString()); //input id
                }
            }
            QString id = ui->reviewFID->text();
            qDebug()<< id;
            ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(id));//afficher materiaux de F choisix
}

///ajouter et modifier le review totale du F choisix
void MainWindow::on_postReview_clicked()
{
    QProcess *pro = new QProcess(this);
    QString time = ui->timeBox->currentText();
    QString communication = ui->commBox->currentText();
    QString qualite = ui->jawdaBox->currentText();
    QString id = ui->reviewFID->text();
    int review = F.calculReview(time,qualite,communication);
    QString r = QString::number(review);
    bool test = F.reviewF(time,qualite,communication,id);
    QString tel = "+21653522793";
    if(test){
        if(review>3)
        pro->startDetached("C:\\cygwin64\\bin\\mintty.exe", QStringList() << "/home/jallouli/sms.sh"<<tel<<r);
        //update review totale chaque ajout dun review
        F.reviewTotale(id);
        F.updateFinalReviewFrounisseur(id,F.reviewTotale(id));
        ui->Ftable->setModel(F.afficher());
        delete pro;
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("review added successfuly !\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("review non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

///refference,Prix (M choisix) -> inputs
void MainWindow::on_Tabmaterielle_activated(const QModelIndex &index)
{

    QString REFERENCE=ui->Tabmaterielle->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from MATERIEL where REFERENCE = '"+REFERENCE+"' ");
    if(qry.exec())
    {
        while(qry.next()){
           ui->reviewFIDMAteriele->setText(qry.value(2).toString());
           ui->prix->setText(qry.value(1).toString());
        }
    }
}

///ajouter M dans tab Facture
void MainWindow::on_ajouterIntoFacture_clicked()
{
    qDebug()<< "prix init :"<<prixTotale;
    QString id = ui->reviewFIDMAteriele->text();
    int prix = ui->prix->text().toInt();
    int quantite = ui->quantite->text().toInt();
    prixTotale+=(prix*quantite);
    qDebug()<< "prix :"<<prixTotale;
    F.ajouterIntFacture(id,prix,quantite);
    ui->tabFacture->setModel(F.afficherFacture());
    QString idF = ui->reviewFID->text();
    ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(idF));

}

///generer une facture pdf
void MainWindow::on_genererFacture_clicked()
{
    qDebug()<< "prix finale :"<< prixTotale;
    F.genererFacture(&prixTotale);
    ui->tabFacture->setModel(F.afficherFacture());
}
