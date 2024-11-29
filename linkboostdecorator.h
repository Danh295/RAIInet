#ifndef LINKBOOSTDECORATOR_H
#define LINKBOOSTDECORATOR_H
#include "decorator.h"
#include "board.h"
#include <string>
#include <unordered_map>
using namespace std;

class LinkBoostDecorator : public Decorator {

    char link_name; 
    char direction;
    unordered_map<char,pair<int, int>> linkPositions;
    bool ability_triggered = false;
    
    public:
        LinkBoostDecorator(Board *base, char link_name, char direction, unordered_map<char, pair<int, int>> linkPositions);
        unordered_map<char, pair<int, int>> getLinkPositions();
        char displayAt(int row, int col) override;
};

#endif