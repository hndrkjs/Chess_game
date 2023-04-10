#include <iostream>
using namespace std;


#ifndef PIECES_HPP
#define PIECES_HPP
class Pieces{
      
    public:
    
    bool isWhite;
    bool isKilled;
    bool isKing = false;
    bool isKnight = false;
    
    virtual void setImage(bool isWhite,int x,SVG &board) =0;
    
    //Der Konstruktor
    Pieces(){
    }
    
    virtual void setMove(int endx,int endy) =0;
    virtual bool isLegalMove(int sx, int sy, int ex, int ey,Pieces *piece) =0;
    virtual void setIsKilled(bool isKilled) =0;
    
    //Getter
    bool getIsWhite(){
        return this->isWhite;
    }
    
    bool getIsKilled(){
        return this->isKilled;
    }
    
    bool getIsKing() {
        return this->isKing;
    }
    
    bool getIsKnight() {
        return this->isKnight;
    }
   
    //Setter
    void setIsWhite(bool isWhite){
        this->isWhite = isWhite;
    }
 
    
};
#endif