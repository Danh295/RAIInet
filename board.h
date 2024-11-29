#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board {
    public:
        virtual ~Board();
        virtual char displayAt(int row, int col);
};

#endif