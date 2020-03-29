#include "math/Halver.hpp"

Halver::Halver(const int num)
  : num(num)
{ }

Halver::~Halver() { }

int Halver::halved() { return num / 2; }