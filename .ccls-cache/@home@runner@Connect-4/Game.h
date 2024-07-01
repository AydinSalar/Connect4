#ifndef GAME_H
#define GAME_H

// header files
#include "GameBoard.h"
#include "Player.h"
#include "ScoreManager.h"
#include <string>

using namespace std;

// class definition 
class Game {
private:
  // variables of different types
  Player player1, player2;
  GameBoard board;
  Player *currentPlayer;
  ScoreManager &scoreManager;

public:
  // constructor
  Game(const string &player1Name, const string &player2Name,
       ScoreManager &scoreMgr);

  // functions for the game
  void startGame();
  void switchPlayer();
  void playTurn();
  void checkGameState();
  void endGame();
  void playGame();
  void displayPlayerScore(const string &playerName);
};

#endif