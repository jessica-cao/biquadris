#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSIDSPLAY_H_
#include "player.h"
#include "info.h"
#include "window.h"
#include <vector>
#include <iostream>

class GraphicsDisplay {
    Player *playerOne;
    Player *playerTwo;
    Xwindow *xw;

    const int col = 11;
    const int row = 15;

    public:
    GraphicsDisplay(Player * playerOne, Player * playerTwo);
    void setColourBlock(int start, int end, int mult, int dim, int colour);
    void printSquare();
    void render();
};

#endif
