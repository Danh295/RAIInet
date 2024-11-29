#ifndef ABILITYDECORATOR_H
#define ABILITYDECORATOR_H
#include "decorator.h"
#include "board.h"
#include <string>
#include <unordered_map>
using namespace std;

class AbilityDecorator : public Decorator {

    int x,y;
    unordered_map<char,pair<int, int>> linkPositions;

public:
    AbilityDecorator(Board *base, int x, int y, Ability ability, unordered_map<char, pair<int, int>> linkPositions);
    char linkAt(int row, int col);
    Ability* abilityAt(int row, int col);
    char displayAt(int row, int col) ;
};

#endif