#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "architect.h"
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_5_clicked();

    void on_pushButtonAfficherDech_2_clicked();

    void on_pushButtonrechdech_2_clicked();
    void on_pushButton_8_clicked();

    void on_EnregistrerPB_3_clicked();

    void on_EnregistrerPB_2_clicked();

    void on_EnregistrerPB_4_clicked();

    void on_pdf_clicked();

    void on_excel_clicked();

    void on_connexion_clicked();

    void on_pushButtonAfficherDech_3_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
     QStringList files;
    Architect A;
};

#endif // MAINWINDOW_H
