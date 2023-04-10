#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef KING_HPP
#define KING_HPP
class King: public Pieces{
    
    private:
    Image *king;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            king = new Image("Pieces/König_Weiß.png",360,600,80,80,&board);
        } else {
           king = new Image("Pieces/König_Schwarz.png",360,40,80,80,&board); 
        }
    }
    
    public:
    
    //Der Konstruktor für den König
    King(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        isKing = true;
        setImage(isWhite,x,board);
    }
    
    
    //Die Operation, um zu überprüfen, ob der König bewegt werden kann
    bool isLegalMove(int sx,int sy,int ex, int ey,Pieces *piece) {
        
        int x = abs(sx - ex);
        int y = abs(sy - ey);
        
        if(piece != nullptr) {
            if(this->isWhite != piece->getIsWhite()) {
                if((x == 1 && y == 1) || (x == 0 && y == 1) || (x == 1 && y == 0)) {
                    return true; 
                } else {
                    return false;
                }
            } else {
                return false;
            }
            
        } else {
            if((x == 1 && y == 1) || (x == 0 && y == 1) || (x == 1 && y == 0)) {
               return true; 
            } else {
                return false;
            }
        }
        return false;
    }    
    
    //Die Operation zum Bewegen
    void setMove(int endx,int endy) {
        king->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        if (this->isWhite == true) {
            king->moveTo(690,40);
        } else {
            king->moveTo(690,600);
        }
        this->isKilled = isKilled;
    }
};
#endif