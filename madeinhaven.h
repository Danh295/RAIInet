#ifndef MADEINHAVEN_H
#define MADEINHAVEN_H
#include "ability_x.h"

class MadeInHaven : public Ability {
    int id;

public:
    MadeInHaven(int id);
    
    char effect() override;
};

#endif