#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{
    int idprojet,etat;
    QString localisation,reference,idarchitecte;
    QString prix_totale,date_start;
public:
    //Constructors
    Projet();
    Projet(QString localisation,QString idarchitecte,QString reference,QString prix_totale,QString date_start);
    //Getters
    int getIdprojet(){return idprojet;}
    int getEtat(){return etat;}
    QString getDate_start(){return date_start;}
    QString getLocalisation(){return localisation;}
    QString getIdarchitecte(){return idarchitecte;}
    QString getReference(){return reference;}
    QString getPrix_totale(){return prix_totale;}
    //Setters
    void setIdprojet(int ip){idprojet=ip;}
    void setEtat(int e){etat=e;}
    void setDate_start(int d){date_start=d;}
    void setLocalisation(QString l){localisation=l;}
    void setIdarchitecte(QString ia){idarchitecte=ia;}
    void setReference(QString r){reference=r;}
    void setPrix_totale(QString pt){prix_totale=pt;}
    //Functions
    bool ajouter();
    bool modifier(QString localisation,QString idarchitecte,QString reference,QString prix_totale,int etat);
    bool archiver(int idprojet,QString localisation,QString idarchitecte,QString reference,QString prix_totale,int etat);
    bool archiver_reverse(int idprojet,QString localisation,QString idarchitecte,QString reference,QString prix_totale,int etat);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_archive();
    bool supprimer(int id);
    QSqlQueryModel * affichertrie(int x);
    QSqlQueryModel * afficherrech(QString x);
    QSqlQueryModel *afficher_C1();
    QSqlQueryModel *afficher_C2();
    QSqlQueryModel *afficher_C3();
};

#endif // PROJET_H
