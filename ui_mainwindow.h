/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *Label_WindDir;
    QLineEdit *Input_WindDir;
    QLabel *Label_Deg;
    QLabel *Label_TWS;
    QLineEdit *Input_TWS;
    QLabel *Label_Knots;
    QComboBox *Box_Start;
    QComboBox *Box_Finish;
    QLabel *Label_Result;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Button_Update;
    QWidget *downWidget;
    QLabel *Label_Laps;
    QLabel *label_5;
    QPushButton *Button_SumClear;
    QLabel *label_6;
    QLabel *Label_TotalTime;
    QPushButton *Button_Plus;
    QPushButton *Button_Alter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Label_WindDir = new QLabel(centralWidget);
        Label_WindDir->setObjectName(QString::fromUtf8("Label_WindDir"));
        Label_WindDir->setGeometry(QRect(20, 10, 100, 35));
        Input_WindDir = new QLineEdit(centralWidget);
        Input_WindDir->setObjectName(QString::fromUtf8("Input_WindDir"));
        Input_WindDir->setGeometry(QRect(180, 10, 120, 35));
        Label_Deg = new QLabel(centralWidget);
        Label_Deg->setObjectName(QString::fromUtf8("Label_Deg"));
        Label_Deg->setGeometry(QRect(300, 10, 16, 35));
        Label_TWS = new QLabel(centralWidget);
        Label_TWS->setObjectName(QString::fromUtf8("Label_TWS"));
        Label_TWS->setGeometry(QRect(20, 50, 150, 35));
        Input_TWS = new QLineEdit(centralWidget);
        Input_TWS->setObjectName(QString::fromUtf8("Input_TWS"));
        Input_TWS->setGeometry(QRect(180, 50, 120, 35));
        Label_Knots = new QLabel(centralWidget);
        Label_Knots->setObjectName(QString::fromUtf8("Label_Knots"));
        Label_Knots->setGeometry(QRect(300, 50, 21, 35));
        Box_Start = new QComboBox(centralWidget);
        Box_Start->setObjectName(QString::fromUtf8("Box_Start"));
        Box_Start->setGeometry(QRect(70, 125, 141, 35));
        Box_Finish = new QComboBox(centralWidget);
        Box_Finish->setObjectName(QString::fromUtf8("Box_Finish"));
        Box_Finish->setGeometry(QRect(300, 125, 141, 35));
        Label_Result = new QLabel(centralWidget);
        Label_Result->setObjectName(QString::fromUtf8("Label_Result"));
        Label_Result->setGeometry(QRect(355, 210, 50, 19));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 125, 51, 35));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 125, 31, 35));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 210, 50, 19));
        QFont font;
        font.setItalic(true);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 210, 63, 19));
        label_4->setFont(font);
        Button_Update = new QPushButton(centralWidget);
        Button_Update->setObjectName(QString::fromUtf8("Button_Update"));
        Button_Update->setGeometry(QRect(450, 30, 94, 35));
        downWidget = new QWidget(centralWidget);
        downWidget->setObjectName(QString::fromUtf8("downWidget"));
        downWidget->setGeometry(QRect(5, 280, 590, 280));
        Label_Laps = new QLabel(downWidget);
        Label_Laps->setObjectName(QString::fromUtf8("Label_Laps"));
        Label_Laps->setGeometry(QRect(40, 40, 331, 201));
        label_5 = new QLabel(downWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 10, 201, 19));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        Button_SumClear = new QPushButton(downWidget);
        Button_SumClear->setObjectName(QString::fromUtf8("Button_SumClear"));
        Button_SumClear->setGeometry(QRect(450, 30, 94, 35));
        label_6 = new QLabel(downWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 210, 63, 19));
        label_6->setFont(font);
        Label_TotalTime = new QLabel(downWidget);
        Label_TotalTime->setObjectName(QString::fromUtf8("Label_TotalTime"));
        Label_TotalTime->setGeometry(QRect(450, 210, 63, 19));
        Button_Plus = new QPushButton(centralWidget);
        Button_Plus->setObjectName(QString::fromUtf8("Button_Plus"));
        Button_Plus->setGeometry(QRect(450, 240, 35, 35));
        Button_Alter = new QPushButton(centralWidget);
        Button_Alter->setObjectName(QString::fromUtf8("Button_Alter"));
        Button_Alter->setGeometry(QRect(450, 125, 35, 35));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reisduur-Rechner", 0, QApplication::UnicodeUTF8));
        Label_WindDir->setText(QApplication::translate("MainWindow", "Windrichtung:", 0, QApplication::UnicodeUTF8));
        Label_Deg->setText(QApplication::translate("MainWindow", "\302\260", 0, QApplication::UnicodeUTF8));
        Label_TWS->setText(QApplication::translate("MainWindow", "Windgeschwindigkeit:", 0, QApplication::UnicodeUTF8));
        Label_Knots->setText(QApplication::translate("MainWindow", "kn", 0, QApplication::UnicodeUTF8));
        Label_Result->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Von", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "nach", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Dauer:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Stunden", 0, QApplication::UnicodeUTF8));
        Button_Update->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        Label_Laps->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Gesamtdauer:", 0, QApplication::UnicodeUTF8));
        Button_SumClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "ges: ", 0, QApplication::UnicodeUTF8));
        Label_TotalTime->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        Button_Plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        Button_Alter->setText(QApplication::translate("MainWindow", "\342\206\222\342\206\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
