#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>

class Fournisseur
{
private:
    int id,age,phone;
    QString nom,prenom,email ;

public:
    Fournisseur();
    Fournisseur(int age,int phone,QString nom,QString prenom,QString email);

    //FUNCTIONS
    bool ajouterF();
    QSqlQueryModel *afficher();
    bool supprimer(int id);
    bool modifier(int id, QString nom, QString prenom, int age, int phone, QString email);
    //bool getOneF(int id);

    //GETTERS
    int getID();
    int getAge();
    int getPhone();
    QString getNom();
    QString getPrenom();
    QString getEmail();

    //SETTERS
    void setID(int id);
    void setAge(int age);
    void setPhone(int phone);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setEmail(QString email);
};

#endif // FOURNISSEUR_H
