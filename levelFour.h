#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include <string>
#include <vector>
#include "levels.h"
//#include "state.h"

class LevelFour : public Levels {
    bool random = true;
    std::string fileName = ""; // file name
    std::vector<PieceType> playPieces; // vector for all pieces: the one at the back is meant to play next
    public:
    bool isRandom() override;
    void setRandom(bool randomness) override;

    int getLevel() override;
    std::unique_ptr<Piece> create(Grid * grid) override;
    
    void setFile(std::string fn) override;
};

#endif
