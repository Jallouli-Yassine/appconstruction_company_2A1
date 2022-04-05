#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
       MainWindow w;



       QSplashScreen *splash = new QSplashScreen;
               splash->setPixmap(QPixmap("E:/QT_BIGJ/gestion fournisseur/image/logoSplash.png"));
               splash->show();
               QTimer::singleShot(3000,splash,&QWidget::close);
               QTimer::singleShot(3000,&w,SLOT(show()));

    if(!test)
{
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

    return a.exec();
}
