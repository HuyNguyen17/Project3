#pragma once

// enumeration for genres
enum Genre{};

class game {
public:
    game();
    game(string data); //placeholder for JSON parsing
    ~game();


private:

    const string name;

    struct Company
    {
        unsigned const int id;
        const string name;
    };
    vector<Company> companies;
    set<Genre> genres;

    unsigned const int release_date; // Change to an actual time type is prolly better
    unsigned const int id;

    vector<unsigned int> similarGamesIDs;

};