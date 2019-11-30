// Main

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "grid.h"
#include "levels.h"
#include "levelZero.h"

using namespace std;

int main(int argc, char *argv[]) {
    // sorry the following is probably filled with bugs and syntax errors
    // meant for taking in arguments

    // first I'm considering the arguments
    // then the actual input that is being read in from the user
    // THIS IS ALL SUBJECT TO CHANGE BC IDK WHAT IM DOING; FEEL FREE TO CORRECT JUST LMK!!

    string arg;
    Grid g1, g2; // ctors need to set default level to 0
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
                g1.pLevel = new LevelZero; // syntax and stuff here is gonna have to change and is prob wrong :(
                g2.pLevel = new LevelZero;

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
    Piece * p1, * p2; // piece pointers for g1 and g2

    while (true) { // game not over; please break when done
        // create a piece for cmd interpreter:
        p1 = g1.pLevel.create();
        p2 = g2.pLevel.create();

        /* IGNORE FOR NOW
        if (nLevel == "0") {
            // read from input files
            string pieceInputs;
            ifstream ifs1(fn1);
            while (getline(ifs1, pieceInputs)) {
                istringstream piecesString(pieceInputs);
                string newPiece;

                g1.pLevel.setPiece();
            }

        } else {
            p1 = g1.pLevel.create();
            p2 = g2.pLevel.create();
        }
        */


        // Command interpreter stuff pour Jessica
    }
}
