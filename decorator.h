#ifndef DECORATOR_H
#define DECORATOR_H

#include "board.h"

class Decorator : public Board {  // Base class for all decorators; a Decorator is a Board
  protected:
    Board *base;  // The object(board) the decorator wraps
  public:
    Decorator(Board *b);
    //Since the movement and ability placement are sharing the base, we only delete when 
    //the game is completely done
}; 

#endif
