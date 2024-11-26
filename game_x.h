#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "subject.h"

class Board;
class Player;

class Game: public Subject {
    Board *theboard;
    int turn;
    vector<*Player> players;

    public:
        enum {Blank=0, LinkBoost, Firewall, Download, Polarize, Scan, Z, KingCrimson, MadeInHaven}; // Available abilities.
        explicit Studio(Board *theboard ): theboard{theboard} {}
        //this is just to make it easier 
        enum class abilities {Blank=0, LinkBoost, Firewall, Download, Polarize, Scan, Z, KingCrimson, MadeInHaven}; // Available abilities.
        explicit Studio(Board *theboard,  vector<*Player> input): theboard{theboard} {
            i=0
            for(auto p: input){
                players[i] = std::move(p);
                i+=1;
            }
        }

        Board*& board() { return theboard; }
        void setupPlayer(int turn, vector<*Ability> abilities, vector<*Link> links);
        bool isValidSetup();//checks if everything is fine before beginnig turns in the game, if not throws something
        void ability_to_square(int turn,  int x, int y, int ability_id);
        void ability_to_link(int turn,char link_name, int ability_id);
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
