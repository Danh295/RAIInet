#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board {
    public:
        virtual ~Board();

        virtual char linkAt(int row, int col);
        virtual int abilityAt(int row, int col);
};

#endif