#include "link_x.h"
#include "ability_x.h"


Link::Link(char name, int strength, bool virus): name{name}, strength{strength}, virus{virus} {
    a = new Ability();
    visible = false;
}

Link::~Link(){
    delete a;
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
    
vector<Ability*> Link::getAbilities(){
    return abilities;
}

//only used for longTerm abilities
void Link::setAbility(Ability *b){

    for(auto a: abilities){
        if(a->getId()==b->getId()){
            return;
        }
    }
    abilities.emplace_back(std::move(b));
}

void Link::setStrength(int strenght){
    this->strength = strength;
}
void Link::setType(bool virus){
    this->virus = virus;
}

