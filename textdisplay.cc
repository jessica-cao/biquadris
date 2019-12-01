#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Player * const playerOne, Player * const playerTwo, string nextOne, string nextTwo):
    playerOne{playerOne}, playerTwo{playerTwo}, nextOne{nextOne}, nextTwo{nextTwo} {}


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
    vector<vector<char>> & gOne = td.playerOne->theGrid->getGrid();
    vector<vector<char>> & gTwo = td.playerTwo->theGrid->getGrid();
    out << "Level:   " << td.playerOne->nLevel << "    Level:   " << td.playerTwo->nLevel << endl;
    out << "Score:   " << td.playerOne->score << "    Score:    " << td.playerTwo->score << endl;  // how to track score? in player
    out << "-----------    -----------" << endl;
    out << "                          " << endl;
    out << "                          " << endl;
    out << "                          " << endl;
    for (int i = 0; i < td.row; ++i) {
        for (int j = 0; j < td.col; ++j) {
            if (td.playerOne->blind && j >= 2 && j <= 8
                    && i >= 2 && i <= 11) {
                out << "?";
            } else {
                out << gOne[i][j];
            }
        }
        out << "    ";
        for (int k = 0; k < td.col; ++k) {
            if (td.playerTwo->blind && k >= 2 && k <= 8
                    && i >= 2 && i <= 11) {
                out << "?";
            } else {
                out << gTwo[i][k];
            }
        }
        out << endl;
    }
    out << "-----------    -----------" << endl;
    out << "Next:          Next:" << endl;
    printPieceTop(out, td.nextOne);
    out << "    ";
    printPieceTop(out, td.nextTwo);
    out << endl;
    printPieceBot(out, td.nextOne);
    out << "    ";
    printPieceBot(out, td.nextTwo);
    out << endl;
}

