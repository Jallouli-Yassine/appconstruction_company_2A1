#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class materiel
{
    QString reference,nom,matricule,idfournisseur;
    int quantite,prix,etat;
public:
    materiel();
    materiel(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,int etat);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trie();
    bool ajouter();
    bool supprimer(QString reference);
    bool modifier(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,int etat);
//getters
int getQuantite(){return quantite;}
int getPrix(){return prix;}
int getEtat(){return etat;}
QString getReference(){return reference;}
QString getNom(){return nom;}
QString getMatricule(){return  matricule;}
QString getIdfournisseur(){return idfournisseur;}
QSqlQueryModel* chercher(QString name);
//setters
void setQuantite(int q){quantite=q;}
void setPrix(int pt){prix=pt;}
void setEtat(int et){etat=et;}
void setReference(QString r){reference=r;}
void setNom(QString n){nom=n;}
void setMatricule(QString mat){matricule=mat;}
void setIdfournisseur(QString id){idfournisseur=id;}

};
#endif // MATERIEL_H
