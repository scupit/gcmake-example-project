#include <iostream>

#include "math/Doubler.hpp"
#include "math/Halver.hpp"

#include "printing/Hello.hpp"
#include "printing/Moo.hpp"

#include "QuickHeader.hpp"

using namespace std;

int main() {
  int initialValue = 12;

  cout << "Initial value: " << initialValue << endl
  << "Doubled: " << Doubler(initialValue).doubled() << endl
  << "Halved: " << Halver(initialValue).halved() << endl;

  cout << std::endl;
  Hello::printHello();
  Moo::printMoo();

  printQuick();

  return 0;
}