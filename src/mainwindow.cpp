//
// Created by ricky on 4/20/24.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parser.h"
#include <QString>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameGraph = parsed->parseToGraph("../data/data.json");

    auto *completer = new QCompleter(gameGraph.getQStringGameNames(), ui->lineEdit);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    // Set the QCompleter to the existing QLineEdit
    ui->lineEdit->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto testVector = gameGraph.findByName(ui->lineEdit->text().toStdString());
    if(!testVector.empty())
    {
        for (const auto& gamePtr : testVector)
        {
            ui->textBrowser_2->setHtml(
                    ui->lineEdit->text()
                    + " Released on: " + QString::fromStdString(gamePtr->getReleaseDate())

            );
            ui->textBrowser_2->append("<br>Check out these <b>awesome</b> games: <br>");
            for (auto simiGames : gameGraph.findByID(gamePtr->getID())->getSimilarGames())
            {
                ui->textBrowser_2->append(QString::fromStdString(gameGraph.findByID(simiGames)->getName()));
            }
        }
    }
    else
    {
        ui->textBrowser_2->setHtml(ui->lineEdit->text() + " is not a valid game. Please try a different game name.");
    }
}