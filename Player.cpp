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

#include "Player.h"

Player::Player()
{
  std::string name = "Default";
  playerID = 0;
}

Player::Player(int playerID)
{
  if (playerID == 1 || playerID  == 2) {
    this->playerID = playerID;
  }
  else {
    this->playerID = 0;
  }
}

void Player::setName(std::string name)
{
  if (name.length() > 0) {
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
  if (playerID == 1 || playerID == 2) {
    this->playerID = playerID;
  }
  else {
    playerID = 0;
  }
}

int Player::getPlayerID()
{
  return playerID;
}
