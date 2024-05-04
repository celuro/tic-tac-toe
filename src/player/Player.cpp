/******************************************************************************
* @file Player.cpp
* @brief Implementation of behaviour of the Player class
*
* Purpose: This file implements the behaviour related to the player for the
* game. It handles encapsulation by providing getters and setters for the id
* and name.
*
* @author mimikyumom.
* @bug No known bugs
******************************************************************************/

#include "../../include/player/Player.h"

Player::Player()
{
  std::string name = "Default";
  playerID = DEFAULT_PLAYER_ID;
}

Player::Player(int playerID)
{
  if (playerID == PLAYER_ONE || playerID  == PLAYER_TWO) {
    this->playerID = playerID;
  }
  else {
    this->playerID = DEFAULT_PLAYER_ID;
  }
}

void Player::setName(std::string name)
{
  if (name.length() > MIN_NAME_LENGTH) {
    this->name = name;
  }
  else {
    this->name = "Default";
  }
}

std::string Player::getName()
{
  return name;
}

void Player::setPlayerID(int playerID)
{
  if (playerID == PLAYER_ONE || playerID == PLAYER_TWO) {
    this->playerID = playerID;
  }
  else {
    playerID = DEFAULT_PLAYER_ID;
  }
}

int Player::getPlayerID() const
{
  return playerID;
}
