#include "download_x.h"
#include "ability_x.h"


int Download::effect( Link& link){
    if(link.is_virus()){
        return -1;
    }
    return 1;

    //continue this in the game by updating the player and replacing the position of the link to a dot.
}