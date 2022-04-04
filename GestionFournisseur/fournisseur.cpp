#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <iostream>
#include <QTableView>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QProcess>
using namespace std;

///CONSTRUCT
Fournisseur::Fournisseur()
{
    this->id = 0;
    this->age = 0;
    this->phone = 0;
    this->nom = " ";
    this->prenom = " ";
    this->email = " ";
}
Fournisseur::Fournisseur(int age,int phone,QString nom,QString prenom,QString email)
{
    this->age = age;
    this->phone = phone;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
}

///GETTERS
int Fournisseur::getID()
{
    return this->id;
}
int Fournisseur::getAge()
{
    return this->age;
}
int Fournisseur::getPhone()
{
    return this->phone;
}
QString Fournisseur::getNom()
{
    return this->nom;
}
QString Fournisseur::getPrenom()
{
    return this->prenom;
}
QString Fournisseur::getEmail()
{
    return this->email;
}

///SETTERS
void Fournisseur::setID(int id)
{
    this->id = id;
}
void Fournisseur::setAge(int age)
{
    this->age = age;
}
void Fournisseur::setPhone(int phone)
{
    this->phone = phone;
}
void Fournisseur::setNom(QString nom)
{
    this->nom = nom;
}
void Fournisseur::setPrenom(QString prenom)
{
    this->prenom = prenom;
}
void Fournisseur::setEmail(QString email)
{
    this->email = email;
}

///FUNCTIONS
bool Fournisseur::ajouterF()
{

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

QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from FOURNISSEUR");
    return model;
}

bool Fournisseur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from FOURNISSEUR where ID = :id");
    query.bindValue(":id", id);
    return  query.exec();
}

bool Fournisseur::modifier(int id,QString nom,QString prenom,int age,int phone,QString email)
{
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

QSqlQueryModel* Fournisseur::chercher(QString name)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString search = "%"+name+"%";
    model->setQuery("SELECT * FROM FOURNISSEUR WHERE NOM like '"+search+"'");
    //model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    return model ;
}

QSqlQueryModel* Fournisseur::trie(QString attribute, QString croissance)
{
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

bool Fournisseur::deleteAll()
{
    QSqlQuery query;
    query.prepare("TRUNCATE TABLE FOURNISSEUR");
    return  query.exec();
}

///*********************BEGIN REVIEW*********************
//calculer review choisix
int Fournisseur::calculReview(QString time, QString qualite, QString communication)
{
    int reviewNote = 0;

    QStringList timeList;
    timeList << "very bad" << "bad" << "meduim" << "good" << "very good";

    QStringList qualiteList;
    qualiteList  << "very bad" << "bad" << "meduim" << "good" << "very good";

    QStringList communicationList;
    communicationList  << "very bad" << "bad" << "meduim" << "good" << "very good";

    switch(timeList.indexOf(time))
    {
    case 0:
        reviewNote++;
        break;
    case 1:
        reviewNote+=2;
        break;
    case 2:
        reviewNote+=3;
        break;
    case 3:
        reviewNote+=4;
        break;
    case 4:
        reviewNote+=5;
        break;
    }

    switch(qualiteList.indexOf(qualite))
    {
    case 0:
        reviewNote++;
        break;
    case 1:
        reviewNote+=2;
        break;
    case 2:
        reviewNote+=3;
        break;
    case 3:
        reviewNote+=4;
        break;
    case 4:
        reviewNote+=5;
        break;
    }

    switch(communicationList.indexOf(communication))
    {
    case 0:
        reviewNote++;
        break;
    case 1:
        reviewNote+=2;
        break;
    case 2:
        reviewNote+=3;
        break;
    case 3:
        reviewNote+=4;
        break;
    case 4:
        reviewNote+=5;
        break;
    }
    return qRound(double(reviewNote)/3);
    //reviewNote/=3;
    //qDebug()<< reviewNote ;
};

//ajouter review deja calculer
bool Fournisseur::reviewF(QString time, QString qualite, QString communication, QString id)
{

    QSqlQuery query;
    query.prepare("INSERT INTO REVIEW (IDFOURNISSEUR,REVIEWNUMBER) "
                  "VALUES (:IDFOURNISSEUR,:REVIEWNUMBER)");

    query.bindValue(":IDFOURNISSEUR", id);
    query.bindValue(":REVIEWNUMBER", calculReview(time,qualite,communication));
    //qDebug() << calculReview(time,qualite,communication);

    return  query.exec();
}

//calculer review totale d'un F donner
int Fournisseur::reviewTotale(QString id)
{
    int reviewTotale = 0;
    QTableView table_review;
    QSqlQueryModel * Mod=new  QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from REVIEW where IDFOURNISSEUR = '"+id+"' ");
    qry.exec();
    Mod->setQuery(qry);
    table_review.setModel(Mod);

    const int ligne = table_review.model()->rowCount();

    for(int i=0; i<ligne; i++)
    {
        reviewTotale+=table_review.model()->data(table_review.model()->index(i, 2)).toInt();
    }

    return qRound(double(reviewTotale/ligne));

}

//tupdati chaque ajout d'un review el case review (totale) mta F
bool Fournisseur::updateFinalReviewFrounisseur(QString id,int review)
{
    QSqlQuery queryRev;
    queryRev.prepare("update FOURNISSEUR set review = :review WHERE ID = :id");
    //inj
    queryRev.bindValue(":review", review);
    queryRev.bindValue(":id", id);
    return queryRev.exec();
}
///*********************END REVIEW*********************

///*********************BEGIN FACTURE*********************
//afficher materiaux d'un fournisseur choisi
QSqlQueryModel* Fournisseur::afficherMaterielleFournisseur(QString id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT REFERENCE,PRIX,QUANTITE,IDFOURNISSEUR from MATERIEL INNER JOIN FOURNISSEUR ON MATERIEL.IDFOURNISSEUR = "+id+" where FOURNISSEUR.id = "+id+"");
    return model;
}

//Ajouter mateiraux dans fact
bool Fournisseur::ajouterIntFacture(QString matricule, int prix, int quantite)
{
    bool found = false,enStock = false;
    int indiceM=0;
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

    //deja dans la facutre ou non
    for(int i=0; i<ligne; i++)
    {
        if(table_facture.model()->data(table_facture.model()->index(i, 0))==matricule)
            found = true;
    }

    //en stock ou non dans materielle
    for(int i=0; i<ligneM; i++)
    {
        if(table_materiel.model()->data(table_materiel.model()->index(i, 2))==matricule)
        {
            indiceM=i;
            enStock = true;
        }
    }

    //int qtF = table_facture.model()->data(table_facture.model()->index(indiceF, 2)).toInt();
    int qtM = table_materiel.model()->data(table_materiel.model()->index(indiceM, 7)).toInt();
    //qDebug() << qtF << qtM ;
    if(found == true && enStock == true)
    {
        if(quantite <= qtM )
        {

            // ++qtF
            qry.prepare("UPDATE FACTURE SET FACTURE.QUANTITE = FACTURE.QUANTITE + :QUANTITE WHERE FACTURE.IDMATERIELLE = :IDMATERIELLE");
            qry.bindValue(":IDMATERIELLE", matricule);
            qry.bindValue(":QUANTITE", quantite);

            // --qtM
            queryMinusQT.prepare("UPDATE MATERIEL SET QUANTITE = QUANTITE - :QUANTITE WHERE REFERENCE = :IDMATERIELLE AND QUANTITE>= :QUANTITE");
            queryMinusQT.bindValue(":IDMATERIELLE", matricule);
            queryMinusQT.bindValue(":QUANTITE", quantite);
            queryMinusQT.exec();
            return qry.exec();

        }
        else
        {
            QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                                    QObject::tr("ERROR Quantite insufisante\n""Click to Cancel."), QMessageBox::Cancel);
            return false;
        }
    }
    else if(enStock == true and found == false)
    {
        if(quantite > qtM )
        {
            QMessageBox::critical  (nullptr, QObject::tr("not OK"),
                                    QObject::tr("ERROR Quantite insufisante\n""Click to Cancel."), QMessageBox::Cancel);
            return false;

        }
        else
        {
            // ajout M in Facture
            qry.prepare("INSERT INTO FACTURE (IDMATERIELLE,PRIX,QUANTITE) VALUES (:IDMATERIELLE,:PRIX,:QUANTITE)");
            qry.bindValue(":IDMATERIELLE", matricule);
            qry.bindValue(":PRIX", prix);
            qry.bindValue(":QUANTITE", quantite);

            //--qtM
            queryMinusQT.prepare("UPDATE MATERIEL SET QUANTITE = QUANTITE - :QUANTITE WHERE REFERENCE = :IDMATERIELLE AND QUANTITE>= :QUANTITE");
            queryMinusQT.bindValue(":IDMATERIELLE", matricule);
            queryMinusQT.bindValue(":QUANTITE", quantite);
            queryMinusQT.exec();
            return qry.exec();
        }
    }
    else
        return false;
}

