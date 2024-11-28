#include "player_x.h"
#include "ability_x.h"
#include "link_x.h"


Player::Player(int id): id{id} {
    

    for(int i = 0; i < num_of_abilities; ++i){
        abilities[i] = nullptr;
    }

    if(id == 1){
        links[0] = new Link('a', 0, true);
        links[1] = new Link('b', 0, true);
        links[2] = new Link('c', 0, true);
        links[3] = new Link('d', 0, true);
        links[4] = new Link('e', 0, false);
        links[5] = new Link('f', 0, false);
        links[6] = new Link('g', 0, false);
        links[7] = new Link('h', 0, false);
    }
    else if(id ==2){
        links[0] = new Link('A', 0, true);
        links[1] = new Link('B', 0, true);
        links[2] = new Link('C', 0, true);
        links[3] = new Link('D', 0, true);
        links[4] = new Link('E', 0, false);
        links[5] = new Link('F', 0, false);
        links[6] = new Link('G', 0, false);
        links[7] = new Link('H', 0, false);
    }
    else if(id==3){
        links[0] = new Link('q', 0, true);
        links[1] = new Link('r', 0, true);
        links[2] = new Link('t', 0, true);
        links[3] = new Link('u', 0, true);
        links[4] = new Link('v', 0, false);
        links[5] = new Link('x', 0, false);
        links[6] = new Link('y', 0, false);
        links[7] = new Link('z', 0, false);
    }
    else if(id==4){
        links[0] = new Link('Q', 0, true);
        links[1] = new Link('R', 0, true);
        links[2] = new Link('T', 0, true);
        links[3] = new Link('U', 0, true);
        links[4] = new Link('V', 0, false);
        links[5] = new Link('X', 0, false);
        links[6] = new Link('Y', 0, false);
        links[7] = new Link('Z', 0, false);
    }
}

int getId(){
    return id;
}
Link* Player::getLink(char name){
    for(int i = 0; i < num_of_links; ++i){
        if(links[i]!=nullptr && links[i]->getName()==name){
            return l;
        }
    }
    return nullptr;
}
void Player::setAbility(int idx, Ability *b){
    if (idx < 0 || idx >= 5) {
        return;
    }
    
    abilities[idx] = std::move(b);
}

vector<Ability*> Player::getAbility(){
    vector<Ability*> v = {nullptr};
    for(int i = 0; i < num_of_abilities; ++i){
        v.emplace_back(abilities[i]);
    }
    return v;
}


void Player::setLink(int idx, int strength, bool virus){
    links[idx]->setStrength(strength);
    links[idx]->setType(virus);

}
bool Player::isReady(){
    for(int i = 0; i < num_of_links; ++i){
        if(links[i]==nullptr || links[i]->getStrength()==0){
            return false;
        }
    }
    for(int i = 0; i < num_of_abilities; ++i){
        if(abilities[i]==nullptr){
            return false;
        }
    }

    return true;
}

bool Player::removeAbility(int ability_id){

    for(int i = 0; i < num_of_abilities; ++i){
        if(abilities[i]!=nullptr and abilities[i]->getId()==ability_id){
            abilities[i] = nullptr;
            return true;
        }
    }
    return false;
}