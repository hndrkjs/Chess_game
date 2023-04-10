# Chess_game

This is the code for a standard chess game I implemented as a final project at the end of my first semester. It is written in C++ and makes some use of specific libraries from the lecture. 

Main Chess implements the functionality of actually playing a game of chess. 
All of the pieces inherit from the Piece class. This class implements the basic functionality of any given piece. The individual classes for the pieces implement piece-specific behaviour.

The Game class implements the functionality of playing a game. That is, it switches between the players and checks whether the game is over.

The Chesssboard class implements the main logic of the game. It holds code for all the rules and can check whether any player is in a check-mate.

The Player class keeps track of the individual players.
