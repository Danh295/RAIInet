#ifndef PLAYER_H
#define PLAYER_H
#include "link_x.h"
#include <vector>

using namespace std;

class Link;
class Ability;

class Player{
    int id;
    static const int num_of_links= 8;
    static const int num_of_abilities =5;
    Link* links[num_of_links];
    char abilities[num_of_abilities];
    int downloaded_virus=0;
    int downloaded_data=0;

public:
    Player(int id);
    Link* getLink(char name); //getter 
    void setAbility(int idx, char b);
    void setLink(int idx, int strength, bool virus);
    bool isReady(); //is the player ready to play?
    string getAbilities();
    bool removeAbility(char ability_id);
    int getId();
    void setRandomLinks();
    int getDownloadedData();
    int getDownloadedVirus();
    vector<Link*> getAllLinks();
    void incrementDownloadedVirus();
    void incrementDownloadedData();
};

#endif