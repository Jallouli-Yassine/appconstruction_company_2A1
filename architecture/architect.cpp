#include "architect.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Architect::Architect()
{

id=0; nom=" "; prenom=""; ntel=0; email="";
}
Architect::Architect(int id,QString nom,QString prenom,int ntel,QString email)
{
    this->id=id; this->nom=nom; this->prenom=prenom;this->ntel=ntel;this->email=email;
}
int Architect::getid(){
    return id;
}
QString Architect::getnom(){
    return nom;
}
QString Architect::getprenom(){
    return prenom;
}
int Architect::getntel(){
    return ntel;
}
QString Architect::getemail(){
    return email;
}
void Architect::setid(int id){this->id=id;}
void Architect::setnom(QString nom){this->nom=nom;}
void Architect::setprenom(QString prenom){this->prenom=prenom;}
void Architect::setntel(int ntel){this->ntel=ntel;}
void Architect::setemail(QString email){this->email=email;}
 bool Architect::ajouter()
 {

     QSqlQuery query;
     QString id_string= QString::number(id);
       QString ntel_string= QString::number(ntel);
     query.prepare("INSERT INTO ARCHITECT (id, nom, prenom,ntel,email) "
                   "VALUES (:id, :nom, :prenom, :ntel, :email)");
     query.bindValue(0, id_string);
     query.bindValue(1, nom);
     query.bindValue(2, prenom);
     query.bindValue(3, ntel_string);
     query.bindValue(4, email);

    return query.exec();



 }
  bool Architect::supprimer(int id)
  {
      QSqlQuery query;

      query.prepare(" Delete from ARCHITECT where id=:id");
      query.bindValue(0, id);
     return query.exec();
  }
QSqlQueryModel* Architect::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM ARCHITECT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_telephone"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
          return model;
}
bool Architect::modifier(int id,QString nom,QString prenom,int ntel,QString email){
    QSqlQuery query;
    QString id1 = QString::number(id);
    QString phone1 = QString::number(ntel);

    query.prepare("update ARCHITECT set  nom= :nom, prenom= :prenom, ntel= :ntel, email= :email WHERE id = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":ntel", phone1);
    query.bindValue(":email", email);
    query.bindValue(":id", id1);
    return query.exec();
}
QSqlQueryModel* Architect::trie(QString attribute , QString croissance){
    QSqlQueryModel* model = new QSqlQueryModel();
    if(attribute == "ID" && croissance == "croissante")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY ID ASC ");

    else if(attribute == "ID" && croissance == "decroissante")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY ID DESC ");
    else if(attribute == "NOM" && croissance == "croissante")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY NOM ASC ");
    else if(attribute == "NOM" && croissance == "decroissante")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY NOM DESC ");
    return model;
}
