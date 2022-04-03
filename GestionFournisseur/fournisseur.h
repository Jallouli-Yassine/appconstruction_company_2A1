#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE

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
    QSqlQueryModel* chercher(QString nom);
    QSqlQueryModel* trie(QString attribute , QString croissance);
    bool deleteAll();
    int calculReview(QString time , QString qualite , QString communication);
    bool reviewF(QString time , QString qualite , QString communication , QString id);
    QSqlQueryModel *afficherMaterielleFournisseur(QString id);
    bool ajouterIntFacture(QString matricule , int prix , int quantite);
    QSqlQueryModel* afficherFacture();
    int statNBfournisseur();
    QChartView * stat();
    bool updateFinalReviewFrounisseur(QString id,int review);
    int reviewTotale(QString id);
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
