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
    QString name = ui->searchNameInput->text();
    ui->searchTable->setModel(F.chercher(name));
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

void MainWindow::on_Freview_activated(const QModelIndex &index)
{
    QString value=ui->Freview->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from FOURNISSEUR where ID='"+value+"'");
            if(qry.exec())
            {
                while(qry.next()){
                   ui->reviewFID->setText(qry.value(0).toString());
                }
            }

            QString id = ui->reviewFID->text();
            qDebug()<< id;
            ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(id));
}


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
        //QProcess::startDetached("C:\\cygwin64\\bin\\mintty.exe", QStringList() << "/home/jallouli/sms.sh"<<tel<<r);
        //update review totale chaque ajout dun review
        F.reviewTotale(id);
        F.updateFinalReviewFrounisseur(id,F.reviewTotale(id));
        ui->Ftable->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("review added successfuly !\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("review non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

/*
void MainWindow::on_reviewFIDMAteriele_textEdited(const QString &arg1)
{

}


void MainWindow::on_genererM_clicked()
{
     QString id = ui->reviewFID->text();
     qDebug()<< id;
     ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(id));
}
*/

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
int prixTotale = 0;
void MainWindow::on_genererFacture_clicked()
{

    QTableView table_facture;
        QSqlQueryModel * Mod=new  QSqlQueryModel();
        //QString value=ui->reviewFID->text();

             QSqlQuery qry;

             qry.prepare("select * from FACTURE");
             qry.exec();
             Mod->setQuery(qry);
             table_facture.setModel(Mod);

             QString strStream;
             QTextStream out(&strStream);

            const int rowCount = table_facture.model()->rowCount();

            const int columnCount =  table_facture.model()->columnCount();

             const QString strTitle ="Document";
             out <<  "<html>\n"
                                     "<img src='E:/QT_BIGJ/gestion fournisseur/image/logo.png' height='120' width='120'/>"
                                 "<head>\n"
                                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 <<  QString("<title>%1</title>\n").arg(strTitle)
                                 <<  "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des produits")
                                <<"<br>"

              <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                             out << "<thead><tr bgcolor=#f0f0f0>";

                             for (int column = 0; column < columnCount; column++)
                                 if (!table_facture.isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(table_facture.model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!table_facture.isColumnHidden(column)) {
                                         QString data = table_facture.model()->data(table_facture.model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";

                             }
                             //prix totale :


                                     out <<  "</table>\n";
                                   out <<"<br> <br>";
                                             out <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                                                            out << "<thead><tr bgcolor=#f0f0f0>";
                             out << QString("<th>%1</th>").arg("PRIX TOTALE");
                                             out << "<tr>";
                            out << QString("<th>%1</th>").arg(prixTotale);
                                             out << "</tr>";
                                             out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

                                     // out << QString("PRIX :'"+prixTotale+"'").arg(prixTotale);
                               // out << "<h1> prix totale : "+prixTotale+" </h1>";
                                     QTextDocument *document = new QTextDocument();
                                     document->setHtml(strStream);

                                     QPrinter printer;
                                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                     if (dialog->exec() == QDialog::Accepted) {

                                         document->print(&printer);
                                     }
                                     printer.setOutputFormat(QPrinter::PdfFormat);
                                     printer.setPaperSize(QPrinter::A4);
                                     printer.setOutputFileName("/tmp/produit.pdf");
                                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));
                                     delete document;
                                     QSqlQuery query;
                                     query.prepare("TRUNCATE TABLE FACTURE");
                                     query.exec();
                                     ui->tabFacture->setModel(F.afficherFacture());

                                     //qDebug()<<prixTotale;

                                     prixTotale = 0;
}

void MainWindow::on_ajouterIntoFacture_clicked()
{


    QString id = ui->reviewFIDMAteriele->text();
    int prix = ui->prix->text().toInt();
    int quantite = ui->quantite->text().toInt();
    prixTotale+=(prix*quantite);
    F.ajouterIntFacture(id,prix,quantite);
    ui->tabFacture->setModel(F.afficherFacture());
    ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(id));

    //qDebug()<< "siuuuuuuuuuuuuuuuuuuu" ;

}

void MainWindow::on_triBTN_2_clicked()
{
    F.statNBfournisseur();
}
