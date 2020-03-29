#include <iostream>

// #include "math/Doubler.hpp"
// #include "math/Halver.hpp"

#include "printing/Hello.hpp"
#include "printing/Moo.hpp"

using namespace std;

int main() {
  // int initialValue = 12;

  // cout << "Initial value: " << initialValue << endl;
  // cout << "Doubled: " << Doubler(initialValue).doubled() << endl;
  // cout << "Halved: " << Halver(initialValue).halved() << endl;

  cout << std::endl;
  Hello::printHello();
  Moo::printMoo();

  return 0;
}