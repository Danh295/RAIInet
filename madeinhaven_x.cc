#include "madeinhaven_x.h"
#include "ability_x.h"


bool MadeInHaven::effect(int ability_id){
    //all link based abilities are ineffective on this link, except for download
    // made in haven can only be stopped if taken off the board
    if(ability_id == 3){//if the ability is a download
        return true;
    }
    return false;
}

