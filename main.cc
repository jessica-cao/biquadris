// Main

#include <iostream>
#include <string>
#include "player.h"
#include "levels.h"
#include "levelZero.h"
#include "trie.h"
#include "textdisplay.h"

using namespace std;

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
    unique_ptr<Player> player1, player2; // ctors need to set default level to 0
                                // will need a field that points to Level obj, which then specifies the lvl (eg. LevelZero)
                                // call Piece * pLevel (playerLevel) and string nLevel (numLevel)
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
                player1->pLevel = new LevelZero; // syntax and stuff here is gonna have to change and is prob wrong :(
                player2->pLevel = new LevelZero;

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

    cin.exceptions(ios::eofbit|ios::failbit);
    // add any additional intializations here
    string cmd; // reads in a command
    unique_ptr<Piece> p1, p2; // piece pointers for g1 and g2
    int countTurns = 0;
    Trie* head = new Trie();
	head->insertCommands();
    int multiplier = 1; // some commands have a multiplier prefix; to show how many times a command is executed

    try {
        
        // Command interpreter stuff pour Jessica it is I. The frenchiest fry
        while (true) { // game not over; break when done
        // create a piece for command interpreter:
            player1->pLevel->setFile(fn1);  // to clean later: just set immediately in for loop for args
            player1->pLevel->setFile(fn2);
            
            p1 = player1->pLevel->create(); // create your piece; this is the current piece that the cmd is acting on
            player1->theGrid->attach(p1);
            p2 = player2->pLevel->create(); // create the opponent's piece; the opponent's current piece
            player2->theGrid->attach(p2);

            cin >> cmd;
            multiplier = head->parsePrefix(cmd); // check if the command we have has a prefix

            // if the cmd doesn't have a prefix, or if someone wants to mess w it
            // the multiplier is set to 1, so the command executes once
            if (multiplier <= 0) {
                multiplier = 1;
            }
            
            try {
                string currComm = head->search(cmd);

                if (currComm == "left") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->move_l();
                        } else {
                            p2->move_l();
                        }
                    }
                } else if (currComm == "right") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->move_r();
                        } else {
                            p2->move_r();
                        }
                    }

                } else if (currComm == "down") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->move_d();
                        } else {
                            p2->move_d();
                        }
                    }
                } else if (currComm == "clockwise") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->rotate_cw();
                        } else {
                            p2->rotate_cw();
                        }
                    }

                } else if (currComm == "counterclockwise") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->rotate_ccw();
                        } else {
                            p2->rotate_ccw();
                        }
                    }
                } else if (currComm == "drop") {
                    for (int i = 0; i < multiplier; ++i) {
                        if (countTurns % 2 == 0) {
                            p1->drop();
                        } else {
                            p2->drop();
                        }
                    }
                } else if (currComm == "levelup") {
                    int desiredLvl;
                    if (countTurns % 2 == 0) {
                        desiredLvl = multiplier + stoi(player1->nLevel);
                        if (desiredLvl <= MAXLEVEL) {
                            player1->nLevel = to_string(desiredLvl);
                        } else {
                            player1->nLevel = to_string(MAXLEVEL);
                        }
                    } else {

                    }
                    

                } else if (currComm == "leveldown") {
                  
                } else if (currComm == "random") { // no multiplier

                } else if (currComm == "norandom") { // no multiplier
                
                } else if (currComm == "sequence") {

                } else if (currComm == "restart") { // no multiplier

                } else if (currComm == "I") {

                } else if (currComm == "J") {

                } else if (currComm == "L") {
                    
                } else if (currComm == "O") {

                } else if (currComm == "S") {

                } else if (currComm == "Z") {

                } else if (currComm == "T") {

                }

                // check for victory condition here 
                // if victory, then break
                
                multiplier = 1;
                ++countTurns;
            } catch (logic_error &le) {
                cout << le.what() << endl;
            }
            
        }
    } catch (ios::failure &) {
        // any I/O failure quits the game automatically 
    }

}
