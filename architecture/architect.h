#ifndef ARCHITECT_H
#define ARCHITECT_H
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>


class Architect
{
public:
     Architect();
     Architect(int,QString,QString,int,QString);
     int getid();
     QString getnom();
     QString getprenom();
     int getntel();
     QString getemail();
     void setid(int);
     void setnom(QString);
     void setprenom(QString);
     void setntel(int);
     void setemail(QString);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int,QString,QString,int,QString);
     QSqlQueryModel* chercher(QString);
     QSqlQueryModel* trie(QString attribute , QString croissance);
private:
    int id,ntel;
    QString nom,prenom,email;
};

#endif // ARCHITECT_H
