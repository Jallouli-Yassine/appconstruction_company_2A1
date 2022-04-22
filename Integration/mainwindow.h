#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include <QMainWindow>
#include <employee.h>
#include<qrcodegen.hpp>
#include "arduino.h"
#include "fournisseur.h"
#include<QTimer>
#include "projet.h"

#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
QT_CHARTS_USE_NAMESPACE




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int prixTotale = 0;


private slots:
//********************Bousbih********************************
    void on_pb_ajouter_clicked();

    void on_supprimer_clicked();


    void on_modifier_clicked();

    void on_chercher_clicked();

    void on_tri_activated(const QString &arg1);
    
    void on_QR_clicked();

    void on_pdf_clicked();

    void on_tabemp_activated(const QModelIndex &index);


//**********************************************jallouli************************************
    void on_ajouterF_clicked();

    void on_deleteFbtn_clicked();

    void on_LoadData_clicked();

    void on_updateBTN_clicked();

    void on_triBTN_clicked();

    void on_chercherID_clicked();

    void on_Ftable_activated(const QModelIndex &index);

    void on_deleteAll_clicked();

    void on_Freview_activated(const QModelIndex &index);


    void on_postReview_clicked();

    void on_Tabmaterielle_activated(const QModelIndex &index);

    void on_genererFacture_clicked();

    void on_ajouterIntoFacture_clicked();

    void update_label();
    void concatRfid();
    void addHours(QString RFID);


    void on_GestiondesEmployee_clicked();

    void on_GestiondesFournisseurs_clicked();

    void on_GestiondesArchitects_clicked();

    void on_GestiondesClients_clicked();

    void on_GestiondesProjets_clicked();

    void on_GestiondesMateriaux_clicked();

    void on_retmenu_clicked();

    void on_retmenu_2_clicked();

    /* Yosr*/
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    //void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);


    void on_comboBox_currentIndexChanged(int index);


    void on_pushButton_2_clicked();


    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_archive_clicked();

    void on_pushremove_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);


    void on_calendarWidget_clicked(const QDate &date);




    void on_pushPDF_clicked();

    void on_Chart_clicked();



    void on_pushButton_off_clicked();

    /* Yosr*/
private:
    Ui::MainWindow *ui;
    employee E;
    Fournisseur F;
    QByteArray data;
    arduino A;
    QString uid;
    QTimer timer;
    Projet *ptmp;
};
#endif // MAINWINDOW_H
