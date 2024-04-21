/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditSearchBar;
    QPushButton *pushBtnSearch;
    QTextBrowser *textBrowserHeader;
    QRadioButton *radioBtnBFS;
    QRadioButton *radioBtnDFS;
    QTextBrowser *textBrowserLstWgtResults;
    QRadioButton *radioBtnGames;
    QRadioButton *radioBtnGenre;
    QRadioButton *radioBtnCompany;
    QRadioButton *radioBtnConnectedTo;
    QLineEdit *lineEditConnectedToResults;
    QTextBrowser *textBrowsrConnectedToResult;
    QListWidget *listWgtSearchObjects;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1277, 599);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEditSearchBar = new QLineEdit(centralwidget);
        lineEditSearchBar->setObjectName("lineEditSearchBar");
        lineEditSearchBar->setGeometry(QRect(19, 119, 281, 25));
        pushBtnSearch = new QPushButton(centralwidget);
        pushBtnSearch->setObjectName("pushBtnSearch");
        pushBtnSearch->setGeometry(QRect(310, 120, 80, 25));
        textBrowserHeader = new QTextBrowser(centralwidget);
        textBrowserHeader->setObjectName("textBrowserHeader");
        textBrowserHeader->setGeometry(QRect(350, 10, 321, 51));
        textBrowserHeader->setFrameShape(QFrame::NoFrame);
        textBrowserHeader->setFrameShadow(QFrame::Sunken);
        radioBtnBFS = new QRadioButton(centralwidget);
        radioBtnBFS->setObjectName("radioBtnBFS");
        radioBtnBFS->setGeometry(QRect(40, 350, 131, 23));
        radioBtnDFS = new QRadioButton(centralwidget);
        radioBtnDFS->setObjectName("radioBtnDFS");
        radioBtnDFS->setGeometry(QRect(40, 390, 131, 23));
        textBrowserLstWgtResults = new QTextBrowser(centralwidget);
        textBrowserLstWgtResults->setObjectName("textBrowserLstWgtResults");
        textBrowserLstWgtResults->setGeometry(QRect(840, 100, 401, 451));
        radioBtnGames = new QRadioButton(centralwidget);
        radioBtnGames->setObjectName("radioBtnGames");
        radioBtnGames->setGeometry(QRect(20, 80, 141, 23));
        radioBtnGenre = new QRadioButton(centralwidget);
        radioBtnGenre->setObjectName("radioBtnGenre");
        radioBtnGenre->setGeometry(QRect(170, 80, 141, 23));
        radioBtnCompany = new QRadioButton(centralwidget);
        radioBtnCompany->setObjectName("radioBtnCompany");
        radioBtnCompany->setGeometry(QRect(310, 80, 151, 23));
        radioBtnConnectedTo = new QRadioButton(centralwidget);
        radioBtnConnectedTo->setObjectName("radioBtnConnectedTo");
        radioBtnConnectedTo->setGeometry(QRect(40, 440, 131, 23));
        lineEditConnectedToResults = new QLineEdit(centralwidget);
        lineEditConnectedToResults->setObjectName("lineEditConnectedToResults");
        lineEditConnectedToResults->setGeometry(QRect(180, 440, 221, 25));
        textBrowsrConnectedToResult = new QTextBrowser(centralwidget);
        textBrowsrConnectedToResult->setObjectName("textBrowsrConnectedToResult");
        textBrowsrConnectedToResult->setGeometry(QRect(40, 480, 361, 71));
        listWgtSearchObjects = new QListWidget(centralwidget);
        listWgtSearchObjects->setObjectName("listWgtSearchObjects");
        listWgtSearchObjects->setGeometry(QRect(480, 100, 341, 451));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1277, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushBtnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        textBrowserHeader->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                                             "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
                                                                             "p, li { white-space: pre-wrap; }\n"
                                                                             "hr { height: 1px; border-width: 0; }\n"
                                                                             "li.unchecked::marker { content: \"\\2610\"; }\n"
                                                                             "li.checked::marker { content: \"\\2612\"; }\n"
                                                                             "</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
                                                                             "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:700; color:#1a5fb4;\">Gamerz Edge</span></p></body></html>", nullptr));
        radioBtnBFS->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        radioBtnDFS->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        radioBtnGames->setText(QCoreApplication::translate("MainWindow", "Search by games", nullptr));
        radioBtnGenre->setText(QCoreApplication::translate("MainWindow", "Search by genre", nullptr));
        radioBtnCompany->setText(QCoreApplication::translate("MainWindow", "Search by company", nullptr));
        radioBtnConnectedTo->setText(QCoreApplication::translate("MainWindow", "Connected To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H