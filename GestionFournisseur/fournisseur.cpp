#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <iostream>
#include <QTableView>
using namespace std;

Fournisseur::Fournisseur()
{
    this->id = 0;
    this->age = 0;
    this->phone = 0;
    this->nom = " ";
    this->prenom = " ";
    this->email = " ";
}

Fournisseur::Fournisseur(int age,int phone,QString nom,QString prenom,QString email){
    this->age = age;
    this->phone = phone;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
}

//GETTERS
int Fournisseur::getID(){ return this->id; }
int Fournisseur::getAge(){ return this->age; }
int Fournisseur::getPhone(){ return this->phone; }
QString Fournisseur::getNom(){ return this->nom; }
QString Fournisseur::getPrenom(){ return this->prenom; }
QString Fournisseur::getEmail(){ return this->email; }

//SETTERS
void Fournisseur::setID(int id){ this->id = id; }
void Fournisseur::setAge(int age){ this->age = age; }
void Fournisseur::setPhone(int phone){ this->phone = phone; }
void Fournisseur::setNom(QString nom){ this->nom = nom; }
void Fournisseur::setPrenom(QString prenom){ this->prenom = prenom; }
void Fournisseur::setEmail(QString email){ this->email = email; }

//FUNCTIONS
bool Fournisseur::ajouterF(){

    QSqlQuery query;
       query.prepare("INSERT INTO FOURNISSEUR (NOM,PRENOM,AGE,PHONE,EMAIL) "
                     "VALUES (:NOM,:PRENOM,:AGE,:PHONE,:EMAIL)");

       query.bindValue(":NOM", this->nom);
       query.bindValue(":PRENOM", this->prenom);
       query.bindValue(":AGE", this->age);
       query.bindValue(":PHONE", this->phone);
       query.bindValue(":EMAIL", this->email);
          //query.bindValue(":REVIEW", 0);
       return  query.exec();
}

QSqlQueryModel* Fournisseur::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from FOURNISSEUR");
    return model;
}

/*
bool Fournisseur::getOneF(int id){
    QSqlQuery query;
    if(query.prepare("select * from FOURNISSEUR where ID = :id")){
        query.bindValue(":id" , id);
        qDebug() <<  5 << endl;
        return  query.exec();
    }
    return false;
}
*/
bool Fournisseur::supprimer(int id){
    QSqlQuery query;
    query.prepare("delete from FOURNISSEUR where ID = :id");
        query.bindValue(":id" , id);
        return  query.exec();
}

bool Fournisseur::modifier(int id,QString nom,QString prenom,int age,int phone,QString email){
    QSqlQuery query;
    QString id1 = QString::number(id);
    QString phone1 = QString::number(phone);

    query.prepare("update FOURNISSEUR set NOM = :nom, PRENOM= :prenom, AGE= :age, PHONE= :phone, EMAIL= :email WHERE ID = :id");
    //inj
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":phone", phone1);
    query.bindValue(":email", email);
    query.bindValue(":age", age);
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Fournisseur::chercher(QString name){
   QSqlQueryModel* model = new QSqlQueryModel();
   QString search = "%"+name+"%";
    model->setQuery("SELECT * FROM FOURNISSEUR WHERE NOM like '"+search+"'");
    //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    return model ;
}

QSqlQueryModel* Fournisseur::trie(QString attribute , QString croissance){
    QSqlQueryModel* model = new QSqlQueryModel();
    if(attribute == "ID" && croissance == "croissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY ID ASC ");
    else if (attribute == "AGE" && croissance == "croissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY AGE ASC ");
    else if(attribute == "ID" && croissance == "decroissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY ID DESC ");
    else if(attribute == "AGE" && croissance == "decroissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY AGE DESC ");
    else if(attribute == "NOM" && croissance == "croissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY NOM ASC ");
    else if(attribute == "NOM" && croissance == "decroissante")
        model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY NOM DESC ");
    return model;
}

bool Fournisseur::deleteAll(){
    QSqlQuery query;
    query.prepare("TRUNCATE TABLE FOURNISSEUR");
     return  query.exec();
}

