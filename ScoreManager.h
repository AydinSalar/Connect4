#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include "Score.h"
#include <map>
#include <string>

using namespace std;

// class definition
class ScoreManager {
private:
  // map variable to manage the scores
  map<string, Score> scores;

public:
  // constructor
  ScoreManager();
  ~ScoreManager();

  // functions managing the scores
  void updateScore(const string &playerName, bool win, bool draw);
  void readScoresFromFile(const string &filename);
  void writeScoresToFile(const string &filename);
  Score getScore(const string &playerName) const;
  void updatePlayerName(const string &oldName, const string &newName);
  void resetScores(const string &player1Name, const string &player2Name);
};

#endif