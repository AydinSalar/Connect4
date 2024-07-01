#ifndef SCORE_H
#define SCORE_H

#include <string>

struct Score {
  int wins;
  int losses;
  int draws;

  Score() : wins(0), losses(0), draws(0) {}
  Score(int w, int l, int d) : wins(w), losses(l), draws(d) {}
};

#endif