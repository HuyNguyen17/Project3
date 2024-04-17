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
    //placeholder for JSON parsing
    //will include companies, genres, similar games, release date, and id
    game(string data);
    ~game();

    //getters
    vector<Company> getCompanies() const;
    set<Genre> getGenres() const;
    unsigned int getID() const;
    string getName() const;
    unsigned int getReleaseDate() const;
    vector<unsigned int> getSimilarGames() const;

    //used for the unordered map
    bool operator==(const game &other) const;
private:

    const string name;

    vector<Company> companies;
    set<Genre> genres;

    unsigned const int release_date; // Change to an actual time type is prolly better
    unsigned const int id;

    vector<unsigned int> similarGamesIDs;

};
// functor to hash a game
struct gameHash
{
    size_t operator()(const game& game) const;
};