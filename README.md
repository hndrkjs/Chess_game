# Chess_game

This is the code for a standard chess game I implemented as a final project at the end of my first semester. It is written in C++ and makes some use of specific libraries from the lecture. 

Main Chess implements the functionality of actually playing a game of chess. 
All of the pieces inherit from the Piece class. This class implements the basic functionality of any given piece. The individual classes for the pieces implement piece-specific behaviour.

The Game class keeps track of the main rules of a game and checks whether the game is over at any given point. It also holds the function to prohibit invalid moves. 

The Player class keeps track of the individual players.
