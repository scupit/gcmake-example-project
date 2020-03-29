#include <iostream>

#include "math/Doubler.hpp"
#include "math/Halver.hpp"

#include "matrices/Matrix.hpp"

#include "QuickHeader.hpp"

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
  printQuick();

  printMatrix(dbl.asMatrix(2, 3));

  return 0;
}