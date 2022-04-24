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
#include<QProcess>


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
#include<QSerialPort>
#include<QSerialPortInfo>
#include<QSplashScreen>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include <QFileDialog>
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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QChartView>
#include "arduino.h"
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
#include <QtDebug>
QT_CHARTS_USE_NAMESPACE









MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_2->setTabEnabled(0, true);


    //**************************************************arduino*********************

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

        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(concatRfid()));










//**************************************************************************************


//*************ja3louli************************
        ui->verticalLayout_2->addWidget(F.stat());
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

//*************************


    ui->le_cin->setValidator(new QIntValidator(100, 999999, this));
    ui->le_salaire->setValidator(new QIntValidator(100, 7000, this));

    ui->verticalLayout->addWidget(E.stat());

    ui->tabemp->setModel(E.afficher());

    ui->salaire_mod->setValidator(new QIntValidator(100, 7000, this));
    ui->cin_mod->setValidator(new QIntValidator(100, 999999, this));
    ui->role_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->name_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->prenom_mod->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_role->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    //*Yosr*//
    ui->verticalLayout_10->addWidget(ptmp->stat());
    ui->tableView->setModel(ptmp->afficher());
    ui->tableView_3->setModel(ptmp->afficher_C1());
    ui->tableView_4->setModel(ptmp->afficher_C2());
    ui->tableView_5->setModel(ptmp->afficher_C3());
    ui->tableView_2->setModel(ptmp->afficher_archive());
    ui->lineEdit_p->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_id->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_a->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")  ));
    //*Yosr*//
//kamel------------------
    ui->verticalLayout_19->addWidget(m->stat());
    ui->tableView_11->setModel(m->afficher());
    ui->nomLE->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->ReferenceLE_4->setValidator(new QIntValidator (0,999,this));
    ui->ReferenceLE_2->setValidator(new QIntValidator (0,9999,this));
//kamel-------------------
    //mehdi------------
    ui->verticalLayout_20->addWidget(c.stat());
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

//mehdi--------------

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
        ui->verticalLayout->addWidget(E.stat());


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
        ui->verticalLayout->addWidget(E.stat());


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
        ui->verticalLayout->addWidget(E.stat());


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
                printer.setOutputFileName("../PDFs/employee.pdf");

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
               painter.setPen(Qt::yellow);
               painter.drawText(260,100,"Fiche employee");

               font.setPixelSize(30);
               painter.setFont(font);
               painter.setPen(Qt::yellow);
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


//*********************************************jallouli*********************************




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
    int quantite=0;
    QString id = ui->reviewFIDMAteriele->text();
    int prix = ui->prix->text().toInt();
    quantite = ui->quantite->text().toInt();
    qDebug()<<quantite;
    if( quantite==0 )
    {
        QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                         QObject::tr("remplir tout les champs\n""Click to Cancel."), QMessageBox::Cancel);
    }else
    {
        prixTotale+=(prix*quantite);
        qDebug()<< "prix :"<<prixTotale;
        F.ajouterIntFacture(id,prix,quantite);
        ui->tabFacture->setModel(F.afficherFacture());
        QString idF = ui->reviewFID->text();
        ui->Tabmaterielle->setModel(F.afficherMaterielleFournisseur(idF));
    }
}

///generer une facture pdf
void MainWindow::on_genererFacture_clicked()
{
    qDebug()<< "prix finale :"<< prixTotale;
    F.genererFacture(&prixTotale);
    ui->tabFacture->setModel(F.afficherFacture());
}

