#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include <vector>
#include "levels.h"
//#include "state.h"


class LevelZero : public Levels {
    std::string fileName = ""; // file name
    std::vector<PieceType> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    bool isRandom() override;
    void setRandom(bool randomness) override;
    
    int getLevel() override;
    std::unique_ptr<Piece> create(Grid * grid) override;
    
//    string getFile();  // what file to read from; unnecessary?
    void setFile(std::string fn) override;  // change the file: main should be using this!!
};

#endif
