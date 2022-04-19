#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include <QMainWindow>
#include <employee.h>
#include<qrcodegen.hpp>
#include "arduino.h"
#include "fournisseur.h"
#include<QTimer>







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

    void on_TEST_clicked();

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


private:
    Ui::MainWindow *ui;
    employee E;
    Fournisseur F;
    QByteArray data;
    arduino A;
    QString uid;
    QTimer timer;

};
#endif // MAINWINDOW_H
