#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef KNIGHT_HPP
#define KNIGHT_HPP
class Knight: public Pieces{
    
    private:
    Image *knight;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            knight = new Image("Pieces/Pferd_Weiß.png",40+x*80,600,80,80,&board);
        } else {
           knight = new Image("Pieces/Pferd_Schwarz.png",40+x*80,40,80,80,&board); 
        }
    }
    
    public:
    
    Knight(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        setImage(isWhite,x,board);
        isKnight = true;
    }
   
    //Die Operation, um zu überprüfen, ob der Knight bewegt werden kann
    bool isLegalMove(int sx, int sy, int ex, int ey,Pieces *piece) {
        
        int x = abs(sx - ex);
        int y = abs(sy - ey);
        
        if(piece != nullptr) {
            if ((piece->getIsWhite() != this->isWhite)) {
                if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
                    return true; 
                } else {
                    return false;
                }
            } else {
                return false;
            }  
        } else {
           if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
               return true; 
           } else {
               return false;
           }
        }
        return false;
    }
    
    //Die Operation zum Bewegen
    void setMove(int endx,int endy) {
        knight->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        knight->moveTo(690,40);
        this->isKilled = isKilled;
    }
       
};
#endif