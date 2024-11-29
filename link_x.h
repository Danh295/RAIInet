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
    bool downloaded;
    string abilities="";

public:
    Link(char name, int strength, bool virus);
    char getName(){return name;}   //getter 
    void shambles();//setter
    bool isVirus();//getter
    void enlighten();//setter
    int getStrength();//getter
    bool isDownloaded();
    bool isVisible();
    void gotDownloaded();
    string getAbilities();
    void setAbility(char a);
    void setStrength(int strenght);
    void setType(bool virus);
};

#endif