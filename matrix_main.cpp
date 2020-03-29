#include <iostream>

#include "math/Doubler.hpp"
#include "math/Halver.hpp"

#include "printing/Hello.hpp"
#include "printing/Moo.hpp"

#include "matrices/Matrix.hpp"

using namespace std;

void printMatrix(Matrix<int>&& mat) {
  for (size_t i = 0; i < mat.rows(); ++i) {
    for (size_t j = 0; j < mat.cols(); ++j) {
      cout << mat[i][j] << '\t';
    }
    cout << endl;
  }
}

int main() {
  int initialValue = 12;
  Doubler dbl(initialValue);

  cout << "Initial value: " << initialValue << endl;
  cout << "Doubled: " << dbl.doubled() << endl;
  cout << "Halved: " << Halver(initialValue).halved() << endl;

  cout << std::endl;
  Hello::printHello();
  Moo::printMoo();

  printMatrix(dbl.asMatrix(2, 3));

  return 0;
}