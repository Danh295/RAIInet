#ifndef BOARDSETUP_H
#define BOARDSETUP_H
#include "board.h"
#include <iostream>


class BoardSetup: public Board {

    unordered_map<char, pair<int, int>> linkPositions;

    public:
        BoardSetup(int number_of_players);
        char linkAt(int row, int col) override;
        Ability* abilityAt(int row, int col) override;
        char displayAt(int row, int col) override;
};

#endif
