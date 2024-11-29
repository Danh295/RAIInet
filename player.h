#ifndef Player_H
#define Player_H
#include <vector>
#include <utility>
#include <memory>
#include <map>
#include <stdlib.h>
#include "board.h"
#include "link.h"
#include "ability.h"


using namespace std;


class Player : public Board {
    protected:
        Board* previous;
        int id;
        map<char, unique_ptr<Link>> links;
        vector<unique_ptr<Link>> fireWalls;
        vector<unique_ptr<Link>> server;
        int linkNum = 8;
        map<int, Player*> opponents;
        //map<int, Player *> opponents;     //in case there are more than 2 players
        int abilityCount; // # of unused abilities
        map <int, pair<unique_ptr<Ability>, int>> abilities;
        int downloadedV = 0;
        int downloadedF = 0;
        int freezed = 0;       
    public:
        Player(Board* pre, int id);
        
        //adders
        void addLink(int col, int row, int what, int strength, char name);
        void addFireWall(int col, int row, char name); 

        //getters
        char linkAt(int col, int row) override;
        Link* getLink(char name);
        Link* getAllLink(char name);
        int getId();
        int getAbilityCount();
        int getDownloadedF();
        int getDownloadedV();

        //interactions
        bool moveLink(char name, int moveC, int moveR);
        void download(char name);
        void deleteLink(char name);
        void addOpponent(int id, Player* opp);
        bool fireWalled(int col, int row);
        void freeze();
        bool isFreezed();
        
        //Abilities
        //void setDefaultAbilities();
        void addAbility(char newName, unique_ptr<Ability> newAbility);
        int checkAbilityType(int id);
        void useAbility(int id, int opp);               // for abilities targeting the opponent
        void useAbility(int id, int col, int row);          // for abilities targeting a square
        void useAbility(int id, char name);                 // for abilities targeting a link
        void useAbility(int id, char name1, char name2);    // for abilities targeting two links

        //
        void printLinks(int id);
        void printAbilities();
};

#endif