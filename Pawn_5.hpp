#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef PAWN_HPP
#define PAWN_HPP
class Pawn: public Pieces{
    
    private:
    Image *pawn;
    bool firstMove;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            pawn = new Image("Pieces/Bauer_Weiß.png",40+x*80,520,80,80,&board);
        } else {
           pawn = new Image("Pieces/Bauer_Schwarz.png",40+x*80,120,80,80,&board); 
        }
    }
    
    public:
    
    Pawn(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        setImage(isWhite,x,board);
        firstMove = false;
    }
    
    
    //Die Operation, um zu überprüfen, ob der Pawn bewegt werden kann
    bool isLegalMove(int sx,int sy,int ex,int ey,Pieces *piece) {
        
        int x = abs(sx - ex);
        int y = abs(sy - ey);
        if(piece != nullptr) {
            if(this->isWhite == true) {
                if((this->isWhite != piece->getIsWhite()) && (x == 1 && y == 1) && (sy > ey)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if((this->isWhite != piece->getIsWhite()) && (x == 1 && y == 1) && (sy < ey)) {
                    return true;
                } else {
                    return false;
                } 
            }            
        } else {
            if (this->isWhite == true) {
                if ((firstMove == false) && (x == 0 && y == 2) && (sy > ey)) {
                    firstMove = true;
                    return true;
                } else if ((firstMove == true) && (x == 0 && y == 2) && (sy > ey)) {
                    return false;
                } else if ((x == 0 && y == 1) && (sy > ey)) {
                    firstMove = true;
                    return true;
                }              
            } else {
                 if ((firstMove == false) && (x == 0 && y == 2) && (sy < ey)) {
                    firstMove = true;
                    return true;
                } else if ((firstMove == true) && (x == 0 && y == 2) && (sy < ey)) {
                    return false;
                } else if ((x == 0 && y == 1) && (sy < ey)) {
                     firstMove = true;
                    return true;
                }
            }
        }
        return false;
    }
    
    //Die Operation zum Bewegen
    void setMove(int endx,int endy) { 
        pawn->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        if (this->isWhite == true) {
            pawn->moveTo(690,40);
        } else {
            pawn->moveTo(690,600);
        }
        this->isKilled = isKilled;
    }
    
};
#endif

