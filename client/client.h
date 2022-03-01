#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include"Client.h"
#include <QSqlQueryModel>
#include <QMessageBox>
class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString);
    int getnum();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getDDN();
    void setnum(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setDDN(QString);
    bool ajoute();
    QSqlQueryModel *afficher();
    bool supprimer(QString);


private:
    QString nom,prenom,email,DDN;
    int num;



};


#endif // CLIENT_H
