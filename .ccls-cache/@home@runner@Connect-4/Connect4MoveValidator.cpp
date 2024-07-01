// including the header files
#include "Connect4MoveValidator.h"
#include "GameBoard.h"

using namespace std;

// initalizing the game board
Connect4MoveValidator::Connect4MoveValidator(const vector<vector<char>> &board)
    : board(board) {}

// check move validity 
bool Connect4MoveValidator::isValidMove(int x, int y) const {
  return y == 0 && x >= 1 && x <= board[0].size() && board[0][x - 1] == ' ';
}