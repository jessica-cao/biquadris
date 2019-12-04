#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Player * playerOne, Player * playerTwo):
    playerOne{playerOne}, playerTwo{playerTwo} {}


string scoreSpacing(int score) {
    if (score < 10) {
        return "    ";
    } else if (score < 100) {
        return "   ";
    } else if (score < 1000) {
        return "  ";
    } else if (score < 10000) {
        return " ";
    } else {
        return "";
    }
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    // TODO
    vector<vector<char>> & gOne = td.playerOne->theGrid->getGrid();
    vector<vector<char>> & gTwo = td.playerTwo->theGrid->getGrid();
    out << "Level:    " << td.playerOne->nLevel << "    Level:    " << td.playerTwo->nLevel << endl;
    out << "Score:" << scoreSpacing(td.playerOne->getScore()) << td.playerOne->getScore() << "    Score:" << scoreSpacing(td.playerTwo->getScore()) << td.playerTwo->getScore() << endl;  // how to track score? in player
    out << "-----------    -----------" << endl;
    for (int i = 0; i < td.row + 3; ++i) {
        for (int j = 0; j < td.col; ++j) {
            if (td.playerOne->isBlind() && j >= 2 && j <= 8
                    && i >= 6 && i <= 15) {  // 2 and 11 before
                out << "?";
            } else {
                out << gOne[i][j];
            }
        }
        out << "    ";
        for (int k = 0; k < td.col; ++k) {
            if (td.playerTwo->isBlind() && k >= 2 && k <= 8
                    && i >= 6 && i <= 15) {  // 1 and 10 before
                out << "?";
            } else {
                out << gTwo[i][k];
            }
        }
        out << endl;
    }

    out << "-----------    -----------" << endl;
    out << "Next:          Next:" << endl;


    PieceType pieceIs1 = td.playerOne->getNext()->getInfo().piece_type;
    if (pieceIs1 == PieceType::IBlock) {
        out << "IIII       ";
    } else if (pieceIs1 == PieceType::JBlock) {
        out << "J          ";
    } else if (pieceIs1 == PieceType::LBlock) {
        out << "  L        ";
    } else if (pieceIs1 == PieceType::TBlock) {
        out << "TTT        ";
    } else if (pieceIs1 == PieceType::ZBlock) {
        out << "ZZ         ";
    } else if (pieceIs1 == PieceType::SBlock) {
        out << " SS        ";
    } else if (pieceIs1 == PieceType::OBlock) {
        out << "OO         ";
    }
    out << "    ";
    PieceType pieceIs2 = td.playerTwo->getNext()->getInfo().piece_type;
    if (pieceIs2 == PieceType::IBlock) {
        out << "IIII       ";
    } else if (pieceIs2 == PieceType::JBlock) {
        out << "J          ";
    } else if (pieceIs2 == PieceType::LBlock) {
        out << "  L        ";
    } else if (pieceIs2 == PieceType::TBlock) {
        out << "TTT        ";
    } else if (pieceIs2 == PieceType::ZBlock) {
        out << "ZZ         ";
    } else if (pieceIs2 == PieceType::SBlock) {
        out << " SS        ";
    } else if (pieceIs2 == PieceType::OBlock) {
        out << "OO         ";
    }
    out << endl;


    if (pieceIs1 == PieceType::IBlock) {
        out << "           ";
    } else if (pieceIs1 == PieceType::JBlock) {
        out << "JJJ        ";
    } else if (pieceIs1 == PieceType::LBlock) {
        out << "LLL        ";
    } else if (pieceIs1 == PieceType::TBlock) {
        out << " T         ";
    } else if (pieceIs1 == PieceType::ZBlock) {
        out << " ZZ        ";
    } else if (pieceIs1 == PieceType::SBlock) {
        out << "SS         ";
    } else if (pieceIs1 == PieceType::OBlock) {
        out << "OO         ";
    }
    out << "    ";
    if (pieceIs2 == PieceType::IBlock) {
        out << "           ";
    } else if (pieceIs2 == PieceType::JBlock) {
        out << "JJJ        ";
    } else if (pieceIs2 == PieceType::LBlock) {
        out << "LLL        ";
    } else if (pieceIs2 == PieceType::TBlock) {
        out << " T         ";
    } else if (pieceIs2 == PieceType::ZBlock) {
        out << " ZZ        ";
    } else if (pieceIs2 == PieceType::SBlock) {
        out << "SS         ";
    } else if (pieceIs2 == PieceType::OBlock) {
        out << "OO         ";
    }
    out << endl;
    return out;
}

