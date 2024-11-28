#include <iostream>
#include "ability_x.h"
#include "link_x.h"
#include "board_x.h"
#include "game_x.h"
#include "player_x.h"


void Game::setupPlayer(int turn, vector<*Ability> abilities, vector<*Link> links){
    Player* p = players[turn%number_of_players];
    
    for (auto l: links){
        p->setLink(l);
    }

    i=0
    for (auto a: abilities){
        p->setAbilities(i,a);
        i++;
    }

}

//might take this one out
bool Game::isValidSetup(){
    for(auto& p: players){
        if(!p->isReady()){
            return false;
        }
    }
    return true;
}

void Game::playerAbilityToPlayerLink(int turn, char link_name, Ability ability){
    player *p = players[turn%number_of_players];
    Link *l = p->getLink(link_name);
    int ability_id = ability->getId();
    for(int id: longTermLinkAbilitiesId){
        if(ability_id==id){
            if(p->removeAbility(ability_id)){
                l->setAbility(&ability);
            }
        }
    }
    

}

int Game::findWinner(){
    int d,v;
    int losers = 0;

    for (auto it = players.begin(); it != players.end(); ++it){

        d = *it->downloaded_data;
        v = *it->downloaded_virus;
        if (v==4) {
            players.erase(it);
            number_of_players--;
        }
        if(d==4){
            return *it->getId();
        }

    }

    if (number_of_playersx==1){
        return players[0]->getId();
    }
    return 0;
}

void Game::removeLinkOnBoard(char link_name){
    theboard->removeLink(link_name);
}

void Game::playerAbilityToOpponentLink(int turn,char link_name, Ability ability){
    player *p = players[turn%number_of_players];
    Link *l = nullptr;


    for(int i=0; i<number_of_players; i++){
        if(i==turn%number_of_players){
            continue;
        }
        Player* o = players[i];
        l = o->getLink(link_name);
        if(l){
            break;
        }
    }
    if(!l){
        return;
    }

    bool apply_ability = true;

    for(auto& a: l->getAbilities){
        if(a->getId() == 8){//made in haven
            apply_ability = a.effect(ability.getId());
        }
    }

    if(apply_ability){
        if(ability.getId()==3){
            if(!ability.effect(l)){ //if the link is a virus
                o->downloaded_data++;
            }
            else{
                o->downloaded_virus++;
            }
        }
        else if(ability.getId()==4){
            //shambles link
            ability.effect(l);
        }
        else if(ability.getId()==5 ){
            //enlighten link
            ability.effect(l);
        }
        else if(ability.getId()==6){
            //skip the next player's turn???
            //bro this literally affect the GAAAAAAAME T_T
            //this ability is unfair on a 1v1 game
            //turn++;
        }
    }
}

void Game::render(){
    notifyObservers();
    turn++;
}

void Game::animate(int numTurns){
    for ( int i = 0; i < numTurns; ++i ) render();
}

char Game::getState(int row, int col) const {
    return board->displayAt(row,col);
}

void Game::opponentAbilityOnSquare(int turn, int row, int col){

    //we want to know if there was an ability on this square
    //before the link stepped on it.
    
    Ability* a = board->base->AbilityAt(row,col);
    if(a==nullptr){
        return;
    }
    char name = board->linkAt(row,col);
    Player* p = players[turn%number_of_players];

    Link* l = p->getLink(link_name);
    if(l){
        for(int id: squareAbilitiesId){
            if(id == a->getId()){
                if(a.getId()==2 && a.effect(l)){
                    //if the link is a virus
                    p->downloaded_virus+=1;
                }
            }
        }
        
    }
}

// there will be a change to the ability class, it must use decorator pattern
//once that is applied i will continue.

#endif
