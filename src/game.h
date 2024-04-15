#pragma once

// enumeration for genres
enum Genre{};

struct Company
{
    unsigned const int id;
    const string name;
};

class game {
public:
    game();
    //placeholder for JSON parsing
    //will include companies, genres, similar games, release date, and id
    game(string data);
    ~game();

    //getters
    vector<Company> getCompanies();
    set<Genre> getGenres();
    unsigned int getID();
    string getName();
    unsigned int getReleaseDate();
    vector<unsigned int> getSimilarGames();
private:

    const string name;

    vector<Company> companies;
    set<Genre> genres;

    unsigned const int release_date; // Change to an actual time type is prolly better
    unsigned const int id;

    vector<unsigned int> similarGamesIDs;

};