//***************arduino (jalouli &bousbih)****************************
void MainWindow::concatRfid()
{
    bool found =false;
        QString nom="",RFID,msg,id;
        QString salaire;
        data =A.read_from_arduino();
        qDebug() <<"a=" << data;
        if (data!="#")
            uid+=data;
        else {
            int pos = uid.lastIndexOf(QChar('/'));
            qDebug() << "uid="<< uid.left(pos);
            qDebug()  << uid;
            QTableView tableEmploye;
            QSqlQueryModel * Mod=new  QSqlQueryModel();
            QSqlQuery qry;
            qry.prepare("select * from EMPLOYEE");
            qry.exec();
            Mod->setQuery(qry);
            tableEmploye.setModel(Mod);
            const int ligne = tableEmploye.model()->rowCount();
            for (int var = 0; var < ligne; var++) {
                if(tableEmploye.model()->data(tableEmploye.model()->index(var, 8))==uid)
                {
                   id= tableEmploye.model()->data(tableEmploye.model()->index(var, 0)).toString();
                   nom= tableEmploye.model()->data(tableEmploye.model()->index(var, 2)).toString();
                   salaire= tableEmploye.model()->data(tableEmploye.model()->index(var, 4)).toString();
                   RFID = tableEmploye.model()->data(tableEmploye.model()->index(var, 8)).toString();
                   found=true;
                   var=ligne;
                }
            }
            msg= tr("salaire = ")+salaire;
            const char * p= msg.toStdString().c_str();
            //qDebug()<<(*p);


                if(found){
                    A.writeStringToArduino(p);
                    qDebug()<<"bonjour "<<nom;
                    for (int i=0;i<5;i++) {
                        //QThread::sleep(60);
                        addHours(RFID);
                        E.calculeprime(id);
                        ui->tabemp->setModel(E.afficher());
                    }
                }else{
                    qDebug()<<"error";
                    A.writeStringToArduino("ERROR");
                }
            uid="";
            found = false;
            //qDebug() << uid;
 }
}
void MainWindow::addHours(QString RFID)
{
    QSqlQuery qry;
    qry.prepare("UPDATE EMPLOYEE SET NBHTRAVAIL = NBHTRAVAIL + 1 WHERE RFID = :RFID");
    qry.bindValue(":RFID", RFID);
    qry.exec();
}
//**********************************************************************************************
//*******************************************MENU****************************************
void MainWindow::on_GestiondesEmployee_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->tabWidget_2->setTabEnabled(1, true);

}

void MainWindow::on_GestiondesFournisseurs_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);
    ui->tabWidget_2->setTabEnabled(2, true);

}

void MainWindow::on_GestiondesArchitects_clicked()
{
    ui->tabWidget_2->setCurrentIndex(3);
    ui->tabWidget_2->setTabEnabled(3, true);

}

void MainWindow::on_GestiondesClients_clicked()
{
    ui->tabWidget_2->setCurrentIndex(4);
    ui->tabWidget_2->setTabEnabled(4, true);

}

void MainWindow::on_GestiondesProjets_clicked()
{
    ui->tabWidget_2->setCurrentIndex(5);
    ui->tabWidget_2->setTabEnabled(5, true);

}

void MainWindow::on_GestiondesMateriaux_clicked()
{
    ui->tabWidget_2->setCurrentIndex(6);
    ui->tabWidget_2->setTabEnabled(6, true);

}

void MainWindow::on_retmenu_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);

}

void MainWindow::on_retmenu_2_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}
//********************************fin Menu***************************************

