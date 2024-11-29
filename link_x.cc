#include "link_x.h"
#include <string>
#include <iostream>
using namespace std;

Link::Link(char name, int strength, bool virus): name{name}, strength{strength}, virus{virus} {
    visible = false;
    downloaded = false;
}



bool Link::isVisible(){
    return visible;
}
void Link::shambles(){//setter
    virus = !virus;
}
void Link::enlighten(){//setter
    visible = true;
}
bool Link::isVirus(){//getter
    return this->virus;
}
    
int Link::getStrength(){//getter
    return this->strength;
}
    
string Link::getAbilities(){
    return this->abilities;
}

//only used for longTerm abilities
void Link::setAbility(char a){

    for(auto ab: abilities){
        if(ab == a){
            return;
        }
    }

    this->abilities= this->abilities + a;
}

void Link::setStrength(int strength){
    this->strength = strength;
}
void Link::setType(bool virus){
    this->virus = virus;
}


bool Link::isDownloaded(){
    return downloaded;
}
void Link::gotDownloaded(){
    downloaded = true;
}
