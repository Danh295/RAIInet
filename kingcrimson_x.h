#ifndef kINGCRIMSON_H
#define kINGCRIMSON_H
#include "ability_x.h"
#include <utility>

class KingCrimson : public Ability {
    const int id = 7;
    int to_x, to_y;
public:
    KingCrimson(int to_x, int to_y);
    int getId(){return id;}
    pair<int, int> effect() override;
};

#endif