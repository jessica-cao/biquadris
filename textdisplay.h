#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "player.h"
#include "observer.h" // subject and observer are both in observer
#include "info.h"
#include <iostream>
#include <vector>

using namespace std;

class Cell;

class TextDisplay {
    Player * playerOne;
    Player * playerTwo;
    
    const int col = 11;
    const int row = 15;

    public:
    TextDisplay(Player * playerOne, Player * playerTwo);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
