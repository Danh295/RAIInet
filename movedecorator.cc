#include "movedecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

MoveDecorator::MoveDecorator(Board *base, char link_name, char direction, std::unordered_map<char, std::pair<int, int>> linkPositions)
    : Decorator{base}, link_name{link_name}, direction{direction}{

                this->linkPositions= linkPositions;
                // Check if the link exists in the map
                if (this->linkPositions.count(link_name) == 0) {
                    cerr << "Error: Link " << link_name << " not found on the board!" << endl;
                    return;
                }
                
                // Get current position
                int dx = this->linkPositions[link_name].first;
                int dy = this->linkPositions[link_name].second;

                from_x = dx;
                from_y = dy;

                if(from_x == -1 and from_y == -1){
                    cerr << "Error: Link " << link_name << " not found on the board!" << endl;
                    return;
                }
                cout << "position H "<<  this->linkPositions['H'].first <<" "<<this->linkPositions[link_name].second <<endl;
                // Calculate the new position based on the direction
                int move = 1;
                switch (direction) {
                    case 'u': dx -= move; break;
                    case 'd': dx += move; break;
                    case 'l': dy -= move; break;
                    case 'r': dy += move; break;
                    default: cerr << "Error: Invalid direction " << direction << endl; return;
                }

                // Update the position in the map
                this->linkPositions[link_name] = {dx, dy};
                
}

char MoveDecorator::displayAt(int row, int col) {

    if(row==-1 and col == -1){
        return '.';
    }
    // Handle the moved link
    if (row == from_x && col == from_y ) {
        return '.'; // Previous position of the link
    }
    else if (linkPositions.find(link_name) != linkPositions.end() &&
        row == linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name; // New position of the link
    }
    // Default to base board's display
    return base->displayAt(row, col);
}

std::unordered_map<char, std::pair<int, int>> MoveDecorator::getLinkPositions() {

    return linkPositions;
}

void MoveDecorator::removeLink(char link_name) {
    // Remove the link from both this decorator and the base board
    // linkPositions.erase(link_name);
    // base->removeLink(link_name);
}
