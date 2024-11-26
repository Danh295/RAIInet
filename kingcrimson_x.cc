#include "kingcrimson_x.h"
#include "ability_x.h"
#include <utility>


KingCrimson::KingCrimson(int to_x, int to_y): to_x{to_x}, to_y{to_y} {}

Pair<int,int> KingCrimson::effect(){

    return make_pair(to_x, to_y);
}


    