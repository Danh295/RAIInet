#ifndef BOARDSETUP_H
#define BOARDSETUP_H
#include "board.h"
#include <iostream>


class BoardSetup: public Board {

    unordered_map<char, pair<int, int>> linkPositions;

    public:

        char linkAt(int row, int col) override;
        int abilityAt(int row, int col) override;
};

#endif
