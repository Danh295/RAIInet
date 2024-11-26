#ifndef Z_H
#define Z_H
#include "ability_x.h"

class Z : public Ability {
    const int id = 6;

public:
    Z(int id);
    char getId();
    char effect() override;
};

#endif