/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame;
    QLineEdit *age;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *tel;
    QLineEdit *email;
    QPushButton *ajouterF;
    QPushButton *pushButton_3;
    QWidget *afficherF;
    QFrame *frame_2;
    QPushButton *LoadData;
    QTableView *Ftable;
    QWidget *tab_3;
    QFrame *frame_3;
    QGroupBox *groupBox_5;
    QLineEdit *deleteID;
    QPushButton *deleteFbtn;
    QGroupBox *groupBox_8;
    QLineEdit *updateID;
    QPushButton *updateBTN;
    QLineEdit *nomUpdate;
    QLineEdit *prenomUpdate;
    QLineEdit *ageUpdate;
    QLineEdit *telUpdate;
    QLineEdit *emailUpdate;
    QWidget *tab_4;
    QFrame *frame_4;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonStatistiques;
    QComboBox *croissanceBox;
    QComboBox *attributeBox;
    QPushButton *triBTN;
    QTableView *TriTable;
    QGroupBox *groupBox_3;
    QLineEdit *searchIDinput;
    QPushButton *chercherID_2;
    QTableView *searchTable_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1319, 669);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(130, 80, 851, 511));
        tabWidget->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 851, 491));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"}\n"
"\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"transform: scale(1.2); \n"
"width : 250px;\n"
"color:#F3D617;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#a0a0a0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #333;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        age = new QLineEdit(frame);
        age->setObjectName(QStringLiteral("age"));
        age->setGeometry(QRect(80, 220, 141, 20));
        nom = new QLineEdit(frame);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(80, 150, 141, 20));
        prenom = new QLineEdit(frame);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(280, 150, 161, 20));
        prenom->setMaximumSize(QSize(16777215, 20));
        tel = new QLineEdit(frame);
        tel->setObjectName(QStringLiteral("tel"));
        tel->setGeometry(QRect(280, 220, 161, 20));
        email = new QLineEdit(frame);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(80, 290, 361, 20));
        ajouterF = new QPushButton(frame);
        ajouterF->setObjectName(QStringLiteral("ajouterF"));
        ajouterF->setGeometry(QRect(170, 380, 151, 31));
        ajouterF->setCursor(QCursor(Qt::PointingHandCursor));
        ajouterF->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 90, 311, 331));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/moham/OneDrive/Bureau/c++_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(250, 250));
        tabWidget->addTab(tab, QString());
        afficherF = new QWidget();
        afficherF->setObjectName(QStringLiteral("afficherF"));
        frame_2 = new QFrame(afficherF);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(-10, 0, 861, 491));
        frame_2->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"}\n"
