#include "text.h"
#include  <iostream>

using namespace std;

Text::Text(Game *game, int id):
game{game}, id{id}{
    game->attach(this);
    if (id == 0) otherId = 1;
    else otherId = 0;
}

void Text::notify () {
    if(id==0){
        cout<<"=========="<<endl;
        cout<<"Player 1 Turn" <<endl;
        cout<<"=========="<<endl;
    }else{
        cout<<"=========="<<endl;
        cout<<"Player 2 POV" <<endl;
        cout<<"=========="<<endl;
    }
    cout << "Player " << id+1 << ':' << endl;
    cout << "Downloaded: ";
    game->printDownloaded(id);
    cout << endl << "Abilities: ";
    game->printPlayerAbilityCount(id);
    cout << endl;
    game->printLinks(id);
    for (int j = 0; j < 8; ++j) {
        cout << '=';
    }
    cout << endl;
    if(id==0){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(game->getState(i, j)=='w'){
                    cout<< '.';
                }
                else{
                    cout << game->getState(i, j);
                }
            }
        cout << endl;
        }
    }
    else{
        for (int i =7 ; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                if(game->getState(i, j)=='m'){
                    cout<< '.';
                }
                else{
                    cout << game->getState(i, j);
                }
                
            }
        cout << endl;
        }
    }
    
    for (int j = 0; j < 8; ++j) {
        cout << '=';
    }
    cout << endl;
    cout << "Player " << otherId+1 << ':' << endl;
    cout << "Downloaded: ";
    game->printDownloaded(otherId);
    cout << endl << "Abilities: ";
    game->printPlayerAbilityCount(otherId);
    cout << endl;
    game->printOpponentLinks(otherId);
    cout <<endl;
    cout<<endl;
}
