#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

#include <QSplashScreen>
#include <QTimer>
#include <QApplication>
#include <QLabel>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();

    MainWindow w;

    QMovie *movie = new QMovie("E:/QT_BIGJ/gestion fournisseur/image/splashGif.gif");
    QLabel *processLabel = new QLabel(nullptr);

    processLabel->resize(1366,768);  // to make sure its large enough

    processLabel->setMovie(movie);
    processLabel->setWindowFlags(Qt::FramelessWindowHint);
    processLabel->setAlignment(Qt::AlignCenter);
    processLabel->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,processLabel->size(),qApp->desktop()->availableGeometry()));

    movie->start();
    processLabel->show();

    QTimer::singleShot(5000,processLabel,SLOT(close()));
    QTimer::singleShot(5000,&w,SLOT(show()));



            if(!test)
        {
                QMessageBox::information(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

        return a.exec();
}
