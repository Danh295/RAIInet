#include "linkboostdecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

LinkBoostDecorator::LinkBoostDecorator(Board *base, char link_name, char direction, unordered_map<char, pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, direction{direction} {

            this->linkPositions = linkPositions;
            int dx= this->linkPositions[link_name].first;
            int dy =this->linkPositions[link_name].second;
            from_x = dx;
            from_y = dy;
            int move = 2;

            switch (direction) {
                case 'u': dx= dx -move; break;
                case 'd': dx= dx+move; break;
                case 'l': dy= dy-move; break;
                case 'r': dy=dy+move; break;
            }
            
            this->linkPositions[link_name]={dx, dy};
        }

char LinkBoostDecorator::displayAt(int row, int col){
    if (row ==  linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name;
    }
    if(row == from_y && col == from_x){
        return '.';
    }
    return base->displayAt(row, col);//this points to the previous version on the board
}

std::unordered_map<char, std::pair<int, int>> LinkBoostDecorator::getLinkPositions(){
    return this->linkPositions;
}

void LinkBoostDecorator::removeLink(char link_name){
    if (linkPositions.find(link_name) != linkPositions.end()) {
        // Delete the key
        linkPositions.erase(link_name);
    }
}
