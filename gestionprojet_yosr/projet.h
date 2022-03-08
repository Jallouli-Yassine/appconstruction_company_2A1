#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{
    int idprojet,etat;
    QString localisation,reference,idarchitecte;
    QString prix_totale;
public:
    //Constructors
    Projet();
    Projet(QString localisation,QString idarchitecte,QString reference,QString prix_totale);
    //Getters
    int getIdprojet(){return idprojet;}
    QString getLocalisation(){return localisation;}
    QString getIdarchitecte(){return idarchitecte;}
    QString getReference(){return reference;}
    QString getPrix_totale(){return prix_totale;}
    //Setters
    void setIdprojet(int ip){idprojet=ip;}
    void setLocalisation(QString l){localisation=l;}
    void setIdarchitecte(QString ia){idarchitecte=ia;}
    void setReference(QString r){reference=r;}
    void setPrix_totale(QString pt){prix_totale=pt;}
    //Functions
    bool ajouter();
    bool modifier(QString localisation,QString idarchitecte,QString reference,QString prix_totale);
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    QSqlQueryModel * affichertrie(int x);
    QSqlQueryModel * afficherrech(QString x);

};

#endif // PROJET_H
