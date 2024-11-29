#include "boardsetup.h"
#include "board.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

BoardSetup::BoardSetup(int number_of_players)
        {
            vector<string> cur_board = {
                    "abcSSfgh",
                    "...de...",
                    "........",
                    "........",
                    "........",
                    "........",
                    "...DE...",
                    "ABCSSFGH"
                };

            
            if(number_of_players == 4){
                cur_board = {
                     "abcSSfgh",
                    "Q...de...q",
                    "R........r",
                    "T........t",
                    "SU......uS",
                    "SV......vS",
                    "x........x",
                    "Y........y",
                    "Z...DE...z",
                     "ABCSSFGH"
                };
            }

            for(int i= 0; i<8; i++){
                for(int j = 0; j<8;j++){
                    if(cur_board[i][j]!='.' and cur_board[i][j]!='S'){
                        linkPositions[cur_board[i][j]] = {i,j};
                    }
                }
            }

}

char BoardSetup::displayAt(int row, int col) {
    return cur_board[row][col];
}


std::unordered_map<char, std::pair<int, int>> BoardSetup::getLinkPositions(){
    return linkPositions;
}

void BoardSetup::removeLink(char link_name){
    if (linkPositions.find(link_name) != linkPositions.end()) {
        // Delete the key
        linkPositions.erase(link_name);
    }
}
