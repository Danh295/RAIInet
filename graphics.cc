#include "graphics.h"

// Public Graphics ConcreteObserver Methods ------------------------------------

// Graphics ctor (attaches observer)
Graphics::Graphics(Game *subject):
    subject{subject}, 
    displayWin{width, height} {
        subject->attach(this); // attach observer to studio subject
}

// Graphics dtor (detaches observer)
Graphics::~Graphics() { subject->detach(this); }

// Notify display observers
void Graphics::notify() {

    // display board as a grid of squares/rectangles
    const int cellSize = 10;
    for (int i = 0; i <= 8; ++i) {
        for (int j = 0; j <= 8; ++j) {
            char c = subject->getState(i, j);
            displayWin.fillRectangle(j * cellSize, i * cellSize, pixels, pixels, getColour(c));
        }
    }
}

// Convert char to corresponding color value
int Graphics::getColour(char c) {
    if (c >= 'a' && c <= 'h') return Xwindow::Red;  // Player 1 links
    if (c >= 'A' && c <= 'Z') return Xwindow::Blue; // Player 2 links
    if (c == 'S') return Xwindow::Green;            // Server ports
    if (c == '.') return Xwindow::White;            // Empty space
    if (c == 'w' || c == 'm') return Xwindow::Grey; // Firewall
    return 1;
}