int calculReview(QString time , QString qualite , QString communication){
    int reviewNote = 0;

    QStringList timeList;
    timeList << "very bad" << "bad" << "meduim" << "good" << "very good";

    QStringList qualiteList;
    qualiteList  << "very bad" << "bad" << "meduim" << "good" << "very good";

    QStringList communicationList;
    communicationList  << "very bad" << "bad" << "meduim" << "good" << "very good";

    switch(timeList.indexOf(time)){
            case 0: reviewNote++; break;
            case 1: reviewNote+=2; break;
            case 2: reviewNote+=3; break;
            case 3: reviewNote+=4; break;
            case 4: reviewNote+=5; break;
    }

    switch(qualiteList.indexOf(qualite)){
            case 0: reviewNote++; break;
            case 1: reviewNote+=2; break;
            case 2: reviewNote+=3; break;
            case 3: reviewNote+=4; break;
            case 4: reviewNote+=5; break;
    }

    switch(communicationList.indexOf(communication)){
            case 0: reviewNote++; break;
            case 1: reviewNote+=2; break;
            case 2: reviewNote+=3; break;
            case 3: reviewNote+=4; break;
            case 4: reviewNote+=5; break;
    }
    return qRound(double(reviewNote)/3);
    //reviewNote/=3;
   //qDebug()<< reviewNote ;

};

int Fournisseur::reviewTotale(QString id){
        int reviewTotale = 0;
        QTableView table_review;
        QSqlQueryModel * Mod=new  QSqlQueryModel();
             QSqlQuery qry;
             qry.prepare("select * from REVIEW where IDFOURNISSEUR = '"+id+"' ");
             qry.exec();
             Mod->setQuery(qry);
             table_review.setModel(Mod);

             const int ligne = table_review.model()->rowCount();

             for(int i=0;i<ligne;i++){
                    reviewTotale+=table_review.model()->data(table_review.model()->index(i, 2)).toInt();
             }

             return qRound(double(reviewTotale/ligne));

}

bool Fournisseur::updateFinalReviewFrounisseur(QString id,int review){
    QSqlQuery queryRev;
    queryRev.prepare("update FOURNISSEUR set review = :review WHERE ID = :id");
    //inj
    queryRev.bindValue(":review", review);
    queryRev.bindValue(":id", id);
    return queryRev.exec();
}

bool Fournisseur::reviewF(QString time , QString qualite , QString communication , QString id)
{

    QSqlQuery query;
       query.prepare("INSERT INTO REVIEW (IDFOURNISSEUR,REVIEWNUMBER) "
                     "VALUES (:IDFOURNISSEUR,:REVIEWNUMBER)");

       query.bindValue(":IDFOURNISSEUR", id);
       query.bindValue(":REVIEWNUMBER", calculReview(time,qualite,communication));
       //qDebug() << calculReview(time,qualite,communication);

       return  query.exec();
}

QSqlQueryModel* Fournisseur::afficherMaterielleFournisseur(QString id){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT REFERENCE,PRIX,QUANTITE,IDFOURNISSEUR from MATERIEL INNER JOIN FOURNISSEUR ON MATERIEL.IDFOURNISSEUR = "+id+" where FOURNISSEUR.id = "+id+"");
    return model;
}

bool Fournisseur::ajouterIntFacture(QString matricule , int prix , int quantite){
    QVariant a = quantite;
    bool found = false,enStock = false;
    int indiceF = 0,indiceM=0;
    QTableView table_facture,table_materiel;
        QSqlQueryModel * Mod=new  QSqlQueryModel();
           QSqlQueryModel * ModM=new  QSqlQueryModel();
             QSqlQuery qry,query,queryMinusQT;
             qry.prepare("select * from FACTURE");
             qry.exec();
             Mod->setQuery(qry);
             table_facture.setModel(Mod);


             query.prepare("select * from MATERIEL");
             query.exec();
             ModM->setQuery(query);
             table_materiel.setModel(ModM);


             const int ligne = table_facture.model()->rowCount();
             const int ligneM = table_materiel.model()->rowCount();

             for(int i=0;i<ligne;i++){
                 if(table_facture.model()->data(table_facture.model()->index(i, 0))==matricule)
                 {
                    indiceF=i;
                    found = true;
                 }
             }



             for(int i=0;i<ligneM;i++){
                 if(table_materiel.model()->data(table_materiel.model()->index(i, 2))==matricule)
                 {
                    indiceM=i;
                    enStock = true;
                 }

             }

             int qtF = table_facture.model()->data(table_facture.model()->index(indiceF, 2)).toInt();
             int qtM = table_materiel.model()->data(table_materiel.model()->index(indiceM, 7)).toInt();
                qDebug() << qtF << qtM ;
             if(found == true && enStock == true)
             {
                if(quantite <= qtM ){

                    // + f
                     qry.prepare("UPDATE FACTURE SET FACTURE.QUANTITE = FACTURE.QUANTITE + :QUANTITE WHERE FACTURE.IDMATERIELLE = :IDMATERIELLE");
                     qry.bindValue(":IDMATERIELLE", matricule);
                     qry.bindValue(":QUANTITE", quantite);

                     // - m

                     queryMinusQT.prepare("UPDATE MATERIEL SET QUANTITE = QUANTITE - :QUANTITE WHERE REFERENCE = :IDMATERIELLE AND QUANTITE>= :QUANTITE");

                     queryMinusQT.bindValue(":IDMATERIELLE", matricule);
                     queryMinusQT.bindValue(":PRIX", prix);
                     queryMinusQT.bindValue(":QUANTITE", quantite);
                     queryMinusQT.exec();
                     return qry.exec();

                }else {
                    qDebug() << "ERROR" ;
                    return false;

                }
             }else if(enStock == true and found == false){
                if(quantite > qtM ){
                    qDebug() << "ERROR" ;
                    return false;

                }else
                {
                    // tsir lajout fl facture
                    qry.prepare("INSERT INTO FACTURE (IDMATERIELLE,PRIX,QUANTITE) VALUES (:IDMATERIELLE,:PRIX,:QUANTITE)");
                    qry.bindValue(":IDMATERIELLE", matricule);
                    qry.bindValue(":PRIX", prix);
                    qry.bindValue(":QUANTITE", quantite);
                    //na9es qt fl tab materiel
                    queryMinusQT.prepare("UPDATE MATERIEL SET QUANTITE = QUANTITE - :QUANTITE WHERE REFERENCE = :IDMATERIELLE AND QUANTITE>= :QUANTITE");

                    queryMinusQT.bindValue(":IDMATERIELLE", matricule);
                    queryMinusQT.bindValue(":PRIX", prix);
                    queryMinusQT.bindValue(":QUANTITE", quantite);
                    queryMinusQT.exec();
                    return qry.exec();
                }
             }else
                 return false;
}

