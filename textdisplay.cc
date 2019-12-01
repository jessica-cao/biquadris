#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Player * const playerOne, Player * const playerTwo, string nextOne, string nextTwo):
    playerOne{playerOne}, playerTwo{playerTwo}, nextOne{nextOne}, nextTwo{nextTwo} {}


string PieceTop(string pieceIs) {
    if (pieceIs == "I") {
        return "IIII       ";
    } else if (pieceIs == "J") {
        return "J          ";
    } else if (pieceIs == "L") {
        return "  L        ";
    } else if (pieceIs == "T") {
        return "TTT        ";
    } else if (pieceIs == "Z") {
        return "ZZ         ";
    } else if (pieceIs == "S") {
        return " SS        ";
    } else if (pieceIs == "O") {
        return "OO         ";
    }
    return;
}

string PieceBot(string pieceIs) {
    if (pieceIs == "I") {
        return "           ";
    } else if (pieceIs == "J") {
        return "JJJ        ";
    } else if (pieceIs == "L") {
        return "LLL        ";
    } else if (pieceIs == "T") {
        return " T         ";
    } else if (pieceIs == "Z") {
        return " ZZ        ";
    } else if (pieceIs == "S") {
        return "SS         ";
    } else if (pieceIs == "O") {
        return "OO         ";
    }
    return;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    // TODO
    vector<vector<char>> & gOne = td.playerOne->theGrid->getGrid();
    vector<vector<char>> & gTwo = td.playerTwo->theGrid->getGrid();
    out << "Level:   " << td.playerOne->nLevel << "    Level:   " << td.playerTwo->nLevel << endl;
    out << "Score:   " << td.playerOne->getScore() << "    Score:    " << td.playerTwo->getScore() << endl;  // how to track score? in player
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
    out << PieceTop(td.nextOne) << "    " << PieceTop(td.nextTwo) << endl;
    out << PieceBot(td.nextOne) << "    " << PieceBot(td.nextTwo) << endl;
    return out;
}

