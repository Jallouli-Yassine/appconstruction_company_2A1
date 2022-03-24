#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class materiel
{
    QString reference,nom,matricule,idfournisseur,etat;
    int quantite,prix;
public:
    materiel();
    materiel(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,QString etat);
    QSqlQueryModel * afficher();
    QSqlQueryModel * trie();
    bool ajouter();
    bool supprimer(QString reference);
    bool modifier(QString reference,QString nom,QString matricule,QString idfournisseur,int quantite,int prix,QString etat);
//getters
int getQuantite(){return quantite;}
int getPrix(){return prix;}
QString getEtat(){return etat;}
QString getReference(){return reference;}
QString getNom(){return nom;}
QString getMatricule(){return  matricule;}
QString getIdfournisseur(){return idfournisseur;}
QSqlQueryModel* chercher(QString name);
//setters
void setQuantite(int q){quantite=q;}
void setPrix(int pt){prix=pt;}
void setEtat(QString et){etat=et;}
void setReference(QString r){reference=r;}
void setNom(QString n){nom=n;}
void setMatricule(QString mat){matricule=mat;}
void setIdfournisseur(QString id){idfournisseur=id;}

};
#endif // MATERIEL_H
