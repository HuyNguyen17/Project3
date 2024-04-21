//
// Created by ricky on 4/20/24.
//

#ifndef PROJECT3_MAINWINDOW_H
#define PROJECT3_MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include "parser.h"
#include <iostream>
#include <QCompleter>
#include <QListWidgetItem>

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
    void on_radioBtnCompany_toggled(bool checked);
    void on_radioBtnGenre_toggled(bool checked);
    void on_radioBtnConnectedTo_toggled(bool checked);
    void on_listWgtSearchObjects_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    class Parser* parsed;
    QCompleter* gameCompleter;
    QCompleter* genreCompleter;
    QCompleter* companyCompleter;

    void displayGameInfo(shared_ptr<game> gamePtr);
};

#endif //PROJECT3_MAINWINDOW_H