void Fournisseur::genererFacture(int *prixTotale)
{
    QTableView table_facture;
    QSqlQueryModel * Mod=new  QSqlQueryModel();
    //QString value=ui->reviewFID->text();

    QSqlQuery qry;

    qry.prepare("select * from FACTURE");
    qry.exec();
    Mod->setQuery(qry);
    table_facture.setModel(Mod);

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = table_facture.model()->rowCount();

    const int columnCount =  table_facture.model()->columnCount();

    const QString strTitle ="FACTURE";
    out <<  "<html>\n"
        "<img src='E:/QT_BIGJ/gestion fournisseur/image/logo.png' height='120' width='120'/>"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
        "<body bgcolor=#ffffff>\n"
        << QString("<h3 style=\" font-size: 50px; font-family: Lato, Helvetica, sans-serif; color: #001F26; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Facture D'achat")
        <<"<br>"

        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
    out << "<thead><tr bgcolor=#F3F617>";
//afficher colonne headers (idmat,prix,qt):
    for (int column = 0; column < columnCount; column++)
            out << QString("<th color:#FFFFFF>%1</th>").arg(table_facture.model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

//afficher ligne+colonne (données):
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++)
        {
                QString data = table_facture.model()->data(table_facture.model()->index(row, column)).toString().simplified();
                out << QString("<th>%1</th>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n";

    out <<"<br> <br>";

    out <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
    out << "<thead><tr bgcolor=#F3F617>";
    out << QString("<th>%1</th>").arg("PRIX TOTALE");
    out << "<tr>";
    out << QString("<th>%1</th>").arg(*prixTotale);
    out << "</tr>";
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted)
        document->print(&printer);
    delete dialog;
    delete document;
    QSqlQuery query;
    query.prepare("TRUNCATE TABLE FACTURE");
    query.exec();

    //qDebug()<<prixTotale;

    (*prixTotale) = 0;
}

QSqlQueryModel* Fournisseur::afficherFacture()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURE");
    return model;
}
///*********************END FACTURE*********************

///*********************BEGIN STATISTIQUE*********************
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
    chart->setTitle("statistique sure les review des fournisseurs");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(0,31,38,1)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
    series->setLabelsVisible();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing,true);

    return chartView;
}
///*********************END STATISTIQUE*********************
