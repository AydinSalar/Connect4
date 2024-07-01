#ifndef CONNECT4MOVEVALIDATOR_H
#define CONNECT4MOVEVALIDATOR_H

#include "MoveValidator.h"
#include <vector> 

using namespace std;

class Connect4MoveValidator : public MoveValidator{
private:
  const vector<vector<char>> &board;

public:
  Connect4MoveValidator(const vector<vector<char>>& board);
  bool isValidMove(int x, int y) const override;
};

#endif