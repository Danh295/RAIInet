#include "movedecorator.h"
#include "board.h"
#include <iostream>
using namespace std;

MoveDecorator::MoveDecorator(Board *base, char link_name, char direction, std::unordered_map<char, std::pair<int, int>> linkPositions)
    : Decorator{base}, link_name{link_name}, direction{direction} {
    cout << "in moving";

    // Get the current link positions from the base board
    linkPositions = base->getLinkPositions();

    // Find the current position of the link
    auto it = linkPositions.find(link_name);
    if (it == linkPositions.end()) {
        cerr << "Error: Link " << link_name << " not found on the board!" << endl;
        return;
    }

    int dx = it->second.first;
    int dy = it->second.second;
    from_x = dx;
    from_y = dy;

    // Calculate new position based on direction
    int move = 1;
    switch (direction) {
        case 'u': dx -= move; break;
        case 'd': dx += move; break;
        case 'l': dy -= move; break;
        case 'r': dy += move; break;
        default: cerr << "Error: Invalid direction " << direction << endl; return;
    }

    // Update link positions
    linkPositions[link_name] = {dx, dy};
    base->removeLink(link_name); // Clear the previous position on the base board
}

char MoveDecorator::displayAt(int row, int col) {
    // Handle the moved link
    if (row == from_x && col == from_y) {
        return '.'; // Previous position of the link
    }
    if (linkPositions.find(link_name) != linkPositions.end() &&
        row == linkPositions[link_name].first && col == linkPositions[link_name].second) {
        return link_name; // New position of the link
    }

    // Default to base board's display
    return base->displayAt(row, col);
}

std::unordered_map<char, std::pair<int, int>> MoveDecorator::getLinkPositions() {
    // Combine updated positions with the base board's positions
    auto basePositions = base->getLinkPositions();
    basePositions.insert(linkPositions.begin(), linkPositions.end());
    return basePositions;
}

void MoveDecorator::removeLink(char link_name) {
    // Remove the link from both this decorator and the base board
    linkPositions.erase(link_name);
    base->removeLink(link_name);
}
