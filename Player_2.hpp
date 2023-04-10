#include <iostream>
using namespace std;


#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player{
    
    private:
    
        string name;
        bool isTurn;
        int points;
        bool isWhite;
        bool hasWon;
           
    public:
    
        Player(){
        }

        Player(string name,bool isWhite,bool isTurn) {
            this->name = name;
            this->isWhite = isWhite;
            points = 0;
            this->isTurn = isTurn;
            hasWon = false;
        }
    
    
    
        //Getter
        string getName() {
            return name;
        }
    
        bool getIsWhite() {
            return isWhite;
        }
        
        bool getIsTurn() {
            return isTurn;
        }
    
        int getPoints(){
            return points;
        }
        
        bool getHasWon() {
            return hasWon;
        }
    
    
        //Setter
    
        void setName(string name){
            this->name = name;
        }
        
        void setIsWhite(bool isWhite){
            this->isWhite = isWhite;
        }
    
        void setIsTurn(bool isTurn){
            this->isTurn = isTurn;
        }
    
        void setPoints(int points){
            this->points = points;
        }
    
        void setHasWon(bool hasWon) {
            this->hasWon = hasWon;
        }
    
};
#endif