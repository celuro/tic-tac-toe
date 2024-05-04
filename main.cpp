/******************************************************************************
* @file main.cpp
* @brief Manages the game loop 
*
* Purpose: This file repesents the instance of the game and manages the game 
* loop by asking for player input until either player wins or has a tie.
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#include "Board.h"
#include "Player.h"

int main(void) {
  Board gameBoard;
  std::cout << "Weclome to Tic-Tac-Toe!\n";
  std::cout << "=======================\n";

  // These are player ID's so that the game knows who they are
  Player playerOne(1);
  Player playerTwo(2);
  
  // Player names will be used when they win the game to personalize it
  std::string p1Name;
  std::string p2Name;
  std::cout << "Enter the name of player one: ";
  std::cin >> p1Name;
  playerOne.setName(p1Name);
  std::cout << "Enter the name of player two: ";
  std::cin >> p2Name;
  playerTwo.setName(p2Name);

  // We need to know if the game is finished to stop the game and the amount of turns used.
  bool gameFinished = gameBoard.didPlayerWin("Default");
  bool gameTie = gameBoard.checkPossibleTie();
  int turn = 1;

  std::cout << "Starting...\n";
  gameBoard.displayBoard();

   //Game loop is needed to update the game board based on player actions
   while (!gameFinished && !gameTie) {
    std::cout << "Turn " << turn << '\n';
    std::cout << "Player One Input: ";
    gameBoard.playerInput(playerOne.getPlayerID());
    gameBoard.displayBoard();
    gameFinished = gameBoard.didPlayerWin(playerOne.getName());
    gameTie = gameBoard.checkPossibleTie();
    if (gameFinished || gameTie) {
      break;
    }
    
    std::cout << "Player Two Input: ";
    gameBoard.playerInput(playerTwo.getPlayerID());
    gameBoard.displayBoard();
    gameTie = gameBoard.checkPossibleTie();
    gameFinished = gameBoard.didPlayerWin(playerTwo.getName());
    if (gameFinished || gameTie) {
      break;
    }

    //Needs to update the game loop to represent the turn
    turn += 1;
  }
}
