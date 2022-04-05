#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "login.h"


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
    void on_b_ajouter_clicked();

    void on_pushButton_3_clicked();

    void on_pb_supp_clicked();


    void on_pb_trienom_clicked();

    void on_pb_trie_prenom_clicked();

    void on_pb_tri_id_clicked();



    void on_cherch_textChanged(const QString &arg1);

    void on_cherch_2_returnPressed();

    void on_b_ajouter_2_clicked();

    void on_tab_client_4_activated(const QModelIndex &index);

    void on_pushButton_insertbutton_clicked();

    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Client c;
};

#endif // MAINWINDOW_H
