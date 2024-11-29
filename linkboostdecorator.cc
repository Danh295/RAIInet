#include "linkboostdecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

LinkBoostDecorator::LinkBoostDecorator(Board *base, char link_name, char direction, unordered_map<char, pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, direction{direction} {

            linkPositions = base.linkPositions;
            int dx= linkPositions[link_name].first;
            int dy =linkPositions[link_name].second;
            from_x = dx;
            from_y = dy;
            move = 2;

            switch (direction) {
                case 'u': dx= dx +move; break;
                case 'd': dx= dy-move; break;
                case 'l': dy= dy-move; break;
                case 'r': dy=dy+move; break;
            }
            
            linkPositions[link_name]={dx, dy};

        }

char LinkBoostDecorator::displayAt(int row, int col){
    if (row ==  linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name;
    }
    if(row == from_y && col == from_x){
        return '.';
    }
    return base->charAt(row, col);//this points to the previous version on the board
}

std::unordered_map<char, std::pair<int, int>> LinkBoostDecorator::getLinkPositions(){
    return linkPositions;
}