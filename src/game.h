#pragma once
#include<set>
#include<vector>
#include<string>
using namespace std;
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
    //will include companies, genres, similar games, release date, and id
    game(int ID, string gameName,string gameReleaseDate, vector<int>& similarGames);
    ~game();

    //getters
    vector<Company> getCompanies() const;
    set<Genre> getGenres() const;
    unsigned int getID() const;
    string getName() const;
    string getReleaseDate() const;
    vector<int> getSimilarGames() const;

    //used for the unordered map
    bool operator==(const game &other) const;
private:

    const string name;

    vector<Company> companies;
    set<Genre> genres;

    string releaseDate; // Change to an actual time type is prolly better
    unsigned int id;

    vector<int> similarGamesIDs;

};
// functor to hash a game
struct gameHash
{
    size_t operator()(const game& game) const;
};