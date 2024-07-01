#include "Disc.h"
#include <iostream>

using namespace std;

Disc::Disc(int x, int y, char symbol) : GameEntity(x, y), symbol(symbol) {}

void Disc::render() const { cout << symbol; }

char Disc::getSymbol() const { return symbol; }