#include "employee.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"




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
//recherche
QSqlQueryModel* employee::chercher(QString id){
   QSqlQueryModel* model = new QSqlQueryModel();
   QString search = "%"+id+"%";
    model->setQuery("SELECT * FROM employee WHERE IDEMPOLYEE like '"+search+"'");
    //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    return model ;
}



//tri

QSqlQueryModel* employee::tri(QString attribute ){
    QSqlQueryModel* model = new QSqlQueryModel();
    if(attribute == "NOM")
        model->setQuery("SELECT * FROM employee ORDER BY NOM ASC ");
    else if (attribute == "SALAIRE" )
        model->setQuery("SELECT * FROM employee ORDER BY SALAIRE ASC ");
    else if (attribute == "NBHTRAVAIL" )
        model->setQuery("SELECT * FROM employee ORDER BY NBHTRAVAIL ASC ");


    return model;
}





//calculer prime pour chaque employee

bool employee::calculeprime(QString id){
    QSqlQuery qry,qryy;
    int salaire,nh,prime;
    float var=0;
    qry.prepare("select IDEMPOLYEE,SALAIRE,NBHTRAVAIL from employee where IDEMPOLYEE like '"+id+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            id=qry.value(0).toString();
            salaire=qry.value(1).toInt();
            nh=qry.value(2).toInt();
            var = ((nh/10)*0.5) ;
            prime = (salaire * var)/100;
            qDebug() << "id: " << id << " | salaire: " << salaire << " | nb heures: " << nh ;
            qryy.prepare("update employee set SALAIRE=:pr where IDEMPOLYEE=:IDEMPOLYEE");
            salaire +=prime;
            qryy.bindValue(":pr",salaire);
            qryy.bindValue(":IDEMPOLYEE",id);
            qryy.exec();
        }

    }
            }


//statistics

QChartView * employee::stat()
{
    int row_count = 0;
    int row_count1 = 0;
    int row_count2 = 0;

            QSqlQuery query,query2,query3;
            query.prepare("SELECT * FROM employee where SALAIRE < 1000 ");
            query.exec();
            query2.prepare("SELECT * FROM employee where (SALAIRE >= 1000) AND (SALAIRE < 5000) ");
            query2.exec();
            query3.prepare("SELECT * FROM employee where SALAIRE >= 5000");
            query3.exec();

            while(query3.next())
                row_count2++;

            while(query2.next())
                row_count1++;

            while(query.next())
                row_count++;


            qDebug()<<row_count<<row_count1<<row_count2;

    QPieSeries *series = new QPieSeries();
    series->append("employee ont un salaire superieur a 5000 DT", row_count2);
    series->append("employee ont un salaire entre 5000 et 1000 DT", row_count1);
    series->append("employee ont un salaire inferieur a 1000 DT", row_count);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistic Des salaires");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(248, 246, 0)));
    series->setLabelsVisible();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

