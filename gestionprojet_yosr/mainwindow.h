#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projet.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


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

private:
    Ui::MainWindow *ui;
    Projet *ptmp;
};
#endif // MAINWINDOW_H
