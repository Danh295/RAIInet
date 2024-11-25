#ifndef ABILITYDECORATOR_H
#define ABILITYDECORATOR_H
#include "decorator.h"
#include "board.h"
using namespace std;

class AbilityDecorator : public Decorator {

    Link link;
    int x,y;
    char direction;
    unordered_map<char,pair<int, int>> linkPositions;

public:
    AbilityDecorator(Board *base, int x, int y, int ability_id, unordered_map<char, pair<int, int>> linkPositions);
    char linkAt(int row, int col) override;
    int abilityAt(int row, int col) override;
};

#endif