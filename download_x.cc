#include "download_x.h"
#include "ability_x.h"


bool Download::effect( Link& link){
    return link.isVirus();
    //continue this in the game by updating the player and replacing the position of the link to a dot.
}