#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>

class Ability {
    public:
        virtual ~Ability();
        virtual Effect(int row, int col);
};

#endif