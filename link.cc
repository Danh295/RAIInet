#include "link.h"

Link::Link (int col, int row, int what, int strength, char name):
col{col}, row{row}, what{what}, strength{strength}, name{name}, initC{col}, initR{row}{}

int Link::getCol(){
    return col;
}

int Link::getRow(){
    return row;
}

char Link::getName(){
    return name;
}

int Link::getStrength(){
    return strength;
}

char Link::getType(){
    if (what == 0){
        return 'D';
    }else {
        return 'V';
    }
} 

int Link::getInitC(){
    return initC;
}

int Link::getInitR() {
    return initR;
}

bool Link::move(int moveCol, int moveRow) {
    col += moveCol * step;
    row += moveRow * step;
    if (col < 0 || col > 7) return true;
    return false;
}

bool Link::battle(Link* target) {
    
    if (strength > target->getStrength()) return true;
    return false;
}

void Link::boost(){
    step++;
}

void Link::polarize() {
    if (what == 0) what = 1;
    else if (what == 1) what = 0;
}

void Link::reveal() {
    visible = true;
}

void Link::teleport(int newCol, int newRow) {
    col = newCol;
    row = newRow;
}

void Link::makeInvincible() {
    invincible = true;
}

bool Link::isInvincible(){
    return invincible;
}

bool Link::isVirus(){
    return what == 1;
}

bool Link::isVisible(){
    return visible;
}

