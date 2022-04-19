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










MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

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

        //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(updateLabel()));
        //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(concatRfid()));










//**************************************************************************************


//*************ja3louli************************
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
