#include <iostream>
#include "link_x.h"
#include "board.h"
#include "game_x.h"
#include "player_x.h"

using namespace std;

//might take this one out
bool Game::isValidSetup(){
    for(auto p: players){
        if(!p->isReady()){
            return false;
        }
    }
    return true;
}

void Game::playerAbilityToPlayerLink(int turn, char link_name, char ability_id){
    Player *p = players[turn%number_of_players];
    Link *l = p->getLink(link_name);

    if(p->removeAbility(ability_id)){
        l->setAbility(ability_id);
    }
}

int Game::findWinner(){
    int d,v;

    for (auto it = players.begin(); it != players.end(); ++it){

        d = (*it)->getDownloadedData();
        v = (*it)->getDownloadedVirus();
        if (v==4) {
            // players.erase(it);
            number_of_players--;
        }
        if(d==4){
            return (*it)->getId();
        }
    }

    if (number_of_players==1){
        return players[0]->getId();
    }
    return 0;
}

void Game::playerAbilityToOpponentLink(int turn,char link_name, char ability_id){
    Player *p = players[turn%number_of_players];
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

    for(char a: l->getAbilities()){
        if(a == 'M' and ability_id !='D'){//made in haven
            apply_ability = false;
            break;
        }
    }

    if(apply_ability){
        if(ability_id=='D'){
            if(l->isVirus()){ //if the link is a virus
                p->incrementDownloadedVirus();
            }
            else{
                p->incrementDownloadedData();
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
    return theboard->displayAt(row,col);
}

unordered_map<char, pair<int, int>> Game::getLinkPositions(){
    return theboard->getLinkPositions();
}

bool Game::checkClashOnSquare(int turn, char linkName, char dir, int move){
    
    unordered_map<char, pair<int, int>> pos = theboard->getLinkPositions();
    int id = turn%number_of_players;
    Player *p = players[id];
    Link *nextLink = p->getLink(linkName);
    int row = pos[linkName].first;
    int col = pos[linkName].second;

    switch (dir) {
        case 'u': row= row-move; break;
        case 'd': row= row+move; break;
        case 'l': col= col-move; break;
        case 'r': col=col+move; break;
    }
    
    if(id == 0 && row < 0){//first player
        cout << "row " << row<<endl;
        if(nextLink->isVirus()){
            p->incrementDownloadedVirus();                
        }
        else{
            p->incrementDownloadedData();           
        }
        nextLink->gotDownloaded();
        return false;
    }
    else if(id == 1 && row >= 8){//should not be hardcoded here
        cout << "row " << row<<endl;
        if(nextLink->isVirus()){
            p->incrementDownloadedVirus();                
        }
        else{
            p->incrementDownloadedData();           
        }
        nextLink->gotDownloaded();
        return false;
    }
    else if(row<0 || row >=8 || col < 0 || col >=8){
        cout << "row " << row<<endl;
        return false;
    }


    char curLinkName = getState(row, col);
    cout << "next step " << curLinkName<<endl;

    if(curLinkName== '.'){
        return true;
    }
    else if(curLinkName == 'w' or curLinkName=='m'){
        for(char a: nextLink->getAbilities()){
            if(a == 'M'){//made in haven
                return true;
            }
        }
        if((turn%number_of_players==0 && curLinkName == 'w') || (turn%number_of_players==1 && curLinkName=='m')){
            nextLink->enlighten();
            if(nextLink->isVirus()){
                p->incrementDownloadedVirus();
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
                    o->incrementDownloadedVirus();
                }
                else{
                    o->incrementDownloadedData();
                }

                theboard->removeLink(linkName);
                nextLink->gotDownloaded();
                return false;
            }
            else{
                if(l->isVirus()){
                    p->incrementDownloadedVirus();
                }
                else{
                    p->incrementDownloadedData();
                }
                theboard->removeLink(l->getId());
                l->gotDownloaded();
                return true;
            }
        }
    }
    return true;
}

void Game::printDownloaded(int id){
    cout << players[id]->getDownloadedVirus()<<"D, " << players[id]->getDownloadedData() << "V";
}
void Game::printPlayerAbilityCount(int id){
    int result = 0;
    for(auto a: players[id]->getAbilities()){
        if(a != ' '){
            result++;
        }
    }

    cout << result;
}
void Game::printLinks(int id){
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
        cout << l->getId() << ": " << type << l->getStrength() << " ";
        if(i==4){
            cout << endl;
        }
    }
    cout <<endl;

}

void Game::printOpponentLinks(int id){
    vector <Link*> links = players[id]->getAllLinks();
    int i =1;
    char type = 'V';
    for(auto l: links){
        cout << l->getId() << ": "; 
        if(!l->isVisible()){
            cout << "? ";
        }
        else{
            if(l->isVirus()){
                type = 'V';
            }
            else{
                type = 'D';
            }

            cout << type << l->getStrength() << " ";
        }
        
        if(i==4){
            cout<<endl;
        }
    }
    cout <<endl;

}

char Game::getAbilityIdThatAffectMovement(int id, char linkName){
    Player* p = players[id];

    Link* l = p->getLink(linkName);

    for(auto a: l->getAbilities()){
        if(a == 'L'){
            return 'L';
        }
    }
    return '.';
}

char Game::getPlayerAbilityById(int id, int idx){
    Player* p = players[id];
    char ability_id = p->getAbilities()[idx-1];
    p->removeAbility(ability_id);
    return ability_id;
}

void Game::addPlayers(int id){
    players.push_back(new Player(id));
}

Player* Game::getPlayer(int id){ 
    return players[id];
}

