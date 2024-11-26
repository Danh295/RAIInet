// movingbox.h
#ifndef MOVEDECORATOR_H
#define MOVEDECORATOR_H
#include "decorator.h"
#include "board.h"
using namespace std;

class MoveDecorator : public Decorator {

    Link link; 
    char direction;
    unordered_map<char,pair<int, int>> linkPositions;
    int from_x, from_y;
    bool ability_triggered = false;
    
    public:
        MoveDecorator(Board *base, Link link, char direction, unordered_map<char, pair<int, int>> linkPositions);
        char linkAt(int row, int col) override;
        int abilityAt(int row, int col) override;
};

#endif