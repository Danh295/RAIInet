#ifndef PLAYER_H
#define PLAYER_H
#include "ability_x.h"
#include "link_x.h"
#include <vector>

class Link;
class Ability;

class Player{
    int id;
    int num_of_links= 8;
    int num_of_abilities =5;
    Link* links[num_of_links]={nullptr};
    Ability* abilities[num_of_abilities] ={nullptr};
    int downloaded_virus=0;
    int downloaded_data=0;

public:
    Player(int id);
    Link* getLink(char name); //getter 
    void setAbility(int idx, Ability *b);
    void Player::setLink(Link *link);
    bool isReady(); //is the player ready to play?
    vector<Link*> getAbilities();
    bool removeAbility(int ability_id);
    int getId();
};

#endif