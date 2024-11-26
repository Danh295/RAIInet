#ifndef kINGCRIMSON_H
#define kINGCRIMSON_H
#include "ability_x.h"

class KingCrimson : public Ability {
    int id;

public:
    KingCrimson(int id);
    
    char effect() override;
};

#endif