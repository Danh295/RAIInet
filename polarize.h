#ifndef POLARIZE_H
#define POLARIZE_H
#include "ability_x.h"

class Polarize : public Ability {
    int id;

public:
    Polarize(int id);
    
    char effect() override;
};

#endif