QSqlQueryModel* Fournisseur::afficherFacture(){
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURE");
    return model;
}


/*
stat :
nbre de fournisseur
revieeW
AKTHER WEHED ANDO MATERIELLE
*/
int Fournisseur::statNBfournisseur()
{
    int somme=0;
    QSqlQuery query;
    query.prepare("select count(ID) from FOURNISSEUR");
    if(query.exec())
    {
        while(query.next())
            somme = query.value(0).toInt();
    }
    qDebug()<<somme;
    return somme;
}

QChartView * Fournisseur::stat()
{
    int OneStar = 0;
    int TwoStar = 0;
    int ThreeStar = 0;
    int FourStar = 0;
    int FiveStar = 0;

            QSqlQuery query,query2,query3,query4,query5;
            query.prepare("SELECT * FROM FOURNISSEUR where REVIEW=1");
            query.exec();

            query2.prepare("SELECT * FROM FOURNISSEUR where REVIEW=2");
            query2.exec();

            query3.prepare("SELECT * FROM FOURNISSEUR where REVIEW=3");
            query3.exec();

            query4.prepare("SELECT * FROM FOURNISSEUR where REVIEW=4");
            query4.exec();

            query5.prepare("SELECT * FROM FOURNISSEUR where REVIEW=5");
            query5.exec();

            while(query.next())
                OneStar++;

            while(query2.next())
                TwoStar++;

            while(query3.next())
                ThreeStar++;

            while(query4.next())
                FourStar++;

            while(query5.next())
                FiveStar++;


            //qDebug()<<row_count<<row_count1;

    QPieSeries *series = new QPieSeries();
    series->append("1 etoile", OneStar);
    series->append("2 etoile", TwoStar);
    series->append("3 etoile", ThreeStar);
    series->append("4 etoile", FourStar);
    series->append("5 etoile", FiveStar);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistique sure les review des fournisseur");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
    series->setLabelsVisible();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

/*
float Crises::etatEC()
    {
    double somme=0;
    int y1(0);
    double pourcent ;
    QSqlQuery query,query1,query2,query3;
    query.prepare("select count(ID_CR) from Crises");
    if(query.exec())
    while(query.next())
    {
        somme = query.value(0).toInt();
    }
    query1.prepare("select count(ID_CR) from Crises where etat = 'En cours'");
    if(query1.exec())
        while(query1.next())
        {
            y1 = query1.value(0).toInt();
        }

        pourcent=(y1 * 100)/somme;
    return pourcent ;
}

float Crises::etatNT()
    {
    double somme=0;
    int y1(0);
    double pourcent ;
    QSqlQuery query,query1,query2,query3;
    query.prepare("select count(ID_CR) from Crises");
    if(query.exec())
    while(query.next())
    {
        somme = query.value(0).toInt();
    }
    query1.prepare("select count(ID_CR) from Crises where etat = 'Non traiter'");
    if(query1.exec())
        while(query1.next())
        {
            y1 = query1.value(0).toInt();
        }

        pourcent=(y1 * 100)/somme;
    return pourcent ;
}
*/
