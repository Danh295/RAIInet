#ifndef LINK_H
#define LINK_H
#include <vector>

using namespace std;

class Link{
    int col, row, what, strength;  //strength: 0:data, 1:virus, 2:firewall(probably not gonna need this)
    int step = 1;
    char name;
    bool visible = false;
    bool invincible = false;
    int initC, initR;
    public:
        Link(int col, int row, int what, int strength, char name);
        int getCol();
        int getRow();
        char getName();
        int getStrength();
        char getType();
        int getInitC();
        int getInitR();
        bool move(int col, int row);
        bool battle(Link* target);
        void boost();
        void polarize();
        void reveal();
        void teleport(int col, int row);
        void makeInvincible();
        bool isInvincible();
        bool isVirus();
        bool isVisible();

};

#endif