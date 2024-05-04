/******************************************************************************
* @file Player.h
* @brief Defines logic related to the player such as their name and if
* they are player one or two
*
* Purpose: This file implements the behaviour related to the board for the
* game. It handles player input, clearing the board, dispalying the board
* and checking win conditions.
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
  std::string name;
  int playerID;
public:
  Player();
  Player(int playerID);
  void setName(std::string name);
  std::string getName();
  void setPlayerID(int playerID);
  int getPlayerID();
};

#endif
