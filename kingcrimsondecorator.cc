#include "kingcrimsondecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

KingCrimsonDecorator::KingCrimsonDecorator(Board *base, char link_name, int to_x, int to_y, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, to_x{to_x}, to_y{to_y} {
            
            this->linkPositions = linkPositions;
            from_x = linkPositions[link_name].first;
            from_y = linkPositions[link_name].second;
            if((from_x<0 or from_x>7)||(from_y<0 or from_y>7)){
                cerr<< "Error: Link "<<link_name << " not found on the board!"<<endl;
                return;
            }
            if(displayAt(to_x, to_y)!='.'){
                return;
            }
            
            linkPositions[link_name]={to_x, to_y};
        }

char KingCrimsonDecorator::displayAt(int row, int col){

    if(row==-1 and col == -1){
        return '.';
    }
    if (row == from_x && col == from_y) {
        return '.'; // Previous position of the link
    }
    else if (linkPositions.find(link_name) != linkPositions.end() &&
        row == linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name; // New position of the link
    }
    return base->displayAt(row, col);//this points to the previous version on the board
}

std::unordered_map<char, std::pair<int, int>> KingCrimsonDecorator::getLinkPositions(){
    return linkPositions;
}

