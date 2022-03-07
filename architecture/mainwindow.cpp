#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "architect.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->id->setValidator(new QIntValidator(0,9999999, this));
        ui->ntel->setValidator(new QIntValidator(0,9999999, this));
ui->education->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{

    int id=ui->id->text().toInt();
     QMessageBox msgBox;
    QString nom =ui->nom->text();
    QString prenom =ui->prenom->text();
    int ntel=ui->ntel->text().toInt();
    QString email =ui->email->text();
    Architect E(id,nom,prenom,ntel,email);
    bool test=E.ajouter();
    if(test)
    {

 msgBox.setText("ajouter succes");
}
    else
      msgBox.setText("echec d'ajouter ");
    msgBox.exec();
ui->education->setModel(E.afficher());
}

void MainWindow::on_supprimer_clicked()
{
    QMessageBox msgBox;
    Architect A1;
    A1.setid(ui->idd->text().toInt());
   bool test=A1.supprimer(A1.getid());
   if(test)
     msgBox.setText("suppression succes");
   else
      msgBox.setText("Echec de suppression");
    msgBox.exec();
ui->education->setModel(A1.afficher());
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox;

        int id = ui->id_2->text().toInt();
        QString nom = ui->nom_2->text();
        QString prenom = ui->prenom_2->text();
        int ntel = ui->ntel_2->text().toInt();
        QString email = ui->email_2->text();
        bool test =  A.modifier(id,nom,prenom,ntel,email);

        if(test)
          msgBox.setText("modifier succes");
        else
           msgBox.setText("Echec de modification");
         msgBox.exec();
     ui->education->setModel(A.afficher());
}

void MainWindow::on_pushButtonAfficherDech_2_clicked()
{
    QString attribute = ui->comboBox_tripar_2->currentText();
    QString croissance = ui->comboBox_typetri_2->currentText();
    qDebug()<< attribute ;
    qDebug()<< croissance ;
    ui->education->setModel(A.trie(attribute,croissance));
}

/*void MainWindow::on_pushButtonrechdech_2_clicked()
{
       QSqlQueryModel* Architect::chercher(QString id){
       QSqlQueryModel* model = new QSqlQueryModel();
       QString search = "%"+id+"%";
        model->setQuery("SELECT * FROM FOURNISSEUR WHERE NOM like '"+search+"'");
        //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
        return model ;
    }
}
*/