//*Yosr*//
void MainWindow::on_pushButton_5_clicked()
{

    int id=ui->lineEdit_p_2->text().toInt();

    bool test=ptmp->supprimer(id);

    if(test)
    {
        delete ptmp->stat();
        ui->verticalLayout_10->addWidget(ptmp->stat());
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
        ui->verticalLayout_10->addWidget(ptmp->stat());
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

        ui->verticalLayout_10->addWidget(ptmp->stat());
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
        ui->verticalLayout_10->addWidget(ptmp->stat());
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



void MainWindow::on_pushButton_off_clicked()
{
    A.write_to_arduino("0");
    qDebug()<<A.read_from_arduino();
}



//*Yosr*//
//kamel-----------------------------
void MainWindow::on_ButtonAjouter_2_clicked()
{
    QString reference=ui->ReferenceLE->text();
    QString nom=ui->nomLE->text();
    QString matricule=ui->MatriculeLE->text();
    QString idfournisseur="1";

    int quantite=ui->ReferenceLE_4->text().toInt();
    int prix=ui->ReferenceLE_2->text().toInt();
    QString etat=ui->comboBox_2->currentText();
    materiel m(reference,nom,matricule,idfournisseur,quantite,prix,etat);
    bool test=m.ajouter();
    //ui->verticalLayout->addWidget(m.stat());
    if(test)     {
         ui->tableView_11->setModel(m.afficher());
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
        ui->tableView_11->setModel(m->afficher());
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
    ui->tableView_11->setModel(m->trie());
}

void MainWindow::on_ButtonAjouter_4_clicked()
{
    QString reference=ui->ReferenceLE_3->text();
    QString nom=ui->nomLE_2->text();
    QString matricule=ui->MatriculeLE_2->text();
    QString idfournisseur="1";
    int quantite=ui->ReferenceLE_6->text().toInt();
    int prix=ui->ReferenceLE_5->text().toInt();
    QString etat=ui->comboBox_3->currentText();


   bool test =  m->modifier(reference,nom,matricule,idfournisseur,quantite,prix,etat);

    if(test){
        ui->tableView_11->setModel(m->afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("update effectué\n""Click to Cancel."),
                                 QMessageBox::Cancel);     }
    else         QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                 QObject::tr("update non effectué\n""Click to Cancel."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_11_activated(const QModelIndex &index)
{
    QString value=ui->tableView_11->model()->data(index).toString();
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
                       //ui->lb_img->setText(qry.value(8).toString()); //image

                    }
                }
}


void MainWindow::update_label()
{
    data=A.read_from_arduino();
    qDebug()<<data;
    if(data=="1")

        ui->label->setText("Status : Raining -_- , Hide the products"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label->setText("Status : Clear :)");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}


void MainWindow::on_Buttonrecherche_clicked()
{
    QString rech= ui->recherche->text();

    ui->tableView_11->setModel(m->chercher(rech));
}

void MainWindow::on_PDF_clicked()
{
    QPrinter printer;

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setOutputFileName("C:/2A1/materielpdf/materiel.pdf");

                   QPainter painter;
                   painter.begin(&printer);
                   QFont font("Times", 10, QFont::Bold);
                   QString nom=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),0)).toString();
                   QString referance=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),1)).toString();
                   QString quantite=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),2)).toString();
                   QString etat=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),3)).toString();
                   QString prix=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),4)).toString();
                   QString matricule=ui->tableView_11->model()->data(ui->tableView_11->model()->index(ui->tableView_11->currentIndex().row(),5)).toString();

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
                   painter.drawText(500,700,prix+"DT");
                   painter.drawText(500,800,matricule);




                   if(painter.end())
                   {
                       QMessageBox::information(nullptr, QObject::tr("FICHE materiel"),
                                                QObject::tr("Fichier materiel Genere.\n"
                                                            "Click Ok to exit."), QMessageBox::Ok);
                   }
}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
   qDebug() << arg1 ;
    ui->tableView_11->setModel(m->filtrer(arg1));
}

void MainWindow::on_BtnIMG_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"),"", tr("Images(*.png*.jpg*.jpeg*.bmp)"));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid=image.load(filename);
        if (valid)
        {


            image = image.scaledToWidth(ui->lb_img->width(), Qt::SmoothTransformation);
            ui->lb_img->setPixmap(QPixmap::fromImage(image));
        }
        else{//error handling
        }
    }
}

void MainWindow::on_on_clicked()
{
    A.write_to_arduino("1");
        qDebug()<<A.read_from_arduino();
}

void MainWindow::on_off_clicked()
{
    A.write_to_arduino("0");
        qDebug()<<A.read_from_arduino();
}

void MainWindow::on_plus_clicked()
{
    A.write_to_arduino("2");
        qDebug()<<A.read_from_arduino();
}



void MainWindow::on_PDF_6_clicked() //moins
{
    A.write_to_arduino("3");
        qDebug()<<A.read_from_arduino();
}


void MainWindow::on_pushButton_OFF_clicked()
{
    A.write_to_arduino("3");
}
//end kamel-------------------------------------------------------------
//begin mehdi -----------------------------------------------------------
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
//end mehdi------------------------------------------------------
