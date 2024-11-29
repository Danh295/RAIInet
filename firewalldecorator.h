#ifndef FIREWALLDECORATOR_H
#define FIREWALLDECORATOR_H
#include "decorator.h"
#include "board.h"
#include <string>
#include <unordered_map>
using namespace std;

class FirewallDecorator : public Decorator {

    int to_x, to_y, turn, number_of_players;
    unordered_map<char,pair<int, int>> linkPositions;
    
    public:
        FirewallDecorator(Board *previous, int turn, int number_of_players, int x, int y, std::unordered_map<char, std::pair<int, int>> linkPositions);
        unordered_map<char, pair<int, int>> getLinkPositions();
        char displayAt(int row, int col) override;

};

#endif