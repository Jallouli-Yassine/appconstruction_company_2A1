#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include"Client.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE


class Client
{
public:
    Client();
    Client(int,int,QString,QString,QString,QString);
    int getnum();
    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getDDN();
    void setnum(int);
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setDDN(QString);
    bool ajoute();
    bool ajoutrdv(QString,QString);
    QSqlQueryModel *afficherrdv();
    QSqlQueryModel *afficher();
    QSqlQueryModel *affichenom();
    QSqlQueryModel *afficheprenom();
    QSqlQueryModel *afficheid();
    QSqlQueryModel *rechercheid(QString);
     bool modifier(int,int,QString,QString,QString,QString);
    bool supprimer(QString);
    QChartView *stat();


private:
    QString nom,prenom,email,DDN;
    int num, id ;



};


#endif // CLIENT_H
