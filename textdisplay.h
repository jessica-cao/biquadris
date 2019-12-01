#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "player.h"
#include "observer.h" // subject and observer are both in observer
#include "info.h"
#include <iostream>
#include <vector>

using namespace std;

class Cell;

class TextDisplay : public Observer<Info, State> { // is there a template for observer?
    Player * playerOne;
    Player * playerTwo;
    string nextOne;
    string nextTwo;
    
    const int col = 11;
    const int row = 15;

    public:
    TextDisplay(Player * const playerOne, Player * const playerTwo, string nextOne, string nextTwo);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
