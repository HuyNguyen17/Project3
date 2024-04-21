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

    gameCompleter = new QCompleter(gameGraph.getQStringGameNames(), ui->lineEditSearchBar);
    gameCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    companyCompleter = new QCompleter(gameGraph.getQStringCompanyNames(), ui->lineEditSearchBar);
    companyCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    genreCompleter = new QCompleter(gameGraph.getQStringGenreNames(), ui->lineEditSearchBar);
    genreCompleter->setCaseSensitivity(Qt::CaseInsensitive);


    // Set the QCompleter to the existing QLineEdit
    ui->lineEditSearchBar->setCompleter(gameCompleter); // game completer by default
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchButtonClick()
{
    ui->textBrowserLstWgtResults->clear(); // clear results at each search
    // only search games if games button checked
    if(ui->radioBtnGames->isChecked())
    {
        auto testVector = gameGraph.findByName(ui->lineEditSearchBar->text().toStdString());
        if (!testVector.empty()) {
            for (const auto &gamePtr: testVector) {
                if (ui->radioBtnBFS->isChecked()) {
                    gameGraph.BFSprintConnectedGames(gamePtr->getName(), 1);

                    for (auto simiGames: gameGraph.getQStringGameNameResults()) {
                        ui->textBrowserLstWgtResults->append(simiGames);
                    }
                } else if (ui->radioBtnDFS->isChecked()) {
                    gameGraph.DFSprintConnectedGames(gamePtr->getName(), 1);

                    for (auto simiGames: gameGraph.getQStringGameNameResults()) {
                        ui->textBrowserLstWgtResults->append(simiGames);
                    }
                }
//            ui->textBrowserLstWgtResults->setHtml(
//                    ui->lineEditSearchBar->text()
//                    + " Released on: " + QString::fromStdString(gamePtr->getReleaseDate())

//            );
//            ui->textBrowserLstWgtResults->append("<br>Check out these <b>awesome</b> games: <br>");
//            for (auto simiGames : gameGraph.findByID(gamePtr->getID())->getSimilarGames())
//            {
//                ui->textBrowserLstWgtResults->append(QString::fromStdString(gameGraph.findByID(simiGames)->getName()));
//            }
            }
        } else {
            ui->textBrowserLstWgtResults->setHtml(
                    ui->lineEditSearchBar->text() + " is not a valid game. Please try a different game name.");
        }
    }
    else if(ui->radioBtnGenre->isChecked())
    {
        // do genre search
    }
    else if (ui->radioBtnCompany->isChecked())
    {
        // do company search
    }
}

void MainWindow::on_radioBtnGames_toggled(bool checked)
{
    // sets the autocompleter if checked
    if(checked)
    {
        ui->lineEditSearchBar->setCompleter(gameCompleter);
    }
}

void MainWindow::on_radioBtnCompany_toggled(bool checked) {
    // sets the autocompleter if checked
    ui->lineEditSearchBar->setCompleter(gameCompleter);
}

void MainWindow::on_radioBtnGenre_toggled(bool checked) {
    // sets the autocompleter if checked
    ui->lineEditSearchBar->setCompleter(gameCompleter);
}
