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

#include "../include/board/Board.h"
#include "../include/player/Player.h"
#include "../include/display/display.h"
#include "../include/game-state/gameState.h"

int main(void) {
  Board gameBoard;

  displayTitle();
  // These are player ID's so that the game knows who they are
  Player playerOne(PLAYER_ONE);
  Player playerTwo(PLAYER_TWO);
  
  // Player names will be used when they win the game to personalize it
  std::string playerOneName = playerNameInput("Player One");
  playerOne.setName(playerOneName);
  std::string playerTwoName = playerNameInput("Player Two");
  playerTwo.setName(playerTwoName);
  std::cout << "\n";

  // If a player won or there is a tie, we use that to stop the game
  bool gameFinished = gameBoard.didPlayerWin("Default");
  bool gameTie = gameBoard.checkPossibleTie();

  // We track each turn so it feels immersive
  int turn = FIRST_TURN;

  startingConfirmation();

   // Game loop is needed to update the game board based on player actions
   while (!gameFinished && !gameTie) {
    std::cout << "Turn " << turn << '\n';
    gameBoard.displayBoard();
    bool didGameEnd = manageInput(playerOne, gameBoard);
    if (didGameEnd) {
      gameOver();
      break;
    }
    
    didGameEnd = manageInput(playerTwo, gameBoard);
    if (didGameEnd) {
      gameOver();
      break;
    }
    turn++;
  }
}