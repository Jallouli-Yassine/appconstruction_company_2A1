#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "architect.h"
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
private:
    Ui::MainWindow *ui;
    Architect A;
};

#endif // MAINWINDOW_H
