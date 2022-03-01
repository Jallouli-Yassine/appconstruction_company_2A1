#include "projet.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Projet::Projet(QString localisation,QString idarchitecte,QString reference,int prix_totale)
{
    this->localisation=localisation;
    this->idarchitecte=idarchitecte;
    this->reference=reference;
    this->prix_totale=prix_totale;
}

bool Projet::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into PROJET(LOCALISATION,IDARCHITECTE,REFERENCE,PRIX_TOTALE)"
                  "values(:LOCALISATION,:IDARCHITECTE,:REFERENCE,:PRIX_TOTALE)");
    query.bindValue(":LOCALISATION",this->localisation);
    query.bindValue(":IDARCHITECTE",this->idarchitecte);
    query.bindValue(":REFERENCE",this->reference);
    query.bindValue(":PRIX_TOTALE",this->prix_totale);
    return query.exec();
}

QSqlQueryModel * Projet::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PROJET");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localistaion"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDA"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("reference"));
    return model;
}
bool Projet::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from PROJET where IDPROJET= :id");
    query.bindValue(":id",res);
    return query.exec();
}

QSqlQueryModel * Projet::affichertrie(int x)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if (x==1)
    {
        model->setQuery("select * from PROJET order by IDPROJET");
    }else if (x==2)
    {
        model->setQuery("select * from PROJET order by IDARCHITECTE");
    }else if(x==3)
    {
        model->setQuery("select * from PROJET order by PRIX_TOTALE");
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localistaion"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDA"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("reference"));
    return model;
}

//QSqlQueryModel * Projet::afficherrech(QString x)
//{
//    QSqlQueryModel * model=new QSqlQueryModel();

//    model->setQuery("select * from PROJET where IDPROJET=:x");

//    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDP"));
//    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
//    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Localistaion"));
//    model->setHeaderData(3,Qt::Horizontal,QObject::tr("IDA"));
//    model->setHeaderData(4,Qt::Horizontal,QObject::tr("reference"));
//    return model;
//}

