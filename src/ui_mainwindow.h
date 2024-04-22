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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditSearchBar;
    QPushButton *pushBtnSearch;
    QTextBrowser *textBrowserHeader;
    QTextBrowser *textBrowserGameHeader;
    QTextBrowser *textBrowserLstWgtResults;
    QCheckBox *checkBoxConnectedTo;
    QLineEdit *lineEditConnectedToResults;
    QTextBrowser *textBrowsrConnectedToResult;
    QListWidget *listWgtSearchObjects;
    QWidget *searchTypeWidget;
    QHBoxLayout *horizontalLayoutSearchCriteria;
    QRadioButton *radioBtnGames;
    QRadioButton *radioBtnGenre;
    QRadioButton *radioBtnCompany;
    QWidget *gameSearchWidget;
    QVBoxLayout *verticalLayoutAlgoType;
    QRadioButton *radioBtnBFS;
    QRadioButton *radioBtnDFS;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QWidget *widget2;
    QHBoxLayout *horizontalLayoutSearch;
    QLabel *labelWaitText;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1277, 599);

        MainWindow->setStyleSheet(QString::fromUtf8("color: white;\n"
                                                    "background-color: rgb(94, 92, 100);\n"
        ));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");

        centralwidget->setStyleSheet("QLineEdit { background-color: rgb(0,0,0)};"
         );

