#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "materiel.h"
#include <QMainWindow>

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


    void on_ButtonAjouter_2_clicked();

    void on_ButtonSupprimer_clicked();

    void on_ButtonTri_clicked();

    void on_ButtonAjouter_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_ButtonTri_2_clicked();

    void on_Buttonrecherche_clicked();

    void on_PDF_clicked();

    void on_comboBox_4_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    materiel *m;
};
#endif // MAINWINDOW_H
