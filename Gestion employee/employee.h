#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlQueryModel>
#include<istream>
#include<fstream>
#include<vector>
#include<QFileDialog>
#include<QPixmap>
#include<QPainter>
#include<QtSvg/QSvgRenderer>
#include<qrcodegen.hpp>
#include<QMainWindow>
#include "qtablewidget.h"








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
   QSqlQueryModel* chercher(QString );
   QSqlQueryModel* tri(QString);
   bool calculeprime(QString id);



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