"\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"transform: scale(1,3); \n"
"color:red;\n"
"}\n"
"\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"color:black;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QTableWidget{\n"
"border:none;\n"
"}\n"
"\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        LoadData = new QPushButton(frame_2);
        LoadData->setObjectName(QStringLiteral("LoadData"));
        LoadData->setGeometry(QRect(330, 300, 231, 171));
        LoadData->setCursor(QCursor(Qt::PointingHandCursor));
        LoadData->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral("C:/Users/moham/Downloads/800px-Cloud_Upload_-_The_Noun_Project.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoadData->setIcon(icon1);
        LoadData->setIconSize(QSize(200, 200));
        LoadData->setAutoDefault(false);
        LoadData->setFlat(false);
        Ftable = new QTableView(frame_2);
        Ftable->setObjectName(QStringLiteral("Ftable"));
        Ftable->setGeometry(QRect(150, 110, 531, 192));
        tabWidget->addTab(afficherF, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        frame_3 = new QFrame(tab_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(-1, -1, 851, 491));
        frame_3->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"}\n"
"\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"transform: scale(1,3); \n"
"color:red;\n"
"}\n"
"\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"color:black;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QTableWidget{\n"
"border:none;\n"
"}\n"
"\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox_5 = new QGroupBox(frame_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(440, 290, 351, 181));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:red;\n"
"border-radius:16px;\n"
"}\n"
"QPushButton:hover {\n"
"transform: scale(5); \n"
"width : 250px;\n"
"color:#F3D617;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#a0a0a0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #333;\n"
"}"));
        deleteID = new QLineEdit(groupBox_5);
        deleteID->setObjectName(QStringLiteral("deleteID"));
        deleteID->setGeometry(QRect(40, 80, 113, 22));
        deleteFbtn = new QPushButton(groupBox_5);
        deleteFbtn->setObjectName(QStringLiteral("deleteFbtn"));
        deleteFbtn->setGeometry(QRect(180, 80, 151, 31));
        deleteFbtn->setCursor(QCursor(Qt::PointingHandCursor));
        deleteFbtn->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        groupBox_8 = new QGroupBox(frame_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(30, 240, 351, 241));
        groupBox_8->setFont(font);
        groupBox_8->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:red;\n"
"border-radius:16px;\n"
"}\n"
"QPushButton:hover {\n"
"transform: scale(5); \n"
"width : 250px;\n"
"color:#F3D617;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#a0a0a0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #333;\n"
"}"));
        updateID = new QLineEdit(groupBox_8);
        updateID->setObjectName(QStringLiteral("updateID"));
        updateID->setGeometry(QRect(250, 100, 71, 31));
        updateBTN = new QPushButton(groupBox_8);
        updateBTN->setObjectName(QStringLiteral("updateBTN"));
        updateBTN->setGeometry(QRect(240, 180, 91, 31));
        updateBTN->setCursor(QCursor(Qt::PointingHandCursor));
        updateBTN->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        nomUpdate = new QLineEdit(groupBox_8);
        nomUpdate->setObjectName(QStringLiteral("nomUpdate"));
        nomUpdate->setGeometry(QRect(40, 40, 61, 20));
        prenomUpdate = new QLineEdit(groupBox_8);
        prenomUpdate->setObjectName(QStringLiteral("prenomUpdate"));
        prenomUpdate->setGeometry(QRect(40, 160, 101, 20));
        prenomUpdate->setMaximumSize(QSize(16777215, 20));
        ageUpdate = new QLineEdit(groupBox_8);
        ageUpdate->setObjectName(QStringLiteral("ageUpdate"));
        ageUpdate->setGeometry(QRect(40, 80, 61, 20));
        telUpdate = new QLineEdit(groupBox_8);
        telUpdate->setObjectName(QStringLiteral("telUpdate"));
        telUpdate->setGeometry(QRect(40, 120, 91, 20));
        emailUpdate = new QLineEdit(groupBox_8);
        emailUpdate->setObjectName(QStringLiteral("emailUpdate"));
        emailUpdate->setGeometry(QRect(40, 200, 121, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        frame_4 = new QFrame(tab_4);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 861, 491));
        frame_4->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"}\n"
