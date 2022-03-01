#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{
    int idprojet;
    QString localisation,idarchitecte,reference;
    int prix_totale;
public:
    //Constructors
    Projet();
    Projet(QString localisation,QString idarchitecte,QString reference,int prix_totale);
    //Getters
    int getIdprojet(){return idprojet;}
    QString getLocalisation(){return localisation;}
    QString getIdarchitecte(){return idarchitecte;}
    QString getReference(){return reference;}
    float getPrix_totale(){return prix_totale;}
    //Setters
    void setIdprojet(int ip){idprojet=ip;}
    void setLocalisation(QString l){localisation=l;}
    void setIdarchitecte(QString ia){idarchitecte=ia;}
    void setReference(QString r){reference=r;}
    void setPrix_totale(int pt){prix_totale=pt;}
    //Functions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    QSqlQueryModel * affichertrie(int x);
    //QSqlQueryModel * afficherrech(QString x);
};

#endif // PROJET_H
