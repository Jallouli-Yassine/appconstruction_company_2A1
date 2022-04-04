﻿#include "materiel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE

materiel::materiel(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,QString etat)
{
    this->reference=reference;
    this->nom=nom;
    this->matricule=matricule;
    this->idfournisseur=idfournisseur;
    this->quantite=quantite;
    this->prix=prix;
    this->etat=etat;
    this->etat=etat;
}

QSqlQueryModel * materiel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select NOM,REFERENCE,QUANTITE,ETAT,PRIX,MATRICULE,IMAGE from MATERIEL");

    return model;
}

QSqlQueryModel * materiel::trie()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select NOM,REFERENCE,QUANTITE,ETAT,PRIX,MATRICULE from MATERIEL order by nom");

    return model;
}
 bool materiel::ajouter()
 {
     QSqlQuery query;

     query.prepare("insert into MATERIEL(REFERENCE,NOM,MATRICULE,IDFOURNISSEUR,QUANTITE,PRIX,ETAT)"
                   "values(:REFERENCE,:NOM,:MATRICULE,:IDFOURNISSEUR,:QUANTITE,:PRIX,:ETAT)");
     query.bindValue(":REFERENCE",this->reference);
     query.bindValue(":NOM",this->nom);
     query.bindValue(":MATRICULE",this->matricule);
     query.bindValue(":IDFOURNISSEUR",this->idfournisseur);
     query.bindValue(":QUANTITE",this->quantite);
     query.bindValue(":PRIX",this->prix);
     query.bindValue(":ETAT",this->etat);
     return query.exec();
 }

 bool materiel::supprimer(QString reference)
 {
     QSqlQuery query;
     query.prepare("Delete from MATERIEL where REFERENCE= :reference");
     query.bindValue(":reference",reference);
     return query.exec();
 }

 bool materiel::modifier(QString reference, QString nom, QString matricule, QString idfournisseur, int quantite, int prix, QString etat){
     QSqlQuery query;
//     QString id1 = QString::number(id);


     query.prepare("update MATERIEL set NOM= :nom, MATRICULE= :matricule, QUANTITE= :quantite, PRIX= :prix ,etat= :etat WHERE REFERENCE = :reference");
     query.bindValue(":nom", nom);
     query.bindValue(":reference", reference);
     query.bindValue(":matricule", matricule);
     query.bindValue(":quantite", quantite);
     query.bindValue(":prix", prix);
     query.bindValue(":etat",etat);
     return query.exec();
 }

 QSqlQueryModel * materiel::chercher(QString name){
    QSqlQueryModel* model = new QSqlQueryModel();
    QString search = "%"+name+"%";
     model->setQuery("SELECT NOM,REFERENCE,QUANTITE,ETAT,PRIX,MATRICULE FROM MATERIEL WHERE NOM like '"+search+"'");
     //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
     return model ;
 }

 QSqlQueryModel * materiel::filtrer(QString filtre)
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select NOM,REFERENCE,QUANTITE,ETAT,PRIX,MATRICULE from MATERIEL where ETAT='"+filtre+"'");

     return model;
 }
 QChartView * materiel::stat()
 {
     int row_count = 0;
     int row_count1 = 0;
     QString x="non loue";
     QString y="loue";

             QSqlQuery query,query2;
             query.prepare("SELECT * FROM MATERIEL where etat='"+x+"'");
             query.exec();
             query2.prepare("SELECT * FROM MATERIEL where etat='"+y+"'");
             query2.exec();

             while(query2.next())
                 row_count1++;

             while(query.next())
                 row_count++;

             qDebug()<<row_count<<row_count1;

     QPieSeries *series = new QPieSeries();
     series->append("Loue", row_count1);
     series->append("Non loue", row_count);
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Statistique des matériels loué et non loué");
     chart->legend()->setAlignment(Qt::AlignRight);
     chart->legend()->setBackgroundVisible(true);
     chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
     chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
     series->setLabelsVisible();

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     return chartView;
 }
