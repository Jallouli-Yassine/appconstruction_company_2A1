#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
    bool test=c.createconnect();
    MainWindow w;
    QSplashScreen *splash = new QSplashScreen;
                   splash->setPixmap(QPixmap("C:/2A1/Esprit-2A/project c++/c_logo.png"));
                   splash->show();
                   QTimer::singleShot(3000,splash,&QWidget::close);
                   QTimer::singleShot(3000,&w,SLOT(show()));
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


return a.exec();
}
