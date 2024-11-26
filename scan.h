#ifndef SCAN_H
#define SCAN_H
#include "ability_x.h"

class Scan : public Ability {
    int id;

public:
    Scan(int id);
    
    char effect() override;
};

#endif