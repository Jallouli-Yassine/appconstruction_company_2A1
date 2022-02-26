#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QAbstractItemView>
#include <QString>
#include <QDebug>
#include <QListWidget>
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QDateTime>
#include <QCalendarWidget>
#include <QTableWidget>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterF_clicked();

    void on_deleteFbtn_clicked();

    void on_LoadData_clicked();

    void on_updateBTN_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
};
#endif // MAINWINDOW_H
