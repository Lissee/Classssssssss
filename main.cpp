#include <iostream>
#include <vector>

using namespace std;
//Продажа игр
enum GENRES {
    Action,
    Adventure,
    Arcade,
    Educational,
    Fighting,
    Other,
    Quest,
    RPG,
    Racing,
    Shooter,
    Strategy
};

enum STATUS {
    Online,
    Offline
};

string getStatus(STATUS status) {
    switch (status) {
        case STATUS::Online:
            return "Online";
        case STATUS::Offline:
            return "Offline";
    }
}

string getGenres(GENRES genres) {
    switch (genres) {
        case GENRES::Action:
            return "Action";
        case GENRES::Adventure:
            return "Adventure";
        case GENRES::Arcade:
            return "Arcade";
        case GENRES::Educational:
            return "Educational";
        case GENRES::Fighting:
            return "Fighting";
        case GENRES::Other:
            return "Other";
        case GENRES::Quest:
            return "Quest";
        case GENRES::RPG:
            return "RPG";
        case GENRES::Racing:
            return "Racing";
        case GENRES::Shooter:
            return "Shooter";
        case GENRES::Strategy:
            return "Strategy";
    }
}

class Game {
    string name;
    unsigned int year;
    string price;
    GENRES genres;
    STATUS status;
public:
    Game(string name, STATUS status, GENRES genres, unsigned int year, string price) :
            name(name), status(status),
            genres(genres),
            year(year), price(price) {
    }

    const string &getName() const {
        return name;
    }

    STATUS getStatus() const {
        return status;
    }

    GENRES getGenres() const {
        return genres;
    }
    const string &getPrice() const {
        return price;
    }

    string getDescription() {
        return "Game: " + name + " | Genres: " + ::getGenres(genres) + " " + ::getStatus(status) + " | " + to_string(year) + " year | " + price + "$";
    }

    static Game *createGameCS_GO() {
        return new Game("CS:GO", STATUS::Online, GENRES::Shooter, 2012, "0");
    }

    static Game *createCyberpunk_2077() {
        return new Game("Cyberpunk 2077", STATUS::Offline, GENRES::Action, 2021, "18.35");
    }

    static Game *createTheWitcher_3_WildHunt(GENRES genres = GENRES::Action, STATUS status = STATUS::Offline) {
        return new Game("The Witcher 3: Wild Hunt",  status, genres, 2015, "16.43");
    }
};

int main() {
    vector<Game *> game_1, game_2;

    game_1.push_back(Game::createGameCS_GO());

    for (int i = 0; i < 3; i++) {
        game_1.push_back(Game::createCyberpunk_2077());
        if (i%2 == 0) {
        game_1.push_back(Game::createTheWitcher_3_WildHunt());
        }
    }

    cout << "Order 1: " << endl;
    for (int i = 0, len = game_1.size(); i < len; i++) {
        cout << game_1[i]->getDescription() << endl;
    }


    for (int i = 0; i < 5; i++) {
        game_2.push_back(Game::createTheWitcher_3_WildHunt());
    }

    cout << "Order 2: " << endl;
    for (int i = 0, len = game_2.size(); i < len; i++) {
        std::cout << game_2[i]->getDescription() << endl;
    }


    return 0;
}