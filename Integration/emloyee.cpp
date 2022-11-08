#include "emloyee.h"
#include<QString>

employee::employee()
{
cin="";
prenom="";
nom="";
id="";
}
void employee::setcin(QString n){cin=n;}
void employee::setprenom (QString n){prenom=n;}
void employee::setnom (QString n){nom=n;}
void employee::setid (QString n){nom=n;}

QString employee::get_cin(){return cin;}
QString employee::get_id(){return id;}
QString employee::get_prenom (){return prenom;}
QString employee::get_nom(){return nom;}
