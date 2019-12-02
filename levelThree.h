#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include "levels.h"


class LevelThree : Levels {
    bool random = false;
    std::string fileName = ""; // file name
    std::vector<PieceType> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    bool isRandom();
    void setRandom(bool randomness);
    int getLevel();
    std::unique_ptr<Piece> create(Grid * grid) override;
    
    void setFile(std::string fn) override;
};

#endif
