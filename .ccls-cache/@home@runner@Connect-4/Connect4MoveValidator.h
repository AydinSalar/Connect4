#ifndef CONNECT4MOVEVALIDATOR_H
#define CONNECT4MOVEVALIDATOR_H

#include "MoveValidator.h"

#include <vector>

using namespace std;

// class definition
class Connect4MoveValidator : public MoveValidator {

private:
  // 2d vector to store the board
  const vector<vector<char>> &board;

public:
  // constructor
  Connect4MoveValidator(const vector<vector<char>> &board);

  // destructor
  bool isValidMove(int x, int y) const override;
};

#endif