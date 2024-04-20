//
// Created by ricky on 4/20/24.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parser.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameGraph = parsed->parseToGraph("../data/smalldata.json");
}

void LoadFile()
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
            // testing to see if findbyname works
//        auto testVector= gameGraph.findByName("Doesn't Exist");
        auto testVector = gameGraph.findByName(ui->lineEdit->text().toStdString());
        if(!testVector.empty())
        {
            for (const auto& gamePtr : testVector)
            {
//                std::cout << "Game: " << gamePtr->getName() << ", Released " << gamePtr->getReleaseDate() << '\n';
                QString qtString = QString::fromStdString(gamePtr->getReleaseDate());
                ui->textBrowser_2->setHtml(ui->lineEdit->text() + "was released in: " + qtString);
            }
        }

}