#ifndef MADEINHAVEN_H
#define MADEINHAVEN_H
#include "ability_x.h"

class MadeInHaven : public Ability {
    const int id=8;

public:
    MadeInHaven();
    int getId(){return id;}
    bool effect() override;
};

#endif