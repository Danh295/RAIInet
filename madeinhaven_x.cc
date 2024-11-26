#include "madeinhaven_x.h"
#include "ability_x.h"


bool madeInHaven::effect(int ability_id){
    if(ability_id == 3){// made in haven can only be stopped if taken off the board
        return false;
    }
    return true;
}

