#include "abilitydecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

AbilityDecorator::AbilityDecorator(Board *previous, int x, int y, Ability ability, std::unordered_map<char, std::pair<int, int>> linkPositions)
        : Decorator{previous}, x{x}, y{y}, ability{ability}{
            linkPositions = previous.linkPositions;

        }

char AbilityDecorator::linkAt(int row, int col){
    return base->linkAt(row, col);//this points to the previous version on the board
}

Ability* AbilityDecorator::abilityAt(int row, int col){
    

    if(isSquareAbility(ability.getId()) and base->abilityAt(row, col)==0 and linkAt(row,col)=='.'){
        return &ability;
    }
    return base->abilityAt(row, col);// this should return the most recent ability on this square should be 
}

char AbilityDecorator::displayAt(int row, int col){
    //if the square is empty and there is an ability on it display the ability. 
    //otherwise display the link

    if(abilityAt(row,col) !=0){ //if the ability id is not zero it is guaranteed to be a square ability at this point
        return ability.display();
    }
    
    return linkAt(row,col);
}