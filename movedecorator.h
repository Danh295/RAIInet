#ifndef MOVEDECORATOR_H
#define MOVEDECORATOR_H
#include "decorator.h"
#include "board.h"
using namespace std;

class MoveDecorator : public Decorator {

    char link_name; 
    char direction;
    unordered_map<char,pair<int, int>> linkPositions;
    int from_x, from_y;
    
    public:
        MoveDecorator(Board *base, char link_name, char direction, unordered_map<char, pair<int, int>> linkPositions);
        unordered_map<char, pair<int, int>> getLinkPositions();
        char displayAt(int row, int col) override;
};

#endif
