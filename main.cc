// Main

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // sorry the following is probably filled with bugs and syntax errors
    // meant for taking in arguments

    // first I'm considering the arguments
    // then the actual input that is being read in from the user
    // THIS IS ALL SUBJECT TO CHANGE BC IDK WHAT IM DOING; FEEL FREE TO CORRECT JUST LMK!!

    cin.exceptions(ios::eofbit!ios::failbit);
    string arg;

    // defaults for things (without args) is:
        // show texts AND graphics
        // same sequence (no rng)
        // use sequence1.txt
        // use sequence2.txt
        // start at levelZero
    for (int i = 0; i < argc-1; ++i) {
        arg = argv[i+1];
        if (arg == "text") {
            // disable graphics
        } else if (arg == "seed") {
            string seed = argv[i+2];
            // rng but tbh not sure for what?? for pieces?? bc i already dealt w that in the levels
        } else if (arg == "scriptfile1") {
            // file to replace sequence1.txt
        } else if (arg == "scriptfile2") {
            // file to replace sequence2.txt
        } else if (arg == "startlevel") {
            string nLevel = argv[i+2];
            // WHAT WILL BE KEEPING TRACK OF THE LEVELS?
            if (nLevel == "0") {
                //
            } else if (nLevel == "1") {
                //
            } else if (nLevel == "2") {
                //
            } else if (nLevel == "3") {
                //
            } else if (nLevel == "4") {
                //
            }
        }
    }
}
