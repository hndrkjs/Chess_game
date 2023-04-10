#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef ROOK_HPP
#define ROOK_HPP
class Rook: public Pieces{
    
    private:
    Image *rook;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            rook = new Image("Pieces/Turm_Weiß.png",40+x*80,600,80,80,&board);
        } else {
           rook = new Image("Pieces/Turm_Schwarz.png",40+x*80,40,80,80,&board); 
        }
    }
    
    public:
    
    Rook(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        setImage(isWhite,x,board);
    }
    
    bool isLegalMove(int sx, int sy, int ex, int ey,Pieces *piece) {
       
       
       int x = abs(sx - ey);
       int y = abs(sy - ey);
       
       if(piece != nullptr) {
            if ((piece->getIsWhite() != this->isWhite)) {
                if ((x == 0 && y < 7) || (y == 0 && x < 7)) {
                    return true; 
                } else {
                    return false;
                }
            } else {
                return false;
            }  
        } else {
           if ((x == 0 && y < 7) || (y == 0 && x < 7)) {
               return true; 
           } else {
               return false;
           }
        }
        return false;
    }
    
   //Die Operation zum Bewegen
   void setMove(int endx,int endy) {
        rook->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        rook->moveTo(690,40);
        this->isKilled = isKilled;
    }
    
};
#endif