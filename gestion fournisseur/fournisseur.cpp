#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <iostream>


using namespace std;
Fournisseur::Fournisseur()
{
    this->id = 0;
    this->age = 0;
    this->phone = 0;
    this->nom = " ";
    this->prenom = " ";
    this->email = " ";
}

Fournisseur::Fournisseur(int age,int phone,QString nom,QString prenom,QString email){
    this->age = age;
    this->phone = phone;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
}

//GETTERS
int Fournisseur::getID(){ return this->id; }
int Fournisseur::getAge(){ return this->age; }
int Fournisseur::getPhone(){ return this->phone; }
QString Fournisseur::getNom(){ return this->nom; }
QString Fournisseur::getPrenom(){ return this->prenom; }
QString Fournisseur::getEmail(){ return this->email; }

//SETTERS
void Fournisseur::setID(int id){ this->id = id; }
void Fournisseur::setAge(int age){ this->age = age; }
void Fournisseur::setPhone(int phone){ this->phone = phone; }
void Fournisseur::setNom(QString nom){ this->nom = nom; }
void Fournisseur::setPrenom(QString prenom){ this->prenom = prenom; }
void Fournisseur::setEmail(QString email){ this->email = email; }

//FUNCTIONS
bool Fournisseur::ajouterF(){

    QSqlQuery query;
       query.prepare("INSERT INTO FOURNISSEUR (NOM,PRENOM,AGE,PHONE,EMAIL) "
                     "VALUES (:NOM,:PRENOM,:AGE,:PHONE,:EMAIL)");

       query.bindValue(":NOM", this->nom);
       query.bindValue(":PRENOM", this->prenom);
       query.bindValue(":AGE", this->age);
       query.bindValue(":PHONE", this->phone);
       query.bindValue(":EMAIL", this->email);
       return  query.exec();
}

QSqlQueryModel* Fournisseur::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from FOURNISSEUR");
    return model;
}
/*
bool Fournisseur::getOneF(int id){
    QSqlQuery query;
    if(query.prepare("select * from FOURNISSEUR where ID = :id")){
        query.bindValue(":id" , id);
        qDebug() <<  5 << endl;
        return  query.exec();
    }
    return false;
}
*/
bool Fournisseur::supprimer(int id){
    QSqlQuery query;
    query.prepare("delete from FOURNISSEUR where ID = :id");
        query.bindValue(":id" , id);
        return  query.exec();
}

bool Fournisseur::modifier(int id,QString nom,QString prenom,int age,int phone,QString email){
    QSqlQuery query;
    QString id1 = QString::number(id);
    QString phone1 = QString::number(phone);

    query.prepare("update FOURNISSEUR set NOM = :nom, PRENOM= :prenom, AGE= :age, PHONE= :phone, EMAIL= :email WHERE ID = :id");
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":phone", phone1);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":id", id);
    return query.exec();
}
