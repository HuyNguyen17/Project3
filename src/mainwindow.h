//
// Created by ricky on 4/20/24.
//

#ifndef PROJECT3_MAINWINDOW_H
#define PROJECT3_MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include "parser.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    graph gameGraph;
private slots:
    void searchButtonClick();
    void on_radioBtnGames_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    class Parser* parsed;
};

#endif //PROJECT3_MAINWINDOW_H
