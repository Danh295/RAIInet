#include "movedecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

MoveDecorator::MoveDecorator(Board *base, char link_name, char direction, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, direction{direction} {
            cout << "in moving";
            linkPositions = base->getLinkPositions();
            int dx= linkPositions[link_name].first;
            int dy =linkPositions[link_name].second;
            from_x = dx;
            from_y = dy;
            int move = 1;

            switch (direction) {
                case 'u': dx= dx+move; break;
                case 'd': dx= dx-move; break;
                case 'l': dy= dy-move; break;
                case 'r': dy=dy+move; break;
            }
            
            linkPositions[link_name]={dx, dy};

        }

char MoveDecorator::displayAt(int row, int col){

    if((row == from_y && col == from_x) || (linkPositions.find(link_name) == linkPositions.end())){
        return '.'; //we just left the square or the link was downloaded
    }
    if (row ==  linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name;
    }
    return base->displayAt(row, col);//this points to the previous version on the board
}
std::unordered_map<char, std::pair<int, int>> MoveDecorator::getLinkPositions(){
    return linkPositions;
}

void MoveDecorator::removeLink(char link_name){
    if (linkPositions.find(link_name) != linkPositions.end()) {
        // Delete the key
        linkPositions.erase(link_name);
    }
}