"\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"transform: scale(1,3); \n"
"color:red;\n"
"}\n"
"\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"color:black;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QTableWidget{\n"
"border:none;\n"
"}\n"
"\n"
"\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        groupBox_4 = new QGroupBox(frame_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 70, 411, 181));
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:red;\n"
"border-radius:16px;\n"
"}\n"
"QPushButton:hover {\n"
"transform: scale(5); \n"
"width : 250px;\n"
"color:#F3D617;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#a0a0a0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #333;\n"
"}\n"
"\n"
""));
        pushButtonStatistiques = new QPushButton(groupBox_4);
        pushButtonStatistiques->setObjectName(QStringLiteral("pushButtonStatistiques"));
        pushButtonStatistiques->setGeometry(QRect(170, 380, 271, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonStatistiques->setFont(font1);
        pushButtonStatistiques->setStyleSheet(QLatin1String("QFrame{\n"
"background:#333;\n"
"\n"
"}\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:red;\n"
"border-radius:16px;\n"
"}\n"
"QPushButton:hover {\n"
"color:blue;\n"
"border-size:20px;\n"
"background:#333\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#b0b0b0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #fefff4;\n"
"}\n"
"QTableWidget{\n"
"background:transparent;\n"
"border:none;\n"
"}\n"
"QTableWidget:hover{\n"
"border:3px;\n"
"}\n"
""));
        croissanceBox = new QComboBox(groupBox_4);
        croissanceBox->setObjectName(QStringLiteral("croissanceBox"));
        croissanceBox->setGeometry(QRect(260, 50, 131, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        croissanceBox->setFont(font2);
        croissanceBox->setStyleSheet(QLatin1String("border: 1px solid;\n"
"border-color:rgb(0, 0, 0);\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"    color: rgb(220, 220, 220);\n"
"    background-color:rgb(89, 155, 255);\n"
"    margin: 0 0 0 0;"));
        attributeBox = new QComboBox(groupBox_4);
        attributeBox->setObjectName(QStringLiteral("attributeBox"));
        attributeBox->setGeometry(QRect(40, 50, 131, 31));
        attributeBox->setFont(font2);
        attributeBox->setStyleSheet(QLatin1String("border: 1px solid;\n"
"border-color:rgb(0, 0, 0);\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"    color: rgb(220, 220, 220);\n"
"    background-color:rgb(89, 155, 255);\n"
"    margin: 0 0 0 0;"));
        triBTN = new QPushButton(groupBox_4);
        triBTN->setObjectName(QStringLiteral("triBTN"));
        triBTN->setGeometry(QRect(140, 120, 151, 31));
        triBTN->setCursor(QCursor(Qt::PointingHandCursor));
        triBTN->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        TriTable = new QTableView(frame_4);
        TriTable->setObjectName(QStringLiteral("TriTable"));
        TriTable->setGeometry(QRect(450, 80, 381, 171));
        groupBox_3 = new QGroupBox(frame_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 280, 761, 181));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:white;\n"
"font-size:16px;\n"
"}\n"
"QPushButton\n"
"{\n"
"background:red;\n"
"border-radius:16px;\n"
"}\n"
"QPushButton:hover {\n"
"transform: scale(5); \n"
"width : 250px;\n"
"color:#F3D617;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"border-radius:15px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#a0a0a0;\n"
"font-size:16px;\n"
"border-bottom:1px solid #333;\n"
"}"));
        searchIDinput = new QLineEdit(groupBox_3);
        searchIDinput->setObjectName(QStringLiteral("searchIDinput"));
        searchIDinput->setGeometry(QRect(40, 90, 113, 22));
        chercherID_2 = new QPushButton(groupBox_3);
        chercherID_2->setObjectName(QStringLiteral("chercherID_2"));
        chercherID_2->setGeometry(QRect(180, 90, 151, 31));
        chercherID_2->setCursor(QCursor(Qt::PointingHandCursor));
        chercherID_2->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        searchTable_2 = new QTableView(groupBox_3);
        searchTable_2->setObjectName(QStringLiteral("searchTable_2"));
        searchTable_2->setGeometry(QRect(360, 40, 351, 121));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1319, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        age->setText(QString());
        age->setPlaceholderText(QApplication::translate("MainWindow", "age", Q_NULLPTR));
        nom->setText(QString());
        nom->setPlaceholderText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        prenom->setText(QString());
        prenom->setPlaceholderText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        tel->setText(QString());
        tel->setPlaceholderText(QApplication::translate("MainWindow", "tel", Q_NULLPTR));
        email->setText(QString());
        email->setPlaceholderText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        ajouterF->setText(QApplication::translate("MainWindow", "ajouter fournisseur", Q_NULLPTR));
        pushButton_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ajouter fournisseur", Q_NULLPTR));
        LoadData->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(afficherF), QApplication::translate("MainWindow", "liste de fournisseurs", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "supprimer fournisseur", Q_NULLPTR));
        deleteID->setText(QString());
        deleteID->setPlaceholderText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        deleteFbtn->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "modifer fournisseur", Q_NULLPTR));
        updateID->setText(QString());
        updateID->setPlaceholderText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        updateBTN->setText(QApplication::translate("MainWindow", "modifer", Q_NULLPTR));
        nomUpdate->setText(QString());
        nomUpdate->setPlaceholderText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        prenomUpdate->setText(QString());
        prenomUpdate->setPlaceholderText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        ageUpdate->setText(QString());
        ageUpdate->setPlaceholderText(QApplication::translate("MainWindow", "age", Q_NULLPTR));
        telUpdate->setText(QString());
        telUpdate->setPlaceholderText(QApplication::translate("MainWindow", "tel", Q_NULLPTR));
        emailUpdate->setText(QString());
        emailUpdate->setPlaceholderText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "chercher/tri", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "TRI", Q_NULLPTR));
        pushButtonStatistiques->setText(QApplication::translate("MainWindow", "STATISTIQUES", Q_NULLPTR));
        croissanceBox->clear();
        croissanceBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "croissante", Q_NULLPTR)
         << QApplication::translate("MainWindow", "decroissante", Q_NULLPTR)
        );
        attributeBox->clear();
        attributeBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "AGE", Q_NULLPTR)
         << QApplication::translate("MainWindow", "NOM", Q_NULLPTR)
        );
        triBTN->setText(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Recherche par ID", Q_NULLPTR));
        searchIDinput->setPlaceholderText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        chercherID_2->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
