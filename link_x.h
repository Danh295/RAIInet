#ifndef LINK_H
#define LINK_H
#include "ability_x.h"

class Ability;

class Link{
    char name;
    bool visible;
    int strength;
    bool virus;
    Ability *a;

public:
    Link(char name, int strength, bool virus);
    char getName(){return name;}   //getter 
    void shambles();//setter
    bool isVirus();//getter
    void enlighten();//setter
    int getStrength();//getter
    Ability getAbility();
    void setAbility(Ability *b);
};

#endif