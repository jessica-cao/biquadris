#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include "levels.h"

class LevelTwo : Levels {
    std::string fileName = ""; // file name
    std::vector<PieceType> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    int getLevel();
    std::unique_ptr<Piece> create(Grid * grid) override;
    
    void setFile(std::string fn) override;
};

#endif
