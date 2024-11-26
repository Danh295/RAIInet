#include "movedecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

MovingBoard::MovingBoard(Board *base, Link link, char direction, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{base}, link_name{link_name}, direction{direction} {

            linkPositions = base.linkPositions;
            int dx= linkPositions[link.name].first;
            int dy =linkPositions[link.name].second;

            int move = 1

            if(link.ability.getId() == 1){
                //this is link boost
                move = link.ability.effect();
            }
            from_x, from_y = dx, dy;



            if(link.ability.getId() == 7){
                //king crimson
                pair<int, int> pair1 = link.ability.effect();
                dx = pair1.first;
                dy = pair1.second;
            }
            else if(direction != ''){
                switch (direction) {
                    case 'u': dx+=move; break;
                    case 'd': dx-=move; break;
                    case 'l': dy-=move; break;
                    case 'r': dy+=move; break;
                }
            }

            
            linkPositions[link.name]={dx, dy};

            if(abilityAt(dx,dy) !=0){
                //the ability will be processed in the game class
                ability_triggered = true;
                abilityAt(dx,dy);//update the ability on the square to nothing
            }

        }

char MovingBoard::linkAt(int row, int col){
    if (row ==  linkPositions[link.name].first && col == linkPositions[link.name].second) {
        return link.name;
    }
    if(row == from_y && col == from_x){
        return '.';
    }
    return base->charAt(row, col);//this points to the previous version on the board
}
int MovingBoard::abilityAt(int row, int col){
    if(ability_triggered){
        return 0;
    }
    return base->abilityAt(row, col);// this should return the most recent ability on this square 
}

char MovingBoard::displayAt(int row, int col){
    //if we made a move, we will always display the link
    return linkAt(row, col);
}