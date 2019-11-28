#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include "levels.h"

using namespace std;

class LevelZero : Levels {
    string pieceIs;
    public:
    AbsPieces * create() override;
    
    string getPiece();  // what piece has been read in
    void setPiece(string newPiece);  // change the piece: main should be using this!!
};

#endif
