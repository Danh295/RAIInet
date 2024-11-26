#ifndef FIREWALL_H
#define FIREWALL_H
#include "ability_x.h"

class Firewall : public Ability {
    int id;

public:
    Firewall(int id);
    
    char effect() override;
};

#endif