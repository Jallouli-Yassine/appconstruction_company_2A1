#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
//#include <QtCharts/QChartView>
//#include <QtCharts/QPieSeries>
//#include <QtCharts/QPieSlice>
//QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QPieSeries *series = new QPieSeries();
//    series->append("Jane", 1);
//    series->append("Joe", 1);
//    QChart *chart = new QChart();
//    chart->addSeries(series);
//    chart->setTitle("Simple piechart example");
//    chart->legend()->hide();
//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);


    connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
return a.exec();
}
