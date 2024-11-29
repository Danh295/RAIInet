#include "text.h"
#include  <iostream>

using namespace std;

Text::Text(Game *game, int id):
game{game}, id{id}{
    game->attach(this);
    if (id == 0) otherId = 1;
    else otherId = 0;
}

void Text::notify () {
    cout << "Player " << id+1 << ':' << endl;
    cout << "Downloaded: ";
    game->printDownloaded(id);
    cout << endl << "Abilities: ";
    game->printPlayerAbilityCount(id);
    cout << endl;
    game->printLinks(id);
    for (int j = 0; j < 8; ++j) {
        cout << '=';
    }
    cout << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << game->getState(i, j);
        }
        cout << endl;
    }
    for (int j = 0; j < 8; ++j) {
        cout << '=';
    }
    cout << endl;
    cout << "Player " << otherId+1 << ':' << endl;
    cout << "Downloaded: ";
    game->printDownloaded(otherId);
    cout << endl << "Abilities: ";
    game->printPlayerAbilityCount(otherId);
    cout << endl;
    game->printOpponentLinks(otherId);
}

