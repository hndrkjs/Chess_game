#include <algoviz/SVG.hpp>
#include <iostream>
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Player.hpp"
using namespace std;


#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP
class Chessboard{
    
    private:
    Rect rects[8][8];
    Pieces *pieces[8][8] = {};
    SVG zeichnung;
    int whiteKingX = 4;
    int whiteKingY = 7;
    int blackKingX = 3;
    int blackKingY = 0;
    
    
    public:
    
    //Der Standardkonstruktor
    Chessboard(){  
    }
    
    //Die Operation, die das Ursprungsbild herstellt
    void createBoard(int size){
        zeichnung = SVG(800,1000,"Chess");
        
        for ( int spalte = 0 ; spalte < 8; spalte = spalte+1 ) {
            for ( int zeile = 0 ; zeile < 8; zeile = zeile+1 ) {

            // Bewege das Rechteck an die richtige Stelle
            rects[spalte][zeile].moveTo((spalte*size),zeile*size);
            // Setze es auf die richtige Größe
            rects[spalte][zeile].setWidth(size);
            rects[spalte][zeile].setHeight(size);
        
            if ( (spalte + zeile) % 2 == 0 ) {
                rects[spalte][zeile].setFill("brown");
            } else {
                rects[spalte][zeile].setFill("burlywood");
            }

            rects[spalte][zeile].addTo(&zeichnung);
            } 
        }
        
        //Die Felderbezeichnungen
        new Text("1",660,(0.5*size),&zeichnung);
        new Text("2",660,(1.5*size),&zeichnung);
        new Text("3",660,(2.5*size),&zeichnung);
        new Text("4",660,(3.5*size),&zeichnung);
        new Text("5",660,(4.5*size),&zeichnung);
        new Text("6",660,(5.5*size),&zeichnung);
        new Text("7",660,(6.5*size),&zeichnung);
        new Text("8",660,(7.5*size),&zeichnung);
        new Text("A",(0.5*size),660,&zeichnung);
        new Text("B",(1.5*size),660,&zeichnung);
        new Text("C",(2.5*size),660,&zeichnung);
        new Text("D",(3.5*size),660,&zeichnung);
        new Text("E",(4.5*size),660,&zeichnung);
        new Text("F",(5.5*size),660,&zeichnung);
        new Text("G",(6.5*size),660,&zeichnung);
        new Text("H",(7.5*size),660,&zeichnung);
        
        //Alle Felder werden vorläufig mit dem nullptr initialisiert
        for ( int spalte = 0 ; spalte < 8; spalte++ ) {
            for ( int zeile = 0 ; zeile < 8; zeile++ ) {
                pieces[spalte][zeile] = nullptr;
            }  
        }
        
        //Erstellen der weißen Figuren
        pieces[0][7] = new Rook(0,true,false,zeichnung);
        pieces[1][7] = new Knight(1,true,false,zeichnung);
        pieces[2][7] = new Bishop(2,true,false,zeichnung);
        pieces[3][7] = new Queen(3,true,false,zeichnung);
        pieces[4][7] = new King(4,true,false,zeichnung);
        pieces[5][7] = new Bishop(5,true,false,zeichnung);
        pieces[6][7] = new Knight(6,true,false,zeichnung);
        pieces[7][7] = new Rook(7,true,false,zeichnung);
        
        for( int spalte = 0; spalte < 8; spalte++) {
            pieces[spalte][6] = new Pawn(spalte,true,false,zeichnung);
        }
        
        //Erstellen der schwarzen Figuren
        pieces[0][0] = new Rook(0,false,false,zeichnung);
        pieces[1][0] = new Knight(1,false,false,zeichnung);
        pieces[2][0] = new Bishop(2,false,false,zeichnung);
        pieces[3][0] = new Queen(3,false,false,zeichnung);
        pieces[4][0] = new King(4,false,false,zeichnung);
        pieces[5][0] = new Bishop(5,false,false,zeichnung);
        pieces[6][0] = new Knight(6,false,false,zeichnung);
        pieces[7][0] = new Rook(7,false,false,zeichnung);
        
        for( int spalte = 0; spalte < 8; spalte++) {
            pieces[spalte][1] = new Pawn(spalte,false,false,zeichnung);
        }
    }
    
