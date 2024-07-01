#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"
#include "ScoreManager.h"
#include <string>

using namespace std;

class Game {
private:
  Player player1, player2;
  GameBoard board;
  Player *currentPlayer;
  ScoreManager &scoreManager;

public:
  Game(const string &player1Name, const string &player2Name,
       ScoreManager &scoreMgr);
  void startGame();
  void displayMenu();
  void displayRules();
  void switchPlayer();
  void playTurn();
  void checkGameState();
  void endGame();
  void playGame();
  void displayPlayerScore(const string &playerName);
};

#endif