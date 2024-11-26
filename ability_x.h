#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>

class Ability {
    const int id = 0;
    public:
        virtual ~Ability();
        virtual effect();
        int getId(){return id;}
};

#endif