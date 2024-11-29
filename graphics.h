#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "observer_x.h"
#include "game_x.h"
#include "window.h"

// Graphics -- ConcreteObserver
class Graphics: public Observer {
    Game *subject;
    
    // window dimensions
    const int width = 700;
    const int height = 700;

    // window dimensions details
    const int cellSize = 50;
    const int boarderSize = 5;
    const int boardSize = 8;

    const int boardWidth = cellSize * boardSize;
    const int boardHeight = cellSize * boardSize;

    // window object details
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
