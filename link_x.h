#ifndef LINK_H
#define LINK_H
#include <vector>
#include <string>

using namespace std;
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
    char getId(){return name;}   //getter 
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