#include "projet.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
Projet::Projet(QString localisation,QString idarchitecte,QString reference,QString prix_totale,QString date_start)
{
    this->localisation=localisation;
    this->idarchitecte=idarchitecte;
    this->reference=reference;
    this->prix_totale=prix_totale;
    this->date_start=date_start;
}

bool Projet::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into PROJET(LOCALISATION,IDARCHITECTE,REFERENCE,PRIX_TOTALE,ETAT,DATE_START)"
                  "values(upper(:LOCALISATION),:IDARCHITECTE,upper(:REFERENCE),:PRIX_TOTALE,:ETAT,:DATE_START)");
    query.bindValue(":LOCALISATION",this->localisation);
    query.bindValue(":IDARCHITECTE",this->idarchitecte);
    query.bindValue(":REFERENCE",this->reference);
    query.bindValue(":PRIX_TOTALE",this->prix_totale);
    query.bindValue(":DATE_START",this->date_start);
    query.bindValue(":ETAT",this->etat=0);
    return query.exec();
}

QSqlQueryModel * Projet::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE,DATE_START from PROJET where etat=0");

    return model;
}
QSqlQueryModel * Projet::afficher_archive()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE,DATE_START from PROJET where etat=1");

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
        model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET order by IDPROJET");
    }else if (x==2)
    {
        model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET order by IDARCHITECTE");
    }else if(x==3)
    {
        model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET order by PRIX_TOTALE");
    }else if(x==0)
    {
        model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET");
    }

    return model;
}

QSqlQueryModel * Projet::afficherrech(QString x)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,PRIX_TOTALE,LOCALISATION,IDARCHITECTE,REFERENCE from PROJET where REFERENCE like '%"+x+"%'");
    return model;
}
bool Projet::archiver(int idprojet,QString localisation,QString idarchitecte,QString reference,QString prix_totale,int etat){
    QSqlQuery query;
    query.prepare("update PROJET set LOCALISATION = :localisation, IDARCHITECTE= :idarchitecte, PRIX_TOTALE= :prix_totale, ETAT=:etat WHERE IDPROJET= :idprojet");
    query.bindValue(":idprojet", idprojet);
    query.bindValue(":localisation", localisation);
    query.bindValue(":idarchitecte", idarchitecte);
    query.bindValue(":reference", reference);
    query.bindValue(":prix_totale", prix_totale);
    query.bindValue(":etat", etat);
    return query.exec();
}

bool Projet::archiver_reverse(int idprojet,QString localisation,QString idarchitecte,QString reference,QString prix_totale,int etat){
    QSqlQuery query;
    query.prepare("update PROJET set LOCALISATION = :localisation, IDARCHITECTE= :idarchitecte, PRIX_TOTALE= :prix_totale, ETAT=:etat WHERE IDPROJET= :idprojet");
    query.bindValue(":idprojet", idprojet);
    query.bindValue(":localisation", localisation);
    query.bindValue(":idarchitecte", idarchitecte);
    query.bindValue(":reference", reference);
    query.bindValue(":prix_totale", prix_totale);
    query.bindValue(":etat", etat);
    return query.exec();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * Projet::afficher_C1()
{
    //Getting date

    int day = QDate::currentDate().day();
    QString d = QString::number(day);
    int month = QDate::currentDate().month();
    QString m = QString::number(month);
    int year = QDate::currentDate().year();
    QString y = QString::number(year);
    qDebug()<<"day: "<<day<<"year: "<<year<<"month: "<<month;
    QString Full_Date = m+'-'+d+'-'+y;
    qDebug()<<Full_Date;
    //This month Intervals//
    QString This_Month = m+'-'+QString::number(QDate::currentDate().daysInMonth())+'-'+y;
    qDebug()<<This_Month;
    //Next month Intervals//
    QString m2 = QString::number(month+1);
    QString Next_Month = m2+'-'+QString::number(01)+'-'+y;
    qDebug()<<Next_Month;
    //Next Year//
    QString y2= QString::number(year+1);
    QString Next_Year = QString::number(01)+'-'+QString::number(01)+'-'+y2;
    qDebug()<<Next_Year;
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,DATE_START from PROJET  where  to_date(DATE_START,'MM-dd-yyyy')BETWEEN to_date('"+Full_Date+"','MM-dd-yyyy') AND to_date('"+This_Month+"','MM-dd-yyyy')");
    return model;
}

QSqlQueryModel * Projet::afficher_C2()
{
    //Getting date

    int day = QDate::currentDate().day();
    QString d = QString::number(day);
    int month = QDate::currentDate().month();
    QString m = QString::number(month);
    int year = QDate::currentDate().year();
    QString y = QString::number(year);
    qDebug()<<"day: "<<day<<"year: "<<year<<"month: "<<month;
    QString Full_Date = m+'-'+d+'-'+y;
    qDebug()<<Full_Date;
    //This month Intervals//
    QString This_Month = m+'-'+QString::number(QDate::currentDate().daysInMonth())+'-'+y;
    qDebug()<<This_Month;
    //Next month Intervals//
    QString m2 = QString::number(month+1);
    QString Next_Month = m2+'-'+QString::number(01)+'-'+y;
    qDebug()<<Next_Month;
    //Next Year//
    QString y2= QString::number(year+1);
    QString Next_Year = QString::number(01)+'-'+QString::number(01)+'-'+y2;
    qDebug()<<Next_Year;
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,DATE_START from PROJET  where DATE_START like '_"+m2+"%'");
    return model;
}

QSqlQueryModel * Projet::afficher_C3()
{
    //Getting date

    int day = QDate::currentDate().day();
    QString d = QString::number(day);
    int month = QDate::currentDate().month();
    QString m = QString::number(month);
    int year = QDate::currentDate().year();
    QString y = QString::number(year);
    qDebug()<<"day: "<<day<<"year: "<<year<<"month: "<<month;
    QString Full_Date = m+'-'+d+'-'+y;
    qDebug()<<Full_Date;
    //This month Intervals//
    QString This_Month = m+'-'+QString::number(QDate::currentDate().daysInMonth())+'-'+y;
    qDebug()<<This_Month;
    //Next month Intervals//
    QString m2 = QString::number(month+1);
    QString Next_Month = m2+'-'+QString::number(01)+'-'+y;
    qDebug()<<Next_Month;
    //Next Year//
    QString y2= QString::number(year+1);
    QString Next_Year = QString::number(01)+'-'+QString::number(01)+'-'+y2;
    qDebug()<<Next_Year;
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select IDPROJET,DATE_START from PROJET  where DATE_START like '%"+y2+"'");
    return model;
}
int Projet::count()
{
    QSqlQuery query;
    query.prepare("select count(IDPROJET) from projet");
    qDebug()<<query.exec();
    return query.exec();
}

QChartView * Projet::stat()
{
    int row_count = 0;
    int row_count1 = 0;
            QSqlQuery query,query2;
            query.prepare("SELECT * FROM PROJET where etat=0");
            query.exec();
            query2.prepare("SELECT * FROM PROJET where etat=1");
            query2.exec();
            while(query2.next())
                row_count1++;
            while(query.next())
                row_count++;
            qDebug()<<row_count<<row_count1;
    QPieSeries *series = new QPieSeries();
    series->append("Archived Projects", row_count1);
    series->append("Non Archived Projects", row_count);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTheme(QChart::ChartThemeBrownSand);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setTitle("Projects Archived and non Achived stats");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
    series->setLabelsVisible();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
