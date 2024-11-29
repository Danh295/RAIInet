#include "kingcrimsondecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

KingCrimsonDecorator::KingCrimsonDecorator(Board *base, char link_name, int to_x, int to_y, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, to_x{to_x}, to_y{to_y} {
            
            linkPositions = base->getLinkPositions();
            from_x = linkPositions[link_name].first;
            from_y = linkPositions[link_name].second;

            if(displayAt(to_x, to_y)!='.'){
                return;
            }
            
            linkPositions[link_name]={to_x, to_y};
        }

char KingCrimsonDecorator::displayAt(int row, int col){
    if (row ==  linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name;
    }
    if(row == from_y && col == from_x){
        return '.';
    }
    return base->displayAt(row, col);//this points to the previous version on the board
}

std::unordered_map<char, std::pair<int, int>> KingCrimsonDecorator::getLinkPositions(){
    return linkPositions;
}


void KingCrimsonDecorator::removeLink(char link_name){
    if (linkPositions.find(link_name) != linkPositions.end()) {
        // Delete the key
        linkPositions.erase(link_name);
    }
}