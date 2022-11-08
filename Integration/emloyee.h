#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class employee
{
private:
   QString nom,prenom,type;
   int cin,nbhtravail,idemployee;
   float salaire;
public:
   employee();
   employee(QString,QString,QString,int,int,int,float);
   bool ajouter();

   //getters
   QString getnom();
   QString getoprenom();
   QString gettype();
   int getcin();
   int getnbhtravail();
   int getid();
   float getsalaire();

   //setters
   void setnom(QString);
   void setprenom(QString);
   void setid(int id);
   void settype(QString);
void setcin(int);
void setnbhtravail(int);
void setsalaire(float);
};

#endif // EMPLOYEE_H
