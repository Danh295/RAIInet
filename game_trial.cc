#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "link_x.h"
#include "board.h"
#include "game_x.h"
#include "player_x.h"

using namespace std;

bool Game::isValidSetup() {
    for (const auto& p : players) {
        if (!p->isReady()) {
            return false;
        }
    }
    return true;
}

void Game::playerAbilityToPlayerLink(int turn, char link_name, char ability_id) {
    auto p = players[turn % number_of_players];
    auto l = p->getLink(link_name);

    if (p->removeAbility(ability_id)) {
        l->setAbility(ability_id);
    }
}

int Game::findWinner() {
    for (auto it = players.begin(); it != players.end(); ++it) {
        auto p = *it;
        if (p->getDownloadedVirus() == 4) {
            // Player lost
            players.erase(it);
            number_of_players--;
        }
        if (p->getDownloadedData() == 4) {
            return p->getId(); // Player wins
        }
    }
    if (number_of_players == 1) {
        return players[0]->getId();
    }
    return 0;
}

void Game::playerAbilityToOpponentLink(int turn, char link_name, char ability_id) {
    auto p = players[turn % number_of_players];
    shared_ptr<Link> l = nullptr;

    for (size_t i = 0; i < players.size(); ++i) {
        if (i == turn % number_of_players) continue;

        auto opponent = players[i];
        l = opponent->getLink(link_name);
        if (l) break;
    }
    if (!l) return;

    bool apply_ability = true;
    for (char a : l->getAbilities()) {
        if (a == 'M' && ability_id != 'D') { // "Made in Heaven"
            apply_ability = false;
            break;
        }
    }

    if (apply_ability) {
        if (ability_id == 'D') {
            if (l->isVirus()) {
                p->incrementDownloadedVirus();
            } else {
                p->incrementDownloadedData();
            }
        } else if (ability_id == 'S') {
            l->shambles();
        } else if (ability_id == 'P') {
            l->enlighten();
        }
    }
}

void Game::render() {
    notifyObservers();
}

char Game::getState(int row, int col) const {
    return theboard->displayAt(row, col);
}

unordered_map<char, pair<int, int>> Game::getLinkPositions() {
    return theboard->getLinkPositions();
}

bool Game::checkClashOnSquare(int turn, char linkName, char dir, int move) {
    auto pos = theboard->getLinkPositions();
    int id = turn % number_of_players;
    auto p = players[id];
    auto nextLink = p->getLink(linkName);

    int row = pos[linkName].first;
    int col = pos[linkName].second;

    switch (dir) {
        case 'u': row += move; break;
        case 'd': row -= move; break;
        case 'l': col -= move; break;
        case 'r': col += move; break;
    }

    if (row < 0 || row >= 8 || col < 0 || col >= 8) return false;

    char curLinkName = getState(row, col);
    if (curLinkName == '.') return true;

    for (const auto& otherPlayer : players) {
        auto l = otherPlayer->getLink(curLinkName);
        if (l) {
            if (l->getStrength() > nextLink->getStrength()) {
                theboard->removeLink(linkName);
                nextLink->gotDownloaded();
                return false;
            } else {
                theboard->removeLink(l->getId());
                l->gotDownloaded();
                return true;
            }
        }
    }
    return true;
}

void Game::printDownloaded(int id) {
    auto p = players[id];
    cout << p->getDownloadedData() << "D, " << p->getDownloadedVirus() << "V\n";
}

void Game::printPlayerAbilityCount(int id) {
    int result = 0;
    for (char a : players[id]->getAbilities()) {
        if (a != ' ') result++;
    }
    cout << result << '\n';
}

void Game::printLinks(int id) {
    const auto& links = players[id]->getAllLinks();
    for (const auto& l : links) {
        char type = l->isVirus() ? 'V' : 'D';
        cout << l->getId() << ": " << type << l->getStrength() << " ";
    }
    cout << endl;
}

void Game::printOpponentLinks(int id) {
    const auto& links = players[id]->getAllLinks();
    for (const auto& l : links) {
        if (l->isVisible()) {
            char type = l->isVirus() ? 'V' : 'D';
            cout << l->getId() << ": " << type << l->getStrength() << " ";
        } else {
            cout << l->getId() << ": ? ";
        }
    }
    cout << endl;
}

char Game::getAbilityIdThatAffectMovement(int id, char linkName) {
    auto l = players[id]->getLink(linkName);
    for (char a : l->getAbilities()) {
        if (a == 'L') return 'L';
    }
    return '.';
}

char Game::getPlayerAbilityById(int id, int idx) {
    auto p = players[id];
    char ability_id = p->getAbilities()[idx - 1];
    p->removeAbility(ability_id);
    return ability_id;
}

void Game::addPlayers(int id) {
    players.push_back(make_shared<Player>(id));
}

shared_ptr<Player> Game::getPlayer(int id) {
    return players[id];
}
