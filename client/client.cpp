#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QChartView>

Client::Client()
{
}
    Client :: Client(int num,int id, QString nom, QString prenom, QString email, QString DDN){
     this->num=num;
        this->nom=nom;
        this->prenom=prenom;
        this->email=email;
        this->DDN=DDN;
        this->id=id;

    }
    int Client:: getnum(){return num;}
    int Client:: getid(){return id;}

    QString Client:: getnom(){return nom;}
    QString Client ::getprenom(){return prenom;}
    QString Client:: getemail(){return email;}
    QString Client:: getDDN(){return DDN;}
    void Client:: setnum(int num){this->num=num;}
    void Client:: setid(int id){this->id=id;}

    void Client:: setnom(QString nom){this->nom=nom;}
    void Client:: setprenom(QString prenom){this->prenom=prenom;}
    void Client:: setemail(QString email){this->email=email;}
    void Client::setDDN(QString DDN){this->DDN=DDN;}



    bool Client:: ajoute(){
QSqlQuery query;
QString res = QString::number(num);


      query.prepare("INSERT INTO CLIENT (NOM, PRENOM, NUMERO,EMAIL,DDN,IDCLIENT) "
                    "VALUES (:NOM, :PRENOM,:NUMERO,:EMAIL, :DDN, :IDCLIENT)");
      query.bindValue(":NOM", this->nom);
      query.bindValue(":PRENOM", this->prenom);
      query.bindValue(":NUMERO", res);
      query.bindValue(":EMAIL", this->email);
      query.bindValue(":DDN", this->DDN);
      query.bindValue(":IDCLIENT", this->id);



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

    QSqlQueryModel * Client:: affichenom(){

        QSqlQueryModel* model= new QSqlQueryModel() ;
              model->setQuery("SELECT *  FROM CLIENT ORDER BY NOM ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr ("name"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr ("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr ("son id "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr ("numero de telephone"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr ("email"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr ("date de naissance"));
return model;
    }



    QSqlQueryModel * Client:: afficheprenom(){

        QSqlQueryModel* model= new QSqlQueryModel() ;
              model->setQuery("SELECT *  FROM CLIENT ORDER BY PRENOM ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr ("name"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr ("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr ("son id "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr ("numero de telephone"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr ("email"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr ("date de naissance"));
return model;
    }


    QSqlQueryModel * Client:: afficheid(){

        QSqlQueryModel* model= new QSqlQueryModel() ;
              model->setQuery("SELECT *  FROM CLIENT ORDER BY IDCLIENT ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr ("name"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr ("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr ("son id "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr ("numero de telephone"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr ("email"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr ("date de naissance"));
return model;
    }


    QSqlQueryModel * Client:: rechercheid(QString rech){

        QSqlQueryModel * model= new QSqlQueryModel();
            QString recher="select * from client where nom like '%"+rech+"%' or prenom like '%"+rech+"%' or email like '%"+rech+"%' or DDN like '%"+rech+"%' ";
            model->setQuery(recher);
            return model;


}



    bool Client::modifier(int num,int id, QString nom, QString prenom, QString email, QString DDN){
        QSqlQuery query;



        query.prepare("update Client set NOM = :nom, PRENOM= :prenom,  NUMERO= :number, EMAIL= :email, DDN=:DDN WHERE IDCLIENT = :idclient");
        query.bindValue(":prenom", prenom);
        query.bindValue(":nom", nom);
        query.bindValue(":number", num);
        query.bindValue(":email", email);
        query.bindValue(":DDN", DDN);
        query.bindValue(":idclient", id);
        return query.exec();
    }


    bool Client::ajoutrdv(QString daterdv,QString id)
    {
        QSqlQuery query;



              query.prepare("INSERT INTO RDV (IDCLIENT, DATERDV) "
                            "VALUES (:IDCLIENT, :DATERDV)");
              query.bindValue(":IDCLIENT", id);
              query.bindValue(":DATERDV", daterdv);

              return query.exec();

    }


    QSqlQueryModel *Client::afficherrdv(){

        QSqlQueryModel* model= new QSqlQueryModel() ;
              model->setQuery("SELECT CLIENT.nom, CLIENT.prenom, CLIENT.IDCLIENT, RDV.DATERDV FROM CLIENT JOIN RDV ON CLIENT.IDCLIENT=RDV.IDCLIENT  ");

   return model;

    }


    QChartView * Client::stat()
    {
        //fzfezz
        int row_count = 0;
        int row_count1 = 0;

                QSqlQuery query,query2;

                query.prepare("SELECT DATERDV FROM RDV ");
                query.exec();
                query2.prepare("SELECT NOM FROM CLIENT ");
                query2.exec();

                while(query2.next())
                    row_count1++;

                while(query.next())
                    row_count++;

                qDebug()<<row_count<<row_count1;

        QPieSeries *series = new QPieSeries();
        series->append("DES CLIENTS ONT UN RENDEZ-VOUS", row_count1);
        series->append("DES CLIENTS QUI N'ONT PAS DE RENDEZ-VOUS", row_count);
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("");
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setBackgroundVisible(true);
        chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
        chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
        series->setLabelsVisible();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        return chartView;
    }

