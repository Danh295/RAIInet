#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include "observer_x.h"
#include "game_x.h"

using namespace std;

class Text : public Observer {
    Game *game;
    int id, otherId;
    public:
        Text(Game *game, int id);
        void notify() override;

};

#endif