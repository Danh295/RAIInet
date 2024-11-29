#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "observer_x.h"
#include "game_x.h"
#include "window.h"

// Graphics -- ConcreteObserver
class Graphics: public Observer {
    Game *subject;
    
    // window dimensions
    const int width = 77;
    const int height = 77;

    // window object & details
    Xwindow displayWin;
    const int pixels = 10;

  public:
    Graphics(Game *subject); 
    ~Graphics();
    void notify() override;

  private:

    int getColour(char c);

};

#endif
