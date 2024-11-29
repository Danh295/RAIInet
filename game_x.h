#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <unordered_map>
#include "player_x.h"
#include "subject_x.h"
using namespace std;

class Board;
class Player;

class Game: public Subject {
    Board *theboard;
    vector<Player*> players;
    int number_of_players;
    //in order to avoid confusion between links and abilities on the board
    //made a pair so we can add more abilities that affect square if needed
    // Pair<int, char> squareAbilitiesDisplay = {
    //     {0, 'm'},
    //     {1, 'w'},
    //     {2, '3'},
    //     {3, '€'}
    // }
    const vector<int> longTermLinkAbilitiesId = {'L','M'};//abilities that stick to the link t
    const vector<int> shortTermLinkAbilitiesId = {'K'};
    const vector<int> attackAbilitiesId = {'D','S','P'};
    const vector<int> squareAbilitiesId = {'F'};
    const vector<int> gameAbilitesId = {'V'};
    string downloadedLinks="";
    public:

        explicit Game(Board *theboard, int number_of_players): theboard{theboard}, number_of_players{number_of_players} {}
        // ~Game(){
        //     delete theboard;
        //     for(auto p: players){
        //         delete p;
        //     }
        // }

        Board*& board() { return theboard; }
        bool isValidSetup();//add to setupPlayer
        void opponentAbilityOnSquare(int turn, int row, int col);
        void removeLinkOnBoard(char link_name);
        void playerAbilityToOpponentLink(int turn,char link_name, char ability_id);
        void playerAbilityToPlayerLink(int turn, char link_name, char ability_id);
        
        int findWinner();
        void addPlayers(int id);
        Player* getPlayer(int id);
        char getPlayerAbilityById(int id, int idx);
        unordered_map<char, pair<int, int>> getLinkPositions();
        bool checkClashOnSquare(int turn, char linkName, char dir, int move);
        void printDownloaded(int id);
        void printPlayerAbilityCount(int id);
        void printLinks(int id);
        void render();
        void animate(int turn);
        char getState(int row, int col) const override;
        char getAbilityIdThatAffectMovement(int id, char linkName);
        void printOpponentLinks(int id);
        string getDownloadedLinks();

        void setDownloadedLinks();
  
};

#endif
