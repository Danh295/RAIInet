#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "subject.h"

class Board;
class Player;

class Game: public Subject {
    Board *theboard;
    int turn;
    int number_of_players;
    vector<*Player> players = {nullptr};
    //in order to avoid confusion between links and abilities on the board
    //made a pair so we can add more abilities that affect square if needed
    Pair<int, char> allAbilities = {
        {0, 'm'},
        {1, 'w'},
        {2, '3'},
        {3, '€'}
    }
    const vector<int> longTermLinkAbilitiesId = {1,8};//abilities that stick to the link t
    const vector<int> shortTermLinkAbilitiesId = {7};
    const vector<int> attackAbilitiesId = {3,4,5};
    const vector<int> squareAbilitiesId = {2};
    const vecort<int> gameAbilitesId = {6};
    public:

        explicit Game(Board *theboard,  vector<*Player> input): theboard{theboard}, number_of_players{size(input)} {
            for(auto p: input){
                players.emplace_back(std::move(p));
            }
        }
        ~Game(){
            delete theboard;
            for(auto p: players){
                delete p;
            }
        }

        Board*& board() { return theboard; }
        void setupPlayer(int turn, vector<*Ability> abilities, vector<*Link> links);
        bool isValidSetup();//add to setupPlayer
        void opponentAbilityOnSquare(int turn, int row, int col);
        void removeLinkOnBoard(char link_name);
        void playerAbilityToOpponentLink(int turn,char link_name, Ability ability);
        void playerAbilityToPlayerLink(int turn, char link_name, Ability ability);
        int findWinner();
        void render();
        void animate(int turns);
        void animate(int turn);
        char getState(int row, int col) const override;
  
};

                //if the square has an ability
                // if(link.ability.getId()!= 8){
                //     p.apply_opponent_ability(abilityAt(dx,dy));
                // }
                // //if the link is(has) madeInHaven(ability_id = 8) he is untoucheable aginst abilities
#endif
