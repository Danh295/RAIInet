#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <unordered_map>
using namespace std;

class Board {
    public:

        virtual char displayAt(int row, int col) = 0;
        virtual std::unordered_map<char, std::pair<int, int>> getLinkPositions() = 0;
        virtual void removeLink(char linkName) = 0;
        virtual ~Board();
};

#endif