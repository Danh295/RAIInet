#ifndef LINK_H
#define LINK_H
#include "ability_x.h"
#include <vector>

class Ability;

class Link{
    char name;
    bool visible;
    int strength;
    bool virus;//type
    //only longterm abilities
    vector<Ability*> abilities={nullptr};

public:
    Link(char name, int strength, bool virus);
    char getName(){return name;}   //getter 
    void shambles();//setter
    bool isVirus();//getter
    void enlighten();//setter
    int getStrength();//getter
    vector<Ability*> getAbilities();
    void setAbility(Ability *b);
    void setStrength(int strenght);
    void setType(bool virus);
};

#endif