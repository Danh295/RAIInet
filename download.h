#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include "ability_x.h"

class Download : public Ability {
    int id;

public:
    Download(int id);
    
    char effect() override;
};

#endif