#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

class MoveValidator{
public:
  virtual bool isValidMove(int x, int y) const = 0;
  virtual ~MoveValidator() = default;
};

#endif