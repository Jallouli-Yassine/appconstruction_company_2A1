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
#include <QtWidgets/QLabel>
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
    QTabWidget *liste;
    QWidget *tab_3;
    QFrame *frame;
    QPushButton *ButtonSupprimer;
    QPushButton *ButtonFiltre;
    QPushButton *ButtonTri;
    QLineEdit *recherche;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QFrame *frame_2;
    QPushButton *ButtonAjouter_2;
    QLabel *Matricule;
    QLabel *NomAjout;
    QPushButton *logoAjout;
    QLineEdit *nomLE;
    QLineEdit *MatriculeLE;
    QLabel *EtatAjout_2;
    QLabel *Refrence_2;
    QLineEdit *ReferenceLE_2;
    QLabel *Refrence_4;
    QPushButton *ButtonAjouter_3;
    QComboBox *comboBox_2;
    QLineEdit *ReferenceLE_4;
    QLabel *Refrence_5;
    QPushButton *ButtonAjouter_4;
    QLineEdit *ReferenceLE;
    QLabel *Refrence;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *nominfo;
    QLabel *label_poidssupmod;
    QLabel *label_provsupmod;
    QLabel *label_typesupmod;
    QLabel *label_poidssupmod_2;
    QLabel *label_ID_2;
    QLabel *label_ID_3;
    QLabel *label_ID_4;
    QLabel *label_ID_5;
    QFrame *frame_3;
    QPushButton *logoinfo;
    QPushButton *pushButtonsupmoddech;
    QPushButton *pushButtonsupmoddech_2;
    QLabel *label_ID_6;
    QLabel *label_ID_7;
    QLabel *label_ID_8;
    QLabel *label_ID_9;
    QLabel *label_ID_10;
    QLabel *label_ID_11;
    QLabel *label_ID_12;
    QPushButton *logoinfo_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(884, 678);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        liste = new QTabWidget(centralwidget);
        liste->setObjectName(QStringLiteral("liste"));
        liste->setGeometry(QRect(20, 30, 1251, 491));
        liste->setStyleSheet(QLatin1String("\n"
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
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        liste->setTabBarAutoHide(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-10, 10, 871, 521));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
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
"color:red;\n"
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
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ButtonSupprimer = new QPushButton(frame);
        ButtonSupprimer->setObjectName(QStringLiteral("ButtonSupprimer"));
        ButtonSupprimer->setGeometry(QRect(730, 100, 91, 31));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        ButtonSupprimer->setFont(font);
        ButtonSupprimer->setStyleSheet(QLatin1String("background-color:#001F26;\n"
""));
        ButtonFiltre = new QPushButton(frame);
        ButtonFiltre->setObjectName(QStringLiteral("ButtonFiltre"));
        ButtonFiltre->setGeometry(QRect(330, 60, 151, 31));
        ButtonFiltre->setFont(font);
        ButtonFiltre->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        ButtonTri = new QPushButton(frame);
        ButtonTri->setObjectName(QStringLiteral("ButtonTri"));
        ButtonTri->setGeometry(QRect(210, 60, 111, 31));
        ButtonTri->setFont(font);
        ButtonTri->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        recherche = new QLineEdit(frame);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(10, 60, 181, 31));
        recherche->setStyleSheet(QLatin1String("border:2px solid color rgb(170, 85, 127);\n"
"border-radius:10px;"));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 100, 661, 211));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(700, 140, 161, 24));
        liste->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QLatin1String("QFrame{\n"
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
"color:red;\n"
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
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 801, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_2->setFont(font1);
        groupBox_2->setAcceptDrops(false);
        groupBox_2->setStyleSheet(QLatin1String("QFrame{\n"
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
"color:red;\n"
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
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 831, 491));
        frame_2->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:black;\n"
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
"color:red;\n"
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
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        ButtonAjouter_2 = new QPushButton(frame_2);
        ButtonAjouter_2->setObjectName(QStringLiteral("ButtonAjouter_2"));
        ButtonAjouter_2->setGeometry(QRect(250, 370, 111, 31));
        ButtonAjouter_2->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        Matricule = new QLabel(frame_2);
        Matricule->setObjectName(QStringLiteral("Matricule"));
        Matricule->setGeometry(QRect(120, 140, 81, 16));
        NomAjout = new QLabel(frame_2);
        NomAjout->setObjectName(QStringLiteral("NomAjout"));
        NomAjout->setGeometry(QRect(120, 100, 46, 13));
        logoAjout = new QPushButton(frame_2);
        logoAjout->setObjectName(QStringLiteral("logoAjout"));
        logoAjout->setGeometry(QRect(600, 70, 281, 251));
        logoAjout->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../c_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoAjout->setIcon(icon);
        logoAjout->setIconSize(QSize(180, 180));
        logoAjout->setFlat(true);
        nomLE = new QLineEdit(frame_2);
        nomLE->setObjectName(QStringLiteral("nomLE"));
        nomLE->setGeometry(QRect(210, 80, 211, 31));
        MatriculeLE = new QLineEdit(frame_2);
        MatriculeLE->setObjectName(QStringLiteral("MatriculeLE"));
        MatriculeLE->setGeometry(QRect(210, 120, 211, 31));
        EtatAjout_2 = new QLabel(frame_2);
        EtatAjout_2->setObjectName(QStringLiteral("EtatAjout_2"));
        EtatAjout_2->setGeometry(QRect(120, 220, 101, 16));
        Refrence_2 = new QLabel(frame_2);
        Refrence_2->setObjectName(QStringLiteral("Refrence_2"));
        Refrence_2->setGeometry(QRect(120, 270, 101, 20));
        ReferenceLE_2 = new QLineEdit(frame_2);
        ReferenceLE_2->setObjectName(QStringLiteral("ReferenceLE_2"));
        ReferenceLE_2->setGeometry(QRect(220, 260, 141, 31));
        Refrence_4 = new QLabel(frame_2);
        Refrence_4->setObjectName(QStringLiteral("Refrence_4"));
        Refrence_4->setGeometry(QRect(120, 320, 141, 20));
        ButtonAjouter_3 = new QPushButton(frame_2);
        ButtonAjouter_3->setObjectName(QStringLiteral("ButtonAjouter_3"));
        ButtonAjouter_3->setGeometry(QRect(270, 320, 91, 21));
        ButtonAjouter_3->setStyleSheet(QLatin1String("background-color:#cece00;\n"
"border-radius:15px;"));
        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(220, 220, 75, 24));
        ReferenceLE_4 = new QLineEdit(frame_2);
        ReferenceLE_4->setObjectName(QStringLiteral("ReferenceLE_4"));
        ReferenceLE_4->setGeometry(QRect(200, 160, 131, 31));
        Refrence_5 = new QLabel(frame_2);
        Refrence_5->setObjectName(QStringLiteral("Refrence_5"));
        Refrence_5->setGeometry(QRect(120, 170, 81, 20));
        ButtonAjouter_4 = new QPushButton(frame_2);
        ButtonAjouter_4->setObjectName(QStringLiteral("ButtonAjouter_4"));
        ButtonAjouter_4->setGeometry(QRect(410, 370, 111, 31));
        ButtonAjouter_4->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        ReferenceLE = new QLineEdit(frame_2);
        ReferenceLE->setObjectName(QStringLiteral("ReferenceLE"));
        ReferenceLE->setGeometry(QRect(210, 50, 131, 31));
        Refrence = new QLabel(frame_2);
        Refrence->setObjectName(QStringLiteral("Refrence"));
        Refrence->setGeometry(QRect(120, 60, 81, 20));
        liste->addTab(tab, QString());
        frame_2->raise();
        groupBox_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setStyleSheet(QLatin1String("QFrame{\n"
"background:white;\n"
"\n"
"}\n"
"QLabel{\n"
"color:black;\n"
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
"color:red;\n"
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
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 831, 511));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"color:black;\n"
"background:white;\n"
"}"));
        nominfo = new QLabel(groupBox);
        nominfo->setObjectName(QStringLiteral("nominfo"));
        nominfo->setGeometry(QRect(70, 90, 101, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setBold(true);
        font2.setWeight(75);
        nominfo->setFont(font2);
        label_poidssupmod = new QLabel(groupBox);
        label_poidssupmod->setObjectName(QStringLiteral("label_poidssupmod"));
        label_poidssupmod->setGeometry(QRect(70, 130, 91, 16));
        label_poidssupmod->setFont(font2);
        label_provsupmod = new QLabel(groupBox);
        label_provsupmod->setObjectName(QStringLiteral("label_provsupmod"));
        label_provsupmod->setGeometry(QRect(70, 210, 101, 31));
        label_provsupmod->setFont(font2);
        label_typesupmod = new QLabel(groupBox);
        label_typesupmod->setObjectName(QStringLiteral("label_typesupmod"));
        label_typesupmod->setGeometry(QRect(70, 170, 91, 21));
        label_typesupmod->setFont(font2);
        label_poidssupmod_2 = new QLabel(groupBox);
        label_poidssupmod_2->setObjectName(QStringLiteral("label_poidssupmod_2"));
        label_poidssupmod_2->setGeometry(QRect(70, 260, 91, 16));
        label_poidssupmod_2->setFont(font2);
        label_ID_2 = new QLabel(groupBox);
        label_ID_2->setObjectName(QStringLiteral("label_ID_2"));
        label_ID_2->setGeometry(QRect(180, 90, 101, 16));
        label_ID_2->setFont(font2);
        label_ID_3 = new QLabel(groupBox);
        label_ID_3->setObjectName(QStringLiteral("label_ID_3"));
        label_ID_3->setGeometry(QRect(180, 130, 101, 16));
        label_ID_3->setFont(font2);
        label_ID_4 = new QLabel(groupBox);
        label_ID_4->setObjectName(QStringLiteral("label_ID_4"));
        label_ID_4->setGeometry(QRect(180, 170, 321, 31));
        label_ID_4->setFont(font2);
        label_ID_5 = new QLabel(groupBox);
        label_ID_5->setObjectName(QStringLiteral("label_ID_5"));
        label_ID_5->setGeometry(QRect(170, 220, 151, 16));
        label_ID_5->setFont(font2);
        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 20, 881, 501));
        frame_3->setStyleSheet(QLatin1String("QFrame{\n"
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
"color:red;\n"
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
"groupeBox{\n"
"background:transparents;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        logoinfo = new QPushButton(frame_3);
        logoinfo->setObjectName(QStringLiteral("logoinfo"));
        logoinfo->setGeometry(QRect(520, 30, 331, 251));
        logoinfo->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        logoinfo->setIcon(icon);
        logoinfo->setIconSize(QSize(180, 180));
        logoinfo->setFlat(true);
        pushButtonsupmoddech = new QPushButton(frame_3);
        pushButtonsupmoddech->setObjectName(QStringLiteral("pushButtonsupmoddech"));
        pushButtonsupmoddech->setGeometry(QRect(520, 330, 111, 31));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        pushButtonsupmoddech->setFont(font3);
        pushButtonsupmoddech->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        pushButtonsupmoddech_2 = new QPushButton(frame_3);
        pushButtonsupmoddech_2->setObjectName(QStringLiteral("pushButtonsupmoddech_2"));
        pushButtonsupmoddech_2->setGeometry(QRect(640, 330, 111, 31));
        pushButtonsupmoddech_2->setFont(font3);
        pushButtonsupmoddech_2->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        label_ID_6 = new QLabel(frame_3);
        label_ID_6->setObjectName(QStringLiteral("label_ID_6"));
        label_ID_6->setGeometry(QRect(170, 240, 101, 16));
        label_ID_6->setFont(font2);
        label_ID_6->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_7 = new QLabel(frame_3);
        label_ID_7->setObjectName(QStringLiteral("label_ID_7"));
        label_ID_7->setGeometry(QRect(380, 240, 101, 16));
        label_ID_7->setFont(font2);
        label_ID_7->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_8 = new QLabel(frame_3);
        label_ID_8->setObjectName(QStringLiteral("label_ID_8"));
        label_ID_8->setGeometry(QRect(280, 240, 101, 16));
        label_ID_8->setFont(font2);
        label_ID_8->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_9 = new QLabel(frame_3);
        label_ID_9->setObjectName(QStringLiteral("label_ID_9"));
        label_ID_9->setGeometry(QRect(70, 280, 101, 16));
        label_ID_9->setFont(font2);
        label_ID_9->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_10 = new QLabel(frame_3);
        label_ID_10->setObjectName(QStringLiteral("label_ID_10"));
        label_ID_10->setGeometry(QRect(170, 280, 101, 16));
        label_ID_10->setFont(font2);
        label_ID_10->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_11 = new QLabel(frame_3);
        label_ID_11->setObjectName(QStringLiteral("label_ID_11"));
        label_ID_11->setGeometry(QRect(280, 280, 101, 16));
        label_ID_11->setFont(font2);
        label_ID_11->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        label_ID_12 = new QLabel(frame_3);
        label_ID_12->setObjectName(QStringLiteral("label_ID_12"));
        label_ID_12->setGeometry(QRect(340, 280, 101, 16));
        label_ID_12->setFont(font2);
        label_ID_12->setStyleSheet(QLatin1String("QLabel{\n"
"color:black;}"));
        logoinfo_2 = new QPushButton(frame_3);
        logoinfo_2->setObjectName(QStringLiteral("logoinfo_2"));
        logoinfo_2->setGeometry(QRect(70, 220, 331, 251));
        logoinfo_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../camion.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        logoinfo_2->setIcon(icon1);
        logoinfo_2->setIconSize(QSize(120, 120));
        logoinfo_2->setFlat(true);
        frame_3->raise();
        nominfo->raise();
        label_poidssupmod->raise();
        label_provsupmod->raise();
        label_typesupmod->raise();
        label_poidssupmod_2->raise();
        label_ID_2->raise();
        label_ID_3->raise();
        label_ID_4->raise();
        label_ID_5->raise();
        liste->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 884, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        liste->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ButtonSupprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        ButtonFiltre->setText(QApplication::translate("MainWindow", "Filtre par location", Q_NULLPTR));
        ButtonTri->setText(QApplication::translate("MainWindow", "Tri par nom", Q_NULLPTR));
        recherche->setText(QString());
        recherche->setPlaceholderText(QApplication::translate("MainWindow", "Recherche...", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "reference a supprimer", Q_NULLPTR));
        liste->setTabText(liste->indexOf(tab_3), QApplication::translate("MainWindow", "Liste de mat\303\251riel", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajouter mat\303\251riel", Q_NULLPTR));
        ButtonAjouter_2->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Matricule->setText(QApplication::translate("MainWindow", "Matricule:", Q_NULLPTR));
        NomAjout->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        logoAjout->setText(QString());
        nomLE->setPlaceholderText(QApplication::translate("MainWindow", "saisir le nom du matriel", Q_NULLPTR));
        MatriculeLE->setPlaceholderText(QApplication::translate("MainWindow", "saisir le matricule", Q_NULLPTR));
        EtatAjout_2->setText(QApplication::translate("MainWindow", "Etat location:", Q_NULLPTR));
        Refrence_2->setText(QApplication::translate("MainWindow", "prix(DT/jour):", Q_NULLPTR));
        ReferenceLE_2->setPlaceholderText(QApplication::translate("MainWindow", "saisir le prix en DT", Q_NULLPTR));
        Refrence_4->setText(QApplication::translate("MainWindow", "Ajouter une image:", Q_NULLPTR));
        ButtonAjouter_3->setText(QApplication::translate("MainWindow", "Upload IMG", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "lou\303\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "non lou\303\251", Q_NULLPTR)
        );
        ReferenceLE_4->setPlaceholderText(QApplication::translate("MainWindow", "qtt", Q_NULLPTR));
        Refrence_5->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        ButtonAjouter_4->setText(QApplication::translate("MainWindow", "modifler", Q_NULLPTR));
        ReferenceLE->setPlaceholderText(QApplication::translate("MainWindow", "R\303\251ference de mat\303\251riel", Q_NULLPTR));
        Refrence->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        liste->setTabText(liste->indexOf(tab), QApplication::translate("MainWindow", "Mat\303\251riel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Fiche d'information", Q_NULLPTR));
        nominfo->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        label_poidssupmod->setText(QApplication::translate("MainWindow", "Matricule:", Q_NULLPTR));
        label_provsupmod->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        label_typesupmod->setText(QApplication::translate("MainWindow", "Information:", Q_NULLPTR));
        label_poidssupmod_2->setText(QApplication::translate("MainWindow", "Etat:", Q_NULLPTR));
        label_ID_2->setText(QApplication::translate("MainWindow", "Camion", Q_NULLPTR));
        label_ID_3->setText(QApplication::translate("MainWindow", "207 TUN 4257", Q_NULLPTR));
        label_ID_4->setText(QApplication::translate("MainWindow", "Poids \303\240 vide : De 3 500 \303\240 44 000 kg\n"
"Utilisation : Transport routier de marchandises", Q_NULLPTR));
        label_ID_5->setText(QApplication::translate("MainWindow", "AD 440 S 33 TP CNG", Q_NULLPTR));
        logoinfo->setText(QString());
        pushButtonsupmoddech->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        pushButtonsupmoddech_2->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        label_ID_6->setText(QApplication::translate("MainWindow", "Disponible", Q_NULLPTR));
        label_ID_7->setText(QApplication::translate("MainWindow", "Lou\303\251", Q_NULLPTR));
        label_ID_8->setText(QApplication::translate("MainWindow", "Etat location:", Q_NULLPTR));
        label_ID_9->setText(QApplication::translate("MainWindow", "prix(jour):", Q_NULLPTR));
        label_ID_10->setText(QApplication::translate("MainWindow", "120 DT", Q_NULLPTR));
        label_ID_11->setText(QApplication::translate("MainWindow", "Dur\303\251e:", Q_NULLPTR));
        label_ID_12->setText(QApplication::translate("MainWindow", "60 jours", Q_NULLPTR));
        logoinfo_2->setText(QString());
        liste->setTabText(liste->indexOf(tab_2), QApplication::translate("MainWindow", "Fiche information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
