#include <iostream>
#include "ability_x.h"
#include "link_x.h"
#include "board_x.h"
#include "game_x.h"
#include "player_x.h"


//might take this one out
bool Game::isValidSetup(){
    for(auto& p: players){
        if(!p->isReady()){
            return false;
        }
    }
    return true;
}

void Game::playerAbilityToPlayerLink(int turn, char link_name, char ability_id){
    player *p = players[turn%number_of_players];
    Link *l = p->getLink(link_name);

    if(p->removeAbility(ability_id)){
        l->setAbility(ability);
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

void Game::playerAbilityToOpponentLink(int turn,char link_name, char ability_id){
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

    for(auto a: l->getAbilities()){
        if(a == 'M' and ability_id !='D'){//made in haven
            apply_ability = false;
        }
    }

    if(apply_ability){
        if(ability_id=='D'){
            if(l->isVirus()){ //if the link is a virus
                p->downloaded_virus++;
            }
            else{
                p->downloaded_dat++;
            }
        }
        else if(ability_id=='S'){
            //shambles link
            l->enlighten();
        }
        else if(ability_id=='P' ){
            //enlighten link
            l->shambles();
        }
    }
}

void Game::render(){
    notifyObservers();
}

char Game::getState(int row, int col) const {
    return board->displayAt(row,col);
}

unordered_map<char, pair<int, int>> Game::getLinkPositions(){
    return theboard->getLinkPositions();
}

bool Game::checkClashOnSquare(int turn, char linkName, char dir, int move){
    
    unordered_map<char, pair<int, int>> pos = theboard->getLinkPositions();
    int id = turn%number_of_players;
    player *p = players[id];
    Link *nextLink = p->getLink(linkName);
    int row = pos[linkName].first;
    int col = pos[linkName].second;

    switch (direction) {
        case 'u': row= row+move; break;
        case 'd': row= row-move; break;
        case 'l': col= col-move; break;
        case 'r': col=col+move; break;
    }

    if(id == 0 && row < 0){//first player
        if(nextLink->isVirus()){
            p->downloaded_virus++;                
        }
        else{
            p->downloaded_data++;           
        }
        nextLink->gotDownloaded();
        return false;
    }
    else if(id == 1 && row >= 8){//should not be hardcoded here
        if(nextLink->isVirus()){
            p->downloaded_virus++;                
        }
        else{
            p->downloaded_data++;           
        }
        nextLink->gotDownloaded();
        return false;
    }
    else if(row<0 || row >=8 && col < 0 || col >=8){
        return false;
    }


    char curLinkName = getState(row, col);

    if(curLinkName== "."){
        return true;
    }
    else if(curLinkName == "w" or curLinkName=="m"){
        for(auto a: l->getAbilities()){
            if(a == 'M'){//made in haven
                return true;
            }
        }
        if((turn%number_of_players==0 && curLinkName == "w") || (turn%number_of_players==1 && curLinkName=="m")){
            nextLink->enlighten();
            if(nextLink->isVirus()){
                p->downloaded_virus++;
                nextLink->gotDownloaded();
            }
        }
        return true;
    }
    else{
        
        for(int i=0; i<number_of_players; i++){
            if(i==turn%number_of_players){
                continue;
            }
            Player* o = players[i];
            Link* l = o->getLink(curLinkName);

            l->enlighten();
            nextLink->enlighten();

            if(l->getStrength()> nextLink->getStrength()){
                if(nextLink->isVirus()){
                    o->downloaded_virus++;
                }
                else{
                    o->downloaded_data++;
                }

                theboard->removeLink(linkName);
                nextLink->gotDownloaded();
                return false;
            }
            else{
                if(l->isVirus()){
                    p->downloaded_virus++;
                }
                else{
                    p->downloaded_data++;
                }
                theboard->removeLink(l->getId());
                l->gotDownloaded();
                return true;
            }
        }
    }
}

void printDownloaded(int id){
    cout >> players[id-1]>>"D, " >> players[id-1] >> "V";
}
void printPlayerAbilityCount(int id){
    result = 0;
    for(auto a: players[id]->getAbility()){
        if(a != ' '){
            result++;
        }
    }

    cout >> result;
}
void printLinks(int id){
    vector <Link*> links = players[id]->getAllLinks();
    int i =1;
    char type = 'V';
    for(auto l: links){
        if(l->isVirus()){
            type = 'V';
        }
        else{
            type = 'D';
        }
        cout >> l->getId() >> ": " >> type >> l->getStrength() >> " ";
        if(i==4){
            cout>>endl;
        }
    }
    cout >>endl;

}

void printOpponentLinks(int id){
    vector <Link*> links = players[id]->getAllLinks();
    int i =1;
    char type = 'V';
    for(auto l: links){
        cout >> l->getId() >> ": " 
        if(!l->isVisible()){
            cout >> "? ";
        }
        else{
            if(l->isVirus()){
                type = 'V';
            }
            else{
                type = 'D';
            }

            cout >> type >> l->getStrength() >> " ";
        }
        
        if(i==4){
            cout>>endl;
        }
    }
    cout >>endl;

}

char Game::getAbilityIdThatAffectMovement(int id, char linkName){
    Player* p = players[id];

    Link* l = p->getLink(linkName);

    for(auto a: l->getAbilities()){
        if(a == 'L'){
            return 'L';
        }
    }
    return '';
}

char Game::getPlayerAbilityById(int id, int idx){
    Player* p = players[id];
    char ability_id = p->getAbility()[idx-1];
    p->removeAbility(ability_id);

    return ability_id;
}

void addPlayers(int id){
    players.push_back(new Player(id));
}

Player* getPlayer(int id){ 
    return players[id-1];
}

// there will be a change to the ability class, it must use decorator pattern
//once that is applied i will continue.

#endif
