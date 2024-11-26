#include "firewall_x.h"
#include "ability_x.h"


int Firewall::effect(Link& link){
    link.visible();
    if(link.isvirus()){
        return -1;
    }
    return 0;

    //continue this in the game by updating the player
    //if 0 ignore, if -1 the player download his own link
}

char Firewall::display(int turn){
    if(turn%2==0){
        return 'm';
    }
    return 'w';
}