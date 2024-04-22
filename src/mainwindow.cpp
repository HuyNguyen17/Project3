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
    setWindowTitle("infoGamerz");
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
    if (ui->radioBtnGames->isChecked())
    {
        ui->labelWaitText->setVisible(false);

        auto testVector = gameGraph.findByName(ui->lineEditSearchBar->text().toStdString());
        if (!testVector.empty()) {
            ui->labelSimilarGame->setVisible(true);
            for (const auto &gamePtr: testVector) {
                if (ui->radioBtnBFS->isChecked())
                {
                    gameGraph.BFSprintConnectedGames(gamePtr->getName(), 1);
                } else if (ui->radioBtnDFS->isChecked()) {
                    gameGraph.DFSprintConnectedGames(gamePtr->getName(), 1);
                }

                // Display Game header
//                ui->lineEditSearchBar->clear();
                ui->textBrowserGameHeader->setHtml("<b><font color='#3584E4'>Viewing:</font></b><br>");
                ui->textBrowserGameHeader->append("<b><font size='4'>"+ QString::fromStdString(gamePtr->getName()) +"</font></b>");
                ui->textBrowserGameHeader->append("<b>Released in</b>: " + QString::fromStdString(gamePtr->getReleaseDate()));
                string genreStr = " <b>Genres:</b> \n";
                for(const auto& genre : gamePtr->getGenres())
                {
                    genreStr += genre.name;
                    genreStr += ", ";
                }
                // remove the last two characters of the string before printing
                ui->textBrowserGameHeader->append(genreStr.substr(0, genreStr.size() - 2).c_str());
//                ui->textBrowserGameHeader->append("Genre: " + QString::fromStdString(gamePtr->getGenres()[0].name));
                ui->textBrowserGameHeader->append("<b>Created by:</b> " + QString::fromStdString(gamePtr->getCompanies()[0].name));

                // populate QListWidget with text corresponding to the results
                ui->listWgtSearchObjects->clear();
                ui->listWgtSearchObjects->addItems(gameGraph.getQStringGameNameResults());
                ui->listWgtSearchObjects->setStyleSheet("border: 1px solid rgb(125, 125, 125); padding-top: 8px; padding-left: 8px");

            }
            // are they checking for connections
            if (ui->checkBoxConnectedTo->isChecked())
            {
                if (!ui->lineEditConnectedToResults->text().toStdString().empty())
                {
                    std::string name1 = ui->lineEditSearchBar->text().toStdString();
                    std::string name2 = ui->lineEditConnectedToResults->text().toStdString();
                    if (ui->radioBtnGames->isChecked())
                    {
                        // Searchpath 0 corresponds to BFS, Searchpath 1 is DFS
                        ui->textBrowsrConnectedToResult->setHtml(gameGraph.gamesConnected(name1, name2, 0));
                    } else
                    {
                        ui->textBrowsrConnectedToResult->setHtml(gameGraph.gamesConnected(name1, name2, 1));
                    }
                }
            }
        }
        else
        {
            ui->textBrowserGameHeader->setHtml(QString::fromStdString(" is not a valid Game. Please try a different Game name."));
        }
    }
    else if(ui->radioBtnGenre->isChecked())
    {
        // do genre search
        auto gamesBygenre = gameGraph.getGamesByGenre(ui->lineEditSearchBar->text().toStdString());
        if (!gamesBygenre.empty()) {
            // store the games from genre into qlist
            QStringList gamesFromGenre;
            for (const auto &gamePtr: gamesBygenre)
            {
                gamesFromGenre << QString::fromStdString(gamePtr->getName());
            }
            // populate QListWidget with text corresponding to the results
            ui->listWgtSearchObjects->clear();
            ui->listWgtSearchObjects->addItems(gamesFromGenre);
        }
        else
        {
            ui->textBrowserGameHeader->setHtml(
                    " is not a valid Genre. Please try a different Genre name.");
        }
    }
    else if (ui->radioBtnCompany->isChecked())
    {
        // do company search
        auto gamesByCompany = gameGraph.getGamesByCompany(ui->lineEditSearchBar->text().toStdString());
        if (!gamesByCompany.empty()) {
            // store the games from genre into qlist
            QStringList gamesFromCompany;
            for (const auto &gamePtr: gamesByCompany)
            {
                gamesFromCompany << QString::fromStdString(gamePtr->getName());
            }
            // populate QListWidget with text corresponding to the results
            ui->listWgtSearchObjects->clear();
            ui->listWgtSearchObjects->addItems(gamesFromCompany);
        }
        else
        {
            ui->textBrowserGameHeader->setHtml(
                    " is not a valid Company. Please try a different Company name.");
        }
    }

}