    //Operation zum Überprüfen, ob Schach vorliegt
    bool isCheck(bool isWhite) {
        Pieces *start;
        Pieces *help;
        int destx;
        int desty;
        //Diese geschachtelte for-Schleife sucht den König des aktuellen Spielers
        for ( int spalte = 0 ; spalte < 8; spalte++) {
            for ( int zeile = 0 ; zeile < 8; zeile++) {
                help = getPiece(spalte,zeile);
                if (help != nullptr) {
                    if ((help->getIsWhite() == isWhite) && (help->getIsKing())) {
                        destx = spalte;
                        desty = zeile;
                    }
                }
            }
        }
        //Die Figuren des Gegners werden unter Berücksichtigung ihrer Möglichkeit, den König zu schlagen, durchlaufen
        for ( int spalte = 0 ; spalte < 8; spalte++ ) {
            for ( int zeile = 0 ; zeile < 8; zeile++ ) {
                start = getPiece(spalte,zeile);
                if (start != nullptr) {
                    if (start->getIsWhite() != isWhite) {
                        //Falls die ausgewählte Figur den König schlagen kann, ist der König im Schach
                        if (pathIsFree(spalte,zeile,destx,desty,start->getIsWhite())) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
        
    
    
    
    //Operation zum Überprüfen, ob der aktuelle Spieler noch Bewegungen ausführen kann
    bool canMove(bool isWhite) {
        int startx;
        int starty;
        //Alle Figuren werden durchlaufen
        for ( int spalte = 0 ; spalte < 8; spalte++ ) {
            for ( int zeile = 0 ; zeile < 8; zeile++ ) {
                Pieces *start = getPiece(spalte,zeile);
                startx = spalte;
                starty = zeile;
                //Falls es eine Figur des aktuellen Spielers ist, werden alle Zugmöglichkeiten überprüft
                if (start != nullptr) {
                    if (start->getIsWhite() == isWhite) {
                        for ( int endx = 0 ; endx < 8; endx++ ) {
                            for ( int endy = 0 ; endy < 8; endy++ ) {
                                Pieces *end = getPiece(endx,endy);
                                //Wenn der Spieler über einen legalen Zug verfügt, wird dieser ausgeführt
                                if (pathIsFree(startx,starty,endx,endy,start->getIsWhite())) {
                                    setPiece(startx,starty,nullptr);
                                    setPiece(endx,endy,start);
                                    //Dann wird überprüft, ob der Zug den Spieler Schach setzen würde. Gibt es eine Möglichkeit
                                    // dann wird true zurückgegeben
                                    if(isCheck(isWhite)) {
                                        setPiece(startx,starty,start);
                                        setPiece(endx,endy,end);
                                    } else {
                                        setPiece(startx,starty,start);
                                        setPiece(endx,endy,end);
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
       }
    
        
    //Diese Funktion überprüft, ob der Weg für die Figur frei ist    
    bool pathIsFree(int startx,int starty,int endx,int endy,bool isWhite) {
        Pieces *start = getPiece(startx,starty);
        Pieces *end = getPiece(endx,endy);
        
        //Das Pferd kann springen, also muss es nicht überprüft werden
        if(start->getIsKnight() == true && start->isLegalMove(startx,starty,endx,endy,end)) {
            return true;
        }
        
        //Bei allen anderen Figuren muss der Weg überprüft werden.
        if (start->isLegalMove(startx,starty,endx,endy,end)) {
            int x = endx;
            int y = endy;
            Pieces *current;
            //Die Schleife läuft dabei rückwärts vom End-Feld zum Start-Feld
            while (x != startx || y != starty) {
                current = getPiece(x,y);
                //Falls eine Figur "im Weg" steht, ist der Zug ungültig
                if(current != nullptr && (x != endx || y != endy)) {
                    return false;
                } 
                //Die x-Koordinate wird näher an den Startpunkt herangesetzt
                if ((x < startx) && (x != startx)) {
                    x++;
                } else if ((x > startx) && (x != startx)) {
                    x--;
                }
                //Die y-Koordinate wird näher an den Startpunkt gesetzt
                if ((y < starty) && (y != starty)) {
                    y++;
                } else if ((y > starty) && (y != starty)) {
                    y--;
                }
            }
            return true;
        } else {
           return false; 
        }
    }
    
    //Die Operation, die die Figuren bewegt, wenn diese bewegt werden dürfen
    bool doMove(int startx,int starty,int endx,int endy,Player *player) {
        Pieces *start = getPiece(startx,starty);
        Pieces *end = getPiece(endx,endy);
        //Das gewählte Feld muss eine Figur enthalten
        if(start != nullptr) {
            //Der Spieler kann nur Figuren seiner eigenen Farbe bewegen
            if(player->getIsWhite() == start->getIsWhite()) {
                //Überprüfung, ob alle Felder für die Figur frei sind
                if (pathIsFree(startx,starty,endx,endy,(start->getIsWhite()))) {
                    //Falls auf dem Zielfeld eine Figur steht, hat dies Implikationen für die Überprüfung
                    if(end != nullptr) { 
                        if(start->getIsWhite() != end->getIsWhite()) {
                            setPiece(endx,endy,start);
                            setPiece(startx,starty,nullptr);
                            //Die Überprüfung, ob dieser Zug den Spieler Schach setzen würde
                            if(isCheck(player->getIsWhite())) {
                                setPiece(endx,endy,nullptr);
                                setPiece(startx,starty,start);
                                return false;
                            } else {
                                end->setIsKilled(true);
                                start->setMove(endx,endy);
                                return true;
                            } 
                        } else {
                             return false;
                        }
                     } else {
                         setPiece(endx,endy,start);
                         setPiece(startx,starty,nullptr);
                         //Die Überprüfung, ob dieser Zug den Spieler Schach setzen würde
                         if(isCheck(start->getIsWhite())) {
                             setPiece(endx,endy,nullptr);
                             setPiece(startx,starty,start);
                             return false;
                         } else {
                             start->setMove(endx,endy);
                             return true;
                         }
                     }
                 } else {
                     return false;
                 }  
            } else {
                return false;
            }
        } else {
            return false;
        }
        return false;
    }
    
    //Setter
    void setPiece(int spalte,int zeile, Pieces *piece) {
        pieces[spalte][zeile] = piece;
    }
            
            
            
    //Getter
    Pieces *getPiece(int x,int y) {
        
        if (x < 0 || x > 7 || y < 0 || y > 7) {
            return nullptr;
        } else {
            return pieces[x][y];
        }
    }
    
    SVG *getSVG() {
        return &zeichnung;
    }
    
    
};
#endif