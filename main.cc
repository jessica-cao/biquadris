// Main

#include <iostream>
#include <string>
#include <memory>
#include "player.h"
#include "levels.h"
#include "levelZero.h"

#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"

#include "trie.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

using namespace std;

// CALL GRID INIT IN PLAYER

// The highest level you can reach
const int MAXLEVEL = 4;

// The lowest level you can reach
const int MINLEVEL = 0;

// first letter in the string and not a number
int firstLetter(string s) {
    int count = 0;
    while (count <= s.length()) {
        if (('A' <= s[count] && s[count] <= 'Z') || ('a' <= s[count] && s[count] <= 'z')) {
            break;
        } else {
            ++count;
        }
    }
    
    return count;
}


int main(int argc, char *argv[]) {
    // sorry the following is probably filled with bugs and syntax errors
    // meant for taking in arguments

    // first I'm considering the arguments
    // then the actual input that is being read in from the user
    // THIS IS ALL SUBJECT TO CHANGE BC IDK WHAT IM DOING; FEEL FREE TO CORRECT JUST LMK!!

    string arg;
    // ctors need to set default level to 0
    // will need a field that points to Level obj, which then specifies the lvl (eg. LevelZero)
    // call Piece * pLevel (playerLevel) and string nLevel (numLevel)
    unique_ptr<Player> player1 {new Player()};
    unique_ptr<Player> player2 {new Player()};
    
    string nLevel = "0"; // intialized level: THIS MAY BE A PROBLEM LATER DEPENDING ON HOW WE SET LEVELUP AND DOWN
    string fn1 = "sequence1.txt";
    string fn2 = "sequence2.txt";

    bool showGD = true;

    // defaults for things (without args) is:
        // show texts AND graphics
        // same sequence (no rng)
        // use sequence1.txt
        // use sequence2.txt
        // start at levelZero
    for (int i = 1; i < argc; ++i) {
        arg = argv[i];
        if (arg == "-text") {
            // disable graphics
            showGD = false;
        } else if (arg[0] == '-' && i+1 == argc) {
            // ERROR
            // the following else ifs need two args. If the current one starts as -notText and there
            // isn't a string following, it is an invalid command!
            throw std::logic_error {"Invalid argument."};
        } else if (arg == "-seed") {
            string seed = argv[i+1];
            srand(stoi(seed));
            // rng but tbh not sure for what?? for pieces?? bc i already dealt w that in the levels
        } else if (arg == "-scriptfile1") {
            // file to replace sequence1.txt
            fn1 = argv[i+1];
        } else if (arg == "-scriptfile2") {
            // file to replace sequence2.txt
            fn2 = argv[i+1];
        } else if (arg == "-startlevel") {
            nLevel = argv[i+1];
            // WHAT WILL BE KEEPING TRACK OF THE LEVELS?
            if (nLevel == "0"){
                continue;
            } else if (nLevel == "1") {
                player1->pLevel.reset();
                player2->pLevel.reset();
                player1->pLevel = make_unique<LevelOne>();
                player2->pLevel = make_unique<LevelOne>();
                player1->nLevel = 1;
                player2->nLevel = 1;
            } else if (nLevel == "2") {
                player1->pLevel.reset();
                player2->pLevel.reset();
                player1->pLevel = make_unique<LevelTwo>();
                player2->pLevel = make_unique<LevelTwo>();
                player1->nLevel = 2;
                player2->nLevel = 2;
            } else if (nLevel == "3") {
                player1->pLevel.reset();
                player2->pLevel.reset();
                player1->pLevel = make_unique<LevelThree>();
                player2->pLevel = make_unique<LevelThree>();
                player1->nLevel = 3;
                player2->nLevel = 3;
                player1->setHeavy(1);
                player2->setHeavy(1);
            } else if (nLevel == "4") {
                player1->pLevel.reset();
                player2->pLevel.reset();
                player1->pLevel = make_unique<LevelFour>();
                player2->pLevel = make_unique<LevelFour>();
                player1->nLevel = 4;
                player2->nLevel = 4;
                player1->setHeavy(1);
                player2->setHeavy(1);
                //*/
            } else {
                // ERROR
            }
        }
    }

    std::cin.exceptions(ios::eofbit|ios::failbit); // why is cin ambiguous here. Jackass.
    // add any additional intializations here
    string cmd; // reads in a command
    int countTurns = 0;
    unique_ptr<Trie> head {new Trie()};
	head->insertCommands();
    int multiplier = 1; // some commands have a multiplier prefix; to show how many times a command is executed

    player1->pLevel->setFile(fn1);  // to clean later: just set immediately in for loop for args
    player2->pLevel->setFile(fn2);
    player1->setNextPiece();
    player1->setCurrPiece();
    player2->setNextPiece();
    player2->setCurrPiece();
    player1->setNextPiece();
    player2->setNextPiece();
    unique_ptr<TextDisplay> td {new TextDisplay(player1.get(), player2.get())}; // should work now with new and improved TextDisplay

    unique_ptr<GraphicsDisplay> gd = nullptr;
    cout << *td;
    if (showGD) {
        gd = std::make_unique<GraphicsDisplay>(player1.get(), player2.get());
        gd->render();
    }
    
    try {
        
        // Command interpreter
        while (true) { // game not over; break when done
        // create a piece for command interpreter:
        
            std::cin >> cmd;
            multiplier = head->parsePrefix(cmd); // check if the command we have has a prefix

            // if the cmd doesn't have a prefix, or if someone wants to mess w it
            // the multiplier is set to 1, so the command executes once
            if (multiplier == 0) {
                multiplier = 1;
            }

            int firstL = firstLetter(cmd);
            cmd = cmd.substr(firstL, cmd.length() - firstL + 1);

            try {

                string currComm = head->search(cmd);
                //cout << currComm;


                if (currComm == "left" || currComm == "right" || currComm == "down") {
//                        cout << "hola i'm the right command\n" << endl;
                    for (int i = 0; i < multiplier; ++i) {
//                            cout << "it moves" << endl;
                        if (countTurns % 2 == 0) {
//                                cout << "inside the loop of the right command, player1\n";
                            player1->move(currComm);
                        } else {
//                                cout << "inside the loop of the command, player 2\n";
                            player2->move(currComm);
                        }
                    }
                } else if (currComm == "drop") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
//                                cout << "inside the loop of the drop command, player1\n";
                            player1->drop();
                        } else {
//                                cout << "inside the loop of the drop command, player2\n";
                            player2->drop();
                        }
                    }
                }else if (currComm == "clockwise" || currComm == "counterclockwise") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            player1->rotate(currComm);
                        } else {
                            player2->rotate(currComm);
                        }
                    }
                } else if (currComm == "levelup") {
                        ///*
                    int desiredLvl;
                    if (countTurns % 2 == 0) {
                        desiredLvl = multiplier + player1->nLevel;
                        if (desiredLvl <= MAXLEVEL) {
                            player1->pLevel.reset();
                            
                            if (desiredLvl == 1) {
                                player1->pLevel = make_unique<LevelOne>();
                                player1->setHeavy(0);
                            } else if (desiredLvl == 2) {
                                player1->pLevel = make_unique<LevelTwo>();
                                player1->setHeavy(0);
                            } else if (desiredLvl == 3) {
                                player1->pLevel = make_unique<LevelThree>();
                                player1->setHeavy(1);
                            } else if (desiredLvl == 4) {
                                player1->pLevel = make_unique<LevelFour>();
                                player1->setHeavy(1);
                            }
                            player1->nLevel = desiredLvl;
                        } else {
                            if (player1->nLevel != MAXLEVEL) {
                                player1->pLevel.reset();
                                player1->pLevel = make_unique<LevelFour>();
                                player1->setHeavy(1);
                            }
                            
                            player1->nLevel = MAXLEVEL;
                        }
                        
                    } else {
                        desiredLvl = multiplier + player2->nLevel;
                        if (desiredLvl <= MAXLEVEL) {
                            player2->pLevel.reset();

                            if (desiredLvl == 1) {
                                player2->pLevel = make_unique<LevelOne>();
                                player2->setHeavy(0);
                            } else if (desiredLvl == 2) {
                                player2->pLevel = make_unique<LevelTwo>();
                                player2->setHeavy(0);
                            } else if (desiredLvl == 3) {
                                player2->pLevel = make_unique<LevelThree>();
                                player2->setHeavy(1);
                            } else if (desiredLvl == 4) {
                                player2->pLevel = make_unique<LevelFour>();
                                player2->setHeavy(1);
                            }
                            player2->nLevel = desiredLvl;
                        } else {
                            if (player2->nLevel != MAXLEVEL) {
                                player2->pLevel.reset();
                                player2->pLevel = make_unique<LevelFour>();
                                player2->setHeavy(1);
                            }
                            
                            player2->nLevel = MAXLEVEL;
                        }
                    }
                    //*/
                } else if (currComm == "leveldown") {
                        ///*
                    int desiredLvl;
                    if (countTurns % 2 == 0) {
                        desiredLvl = player1->nLevel - multiplier;
                        if (desiredLvl >= MINLEVEL) {
                            player1->pLevel.reset();
                            
                            if (desiredLvl == 0) {
                                player1->pLevel = make_unique<LevelZero>();
                                player1->setHeavy(0);
                            } else if (desiredLvl == 1) {
                                player1->pLevel = make_unique<LevelOne>();
                                player1->setHeavy(0);
                            } else if (desiredLvl == 2) {
                                player1->pLevel = make_unique<LevelTwo>();
                                player1->setHeavy(0);
                            } else if (desiredLvl == 3) {
                                player1->pLevel = make_unique<LevelThree>();
                                player1->setHeavy(1);
                            }
                            player1->nLevel = desiredLvl;
                            
                        } else {

                             if (player1->nLevel != MINLEVEL) {
                                player1->pLevel.reset();
                                player1->pLevel = make_unique<LevelZero>();
                                player1->setHeavy(0);
                            }
                            
                            player1->nLevel = MINLEVEL;
                        }
                    } else {
                        desiredLvl = player2->nLevel - multiplier;
                        if (desiredLvl >= MINLEVEL) {
                            player2->pLevel.reset();
                            
                            if (desiredLvl == 0) {
                                player2->pLevel = make_unique<LevelZero>();
                                player2->setHeavy(0);
                            } else if (desiredLvl == 1) {
                                player2->pLevel = make_unique<LevelOne>();
                                player2->setHeavy(0);
                            } else if (desiredLvl == 2) {
                                player2->pLevel = make_unique<LevelTwo>();
                                player2->setHeavy(0);
                            } else if (desiredLvl == 3) {
                                player2->pLevel = make_unique<LevelThree>();
                                player2->setHeavy(1);
                            }
                            player1->nLevel = desiredLvl;
                            
                        } else {
                            if (player2->nLevel != MINLEVEL) {
                                player2->pLevel.reset();
                                player2->pLevel = make_unique<LevelZero>();
                                player2->setHeavy(0);
                            }
                            
                            player2->nLevel = MINLEVEL;
                        }
                        
                    }
                    //*/
                } else if (currComm == "random") { // no multiplier
                    if (countTurns % 2 == 0) {
                        player1->randomness(currComm, "");
                    } else {
                        player2->randomness(currComm, "");
                    }
                } else if (currComm == "norandom") { // no multiplier
                    string fn;
                    while(!(cin >> fn)) {
                        std::cout << "\nPlease provide a file name." << endl;
                    }
                    if (countTurns % 2 == 0) {
                        player1->randomness(currComm, fn);
                    } else {
                        player2->randomness(currComm, fn);
                    }
                } else if (currComm == "sequence") { // reads in a file name, eh

                    string fn;
                    string cmd;

                    while(!(cin >> fn)) {
                        std::cout << "\nPlease provide a file name." << endl;
                    }

                    ifstream file(fn);

                    while (file >> cmd) {
                        cout << "reading" << endl;
                        multiplier = head->parsePrefix(cmd);
                        if (multiplier == 0) {
                            multiplier = 1;
                        }

                        firstL = firstLetter(cmd);
                        cmd = cmd.substr(firstL, cmd.length() - firstL + 1);
                        try {
                            string currComm = head->search(cmd);
                            
                            if (cmd == "restart") { // this is a special case
                            //clear grid, clear score, reset turn to 0,
                            player1->restart(); // clears the first grid
                            player2->restart(); // clears the second grid
                            countTurns = -1;    // This makes sure that no matter who calls restart, player one always plays first
                            player1->pLevel->setFile(fn1);
                            player1->setNextPiece();
                            player1->setCurrPiece();
                            player2->pLevel->setFile(fn2);
                            player2->setNextPiece();
                            player2->setCurrPiece();
                            player1->setNextPiece();
                            player2->setNextPiece();
                            
                            // effects
                            player1->setEffect(false);
                            player2->setEffect(false);
                            player1->setBlind(false);
                            player2->setBlind(false);
                            player1->setHeavy(0);
                            player2->setHeavy(0);
                            } else {
                                if (countTurns % 2 == 0) {
                                    player1->sequence(currComm, multiplier);
                                } else {
                                    player2->sequence(currComm, multiplier);
                                }
                            }
                            
                            if (countTurns % 2 == 0) {
                                int amt = player1->getHeavy();
                                for (int i = 0; i < amt; ++i) {
                                    player1->move("down");
                                }
                            } else {
                                int amt = player2->getHeavy();
                                for (int i = 0; i < amt; ++i) {
                                    player2->move("down");
                                }
                            }
                            
                            // levelFour *block condition
                            // sorry im dumb but how do i keep track of deleted rows? not currently stored anywhere
                            // storing in grid
                            
                            if (countTurns % 10 == 8 && player1->nLevel == 4 && cmd == "drop") {
                                if (player1->theGrid->getDeletedRows() == 0) {
                                    player1->theGrid->insertStarBlock();
                                } else {
                                    player1->theGrid->setDeletedRows(0);
                                }
                            } else if (countTurns % 10 == 9 && player2->nLevel == 4 && cmd == "drop") {
                                if (player2->theGrid->getDeletedRows() == 0) {
                                    player2->theGrid->insertStarBlock();
                                } else {
                                    player2->theGrid->setDeletedRows(0);
                                }
                            }

                    
                            std::cout << *td;
                            if (showGD) {
                                gd->render();
                            }

                            // special effects
                            string effect;
                            if (player1->canEffect()) {
                                std::cout << "Enter effect: ";
                                while (cin >> effect) {
                                    if (effect == "blind") {
                                        player2->setBlind(true); 
                                        break;
                                    } else if (effect == "heavy") {
                                        player2->setHeavy(player2->getHeavy() + 2);
                                        break;
                                    } else if (effect == "force") {
                                        std::cout << "\nChoose piece: ";
                                        string fPiece;
                                        while (cin >> fPiece) {
                                            if (fPiece == "I") {
                                                player2->setSpecificPieceType(PieceType::IBlock);
                                                break;
                                            } else if (fPiece == "J") {
                                                player2->setSpecificPieceType(PieceType::JBlock);
                                                break;
                                            } else if (fPiece == "L") {
                                                player2->setSpecificPieceType(PieceType::LBlock);
                                                break;
                                            } else if (fPiece == "T") {
                                                player2->setSpecificPieceType(PieceType::TBlock);
                                                break;
                                            } else if (fPiece == "Z") {
                                                player2->setSpecificPieceType(PieceType::ZBlock);
                                                break;
                                            } else if (fPiece == "S") {
                                                player2->setSpecificPieceType(PieceType::SBlock);
                                                break;
                                            } else if (fPiece == "O") {
                                                player2->setSpecificPieceType(PieceType::OBlock);
                                                break;
                                            } else {
                                                std::cout << "\nTry again \nChoose piece: ";
                                            }
                                        }
                                        break;
                                    } else {
                                        std::cout << "\nTry again \nEnter effect: ";
                                    }
                                }
                                player1->setEffect(false);
                                std::cout << *td;
                                if (showGD) {
                                    gd->render();
                                }
                            } else if (player2->canEffect()) {
                                std::cout << "Enter effect: ";
                                while (cin >> effect) {
                                    if (effect == "blind") {
                                        player1->setBlind(true); // where to unset? in textdisplay
                                        break;
                                    } else if (effect == "heavy") {
                                        player1->setHeavy(player1->getHeavy() + 2);
                                        break;
                                    } else if (effect == "force") {
                                        std::cout << "\nChoose piece: ";
                                        string fPiece;
                                        while (cin >> fPiece)
                                        {
                                            if (fPiece == "I")
                                            {
                                                player1->setSpecificPieceType(PieceType::IBlock);
                                                break;
                                            }
                                            else if (fPiece == "J")
                                            {
                                                player1->setSpecificPieceType(PieceType::JBlock);
                                                break;
                                            }
                                            else if (fPiece == "L")
                                            {
                                                player1->setSpecificPieceType(PieceType::LBlock);
                                                break;
                                            }
                                            else if (fPiece == "T")
                                            {
                                                player1->setSpecificPieceType(PieceType::TBlock);
                                                break;
                                            }
                                            else if (fPiece == "Z")
                                            {
                                                player1->setSpecificPieceType(PieceType::ZBlock);
                                                break;
                                            }
                                            else if (fPiece == "S")
                                            {
                                                player1->setSpecificPieceType(PieceType::SBlock);
                                                break;
                                            }
                                            else if (fPiece == "O")
                                            {
                                                player1->setSpecificPieceType(PieceType::OBlock);
                                                break;
                                            }
                                            else
                                            {
                                                std::cout << "\nTry again \nChoose piece: ";
                                            }
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        std::cout << "\nTry again \nEnter effect: ";
                                    }
                                }
                                player2->setEffect(false);
                                std::cout << *td;
                                if (showGD) {
                                    gd->render();
                                }
                            }

                            multiplier = 1;

                            if (currComm == "drop")
                            {
                                ++countTurns;
                                if (countTurns % 2 == 0)
                                {
                                    player2->setBlind(false);
                                }
                                else
                                {
                                    player1->setBlind(false);
                                }
                    }

                        } catch (logic_error &le) {
                            std::cout << le.what() << endl;
                        }
                        // check victory - SHIT'S BROKEN
                    /*
                       if (player1->theGrid->isDone() || player2->theGrid->isDone()) {
                           int player1Score = player1->getScore();
                           int player2Score = player2->getScore();
                           
                           if (player1Score > player2Score) {
                               std::cout << "Player 1 wins!" << endl;
                            } else if (player1Score < player2Score) {
                                std::cout << "Player 2 wins!" << endl;
                            } else {
                            std::cout << "A tie!" << endl;
                            }
                        }
                    
                    */
                    }
                } else if (currComm == "restart"){ // no multiplier
                        //clear grid, clear score, reset turn to 0,
                        player1->restart(); // clears the first grid
                        player2->restart(); // clears the second grid
                        countTurns = -1;    // This makes sure that no matter who calls restart, player one always plays first
                        player1->pLevel->setFile(fn1);
                        player1->setNextPiece();
                        player1->setCurrPiece();
                        player2->pLevel->setFile(fn2);
                        player2->setNextPiece();
                        player2->setCurrPiece();
                        player1->setNextPiece();
                        player2->setNextPiece();

                        // effects
                        player1->setEffect(false);
                        player2->setEffect(false);
                        player1->setBlind(false);
                        player2->setBlind(false);
                        player1->setHeavy(0);
                        player2->setHeavy(0);
                } else if (currComm == "I") { // replace current block w the I block
                    // make a method in player that replaces the current block with the I block
                    if (countTurns % 2 == 0) {
                        player1->setSpecificPieceType(PieceType::IBlock);
                    } else {
                        player2->setSpecificPieceType(PieceType::IBlock);
                    }
                } else if (currComm == "J") {
                    if (countTurns % 2 == 0) {
                        player1->setSpecificPieceType(PieceType::JBlock);
                    } else {
                        player2->setSpecificPieceType(PieceType::JBlock);
                    }
                }
                    else if (currComm == "L")
                    {
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::LBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::LBlock);
                        }
                    }
                    else if (currComm == "O")
                    {
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::OBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::OBlock);
                        }
                    }
                    else if (currComm == "S")
                    {
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::SBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::SBlock);
                        }
                    }
                    else if (currComm == "Z")
                    {
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::ZBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::ZBlock);
                        }
                    }
                    else if (currComm == "T")
                    {
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::TBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::TBlock);
                        }
                    }

                    // move downs for heavy
                    if (countTurns % 2 == 0) {
                        int amt = player1->getHeavy();
                        for (int i = 0; i < amt; ++i) {
                            player1->move("down");
                        }
                    } else {
                        int amt = player2->getHeavy();
                        for (int i = 0; i < amt; ++i) {
                            player2->move("down");
                        }
                    }

                    // levelFour *block condition
                    // sorry im dumb but how do i keep track of deleted rows? not currently stored anywhere
                    // storing in grid
                    if (countTurns % 10 == 8 && player1->nLevel == 4 && cmd == "drop") {
                        if (player1->theGrid->getDeletedRows() == 0) {
                            player1->theGrid->insertStarBlock();
                        } else {
                            player1->theGrid->setDeletedRows(0);
                        }
                    } else if (countTurns % 10 == 9 && player2->nLevel == 4 && cmd == "drop") {
                        if (player2->theGrid->getDeletedRows() == 0) {
                            player2->theGrid->insertStarBlock();
                        } else {
                            player2->theGrid->setDeletedRows(0);
                        }
                    }

                    // TO DO print the board right here
                    cout << *td;
                    if (showGD) {
                        gd->render();
                    }

                    // special effects
                    string effect;
                    if (player1->canEffect()) {
                        std::cout << "Enter effect: ";
                        while (cin >> effect) {
                            if (effect == "blind") {
                                player2->setBlind(true);  // where to unset? in textdisplay
                                break;
                            } else if (effect == "heavy") {
                                player2->setHeavy(player2->getHeavy() + 2);
                                break;
                            } else if (effect == "force") {
                                std::cout << "\nChoose piece: ";
                                string fPiece;
                                while (cin >> fPiece) {
                                    if (fPiece == "I") {
                                        player2->setSpecificPieceType(PieceType::IBlock);
                                        break;
                                    } else if (fPiece == "J") {
                                        player2->setSpecificPieceType(PieceType::JBlock);
                                        break;
                                    } else if (fPiece == "L") {
                                        player2->setSpecificPieceType(PieceType::LBlock);
                                        break;
                                    } else if (fPiece == "T") {
                                        player2->setSpecificPieceType(PieceType::TBlock);
                                        break;
                                    } else if (fPiece == "Z") {
                                        player2->setSpecificPieceType(PieceType::ZBlock);
                                        break;
                                    } else if (fPiece == "S") {
                                        player2->setSpecificPieceType(PieceType::SBlock);
                                        break;
                                    } else if (fPiece == "O") {
                                        player2->setSpecificPieceType(PieceType::OBlock);
                                        break;
                                    } else {
                                        std::cout << "\nTry again \nChoose piece: ";
                                    }
                                }
                                break;
                            } else {
                                std::cout << "\nTry again \nEnter effect: ";
                            }
                        }
                        player1->setEffect(false);
                        cout << *td;
                        if (showGD) {
                            gd->render();
                        }
                    } else if (player2->canEffect()) {
                        cout << "Enter effect: ";
                        while (cin >> effect) {
                            if (effect == "blind") {
                                player1->setBlind(true);  // where to unset? in textdisplay
                                break;
                            } else if (effect == "heavy") {
                                player1->setHeavy(player1->getHeavy() + 2);
                                break;
                            } else if (effect == "force") {
                                cout << "\nChoose piece: ";
                                string fPiece;
                                while (cin >> fPiece) {
                                    if (fPiece == "I") {
                                        player1->setSpecificPieceType(PieceType::IBlock);
                                        break;
                                    } else if (fPiece == "J") {
                                        player1->setSpecificPieceType(PieceType::JBlock);
                                        break;
                                    } else if (fPiece == "L") {
                                        player1->setSpecificPieceType(PieceType::LBlock);
                                        break;
                                    } else if (fPiece == "T") {
                                        player1->setSpecificPieceType(PieceType::TBlock);
                                        break;
                                    } else if (fPiece == "Z") {
                                        player1->setSpecificPieceType(PieceType::ZBlock);
                                        break;
                                    } else if (fPiece == "S") {
                                        player1->setSpecificPieceType(PieceType::SBlock);
                                        break;
                                    } else if (fPiece == "O") {
                                        player1->setSpecificPieceType(PieceType::OBlock);
                                        break;
                                    } else {
                                        cout << "\nTry again \nChoose piece: ";
                                    }
                                }
                                break;
                            } else {
                                cout << "\nTry again \nEnter effect: ";
                            }
                        }
                        player2->setEffect(false);
                        cout << *td;
                        if (showGD) {
                            gd->render();
                        }
                    }

                    multiplier = 1;

                    if (currComm == "drop"){
                        ++countTurns;
                        if (countTurns % 2 == 0) {
                            player2->setBlind(false);
                        } else {
                            player1->setBlind(false);
                        }
                    }

                    // check victory - SHIT'S BROKEN
                    /*
                       if (player1->theGrid->isDone() || player2->theGrid->isDone()) {
                           int player1Score = player1->getScore();
                           int player2Score = player2->getScore();
                           
                           if (player1Score > player2Score) {
                               std::cout << "Player 1 wins!" << endl;
                            } else if (player1Score < player2Score) {
                                std::cout << "Player 2 wins!" << endl;
                            } else {
                            std::cout << "A tie!" << endl;
                            }
                        }
                    
                    */
            } catch (logic_error &le) {
                // any invalid command prints an error message
                cout << le.what() << endl;
            }
       
            
        }
    } catch (ios::failure &) {
        // any I/O failure quits the game automatically 
    }

}
