// header file
#include "Disc.h"

// iostream library
#include <iostream>

using namespace std;

// default constructor to initialize the data members
Disc::Disc(int x, int y, char symbol) : GameEntity(x, y), symbol(symbol) {}

// destructor to render the symbol
void Disc::render() const { cout << symbol; }

// function to move the disc
char Disc::getSymbol() const { return symbol; }