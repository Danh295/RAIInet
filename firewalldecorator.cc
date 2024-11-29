#include "firewalldecorator.h"
#include "board.h"
#include "firewall.h"
#include <iostream>
using namespace std;

FirewallDecorator::FirewallDecorator(Board *previous, int turn, int number_of_players, int x, int y, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{previous}, x{x}, y{y}, turn{turn}, number_of_players{number_of_players}{
            linkPositions = previous.linkPositions;

        }

char FirewallDecorator::displayAt(int row, int col){


    if(base->cellAt(row, col) == '.'){//this points to the previous version on the board
        if(turn%number_of_players==0){
            return 'm';
        }
        else if(turn%number_of_players==1){
            return 'w';
        }
    }

    return base->cellAt(row,col);

}

std::unordered_map<char, std::pair<int, int>> FirewallDecorator::getLinkPositions(){
    return linkPositions;
}