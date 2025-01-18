/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *mainColor;
    QLabel *selectedPicture;
    QPushButton *btn_selectPicture;
    QPushButton *btn_computeInGPU;
    QLabel *label;
    QLabel *MainColor_info;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgbrgb(248, 255, 187)\n"
"font: 9pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QMenuBar{\n"
"background-color: rgb(200, 200, 200);\n"
"font: 9pt \"Microsoft YaHei UI\";\n"
"color:rgb(60, 60, 60);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        mainColor = new QLabel(centralwidget);
        mainColor->setObjectName("mainColor");
        mainColor->setGeometry(QRect(490, 170, 301, 261));
        mainColor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        selectedPicture = new QLabel(centralwidget);
        selectedPicture->setObjectName("selectedPicture");
        selectedPicture->setGeometry(QRect(10, 10, 451, 421));
        selectedPicture->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        btn_selectPicture = new QPushButton(centralwidget);
        btn_selectPicture->setObjectName("btn_selectPicture");
        btn_selectPicture->setGeometry(QRect(80, 490, 221, 41));
        btn_selectPicture->setStyleSheet(QString::fromUtf8("backgound-color:rgb(170, 170, 127);"));
        btn_computeInGPU = new QPushButton(centralwidget);
        btn_computeInGPU->setObjectName("btn_computeInGPU");
        btn_computeInGPU->setGeometry(QRect(600, 480, 151, 51));
        btn_computeInGPU->setStyleSheet(QString::fromUtf8("backgound-color:rgb(170, 170, 127);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(530, 140, 221, 21));
        MainColor_info = new QLabel(centralwidget);
        MainColor_info->setObjectName("MainColor_info");
        MainColor_info->setGeometry(QRect(510, 430, 251, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\260\203\347\224\250GPU\345\257\271\345\233\276\347\211\207\347\232\204\344\270\273\350\211\262\350\260\203\350\277\233\350\241\214\350\256\241\347\256\227", nullptr));
        mainColor->setText(QString());
        selectedPicture->setText(QString());
        btn_selectPicture->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        btn_computeInGPU->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\344\270\273\350\211\262\350\260\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\202\250\350\276\223\345\205\245\345\233\276\347\211\207\347\232\204\344\270\273\350\211\262\350\260\203\357\274\232", nullptr));
        MainColor_info->setText(QCoreApplication::translate("MainWindow", "#ffffff", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
