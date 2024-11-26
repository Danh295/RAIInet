#ifndef SCAN_H
#define SCAN_H
#include "ability_x.h"

class Scan : public Ability {
    const int id = 5;

public:
    Scan();
    int getId(){return id;}
    
    void effect() override;
};

#endif