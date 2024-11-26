#ifndef POLARIZE_H
#define POLARIZE_H
#include "ability_x.h"

class Polarize : public Ability {
    const int id = 4;

public:
    Polarize();
    int getId(){return id;}    
    void effect() override;
};

#endif