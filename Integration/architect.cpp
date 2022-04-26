#include "architect.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Architect::Architect()
{

id=0; nom=" "; prenom=""; ntel=0; email="";
}
Architect::Architect(int id,QString nom,QString prenom,int ntel,QString email,QString etat){    this->id=id; this->nom=nom; this->prenom=prenom;this->ntel=ntel;this->email=email;this->etat=etat;}
int Architect::getid(){return id;}
QString Architect::getnom(){return nom;}
QString Architect::getprenom(){return prenom;}
int Architect::getntel(){return ntel;}
QString Architect::getemail(){return email;}
QString Architect::getetat(){return etat;}
void Architect::setid(int id){this->id=id;}
void Architect::setnom(QString nom){this->nom=nom;}
void Architect::setprenom(QString prenom){this->prenom=prenom;}
void Architect::setntel(int ntel){this->ntel=ntel;}
void Architect::setemail(QString email){this->email=email;}
void Architect::setetat(QString etat){this->etat=etat;}

bool Architect::ajouter()
 {

     QSqlQuery query;
     QString id_string= QString::number(id);
       QString ntel_string= QString::number(ntel);
     query.prepare("INSERT INTO ARCHITECT (id, nom, prenom,ntel,email,etat) "
                   "VALUES (:id, :nom, :prenom, :ntel, :email,:etat)");
     query.bindValue(0, id_string);
     query.bindValue(1, nom);
     query.bindValue(2, prenom);
     query.bindValue(3, ntel_string);
     query.bindValue(4, email);
    query.bindValue(5, etat);
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

          return model;
}
bool Architect::modifier(int id,QString nom,QString prenom,int ntel,QString email,QString etat){
    QSqlQuery query;
    QString id1 = QString::number(id);
    QString phone1 = QString::number(ntel);

    query.prepare("update ARCHITECT set  nom= :nom, prenom= :prenom, ntel= :ntel, email= :email, etat= :etat WHERE id = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":ntel", phone1);
    query.bindValue(":email", email);
     query.bindValue(":etat", etat);
    query.bindValue(":id", id1);
    return query.exec();
}
QSqlQueryModel* Architect::trie(QString attribute , QString croissance){
    QSqlQueryModel* model = new QSqlQueryModel();
    if(attribute == "ID" && croissance == "croissant")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY ID ASC ");

    else if(attribute == "ID" && croissance == "decroissant")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY ID DESC ");
    else if(attribute =="NOM" && croissance == "croissant")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY NOM ASC ");
    else if(attribute =="NOM" && croissance == "decroissant")
        model->setQuery("SELECT * FROM ARCHITECT ORDER BY NOM DESC ");
    return model;
}
QSqlQueryModel* Architect::chercher(QString nom){
QSqlQueryModel* model = new QSqlQueryModel();
QString search = "%"+nom+"%";
 model->setQuery("SELECT * FROM ARCHITECT WHERE NOM like '"+search+"'");
 //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
 return model ;
}
QChartView * Architect::stat()
{
    //fzfezz
    int row_count = 0;
    int row_count1 = 0;

            QSqlQuery query,query2;

            query.prepare("SELECT * FROM ARCHITECT where etat='non disponible'");
            query.exec();
            query2.prepare("SELECT * FROM ARCHITECT where etat='disponible'");
            query2.exec();

            while(query2.next())
                row_count1++;

            while(query.next())
                row_count++;

            qDebug()<<row_count<<row_count1;

    QPieSeries *series = new QPieSeries();
    series->append("disponible", row_count1);
    series->append("non disponible", row_count);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("ETAT d'architect");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
    series->setLabelsVisible();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
