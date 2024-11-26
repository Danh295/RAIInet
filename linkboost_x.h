#ifndef LINKBOOST_H
#define LINKBOOST_H
#include "ability_x.h"

class LinkBoost : public Ability {
    int id;

public:
    LinkBoost(int id);
    int getId(){return id;}
    char effect() override;
};

#endif
