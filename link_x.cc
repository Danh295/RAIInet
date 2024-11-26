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
    
Ability* Link::getAbility(){
    return a;
}
void Link::setAbility(Ability *b){
    delete a;
    a = b;
}


