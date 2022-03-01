#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_project2A1");
db.setUserName("mehdi1");//inserer nom de l'utilisateur
db.setPassword("mehdi");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
