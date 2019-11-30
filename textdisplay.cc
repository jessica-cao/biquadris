#include "textdisplay.h"

TextDisplay::TextDisplay(Grid * const gridOne, Grid * const gridTwo, string nextOne, string nextTwo):
    gridOne{gridOne}, gridTwo{gridTwo}, nextOne{nextOne}, nextTwo{nextTwo} {}


std::ostream & printPieceTop(std::ostream &out, string pieceIs) {
    if (pieceIs == "I") {
        out << "IIII       ";
    } else if (pieceIs == "J") {
        out << "J          ";
    } else if (pieceIs == "L") {
        out << "  L        ";
    } else if (pieceIs == "T") {
        out << "TTT        ";
    } else if (pieceIs == "Z") {
        out << "ZZ         ";
    } else if (pieceIs == "S") {
        out << " SS        ";
    } else if (pieceIs == "O") {
        out << "OO         ";
    }
    return out;
}

std::ostream & printPieceBot(std::ostream &out, string pieceIs) {
    if (pieceIs == "I") {
        out << "           ";
    } else if (pieceIs == "J") {
        out << "JJJ        ";
    } else if (pieceIs == "L") {
        out << "LLL        ";
    } else if (pieceIs == "T") {
        out << " T         ";
    } else if (pieceIs == "Z") {
        out << " ZZ        ";
    } else if (pieceIs == "S") {
        out << "SS         ";
    } else if (pieceIs == "O") {
        out << "OO         ";
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    // TODO
    std::vector<std::vector<char>> & gOne = td.gridOne->getGrid();
    std::vector<std::vector<char>> & gTwo = td.gridTwo->getGrid();
    out << "Level:   " << td.gridOne->nLevel << "    Level:   " << td.gridTwo->nLevel << std::endl;
//    out << "Score:" << "Score:" << std::endl;  // how to track score?
    out << "-----------    -----------" << std::endl;
    out << "                          " << std::endl;
    out << "                          " << std::endl;
    out << "                          " << std::endl;
    for (int i = 0; i < td.row; ++i) {
        for (int j = 0; j < td.col; ++j) {
            out << gOne[i][j];
        }
        out << "    ";
        for (int k = 0; k < td.col; ++k) {
            out << gTwo[i][k];
        }
        out << std::endl;
    }
    out << "-----------    -----------" << std::endl;
    out << "Next:          Next:" << std::endl;
    printPieceTop(out, td.nextOne);
    out << "    ";
    printPieceTop(out, td.nextTwo);
    out << std::endl;
    printPieceBot(out, td.nextOne);
    out << "    ";
    printPieceBot(out, td.nextTwo);
    out << std::endl;
}

