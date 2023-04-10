#include <iostream>
#include <math.h>
#include "Pieces.hpp"
using namespace std;


#ifndef QUEEN_HPP
#define QUEEN_HPP
class Queen: public Pieces{
    
    private:
    Image *queen;
    
    void setImage(bool isWhite,int x,SVG &board) {
        if(isWhite) {
            queen = new Image("Chess/Königin-Weiß.png",280,600,80,80,&board);
        } else {
           queen = new Image("Chess/Königin-Schwarz.png",280,40,80,80,&board); 
        }
    }
    
    public:
    
    Queen(int x,bool isWhite,bool isKilled,SVG &board):Pieces(){
        this->isWhite = isWhite;
        this->isKilled = isKilled;
        setImage(isWhite,x,board);
    }
    
    //Die Operation, um zu überprüfen, ob die Queen bewegt werden kann
    bool isLegalMove(int sx, int sy, int ex, int ey,Pieces *piece) {
       
        
        int x = abs(sx - ex);
        int y = abs(sy - ey);
        
        if(piece != nullptr) {
            if ((piece->getIsWhite() != this->isWhite)) {
                if ((x == y) || (x == 0 && y < 7) || (y == 0 && x < 7)) {
                    return true; 
                } else {
                    return false;
                }
            } else {
                return false;
            }  
        } else {
           if ((x == y) || (x == 0 && y < 7) || (y == 0 && x < 7)) {
               return true; 
           } else {
               return false;
           }
        }
        return false;
    }
        
    
    //Die Operation zum Bewegen
    void setMove(int endx, int endy) {
        queen->moveTo(40+endx*80,40+endy*80);
    }
    
    void setIsKilled(bool isKilled){
        if (this->isWhite == true) {
            queen->moveTo(690,40);
        } else {
            queen->moveTo(690,600);
        }
        this->isKilled = isKilled;
    }
   
};
#endif