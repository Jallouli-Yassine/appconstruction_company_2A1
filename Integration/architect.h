#ifndef ARCHITECT_H
#define ARCHITECT_H
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE

class Architect
{

public:
     Architect();
     Architect(int,QString,QString,int,QString,QString);
     int getid();
     QString getnom();
     QString getprenom();
     int getntel();
     QString getemail();
        QString getetat();
     void setid(int);
     void setnom(QString);
     void setprenom(QString);
     void setntel(int);
     void setemail(QString);
     void setetat(QString);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int,QString,QString,int,QString,QString);
     QSqlQueryModel* chercher(QString);
     QSqlQueryModel* trie(QString attribute , QString croissance);
     QChartView * stat();

private:
    int id,ntel;
    QString nom,prenom,email,etat;
};

#endif // ARCHITECT_H
