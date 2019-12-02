# include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(Player *playerOne, Player *playerTwo) :
    playerOne{playerOne}, playerTwo{playerTwo}, xw {new Xwindow(500, 500)} {};

string squareSpacing(int score) {
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

void GraphicsDisplay::setColourBlock(int start, int end, int mult, int dim, int colour) {
    for (int u = start; u < end; ++u) {
        //this->xw->fillRectangle(u, mult * dim, dim, dim, colour);
        this->xw->fillRectangle(mult * dim, u, dim, dim, colour);
    }
}

void GraphicsDisplay::render() {
    int lineHeight = 500 / 26;
    std::vector<std::vector<char>> &gOne = this->playerOne->theGrid->getGrid();
    std::vector<std::vector<char>> &gTwo = this->playerTwo->theGrid->getGrid();
    this->xw->drawString(50, lineHeight, "Level:       " + to_string(this->playerOne->nLevel) + 
    "    Level:    " + to_string(this->playerTwo->nLevel), Xwindow::SeaGreen);
    this->xw->drawString(50, 2 * lineHeight, "Score:" + squareSpacing(this->playerOne->getScore()) + to_string(this->playerOne->getScore())
    + "    Score:" + squareSpacing(this->playerTwo->getScore()) + to_string(this->playerTwo->getScore()), Xwindow::SeaGreen);
    this->xw->drawString(50, 3 * lineHeight, "---------------    ---------------", Xwindow::Plum);

    int middle = 0;

    for (int i = 3; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            if ((this->playerOne->isBlind()) && (j >= 2 && j <= 8) && (i >= 2 && i <= 11)) {
                this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gray);
            } else {
                // print stuff as usual
                if (gOne[i][j] == 'I') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gold);
                } else if (gOne[i][j] == 'J') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Magenta);
                } else if (gOne[i][j] == 'L') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::DarkGreen);
                } else if (gOne[i][j] == 'T') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Cyan);
                } else if (gOne[i][j] == 'Z') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::RebeccaPurple);
                } else if (gOne[i][j] == 'S') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Firebrick);
                } else if (gOne[i][j] == 'O') {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Salmon);
                } else {
                    this->xw->fillRectangle(j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::White);
                }
            }
            middle = j;
        }
        
        for (int k = i + 1; k < i + 5; ++k) {
            this->xw->fillRectangle(middle, k, lineHeight, lineHeight, Xwindow::White);
        }
        for (int l = 0; l < this->col; ++l) {
            if (this->playerTwo->isBlind() && (l >= 2 && l <= 8) && (i >= 2 && i <= 11)) {
                this->xw->fillRectangle(l * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gray);
            } else {
                // prints out stuff as usual
                if (gTwo[i][l] == 'I') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gold);
                } else if (gTwo[i][l] == 'J') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Magenta);
                } else if (gTwo[i][l] == 'L') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::DarkGreen);
                } else if (gTwo[i][l] == 'T') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Cyan);
                } else if (gTwo[i][l] == 'Z') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::RebeccaPurple);
                } else if (gTwo[i][l] == 'S') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Firebrick);
                } else if (gTwo[i][l] == 'O') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Salmon);
                } else {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::White);
                }
            }
        }
    }

    this->xw->drawString(50, 22 * lineHeight, "-----------           -----------", Xwindow::Plum);
    this->xw->drawString(50, 23 * lineHeight,  "Next:                 Next:", Xwindow::SeaGreen);

    PieceType pieceIs1 = this->playerOne->getNext()->getInfo().piece_type;

    if (pieceIs1 == PieceType::IBlock) {
        this->setColourBlock(0, 4, 24, lineHeight, Xwindow::Gold);
        this->setColourBlock(4, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::JBlock) {
        this->setColourBlock(0, 1, 24, lineHeight, Xwindow::Magenta);
        this->setColourBlock(1, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::LBlock) {
        this->setColourBlock(0, 2, 24, lineHeight, Xwindow::White);
        this->setColourBlock(2, 3, 24, lineHeight, Xwindow::DarkGreen);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::TBlock) {
        this->setColourBlock(0, 3, 24, lineHeight, Xwindow::Cyan);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::ZBlock) {
        this->setColourBlock(0, 2, 24, lineHeight, Xwindow::RebeccaPurple);
        this->setColourBlock(2, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::SBlock) {
        this->setColourBlock(0, 1, 24, lineHeight, Xwindow::White);
        this->setColourBlock(1, 3, 24, lineHeight, Xwindow::Firebrick);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::OBlock) {
        this->setColourBlock(0, 2, 24, lineHeight, Xwindow::Salmon);
        this->setColourBlock(2, 11, 24, lineHeight, Xwindow::White);

    }

    // middle space
     this->setColourBlock(11, 14, 24, lineHeight, Xwindow::White);

    // Piece 2
    PieceType pieceIs2 = this->playerTwo->getNext()->getInfo().piece_type;

    if (pieceIs2 == PieceType::IBlock) {
        this->setColourBlock(14, 18, 24, lineHeight, Xwindow::Gold);
        this->setColourBlock(18, 25, 24, lineHeight, Xwindow::White);
    
    } else if (pieceIs1 == PieceType::JBlock) {
        this->setColourBlock(18, 19, 24, lineHeight, Xwindow::Magenta);
        this->setColourBlock(19, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::LBlock) {
        this->setColourBlock(14, 16, 24, lineHeight, Xwindow::White);
        this->setColourBlock(16, 17, 24, lineHeight, Xwindow::DarkGreen);
        this->setColourBlock(17, 25, 24, lineHeight, Xwindow::White);

    } else if (pieceIs2 == PieceType::TBlock) {
        this->setColourBlock(14, 17, 24, lineHeight, Xwindow::Cyan);
        this->setColourBlock(17, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::ZBlock) {
        this->setColourBlock(14, 16, 24, lineHeight, Xwindow::RebeccaPurple);
        this->setColourBlock(16, 25, 24, lineHeight, Xwindow::White);
        

    } else if (pieceIs2 == PieceType::SBlock) {
        this->setColourBlock(14, 15, 24, lineHeight, Xwindow::White);
        this->setColourBlock(15, 17, 24, lineHeight, Xwindow::Firebrick);
        this->setColourBlock(17, 25, 24, lineHeight, Xwindow::White);

    } else if (pieceIs2 == PieceType::OBlock) {
        this->setColourBlock(14, 16, 24, lineHeight, Xwindow::Salmon);
        this->setColourBlock(16, 25, 24, lineHeight, Xwindow::White);
        
    }

//    out << PieceBot(td.playerOne->getNext()) << "    " << PieceBot(td.playerTwo->getNext()) << endl;

// this is the second row
    if (pieceIs1 == PieceType::IBlock) {
        this->setColourBlock(0, 11, 25, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::JBlock) {
        this->setColourBlock(0, 3, 25, lineHeight, Xwindow::Magenta);
        this->setColourBlock(3, 11, 25, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::LBlock) {
        this->setColourBlock(0, 3, 25, lineHeight, Xwindow::DarkGreen);
        this->setColourBlock(3, 11, 25, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::TBlock) {
        this->setColourBlock(0, 1, 25, lineHeight, Xwindow::White);
        this->setColourBlock(1, 2, 25, lineHeight, Xwindow::Cyan);
        this->setColourBlock(2, 11, 25, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::ZBlock) {
        this->setColourBlock(0, 1, 25, lineHeight, Xwindow::White);
        this->setColourBlock(1, 3, 25, lineHeight, Xwindow::RebeccaPurple);
        this->setColourBlock(3, 11, 25, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::SBlock) {
        this->setColourBlock(0, 2, 25, lineHeight, Xwindow::Firebrick);
        this->setColourBlock(2, 11, 25, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::OBlock) {
        this->setColourBlock(0, 2, 25, lineHeight, Xwindow::Salmon);
        this->setColourBlock(2, 11, 25, lineHeight, Xwindow::White);

    }
    
    // set middle space
    this->setColourBlock(11, 14, 25, lineHeight, Xwindow::White);

    if (pieceIs2 == PieceType::IBlock) {
        this->setColourBlock(14, 25, 25, lineHeight, Xwindow::White);
    } else if (pieceIs2 == PieceType::JBlock) {
        this->setColourBlock(14, 17, 25, lineHeight, Xwindow::Magenta);
        this->setColourBlock(17, 25, 25, lineHeight, Xwindow::White);
        //out << "JJJ        ";
    } else if (pieceIs2 == PieceType::LBlock) {
        this->setColourBlock(14, 17, 25, lineHeight, Xwindow::DarkGreen);
        this->setColourBlock(17, 25, 25, lineHeight, Xwindow::White);
        //out << "LLL        ";
    } else if (pieceIs2 == PieceType::TBlock) {
        this->setColourBlock(14, 15, 25, lineHeight, Xwindow::White);
        this->setColourBlock(15, 16, 25, lineHeight, Xwindow::Cyan);
        this->setColourBlock(16, 25, 25, lineHeight, Xwindow::White);
        //out << " T         ";
    } else if (pieceIs2 == PieceType::ZBlock) {
        this->setColourBlock(14, 16, 25, lineHeight, Xwindow::White);
        this->setColourBlock(16, 18, 25, lineHeight, Xwindow::RebeccaPurple);
        this->setColourBlock(18, 25, 25, lineHeight, Xwindow::White);
        //out << " ZZ        ";
    } else if (pieceIs2 == PieceType::SBlock) {
        this->setColourBlock(14, 16, 25, lineHeight, Xwindow::Firebrick);
        this->setColourBlock(16, 25, 25, lineHeight, Xwindow::White);
        //out << "SS         ";
    } else if (pieceIs2 == PieceType::OBlock) {
        this->setColourBlock(14, 16, 25, lineHeight, Xwindow::Salmon);
        this->setColourBlock(16, 25, 25, lineHeight, Xwindow::White);
        //out << "OO         ";
    }

}
