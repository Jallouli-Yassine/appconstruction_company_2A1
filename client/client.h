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
    QSqlQueryModel *afficher();
    QSqlQueryModel *affichenom();
    QSqlQueryModel *afficheprenom();
    QSqlQueryModel *afficheid();
    QSqlQueryModel *rechercheid(QString);

    bool supprimer(QString);


private:
    QString nom,prenom,email,DDN;
    int num, id ;



};


#endif // CLIENT_H
