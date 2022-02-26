#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlQueryModel>


class employee
{
private:
   QString nom,prenom,type,idemployee;
   int cin,nbhtravail;
   float salaire;
public:
   employee();
   employee(QString,QString,QString,QString,int,int,float);


   //functions (les fonctions ya wlidi aaaaaaaa)
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(QString);
   bool modifier(QString,QString,QString,QString,int,float);


   //getters
   QString getnom();
   QString getoprenom();
   QString gettype();
   int getcin();
   int getnbhtravail();
   QString getid();
   float getsalaire();

   //setters
   void setnom(QString);
   void setprenom(QString);
   void setid(QString );
   void settype(QString);
void setcin(int);
void setnbhtravail(int);
void setsalaire(float);
};

#endif // EMPLOYEE_H
