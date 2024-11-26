#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "subject.h"

class Board;
class Player;

class Game: public Subject {
    Board *theboard;
    int turn;
    vector<*Player> players;

    public:
        enum {Blank=0, LinkBoost, Firewall, Download, Polarize, Scan, MadeInHaven, KingCrimson, Z}; // Available abilities.
        explicit Studio(Board *theboard ): theboard{theboard} {}

        Board*& board() { return theboard; }
        void ability_to_square(int turn,  int x, int y, int ability_id);
        void ability_to_link(int turn,char link_name, int ability_id);
        void render();
        void animate(int turns);

        char getState(int row, int col) const override;
  
};

#endif
