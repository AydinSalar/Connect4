#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

// class definition
class MoveValidator {
public:
  // virtual 
  virtual bool isValidMove(int x, int y) const = 0;
  virtual ~MoveValidator() = default;
};

#endif