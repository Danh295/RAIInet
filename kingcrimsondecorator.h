#ifndef KINGCRIMSONDECORATOR_H
#define KINGCRIMSONDECORATOR_H
#include "decorator.h"
#include "board.h"
#include <string>
#include <unordered_map>
using namespace std;

class KingCrimsonDecorator : public Decorator {

    char link_name; 
    int to_x, to_y, from_x, from_y;
    unordered_map<char,pair<int, int>> linkPositions;
    
    public:
        KingCrimsonDecorator(Board *base, char link_name, int to_x, int to_y, unordered_map<char, pair<int, int>> linkPositions);
        unordered_map<char, pair<int, int>> getLinkPositions();
        char displayAt(int row, int col) override;
        void removeLink(char link_name);
};

#endif