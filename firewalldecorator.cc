#include "firewalldecorator.h"
#include "board.h"
#include <unordered_map>
#include <iostream>
using namespace std;

FirewallDecorator::FirewallDecorator(Board *previous, int turn, int number_of_players, int to_x, int to_y, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{previous}, to_x{to_x}, to_y{to_y}, turn{turn}, number_of_players{number_of_players}{
            this->linkPositions = linkPositions;

        }

char FirewallDecorator::displayAt(int row, int col){


    if(row == to_x and col == to_y and base->displayAt(row, col) == '.' ){//this points to the previous version on the board
        if(turn%number_of_players==0){
            return 'm';
        }
        else if(turn%number_of_players==1){
            return 'w';
        }
    }

    return base->displayAt(row,col);

}

std::unordered_map<char, std::pair<int, int>> FirewallDecorator::getLinkPositions(){
    return linkPositions;
}


