#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include "ability_x.h"

class Download : public Ability {
    const int id= 3;

public:
    Download();
    int getId(){return id;}
    void effect() override;
};

#endif