void MainWindow::on_listWgtSearchObjects_itemSelectionChanged() {
    auto selectedItems = ui->listWgtSearchObjects->selectedItems();
    // change the selection to the selected item if it's empty
    if(!selectedItems.empty())
    {
      auto gameName = selectedItems.at(0);
      // uses the first game found by the graph. The name should already be in the map so this should be fine
      auto gamePtr = gameGraph.findByName(gameName->text().toStdString()).at(0);
      //sets the name of the game
      ui->textBrowserLstWgtResults->setHtml(gameName->text());
      displayGameInfo(gamePtr);
    }
}

void MainWindow::displayGameInfo(shared_ptr<game> gamePtr) {

    ui->labelSimilarGameDetail->setVisible(true);
    ui->textBrowserLstWgtResults->setStyleSheet("border: 1px solid rgb(125, 125, 125); padding-top: 8px; padding-left: 8px");
    ui->textBrowserLstWgtResults->append("Released in: " + QString::fromStdString(gamePtr->getReleaseDate()));
    // genres
    string genreStr = " <b>Genres:</b> \n";
    for(const auto& genre : gamePtr->getGenres())
    {
        genreStr += genre.name;
        genreStr += ", ";
    }
    // remove the last two characters of the string before printing
    ui->textBrowserLstWgtResults->append(genreStr.substr(0, genreStr.size() - 2).c_str());

    // companies
    string companyStr = " <b>Companies:</b> \n";
    for(const auto& company : gamePtr->getCompanies())
    {
        companyStr += company.name;
        companyStr += ", ";
    }
    ui->textBrowserLstWgtResults->append(companyStr.substr(0, companyStr.size() - 2).c_str());

    ui->textBrowserLstWgtResults->append("\n");
    // similar games
    ui->textBrowserLstWgtResults->append(" <b>Similar Games</b>");
    for(auto simiGames : gameGraph.findByID(gamePtr->getID())->getSimilarGames())
    {
          ui->textBrowserLstWgtResults->append(QString::fromStdString(gameGraph.findByID(simiGames)->getName()));
    }

}

void MainWindow::on_radioBtnGames_toggled(bool checked)
{
    // sets the autocompleter if checked
    if(checked)
    {
        ui->lineEditSearchBar->clear();
//        ui->listWgtSearchObjects->clear();
//        ui->textBrowserLstWgtResults->clear();
        // show the search config widget for game
        ui->gameSearchWidget->setVisible(true);
        // should prolly group these together into a widget
        ui->checkBoxConnectedTo->setVisible(true);
        ui->lineEditConnectedToResults->setVisible(true);
        ui->lineEditConnectedToResults->clear();
        ui->textBrowsrConnectedToResult->setVisible(true);
        ui->textBrowsrConnectedToResult->clear();

        gameCompleter = new QCompleter(gameGraph.getQStringGameNames(), ui->lineEditSearchBar);
        gameCompleter->setCaseSensitivity(Qt::CaseInsensitive);
        ui->lineEditSearchBar->setCompleter(gameCompleter);

        if(ui->checkBoxConnectedTo->isChecked())
        {
            ui->lineEditConnectedToResults->setCompleter(gameCompleter);
        }
    }
}

void MainWindow::on_radioBtnCompany_toggled(bool checked)
{
    // sets the autocompleter if checked
    if (checked)
    {
        ui->lineEditSearchBar->clear();
//        ui->listWgtSearchObjects->clear();
//        ui->textBrowserLstWgtResults->clear();

        ui->gameSearchWidget->setVisible(false);

        ui->checkBoxConnectedTo->setVisible(false);
        ui->lineEditConnectedToResults->setVisible(false);
        ui->textBrowsrConnectedToResult->setVisible(false);

        companyCompleter = new QCompleter(gameGraph.getQStringCompanyNames(), ui->lineEditSearchBar);
        companyCompleter->setCaseSensitivity(Qt::CaseInsensitive);
        ui->lineEditSearchBar->setCompleter(companyCompleter);
    }
}

void MainWindow::on_radioBtnGenre_toggled(bool checked) {
    // sets the autocompleter if checked
    if (checked)
    {
        ui->lineEditSearchBar->clear();
//        ui->listWgtSearchObjects->clear();
//        ui->textBrowserLstWgtResults->clear();

        ui->gameSearchWidget->setVisible(false);
        ui->checkBoxConnectedTo->setVisible(false);
        ui->lineEditConnectedToResults->setVisible(false);
        ui->textBrowsrConnectedToResult->setVisible(false);

        genreCompleter = new QCompleter(gameGraph.getQStringGenreNames(), ui->lineEditSearchBar);
        genreCompleter->setCaseSensitivity(Qt::CaseInsensitive);
        ui->lineEditSearchBar->setCompleter(genreCompleter);
    }
}

void MainWindow::on_checkBoxConnectedTo_toggled(bool checked)
{
    ui->lineEditConnectedToResults->setCompleter(gameCompleter);
}