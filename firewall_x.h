#ifndef FIREWALL_H
#define FIREWALL_H
#include "ability_x.h"

class Firewall : public Ability {
    const int id = 2;

public:
    Firewall();
    int getId(){return id;}
    bool effect() override;
};

#endif