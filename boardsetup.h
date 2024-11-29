#ifndef BOARDSETUP_H
#define BOARDSETUP_H
#include "board.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class BoardSetup: public Board {

    unordered_map<char, pair<int, int>> linkPositions;
    std::vector<std::string> cur_board;
    public:
        BoardSetup(int number_of_players);
        char displayAt(int row, int col) override;
        unordered_map<char, pair<int, int>> getLinkPositions();
        void removeLink(char link_name);
};

#endif
