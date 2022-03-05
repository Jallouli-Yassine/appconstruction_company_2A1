#include "materiel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

materiel::materiel(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,int etat)
{
    this->reference=reference;
    this->nom=nom;
    this->matricule=matricule;
    this->idfournisseur=idfournisseur;
    this->quantite=quantite;
    this->prix=prix;
    this->etat=etat;
}

QSqlQueryModel * materiel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from MATERIEL");

    return model;
}

QSqlQueryModel * materiel::afficher1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from MATERIEL order by nom");

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

 bool materiel::modifier(QString reference, QString nom, QString matricule, QString idfournisseur, int quantite, int prix, int etat){
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
