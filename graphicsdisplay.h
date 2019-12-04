#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSIDSPLAY_H_
#include "player.h"
#include "info.h"
#include "window.h"
#include <vector>
#include <iostream>

class GraphicsDisplay {
    std::unique_ptr<Player> playerOne;
    std::unique_ptr<Player> playerTwo;
    std::vector<std::vector<char>>gridOne;
    std::vector<std::vector<char>> gridTwo;
    std::unique_ptr<Xwindow> xw;
    int player1lvl = playerOne->nLevel;
    int player2lvl = playerTwo->nLevel;
    int player1score = playerOne->getScore();
    int player2score = playerTwo->getScore();
    const int col = 11;
    const int row = 18;

    public:
    GraphicsDisplay(Player * playerOne, Player * playerTwo);
    void setColourBlock(int start, int end, int mult, int dim, int colour);
    void printSquare();
    void render();
    void renderVictoryP1();
    void renderVictoryP2();
    void renderTie();
    void clearText();
};

#endif
