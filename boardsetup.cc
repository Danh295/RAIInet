#include "boardsetup.h"
#include "board.h"
#include <iostream>
using namespace std;

BoardSetup::BoardSetup(int number_of_players)
        :{
            if(number_of_players == 2){
                cur_board = {
                    "abcSSfgh",
                    "...de...",
                    "........",
                    "........",
                    "........",
                    "........",
                    "...DE...",
                    "ABCSSFGH"
                };

            }
            elif(number_of_players == 4){
                cur_board = {
                     "abcSSfgh",
                    "R...de...r",
                    "T........t",
                    "U........u",
                    "SV......vS",
                    "SQ......qS",
                    "X........x",
                    "Y........y",
                    "Z...DE...z",
                     "ABCSSFGH"
                };
            }

            for(int i= 0; i<size(cur_board); i++){
                for(int j = 0; j<size(cur_board[i]);j++){
                    if(cur_board[i][j]!="." and cur_board[i][j]!="S"){
                        linkPositions[cur_board[i][j]] = {i,j};
                    }
                }
            }

}

char BoardSetup::linkAt(int row, int col) {
    return cur_board[row][col];
}

char BoardSetup::displayAt(int row, int col) {
    return cur_board[row][col];
}

int BoardSetup::abilityAt(int row, int col) {
    return 0; //represent blank ability
}