//        centralwidget->setStyleSheet("QTextBrowser { background-color: rgb(0,0,0)};");

        lineEditSearchBar = new QLineEdit(centralwidget);
        lineEditSearchBar->setObjectName("lineEditSearchBar");
        lineEditSearchBar->setGeometry(QRect(19, 120, 281, 25));
        pushBtnSearch = new QPushButton(centralwidget);
        pushBtnSearch->setObjectName("pushBtnSearch");
        pushBtnSearch->setGeometry(QRect(310, 120, 80, 25));
        textBrowserHeader = new QTextBrowser(centralwidget);
        textBrowserHeader->setObjectName("textBrowserHeader");
        textBrowserHeader->setGeometry(QRect(510, 10, 261, 41));
        textBrowserHeader->setFrameShape(QFrame::NoFrame);

        textBrowserGameHeader = new QTextBrowser(centralwidget);
        textBrowserGameHeader->setObjectName("textBrowserGameHeader");
        textBrowserGameHeader->setGeometry(QRect(20, 160, 371, 171));
        textBrowserGameHeader->setFrameShape(QFrame::NoFrame);
        textBrowserGameHeader->setLineWidth(0);

        textBrowserLstWgtResults = new QTextBrowser(centralwidget);
        textBrowserLstWgtResults->setObjectName("textBrowserLstWgtResults");
        textBrowserLstWgtResults->setGeometry(QRect(940, 100, 311, 451));
        textBrowserLstWgtResults->setFrameShape(QFrame::NoFrame);

        listWgtSearchObjects = new QListWidget(centralwidget);
        listWgtSearchObjects->setObjectName("listWgtSearchObjects");
        listWgtSearchObjects->setGeometry(QRect(580, 100, 341, 451));
        listWgtSearchObjects->setFrameShape(QFrame::NoFrame);
        searchTypeWidget = new QWidget(centralwidget);
        searchTypeWidget->setObjectName("searchTypeWidget");
        searchTypeWidget->setGeometry(QRect(20, 80, 442, 25));
        horizontalLayoutSearchCriteria = new QHBoxLayout(searchTypeWidget);
        horizontalLayoutSearchCriteria->setObjectName("horizontalLayoutSearchCriteria");
        horizontalLayoutSearchCriteria->setContentsMargins(0, 0, 0, 0);
        radioBtnGames = new QRadioButton(searchTypeWidget);
        radioBtnGames->setObjectName("radioBtnGames");
        radioBtnGames->setChecked(true);

        // waiting message
        labelWaitText = new QLabel(centralwidget);
        labelWaitText->setObjectName("labelWaitText");
        labelWaitText->setGeometry(QRect(680, 240, 521, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelWaitText->setFont(font);
        labelWaitText->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228)"));
        labelWaitText->setLineWidth(1);
        labelWaitText->setAlignment(Qt::AlignCenter);

        horizontalLayoutSearchCriteria->addWidget(radioBtnGames);

        radioBtnGenre = new QRadioButton(searchTypeWidget);
        radioBtnGenre->setObjectName("radioBtnGenre");

        horizontalLayoutSearchCriteria->addWidget(radioBtnGenre);

        radioBtnCompany = new QRadioButton(searchTypeWidget);
        radioBtnCompany->setObjectName("radioBtnCompany");

        horizontalLayoutSearchCriteria->addWidget(radioBtnCompany);

        gameSearchWidget = new QWidget(centralwidget);
        gameSearchWidget->setObjectName("gameSearchWidget");
        gameSearchWidget->setGeometry(QRect(40, 350, 54, 54));
        verticalLayoutAlgoType = new QVBoxLayout(gameSearchWidget);
        verticalLayoutAlgoType->setObjectName("verticalLayoutAlgoType");
        verticalLayoutAlgoType->setContentsMargins(0, 0, 0, 0);
        radioBtnBFS = new QRadioButton(gameSearchWidget);
        radioBtnBFS->setObjectName("radioBtnBFS");
        radioBtnBFS->setChecked(true);

        verticalLayoutAlgoType->addWidget(radioBtnBFS);

        radioBtnDFS = new QRadioButton(gameSearchWidget);
        radioBtnDFS->setObjectName("radioBtnDFS");

        verticalLayoutAlgoType->addWidget(radioBtnDFS);

        // connectedto stuff
        checkBoxConnectedTo = new QCheckBox(centralwidget);
        checkBoxConnectedTo->setObjectName("checkBoxConnectedTo");
        checkBoxConnectedTo->setGeometry(QRect(40, 440, 131, 23));
        lineEditConnectedToResults = new QLineEdit(centralwidget);
        lineEditConnectedToResults->setObjectName("lineEditConnectedToResults");
        lineEditConnectedToResults->setPlaceholderText(QString::fromStdString("Enter connected game!"));
        lineEditConnectedToResults->setGeometry(QRect(180, 440, 221, 25));
        textBrowsrConnectedToResult = new QTextBrowser(centralwidget);
        textBrowsrConnectedToResult->setObjectName("textBrowsrConnectedToResult");
        textBrowsrConnectedToResult->setGeometry(QRect(40, 480, 361, 71));
        textBrowsrConnectedToResult->setFrameShape(QFrame::NoFrame);


        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(19, 119, 481, 27));
        horizontalLayoutSearch = new QHBoxLayout(widget2);
        horizontalLayoutSearch->setObjectName("horizontalLayoutSearch");
        horizontalLayoutSearch->setContentsMargins(0, 0, 0, 0);
        lineEditSearchBar = new QLineEdit(widget2);
        lineEditSearchBar->setObjectName("lineEditSearchBar");
        lineEditSearchBar->setPlaceholderText(QString::fromStdString("Enter game to search!"));

        horizontalLayoutSearch->addWidget(lineEditSearchBar);

        pushBtnSearch = new QPushButton(widget2);
        pushBtnSearch->setObjectName("pushBtnSearch");

        horizontalLayoutSearch->addWidget(pushBtnSearch);

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
                                                                             "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:700; color:#ff7800;\">Game Recommender</span></p></body></html>", nullptr));
        checkBoxConnectedTo->setText(QCoreApplication::translate("MainWindow", "Connected To", nullptr));
        radioBtnGames->setText(QCoreApplication::translate("MainWindow", "Search by games", nullptr));
        radioBtnGenre->setText(QCoreApplication::translate("MainWindow", "Search by genre", nullptr));
        radioBtnCompany->setText(QCoreApplication::translate("MainWindow", "Search by company", nullptr));
        radioBtnBFS->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        radioBtnDFS->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        labelWaitText->setText(QCoreApplication::translate("MainWindow", "Discover your next favorite Game!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H