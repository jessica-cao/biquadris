// Main

#include <iostream>
#include <string>
#include <memory>
#include "player.h"
#include "levels.h"
#include "levelZero.h"
/*
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
*/
#include "trie.h"
#include "textdisplay.h"

using namespace std;

// CALL GRID INIT IN PLAYER

// The highest level you can reach
const int MAXLEVEL = 4;

// The lowest level you can reach
const int MINLEVEL = 0;

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
    unique_ptr<Player> player1;
    unique_ptr<Player> player2;
    
    string nLevel = "0"; // intialized level: THIS MAY BE A PROBLEM LATER DEPENDING ON HOW WE SET LEVELUP AND DOWN
    string fn1 = "sequence1.txt";
    string fn2 = "sequence2.txt";

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
        } else if (arg[0] == '-' && i+1 == argc) {
            // the following else ifs need two args. If the current one starts as -notText and there
            // isn't a string following, it is an invalid command!
        } else if (arg == "-seed") {
            string seed = argv[i+1];
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
            if (nLevel == "0") {
                player1->pLevel = make_unique<LevelZero>();
                player2->pLevel = make_unique<LevelZero>();

                // ignore other levels for now
            /*
            } else if (nLevel == "1") {
                //
            } else if (nLevel == "2") {
                //
            } else if (nLevel == "3") {
                //
            } else if (nLevel == "4") {
                //
                */
            }
        }
    }

    std::cin.exceptions(ios::eofbit|ios::failbit); // why is cin ambiguous here. Jackass.
    // add any additional intializations here
    string cmd; // reads in a command
 //   unique_ptr<Piece> p1 {new Piece()}; // piece pointers for player1's grid
 //   unique_ptr<Piece> p2 {new Piece()}; // piece pointer for player2's grid
    int countTurns = 0;
    Trie* head = new Trie();
	head->insertCommands();
    int multiplier = 1; // some commands have a multiplier prefix; to show how many times a command is executed
    unique_ptr<TextDisplay> td {new TextDisplay(player1.get(), player2.get())}; // should work now with new and improved TextDisplay
    int player1Score;
    int player2Score;

    try {
        
        // Command interpreter
        while (true) { // game not over; break when done
        // create a piece for command interpreter:
            player1->pLevel->setFile(fn1);  // to clean later: just set immediately in for loop for args
            player1->pLevel->setFile(fn2);
            
            p1 = make_unique<Piece>(player1->pLevel->create()); // create your piece; this is the current piece that the cmd is acting on
            p1->setLevel(0);
            p1->attach(player1->theGrid.get());
            player1->theGrid->attach(p1.get()); // TODO check on this tmr and see if it still works
            p2 = make_unique<Piece>(player2->pLevel->create()); // create the opponent's piece; the opponent's current piece
            p2->setLevel(0);
            p2->attach(player1->theGrid.get());
            player2->theGrid->attach(p2.get()); // TODO check on this tmr and see if it still works

            std::cin >> cmd;
            multiplier = head->parsePrefix(cmd); // check if the command we have has a prefix

            // if the cmd doesn't have a prefix, or if someone wants to mess w it
            // the multiplier is set to 1, so the command executes once
            if (multiplier == 0) {
                multiplier = 1;
            }
            
            try {

                string currComm = head->search(cmd);

                try {
                    string currComm = head->search(cmd);

                    if (currComm == "left" || currComm == "right" || currComm == "down" || currComm == "drop") {
                        for (int i = 0; i < multiplier; ++i) {
                            if (countTurns % 2 == 0) {
                                p1->move(cmd);
                            } else {
                                p2->move(cmd);
                            }
                        }
                    } else if (currComm == "clockwise" || currComm == "counterclockwise") {
                        for (int i = 0; i < multiplier; ++i) {
                            if (countTurns % 2 == 0) {
                                p1->rotate(cmd);
                            } else {
                                p2->rotate(cmd);
                            }
                        }
                    } else if (currComm == "levelup") {
                        /*
                    int desiredLvl;
                    if (countTurns % 2 == 0) {
                        desiredLvl = multiplier + player1->nLevel;
                        if (desiredLvl <= MAXLEVEL) {
                            player1->pLevel.reset();
                            
                            if (desiredLvl == 1) {
                                player1->pLevel = make_unique<LevelOne>(new LevelOne());
                            } else if (desiredLvl == 2) {
                                player1->pLevel = make_unique<LevelTwo>(new LevelTwo());
                            } else if (desiredLvl == 3) {
                                player1->pLevel = make_unique<LevelThree>(new LevelThree());
                            } else if (desiredLvl == 4) {
                                player1->pLevel = make_unique<LevelFour>(new LevelFour());
                            }
                            player1->nLevel = desiredLvl;
                        } else {
                            if (player1->nLevel != MAXLEVEL) {
                                player1->pLevel.reset();
                                player1->pLevel = make_unique<LevelFour>(new LevelFour());
                            }
                            
                            player1->nLevel = MAXLEVEL;
                        }
                        
                    } else {
                        desiredLvl = multiplier + player2->nLevel;
                        if (desiredLvl <= MAXLEVEL) {
                            player2->pLevel.reset();

                            if (desiredLvl == 1) {
                                player2->pLevel = make_unique<LevelOne>(new LevelOne());
                            } else if (desiredLvl == 2) {
                                player2->pLevel = make_unique<LevelTwo>(new LevelTwo());
                            } else if (desiredLvl == 3) {
                                player2->pLevel = make_unique<LevelThree>(new LevelThree());
                            } else if (desiredLvl == 4) {
                                player2->pLevel = make_unique<LevelFour>(new LevelFour());
                            }
                            player2->nLevel = desiredLvl;
                        } else {
                            if (player2->nLevel != MAXLEVEL) {
                                player2->pLevel.reset();
                                player2->pLevel = make_unique<LevelFour>(new LevelFour());
                            }
                            
                            player2->nLevel = MAXLEVEL;
                        }
                    }
                    */
                    } else if (currComm == "leveldown") {
                        /*
                    int desiredLvl;
                    if (countTurns % 2 == 0) {
                        desiredLvl = player1->nLevel - multiplier;
                        if (desiredLvl >= MINLEVEL) {
                            player1->pLevel.reset();
                            
                            if (desiredLvl == 0) {
                                player1->pLevel = make_unique<LevelZero>(new LevelZero());
                            } else if (desiredLvl == 1) {
                                player1->pLevel = make_unique<LevelOne>(new LevelOne());
                            } else if (desiredLvl == 2) {
                                player1->pLevel = make_unique<LevelTwo>(new LevelTwo());
                            } else if (desiredLvl == 3) {
                                player1->pLevel = make_unique<LevelThree>(new LevelThree());
                            }
                            player1->nLevel = desiredLvl;
                            
                        } else {

                             if (player1->nLevel != MINLEVEL) {
                                player1->pLevel.reset();
                                player1->pLevel = make_unique<LevelZero>(new LevelZero());
                            }
                            
                            player1->nLevel = MINLEVEL;
                        }
                    } else {
                        desiredLvl = player2->nLevel - multiplier;
                        if (desiredLvl >= MINLEVEL) {
                            player2->pLevel.reset();
                            
                            if (desiredLvl == 0) {
                                player2->pLevel = make_unique<LevelZero>(new LevelZero());
                            } else if (desiredLvl == 1) {
                                player2->pLevel = make_unique<LevelOne>(new LevelOne());
                            } else if (desiredLvl == 2) {
                                player2->pLevel = make_unique<LevelTwo>(new LevelTwo());
                            } else if (desiredLvl == 3) {
                                player2->pLevel = make_unique<LevelThree>(new LevelThree());
                            }
                            player1->nLevel = desiredLvl;
                            
                        } else {
                            if (player2->nLevel != MINLEVEL) {
                                player2->pLevel.reset();
                                player2->pLevel = make_unique<LevelZero>(new LevelZero());
                            }
                            
                            player2->nLevel = MINLEVEL;
                        }
                        
                    }
                    */
                    } else if (currComm == "random" || currComm == "noRandom") { // no multiplier
                    if (countTurns % 2 == 0) {
                                p1->randomness(cmd);
                            } else {
                                p2->randomness(cmd);
                            }
                    } else if (currComm == "sequence") {
                        if (countTurns % 2 == 0) {
                                p1->sequence();
                            } else {
                                p2->sequence();
                            }
                    } else if (currComm == "restart")
                    { // no multiplier
                        //clear grid, clear score, reset turn to 0,
                        player1->restart(); // clears the first grid
                        player2->restart(); // clears the second grid
                        countTurns = -1;    // This makes sure that no matter who calls restart, player one always plays first
                    }
                    else if (currComm == "I") { // replace current block w the I block
                        // make a method in player that replaces the current block with the I block
                        if (countTurns % 2 == 0) {
                            player1->setSpecificPieceType(PieceType::IBlock);
                        } else {
                            player2->setSpecificPieceType(PieceType::IBlock);
                        }
                    }
                    else if (currComm == "J")
                    {
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

                    // TODO print the board right here
                    cout << td.get();

                    multiplier = 1;
                    ++countTurns;
                } catch (logic_error &le) { // any invalid command prints an error message

                // check for victory condition here
                // If a piece can no longer be played, a specific error message is thrown. We need to check for that error message.
                player1Score = player1->getScore();
                player2Score = player2->getScore();

                if (player1Score > player2Score) {
                    cout << "Player 1 wins!" << endl;
                } else if (player1Score < player2Score) {
                    cout << "Player 2 wins!" << endl;
                } else {
                    cout << "A tie!" << endl;
                }

                break;
                }
            } catch (logic_error &le) {
                // any invalid command prints an error message
                cout << le.what() << endl;
            }
       
            
        }
    } catch (ios::failure &) {
        // any I/O failure quits the game automatically 
    
    }

}
