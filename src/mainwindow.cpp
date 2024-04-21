//
// Created by ricky on 4/20/24.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parser.h"
#include <QString>
#include <QCompleter>

//Todo: Allen Change widget names, fix the widget frame, incorporate the graph functions for search

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushBtnSearch, &QPushButton::clicked, this, &MainWindow::searchButtonClick);

    gameGraph = parsed->parseToGraph("../data/data.json");

    auto *completer = new QCompleter(gameGraph.getQStringGameNames(), ui->lineEditSearchBar);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    // Set the QCompleter to the existing QLineEdit
    ui->lineEditSearchBar->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchButtonClick()
{
    auto testVector = gameGraph.findByName(ui->lineEditSearchBar->text().toStdString());
    if(!testVector.empty())
    {
        for (const auto& gamePtr : testVector)
        {
            ui->textBrowserLstWgtResults->setHtml(
                    ui->lineEditSearchBar->text()
                    + " Released on: " + QString::fromStdString(gamePtr->getReleaseDate())

            );
            ui->textBrowserLstWgtResults->append("<br>Check out these <b>awesome</b> games: <br>");
            for (auto simiGames : gameGraph.findByID(gamePtr->getID())->getSimilarGames())
            {
                ui->textBrowserLstWgtResults->append(QString::fromStdString(gameGraph.findByID(simiGames)->getName()));
            }
        }
    }
    else
    {
        ui->textBrowserLstWgtResults->setHtml(ui->lineEditSearchBar->text() + " is not a valid game. Please try a different game name.");
    }
}