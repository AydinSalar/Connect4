#ifndef PLAYER_H
#define PLAYER_H

#include "GameBoard.h"
#include <string>

using namespace std;

// class definition
class Player {
private:
  // player name and symbol
  string name;
  char discSymbol;

public:
  // constructor
  Player(const string &name, char discSymbol);

  // functions for the player
  string getName() const;
  char getDiscSymbol() const;
  void makeMove(GameBoard &board);
};

#endif