#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include <vector>
#include "levels.h"

using namespace std;

class LevelZero : Levels {
    string fileName = ""; // file name
    vector<string> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    Piece * create() override;
    
//    string getFile();  // what file to read from; unnecessary?
    void setFile(string fn);  // change the file: main should be using this!!
};

#endif
