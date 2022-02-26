#include "employee.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
#include<QMainWindow>


employee::employee()
{
    idemployee=""; nom=""; prenom=""; type=""; cin=0;nbhtravail=0;salaire=0;

}
employee::employee(QString nom,QString prenom,QString type,QString id,int nbh,int cin,float salaire)
{
    this->idemployee=id;
    this->nom=nom;
    this->prenom=prenom;
    this->nbhtravail=nbh;
    this->cin=cin;
    this->salaire=salaire;
    this->type=type;
}


//setters
void employee::setnom(QString  nom){this->nom=nom;}
void employee::setprenom(QString prenom){this->prenom=prenom;}
void employee::setid(QString id){this->idemployee=id;}
void employee::setcin(int cin){this->cin=cin;}
void employee::setsalaire(float salaire){this->salaire=salaire;}
void employee::settype(QString type){this->type=type;}
void employee::setnbhtravail(int nbh){this->nbhtravail=nbh;}


//getters
QString employee::getnom(){return nom;}
QString employee::getoprenom(){return prenom;}
QString employee::gettype(){return type;}
int employee::getcin(){return cin;}
int employee::getnbhtravail(){return nbhtravail;}
QString employee::getid(){return idemployee;}
float employee::getsalaire(){return salaire;}




//les fonctions


//ajouter
bool employee::ajouter()
{
    QString cin_string=QString::number(this->cin);
    QString salaire_string=QString::number(this->salaire);
    QString nbh_string=QString::number(this->nbhtravail);
    QSqlQuery query;
          query.prepare("INSERT INTO employee (IDEMPOLYEE,CIN,NOM,PRENOM,SALAIRE,TYPE) VALUES (:IDEMPOLYEE,:CIN,:NOM,:PRENOM,:SALAIRE,:TYPE)");
          query.bindValue(":IDEMPOLYEE",this->idemployee);
          query.bindValue(":CIN", cin_string);
          query.bindValue(":NOM", this->nom);
          query.bindValue(":PRENOM", this->prenom);
          query.bindValue(":SALAIRE",salaire_string);
          query.bindValue(":TYPE",this->type);


          return query.exec();



}
//afficher
QSqlQueryModel* employee::afficher()
{

    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery("SELECT * from employee");


    return model;


}
//supprimer
bool employee::supprimer(QString id)
{
    QSqlQuery query;

    query.prepare("DELETE from employee where IDEMPOLYEE=:IDEMPOLYEE ");
    query.bindValue(":IDEMPOLYEE", id);


    return query.exec();

}


//modifier
bool employee::modifier(QString id, QString nom, QString prenom, QString type, int cin, float salaire)
{
    //convertir  les variables pour effectue la modification dans la base de donnees
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString salaire_string=QString::number(salaire);

    query.prepare("update employee set NOM = :nom, PRENOM= :prenom, CIN= :CIN, SALAIRE= :SALAIRE, TYPE= :TYPE WHERE IDEMPOLYEE = :IDEMPOLYEE");
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":SALAIRE",salaire_string);
    query.bindValue(":TYPE", type);
    query.bindValue(":CIN", cin_string);
    query.bindValue(":IDEMPOLYEE",id );
    return query.exec();
}
