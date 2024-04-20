#pragma once
#include<set>
#include<vector>
#include<string>
using namespace std;
// enumeration for genres
struct Genre
{
    const int id;
    const string name;

    Genre(int id, string name) : id(id), name(name) {};
};
struct Company
{
    const int id;
    const string name;

    Company(int id, string name) : id(id), name(name) {};
};

class game {
public:
    //will include companies, genres, similar games, release date, and id
    game(int ID, string gameName, string gameReleaseDate,
         vector<Genre>& genres, vector<Company>& companies, vector<int>& similarGames);
    ~game();

    //getters
    vector<Company> getCompanies() const;
    vector<Genre> getGenres() const;
    int getID() const;
    string getName() const;
    string getReleaseDate() const;
    vector<int> getSimilarGames() const;

    //used for the unordered map
    bool operator==(const game &other) const;
private:

    const string name;
    const string releaseDate; // Change to an actual time type is prolly better

    vector<Company> companies;
    vector<Genre> genres;

    const int id;

    vector<int> similarGamesIDs;

};
// functor to hash a game
struct gameHash
{
    size_t operator()(const game& game) const;
};