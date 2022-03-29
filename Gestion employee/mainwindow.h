#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include <QMainWindow>
#include <employee.h>
#include<qrcodegen.hpp>




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

    void on_pb_ajouter_clicked();

    void on_supprimer_clicked();


    void on_modifier_clicked();

    void on_chercher_clicked();

    void on_tri_activated(const QString &arg1);
    
    void on_QR_clicked();

    void on_pdf_clicked();

    void on_tabemp_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    employee E;


};
#endif // MAINWINDOW_H
