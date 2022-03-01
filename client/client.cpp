#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
Client::Client()
{
}
    Client :: Client(int num, QString nom, QString prenom, QString email, QString DDN){
     this->num=num;
        this->nom=nom;
        this->prenom=prenom;
        this->email=email;
        this->DDN=DDN;

    }
    int Client:: getnum(){return num;}
    QString Client:: getnom(){return nom;}
    QString Client ::getprenom(){return prenom;}
    QString Client:: getemail(){return email;}
    QString Client:: getDDN(){return DDN;}
    void Client:: setnum(int num){this->num=num;}
    void Client:: setnom(QString nom){this->nom=nom;}
    void Client:: setprenom(QString prenom){this->prenom=prenom;}
    void Client:: setemail(QString email){this->email=email;}
    void Client::setDDN(QString DDN){this->DDN=DDN;}
    bool Client:: ajoute(){
QSqlQuery query;
      query.prepare("INSERT INTO CLIENT (NOM, PRENOM, NUMERO,EMAIL,DDN) "
                    "VALUES (:NOM, :PRENOM,:NUMERO,:EMAIL, :DDN)");
      query.bindValue(":NOM", this->nom);
      query.bindValue(":PRENOM", this->prenom);
      query.bindValue(":NUMERO", this->num);
      query.bindValue(":EMAIL", this->email);
      query.bindValue(":DDN", this->DDN);


      return query.exec();
                         }
    QSqlQueryModel * Client:: afficher(){

        QSqlQueryModel* model= new QSqlQueryModel() ;
              model->setQuery("SELECT *  FROM CLIENT");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr ("name"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr ("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr ("son id "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr ("numero de telephone"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr ("email"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr ("date de naissance"));
       return model ;
    }



    bool Client::supprimer(QString id ){

        QSqlQuery query;
        query.prepare("Delete from CLIENT where idclient=:idclient");
        query.bindValue(":idclient", id);
        return query.exec();
    }










