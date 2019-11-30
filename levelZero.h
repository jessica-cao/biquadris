#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include <vector>
#include "levels.h"
#include "state.h"


class LevelZero : public Levels {
    std::string fileName = ""; // file name
    vector<PieceType> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    std::unique_ptr<Piece> create() override;
    
//    string getFile();  // what file to read from; unnecessary?
    void setFile(string fn);  // change the file: main should be using this!!
};

#endif
