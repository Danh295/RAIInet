#include "link_x.h"
#include "ability_x.h"


Link::Link(char name, int strength, bool virus): name{name}, strength{strength}, virus{virus} {
    a = new Ability();
    visible = false;
    downloaded = false;
}

Link::~Link(){
    delete a;
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
    return virus;
}
    
int Link::getStrength(){//getter
    return strength;
}
    
string Link::getAbilities(){
    return abilities;
}

//only used for longTerm abilities
void Link::setAbility(char a){

    for(auto ab: abilities){
        if(ab == a){
            return;
        }
    }
    abilities= abiilities + a;
}

void Link::setStrength(int strenght){
    this->strength = strength;
}
void Link::setType(bool virus){
    this->virus = virus;
}


bool isDownloaded(){
    return downloaded;
}
void gotDownloaded(){
    downloaded = true;
}
