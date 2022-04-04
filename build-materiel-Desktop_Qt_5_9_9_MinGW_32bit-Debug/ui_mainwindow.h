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
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *ButtonAjouter_4;
    QLineEdit *ReferenceLE_3;
    QLabel *EtatAjout_3;
    QLineEdit *ReferenceLE_5;
    QLabel *Refrence_6;
    QLineEdit *MatriculeLE_2;
    QLineEdit *ReferenceLE_6;
    QLabel *Refrence_3;
    QComboBox *comboBox_3;
    QLabel *Matricule_2;
    QLabel *NomAjout_2;
    QLineEdit *nomLE_2;
    QLabel *Refrence_7;
    QGroupBox *groupBox_3;
    QPushButton *Buttonrecherche;
    QPushButton *PDF;
    QPushButton *logoAjout_3;
    QComboBox *comboBox_4;
    QLabel *filtre;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QFrame *frame_2;
    QPushButton *ButtonAjouter_2;
    QLabel *Matricule;
    QLabel *NomAjout;
    QLineEdit *nomLE;
    QLineEdit *MatriculeLE;
    QLabel *EtatAjout_2;
    QLabel *Refrence_2;
    QLineEdit *ReferenceLE_2;
    QLabel *Refrence_4;
    QPushButton *BtnIMG;
    QComboBox *comboBox_2;
    QLineEdit *ReferenceLE_4;
    QLabel *Refrence_5;
    QLineEdit *ReferenceLE;
    QLabel *Refrence;
    QPushButton *logoAjout_4;
    QLabel *lb_img;
    QWidget *tab_2;
    QFrame *frame_3;
    QPushButton *logoAjout_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
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
        ButtonSupprimer->setGeometry(QRect(510, 60, 91, 31));
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
        ButtonFiltre->setGeometry(QRect(350, 60, 151, 31));
        ButtonFiltre->setFont(font);
        ButtonFiltre->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        ButtonTri = new QPushButton(frame);
        ButtonTri->setObjectName(QStringLiteral("ButtonTri"));
        ButtonTri->setGeometry(QRect(230, 60, 111, 31));
        ButtonTri->setFont(font);
        ButtonTri->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        recherche = new QLineEdit(frame);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(20, 60, 181, 31));
        recherche->setStyleSheet(QLatin1String("border:2px solid color rgb(170, 85, 127);\n"
"border-radius:10px;"));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 100, 451, 211));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(610, 60, 161, 24));
        ButtonAjouter_4 = new QPushButton(frame);
        ButtonAjouter_4->setObjectName(QStringLiteral("ButtonAjouter_4"));
        ButtonAjouter_4->setGeometry(QRect(630, 380, 101, 31));
        ButtonAjouter_4->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        ReferenceLE_3 = new QLineEdit(frame);
        ReferenceLE_3->setObjectName(QStringLiteral("ReferenceLE_3"));
        ReferenceLE_3->setGeometry(QRect(630, 110, 131, 31));
        EtatAjout_3 = new QLabel(frame);
        EtatAjout_3->setObjectName(QStringLiteral("EtatAjout_3"));
        EtatAjout_3->setGeometry(QRect(540, 280, 101, 16));
        EtatAjout_3->setStyleSheet(QStringLiteral("color:black;"));
        ReferenceLE_5 = new QLineEdit(frame);
        ReferenceLE_5->setObjectName(QStringLiteral("ReferenceLE_5"));
        ReferenceLE_5->setGeometry(QRect(640, 320, 141, 31));
        Refrence_6 = new QLabel(frame);
        Refrence_6->setObjectName(QStringLiteral("Refrence_6"));
        Refrence_6->setGeometry(QRect(540, 230, 81, 20));
        Refrence_6->setStyleSheet(QStringLiteral("color:black;"));
        MatriculeLE_2 = new QLineEdit(frame);
        MatriculeLE_2->setObjectName(QStringLiteral("MatriculeLE_2"));
        MatriculeLE_2->setGeometry(QRect(630, 180, 211, 31));
        ReferenceLE_6 = new QLineEdit(frame);
        ReferenceLE_6->setObjectName(QStringLiteral("ReferenceLE_6"));
        ReferenceLE_6->setGeometry(QRect(620, 220, 131, 31));
        Refrence_3 = new QLabel(frame);
        Refrence_3->setObjectName(QStringLiteral("Refrence_3"));
        Refrence_3->setGeometry(QRect(540, 120, 81, 20));
        Refrence_3->setStyleSheet(QStringLiteral("color:black;"));
        comboBox_3 = new QComboBox(frame);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(640, 280, 75, 24));
        Matricule_2 = new QLabel(frame);
        Matricule_2->setObjectName(QStringLiteral("Matricule_2"));
        Matricule_2->setGeometry(QRect(540, 200, 81, 16));
        Matricule_2->setStyleSheet(QStringLiteral("color:black;"));
        NomAjout_2 = new QLabel(frame);
        NomAjout_2->setObjectName(QStringLiteral("NomAjout_2"));
        NomAjout_2->setGeometry(QRect(540, 160, 46, 13));
        NomAjout_2->setStyleSheet(QStringLiteral("color:black;"));
        nomLE_2 = new QLineEdit(frame);
        nomLE_2->setObjectName(QStringLiteral("nomLE_2"));
        nomLE_2->setGeometry(QRect(630, 140, 211, 31));
        Refrence_7 = new QLabel(frame);
        Refrence_7->setObjectName(QStringLiteral("Refrence_7"));
        Refrence_7->setGeometry(QRect(540, 330, 101, 20));
        Refrence_7->setStyleSheet(QStringLiteral("color:black;"));
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 100, 341, 321));
        Buttonrecherche = new QPushButton(frame);
        Buttonrecherche->setObjectName(QStringLiteral("Buttonrecherche"));
        Buttonrecherche->setGeometry(QRect(170, 62, 21, 20));
        Buttonrecherche->setFont(font);
        Buttonrecherche->setStyleSheet(QStringLiteral("background-color:white;"));
        PDF = new QPushButton(frame);
        PDF->setObjectName(QStringLiteral("PDF"));
        PDF->setGeometry(QRect(30, 350, 101, 31));
        PDF->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        logoAjout_3 = new QPushButton(frame);
        logoAjout_3->setObjectName(QStringLiteral("logoAjout_3"));
        logoAjout_3->setGeometry(QRect(710, -40, 221, 181));
        logoAjout_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../c_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoAjout_3->setIcon(icon);
        logoAjout_3->setIconSize(QSize(60, 60));
        logoAjout_3->setFlat(true);
        comboBox_4 = new QComboBox(frame);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(130, 20, 75, 24));
        filtre = new QLabel(frame);
        filtre->setObjectName(QStringLiteral("filtre"));
        filtre->setGeometry(QRect(30, 20, 101, 16));
        filtre->setStyleSheet(QStringLiteral("color:black;"));
        groupBox_3->raise();
        ButtonSupprimer->raise();
        ButtonFiltre->raise();
        ButtonTri->raise();
        recherche->raise();
        tableView->raise();
        lineEdit->raise();
        ButtonAjouter_4->raise();
        ReferenceLE_3->raise();
        EtatAjout_3->raise();
        ReferenceLE_5->raise();
        Refrence_6->raise();
        MatriculeLE_2->raise();
        ReferenceLE_6->raise();
        Refrence_3->raise();
        comboBox_3->raise();
        Matricule_2->raise();
        NomAjout_2->raise();
        nomLE_2->raise();
        Refrence_7->raise();
        Buttonrecherche->raise();
        PDF->raise();
        logoAjout_3->raise();
        comboBox_4->raise();
        filtre->raise();
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
        ButtonAjouter_2->setGeometry(QRect(160, 390, 111, 31));
        ButtonAjouter_2->setStyleSheet(QStringLiteral("background-color:#001F26;"));
        Matricule = new QLabel(frame_2);
        Matricule->setObjectName(QStringLiteral("Matricule"));
        Matricule->setGeometry(QRect(120, 140, 81, 16));
        NomAjout = new QLabel(frame_2);
        NomAjout->setObjectName(QStringLiteral("NomAjout"));
        NomAjout->setGeometry(QRect(120, 100, 46, 13));
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
        BtnIMG = new QPushButton(frame_2);
        BtnIMG->setObjectName(QStringLiteral("BtnIMG"));
        BtnIMG->setGeometry(QRect(270, 320, 91, 21));
        BtnIMG->setStyleSheet(QLatin1String("background-color:#cece00;\n"
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
        ReferenceLE = new QLineEdit(frame_2);
        ReferenceLE->setObjectName(QStringLiteral("ReferenceLE"));
        ReferenceLE->setGeometry(QRect(210, 50, 131, 31));
        Refrence = new QLabel(frame_2);
        Refrence->setObjectName(QStringLiteral("Refrence"));
        Refrence->setGeometry(QRect(120, 60, 81, 20));
        logoAjout_4 = new QPushButton(frame_2);
        logoAjout_4->setObjectName(QStringLiteral("logoAjout_4"));
        logoAjout_4->setGeometry(QRect(690, -50, 211, 181));
        logoAjout_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        logoAjout_4->setIcon(icon);
        logoAjout_4->setIconSize(QSize(60, 60));
        logoAjout_4->setFlat(true);
        lb_img = new QLabel(frame_2);
        lb_img->setObjectName(QStringLiteral("lb_img"));
        lb_img->setGeometry(QRect(410, 260, 131, 131));
        liste->addTab(tab, QString());
        frame_2->raise();
        groupBox_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 831, 491));
        frame_3->setStyleSheet(QLatin1String("QFrame{\n"
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
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        logoAjout_5 = new QPushButton(frame_3);
        logoAjout_5->setObjectName(QStringLiteral("logoAjout_5"));
        logoAjout_5->setGeometry(QRect(680, -50, 221, 181));
        logoAjout_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"}"));
        logoAjout_5->setIcon(icon);
        logoAjout_5->setIconSize(QSize(60, 60));
        logoAjout_5->setFlat(true);
        verticalLayoutWidget = new QWidget(frame_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 70, 501, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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

        liste->setCurrentIndex(0);


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
        ButtonAjouter_4->setText(QApplication::translate("MainWindow", "modifler", Q_NULLPTR));
        ReferenceLE_3->setPlaceholderText(QApplication::translate("MainWindow", "R\303\251ference de mat\303\251riel", Q_NULLPTR));
        EtatAjout_3->setText(QApplication::translate("MainWindow", "Etat location:", Q_NULLPTR));
        ReferenceLE_5->setPlaceholderText(QApplication::translate("MainWindow", "saisir le prix en DT", Q_NULLPTR));
        Refrence_6->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        MatriculeLE_2->setPlaceholderText(QApplication::translate("MainWindow", "saisir le matricule", Q_NULLPTR));
        ReferenceLE_6->setPlaceholderText(QApplication::translate("MainWindow", "qtt", Q_NULLPTR));
        Refrence_3->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "loue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "non loue", Q_NULLPTR)
        );
        comboBox_3->setCurrentText(QApplication::translate("MainWindow", "loue", Q_NULLPTR));
        Matricule_2->setText(QApplication::translate("MainWindow", "Matricule:", Q_NULLPTR));
        NomAjout_2->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        nomLE_2->setPlaceholderText(QApplication::translate("MainWindow", "saisir le nom du matriel", Q_NULLPTR));
        Refrence_7->setText(QApplication::translate("MainWindow", "prix(DT/jour):", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        Buttonrecherche->setText(QApplication::translate("MainWindow", "\360\237\224\215", Q_NULLPTR));
        PDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        logoAjout_3->setText(QString());
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "loue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "non loue", Q_NULLPTR)
        );
        comboBox_4->setCurrentText(QApplication::translate("MainWindow", "loue", Q_NULLPTR));
        filtre->setText(QApplication::translate("MainWindow", "Filtrer par", Q_NULLPTR));
        liste->setTabText(liste->indexOf(tab_3), QApplication::translate("MainWindow", "Liste de mat\303\251riel", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajouter mat\303\251riel", Q_NULLPTR));
        ButtonAjouter_2->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Matricule->setText(QApplication::translate("MainWindow", "Matricule:", Q_NULLPTR));
        NomAjout->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        nomLE->setPlaceholderText(QApplication::translate("MainWindow", "saisir le nom du matriel", Q_NULLPTR));
        MatriculeLE->setPlaceholderText(QApplication::translate("MainWindow", "saisir le matricule", Q_NULLPTR));
        EtatAjout_2->setText(QApplication::translate("MainWindow", "Etat location:", Q_NULLPTR));
        Refrence_2->setText(QApplication::translate("MainWindow", "prix(DT/jour):", Q_NULLPTR));
        ReferenceLE_2->setPlaceholderText(QApplication::translate("MainWindow", "saisir le prix en DT", Q_NULLPTR));
        Refrence_4->setText(QApplication::translate("MainWindow", "Ajouter une image:", Q_NULLPTR));
        BtnIMG->setText(QApplication::translate("MainWindow", "Upload IMG", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "loue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "non loue", Q_NULLPTR)
        );
        comboBox_2->setCurrentText(QApplication::translate("MainWindow", "loue", Q_NULLPTR));
        ReferenceLE_4->setPlaceholderText(QApplication::translate("MainWindow", "qtt", Q_NULLPTR));
        Refrence_5->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        ReferenceLE->setText(QString());
        ReferenceLE->setPlaceholderText(QApplication::translate("MainWindow", "R\303\251ference de mat\303\251riel", Q_NULLPTR));
        Refrence->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence:", Q_NULLPTR));
        logoAjout_4->setText(QString());
        lb_img->setText(QString());
        liste->setTabText(liste->indexOf(tab), QApplication::translate("MainWindow", "Mat\303\251riel", Q_NULLPTR));
        logoAjout_5->setText(QString());
        liste->setTabText(liste->indexOf(tab_2), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
