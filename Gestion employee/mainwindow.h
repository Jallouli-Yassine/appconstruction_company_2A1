#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include <QMainWindow>
#include <employee.h>

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
    void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    employee E;
};
#endif // MAINWINDOW_H
