# include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(Player *playerOne, Player *playerTwo) :
    playerOne{playerOne}, playerTwo{playerTwo}, xw {new Xwindow(750, 1000)} {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                gridOne.emplace_back('-');
                gridTwo.emplace_back('-');
            }
        }
    };

string squareSpacing(int score) {
    if (score < 10) {
        return "     ";
    } else if (score < 100) {
        return "    ";
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
        this->xw->fillRectangle(u * dim + 70, mult * dim, dim, dim, colour);
    }
}

void GraphicsDisplay::render() {
    const int lineHeight = 750 / 26;

    std::vector<std::vector<char>> &gOne = this->playerOne->theGrid->getGrid();
    std::vector<std::vector<char>> &gTwo = this->playerTwo->theGrid->getGrid();
    
    if (this->player1lvl != playerOne->nLevel) {
        this->setColourBlock(0, 30, 0, lineHeight, Xwindow::White);
        this->player1lvl = playerOne->nLevel;
    }

    if (this->player2lvl != playerTwo->nLevel) {
        this->setColourBlock(0, 30, 0, lineHeight, Xwindow::White);
        this->player2lvl = playerTwo->nLevel;

    }

    this->xw->drawString(75, lineHeight, "Level:      " + to_string(this->playerOne->nLevel) + 
    "                                                         Level:     " + to_string(this->playerTwo->nLevel), Xwindow::DarkBlue);

    if (this->player1score != playerOne->getScore()) {
        this->setColourBlock(0, 30, 1, lineHeight, Xwindow::White);
        this->player1score = playerOne->getScore();
    }

    if (this->player2score != playerTwo->getScore()) {
        this->setColourBlock(0, 30, 1, lineHeight, Xwindow::White);
        this->player2score = playerTwo->getScore();

    }

    this->xw->drawString(75, 2 * lineHeight, "Score:" + squareSpacing(this->playerOne->getScore()) + to_string(this->playerOne->getScore())
    + "                                                          Score:" + squareSpacing(this->playerTwo->getScore()) + to_string(this->playerTwo->getScore()), Xwindow::DarkBlue);
    
    int middle = 0;

    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            if ((this->playerOne->isBlind()) && (j >= 2 && j <= 8) && (i >= 6 && i <= 15)) { // 2 and 11 before
                // Ghost mode
                this->xw->fillRectangle(1 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gray);
            } else {
                // print stuff as usual
                if (gridOne[i][j] != gOne[i][j]) {
                    if (gOne[i][j] == 'I') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gold);
                    } else if (gOne[i][j] == 'J') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Turqoise);
                    } else if (gOne[i][j] == 'L') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Lavender);
                    } else if (gOne[i][j] == 'T') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Black);
                    } else if (gOne[i][j] == 'Z') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Purple);
                    } else if (gOne[i][j] == 'S') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::LightCoral);
                    } else if (gOne[i][j] == 'O') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Lime);
                    } else if (gOne[i][j] == '*') {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Brown);
                    } else {
                        this->xw->fillRectangle(15 + j * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::DarkBlue);
                    }
                    gridOne[i][j] = gOne[i][j];
                }
            }
            middle = 1 + j;
        }
        
        for (int k = i + 1; k < i + 5; ++k) {
            this->xw->fillRectangle(middle, k, lineHeight, lineHeight, Xwindow::White);
        }

        for (int l = 0; l < this->col; ++l) {
            if (this->playerTwo->isBlind() && (l >= 2 && l <= 8) && (i >= 6 && i <= 15)) {
                this->xw->fillRectangle(l * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gray);
            } else {
                // prints out stuff as usual
                if (gridTwo[i][l] != gTwo[i][l]) {
                    if (gTwo[i][l] == 'I') {
                    this->xw->fillRectangle(( l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Gold);
                } else if (gTwo[i][l] == 'J') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Turqoise);
                } else if (gTwo[i][l] == 'L') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Lavender);
                } else if (gTwo[i][l] == 'T') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Black);
                } else if (gTwo[i][l] == 'Z') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Purple);
                } else if (gTwo[i][l] == 'S') {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::LightCoral);
                } else if (gTwo[i][l] == 'O') {
                    this->xw-> fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Lime);
                } else if (gTwo[i][l] == '*') {
                    this->xw-> fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::Brown);
                } else {
                    this->xw->fillRectangle((l + 14) * lineHeight, (i + 3) * lineHeight, lineHeight, lineHeight, Xwindow::DarkBlue);
                }
                gridTwo[i][l] = gTwo[i][l];
                }
            }
        }
    }

    this->xw->drawString(100, 22 * lineHeight,  "Next:                                                                  Next:", Xwindow::DarkBlue);

    
    PieceType pieceIs1 = this->playerOne->getNext()->getInfo().piece_type;

    if (pieceIs1 == PieceType::IBlock) {
        this->setColourBlock(0, 4, 23, lineHeight, Xwindow::Gold);
        this->setColourBlock(4, 11, 23, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::JBlock) {
        this->setColourBlock(0, 1, 23, lineHeight, Xwindow::Turqoise);
        this->setColourBlock(1, 11, 23, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::LBlock) {
        this->setColourBlock(0, 2, 23, lineHeight, Xwindow::White);
        this->setColourBlock(2, 3, 23, lineHeight, Xwindow::Lavender);
        this->setColourBlock(3, 11, 23, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::TBlock) {
        this->setColourBlock(0, 3, 23, lineHeight, Xwindow::Black);
        this->setColourBlock(3, 11, 23, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::ZBlock) {
        this->setColourBlock(0, 2, 23, lineHeight, Xwindow::Purple);
        this->setColourBlock(2, 11, 23, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::SBlock) {
        this->setColourBlock(0, 1, 23, lineHeight, Xwindow::White);
        this->setColourBlock(1, 3, 23, lineHeight, Xwindow::LightCoral);
        this->setColourBlock(3, 11, 23, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::OBlock) {
        this->setColourBlock(0, 2, 23, lineHeight, Xwindow::Lime);
        this->setColourBlock(2, 11, 23, lineHeight, Xwindow::White);

    }

    // middle space
     this->setColourBlock(11, 13, 23, lineHeight, Xwindow::White);

    // Piece 2, layer 1
    PieceType pieceIs2 = this->playerTwo->getNext()->getInfo().piece_type;

    if (pieceIs2 == PieceType::IBlock) {
        this->setColourBlock(14, 18, 23, lineHeight, Xwindow::Gold);
        this->setColourBlock(18, 25, 23, lineHeight, Xwindow::White);
    
    } else if (pieceIs2 == PieceType::JBlock) {
        this->setColourBlock(18, 19, 23, lineHeight, Xwindow::Turqoise);
        this->setColourBlock(19, 25, 23, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::LBlock) {
        this->setColourBlock(14, 16, 23, lineHeight, Xwindow::White);
        this->setColourBlock(16, 17, 23, lineHeight, Xwindow::Lavender);
        this->setColourBlock(17, 25, 23, lineHeight, Xwindow::White);

    } else if (pieceIs2 == PieceType::TBlock) {
        this->setColourBlock(14, 17, 23, lineHeight, Xwindow::Black);
        this->setColourBlock(17, 25, 23, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::ZBlock) {
        this->setColourBlock(14, 15, 23, lineHeight, Xwindow::White);
        this->setColourBlock(15, 17, 23, lineHeight, Xwindow::Purple);
        this->setColourBlock(17, 25, 23, lineHeight, Xwindow::White);
        

    } else if (pieceIs2 == PieceType::SBlock) {
        this->setColourBlock(14, 17, 23, lineHeight, Xwindow::White);
        this->setColourBlock(17, 19, 23, lineHeight, Xwindow::LightCoral);
        this->setColourBlock(20, 25, 23, lineHeight, Xwindow::White);

    } else if (pieceIs2 == PieceType::OBlock) {
        this->setColourBlock(14, 16, 23, lineHeight, Xwindow::Lime);
        this->setColourBlock(16, 25, 23, lineHeight, Xwindow::White);
        
    }

//    out << PieceBot(td.playerOne->getNext()) << "    " << PieceBot(td.playerTwo->getNext()) << endl;

// this is the second row
    if (pieceIs1 == PieceType::IBlock) {
        this->setColourBlock(0, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::JBlock) {
        this->setColourBlock(0, 3, 24, lineHeight, Xwindow::Turqoise);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::LBlock) {
        this->setColourBlock(0, 3, 24, lineHeight, Xwindow::Lavender);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);

    } else if (pieceIs1 == PieceType::TBlock) {
        this->setColourBlock(0, 1, 24, lineHeight, Xwindow::White);
        this->setColourBlock(1, 2, 24, lineHeight, Xwindow::Black);
        this->setColourBlock(2, 11, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::ZBlock) {
        this->setColourBlock(0, 1, 24, lineHeight, Xwindow::White);
        this->setColourBlock(1, 3, 24, lineHeight, Xwindow::Purple);
        this->setColourBlock(3, 11, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::SBlock) {
        this->setColourBlock(0, 2, 24, lineHeight, Xwindow::LightCoral);
        this->setColourBlock(2, 11, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs1 == PieceType::OBlock) {
        this->setColourBlock(0, 2, 24, lineHeight, Xwindow::Lime);
        this->setColourBlock(2, 11, 24, lineHeight, Xwindow::White);

    }
    
    // set middle space
    this->setColourBlock(11, 13, 24, lineHeight, Xwindow::White);

    if (pieceIs2 == PieceType::IBlock) {
        this->setColourBlock(14, 25, 24, lineHeight, Xwindow::White);
    } else if (pieceIs2 == PieceType::JBlock) {
        this->setColourBlock(14, 17, 24, lineHeight, Xwindow::Turqoise);
        this->setColourBlock(17, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::LBlock) {
        this->setColourBlock(14, 17, 24, lineHeight, Xwindow::Lavender);
        this->setColourBlock(17, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::TBlock) {
        this->setColourBlock(14, 15, 24, lineHeight, Xwindow::White);
        this->setColourBlock(15, 16, 24, lineHeight, Xwindow::Black);
        this->setColourBlock(16, 25, 24, lineHeight, Xwindow::White);
    
    } else if (pieceIs2 == PieceType::ZBlock) {
        this->setColourBlock(14, 16, 24, lineHeight, Xwindow::White);
        this->setColourBlock(16, 18, 24, lineHeight, Xwindow::Purple);
        this->setColourBlock(18, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::SBlock) {
        this->setColourBlock(16, 18, 24, lineHeight, Xwindow::LightCoral);
        this->setColourBlock(19, 25, 24, lineHeight, Xwindow::White);
        
    } else if (pieceIs2 == PieceType::OBlock) {
        this->setColourBlock(14, 16, 24, lineHeight, Xwindow::Lime);
        this->setColourBlock(16, 25, 24, lineHeight, Xwindow::White);
    }

    // checks for winning condition
    if (this->playerOne->theGrid->isDone() || this->playerTwo->theGrid->isDone()) {
        if (this->playerOne->getScore() > this->playerTwo->getScore()) {
            this->xw->drawString(300, 28 * lineHeight, "Player 1 wins!!!!", Xwindow::DarkBlue);
        } else if (this->playerOne->getScore() < this->playerTwo->getScore()) {
            this->xw->drawString(300, 28 * lineHeight, "Player 2 wins!!!!", Xwindow::DarkBlue);
        } else {
            this->xw->drawString(300, 28 * lineHeight, "A tie!!!!", Xwindow::DarkBlue);
        }
    }

}

