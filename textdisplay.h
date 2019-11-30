#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "grid.h"
#include "observer.h" // subject and observer are both in observer
#include "info.h"
#include <iostream>
#include <vector>

class Cell;

class TextDisplay : public Observer<Info, State> { // is there a template for observer?
    Grid * gridOne;
    Grid * gridTwo;
    string nextOne;
    string nextTwo;
    
    const int col = 11;
    const int row = 15;

    public:
    TextDisplay(Grid * const gridOne, Grid * const gridTwo, string nextOne, string nextTwo);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
