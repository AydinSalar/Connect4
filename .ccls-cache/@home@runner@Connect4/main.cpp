#include "Game.h"
#include "ScoreManager.h"
#include <iostream>
#include <string>

string getPlayerName(const string &prompt) {
  cout << prompt;
  string name;
  getline(cin, name);
  return name;
}

int main() {

  cout << "Welcome to Connect 4!\n";

  string player1Name = getPlayerName("Player 1, please enter your name: ");
  string player2Name = getPlayerName("Player 2, please enter your name: ");

  ScoreManager scoreManager;
  scoreManager.resetScores(player1Name, player2Name);

  Game game(player1Name, player2Name, scoreManager);
  game.startGame();

  return 0;
}