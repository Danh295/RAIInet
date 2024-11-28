#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board {
    public:
        virtual ~Board();

        virtual char linkAt(int row, int col);
        virtual Ability* abilityAt(int row, int col);
        virtual char displayAt(int row, int col);
};

#endif