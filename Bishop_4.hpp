#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef BISHOP_HPP
#define BISHOP_HPP
class Bishop: public Pieces{
    
    private:
    
    Image *bishop;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            bishop = new Image(".../.../img/Pieces/Läufer_Weiß.png",40+x*80,600,80,80,&board);
        } else {
           bishop = new Image(".../.../img/Pieces/Läufer_Schwarz.png",40+x*80,40,80,80,&board); 
        }
    }
    
    public:
    
    Bishop(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        setImage(isWhite,x,board);
    }
    
    //Die Operation, um zu überprüfen, ob der Bishop bewegt werden kann
    bool isLegalMove(int sx, int sy, int ex, int ey,Pieces *piece) {
        
        int x = abs(sx - ex);
        int y = abs(sy - ey);
        if(piece != nullptr) {
            if ((piece->getIsWhite() != this->isWhite) && (x == y)) {
                return true;
            } else {
                return false;
            }  
        } else {
            if(x == y) {
               return true; 
            } else {
                return false;
            }
        }
        return false;
    }
    
    //Die Operation zum Bewegen
    void setMove(int endx,int endy) {
        bishop->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        bishop->moveTo(690,40);
        this->isKilled = isKilled;
    }
};
#endif