#include "connection.h"
#include <QtSql>
#include <QDebug>
connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("construction");//inserer nom de l'utilisateur
db.setPassword("construction");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void connection::closeConnection(){db.close();}
