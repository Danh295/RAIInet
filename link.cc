#include "link.h"

Link::Link (int x, int y, int what, int strength,  char name):
col{col}, row{row}, what{what}, strength{strength}, name{name}{}

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

void Link::move(int moveCol, int moveRow) {
    
    col += moveCol * step;
    row += moveRow * step;
    

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

bool Link::isVirus(){
    return what == 1;
}
