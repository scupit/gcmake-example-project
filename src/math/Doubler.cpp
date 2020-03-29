#include "math/Doubler.hpp"

Doubler::Doubler(const int num)
  : num(num)
{ }

Doubler::~Doubler() { }

int Doubler::doubled() { return num * 2; }