/******************************************************************************
* @file gameState.cpp
* @brief Helper function for the game loop
*
* Purpose: This file manages player names and ending the game
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#include "../include/game-state/gameState.h"

std::string playerNameInput(std::string player)
{
  std::cout << "Enter the name of " << player << ": ";
  std::string name;
  std::cin >> name;
  return name;
}

bool manageInput(Player& player, Board& gameBoard)
{
  std::cout << "Player " << player.getPlayerID() << " input: ";
  gameBoard.playerInput(player.getPlayerID());
  gameBoard.displayBoard();

  // If a player won or they both tied we will commmunicate that the game ends
  bool gameFinished = gameBoard.didPlayerWin(player.getName());
  bool gameTie = gameBoard.checkPossibleTie();

  if (gameFinished || gameTie) {
    return true;
  }
  else {
    return false;
  }
}
