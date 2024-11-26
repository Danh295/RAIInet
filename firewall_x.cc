#include "firewall_x.h"
#include "ability_x.h"


bool Firewall::effect(Link& link){
    link.enlighten();
    
    return link.isVirus();
    //returns true if we need to continue action in game
    //continue this in the game by updating the player
    //if 0 ignore, if -1 the player download his own link
}

char Firewall::display(int turn){
    if(turn%2==0){
        return 'm';
    }
    return 'w';
}