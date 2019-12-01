#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Player * playerOne, Player * playerTwo):
    playerOne{playerOne}, playerTwo{playerTwo} {}


string PieceTop(Piece * nextPiece) {
    PieceType pieceIs = nextPiece->getInfo().piece_type;
    if (pieceIs == PieceType::IBlock) {
        return "IIII       ";
    } else if (pieceIs == PieceType::JBlock) {
        return "J          ";
    } else if (pieceIs == PieceType::LBlock) {
        return "  L        ";
    } else if (pieceIs == PieceType::TBlock) {
        return "TTT        ";
    } else if (pieceIs == PieceType::ZBlock) {
        return "ZZ         ";
    } else if (pieceIs == PieceType::SBlock) {
        return " SS        ";
    } else if (pieceIs == PieceType::OBlock) {
        return "OO         ";
    }
    return "";
}

string PieceBot(Piece * nextPiece) {
    PieceType pieceIs = nextPiece->getInfo().piece_type;
    if (pieceIs == PieceType::IBlock) {
        return "           ";
    } else if (pieceIs == PieceType::JBlock) {
        return "JJJ        ";
    } else if (pieceIs == PieceType::LBlock) {
        return "LLL        ";
    } else if (pieceIs == PieceType::TBlock) {
        return " T         ";
    } else if (pieceIs == PieceType::ZBlock) {
        return " ZZ        ";
    } else if (pieceIs == PieceType::SBlock) {
        return "SS         ";
    } else if (pieceIs == PieceType::OBlock) {
        return "OO         ";
    }
    return "";
}

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
    out << "Level:   " << td.playerOne->nLevel << "    Level:   " << td.playerTwo->nLevel << endl;
    out << "Score:" << scoreSpacing(td.playerOne->getScore()) << td.playerOne->getScore() << "    Score:" << scoreSpacing(td.playerTwo->getScore()) << td.playerTwo->getScore() << endl;  // how to track score? in player
    out << "-----------    -----------" << endl;
    out << "                          " << endl;
    out << "                          " << endl;
    out << "                          " << endl;
    for (int i = 0; i < td.row; ++i) {
        for (int j = 0; j < td.col; ++j) {
            if (td.playerOne->isBlind() && j >= 2 && j <= 8
                    && i >= 2 && i <= 11) {
                out << "?";
            } else {
                out << gOne[i][j];
            }
        }
        out << "    ";
        for (int k = 0; k < td.col; ++k) {
            if (td.playerTwo->isBlind() && k >= 2 && k <= 8
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
    out << PieceTop(td.playerOne->getNext) << "    " << PieceTop(td.playerTwo->getNext) << endl;
    out << PieceBot(td.playerOne->getNext) << "    " << PieceBot(td.playerTwo->getNext) << endl;
    return out;
}

