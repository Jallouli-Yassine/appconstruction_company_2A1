#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //type de base de donne
db.setDatabaseName("construction_company");
db.setUserName("jallouli");//inserer nom de l'utilisateur
db.setPassword("system");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
