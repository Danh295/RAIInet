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
    int downloaded_virus;
    int downloaded_data;

public:
    Player(int id);
    Link* getLink(char name); //getter 
    void setAbility(int idx, Ability *b);
    void Player::setLink(char name, int strength, bool virus);
    bool isReady(); //is the player ready to play?
};

#endif