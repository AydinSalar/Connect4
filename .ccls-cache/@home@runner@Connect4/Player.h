#ifndef PLAYER_H
#define PLAYER_H

#include "GameBoard.h"
#include <string>

using namespace std;

class Player {
private:
  string name;
  char discSymbol;

public:
  Player(const string &name, char discSymbol);
  string getName() const;
  char getDiscSymbol() const;
  void makeMove(GameBoard &board);
};

#endif