#include <iostream>
#include "Chessboard.hpp"
using namespace std;


#ifndef GAME_HPP
#define GAME_HPP
class Game{
    
    private:
    list <string> moves;
    Player *player1;
    Player *player2;
    
   
    public:
    
    //STANDARDKONSTRUKTOR
    Game(string name1,string name2){
        
        player1 = new Player(name1,true,true);
        player2 = new Player(name2,false,false);
        
    }
    
    //Operation, um die Züge abzuwechseln
    void switchTurn() {
        if(player1->getIsTurn() == true) {
            player1->setIsTurn(false);
            player2->setIsTurn(true);
        } else {
            player1->setIsTurn(true);
            player2->setIsTurn(false);
        }
    }
    
    //Eine Operation, um den Status des Spieles auszuwerten
    bool gameOver(Chessboard board) {
        
        if(player1->getIsTurn() == true) {
            if(!board.canMove(player1->getIsWhite())) {
                if(board.isCheck(player1->getIsWhite())) {
                    player2->setHasWon(true);
                    return true;
                } else {
                   return true; 
                }
            } else {
                return false;
            }
            
        } else {
            if(!board.canMove(player2->getIsWhite())) {
                if(board.isCheck(player2->getIsWhite())) {
                    player1->setHasWon(true);
                    return true;
                } else {
                   return true; 
                }
            } else {
                return false;
            }
        }
        return false;     
    }
    
    //Getter
    
    //Dieser Getter gibt den Spieler zurück, der gerade dran ist
    Player *getCurrentPlayer() {
        if(player1->getIsTurn() == true) {
            return player1;
        } else {
            return player2;
        }
    }
    
    void getWinner() {
        if(player1->getHasWon() == true) {
            cout << "Spieler1 hat gewonnen" << "\n";
        } else {
            cout << "Spieler2 hat gewonnen" << "\n";
        }
    }
     
};
#endif

