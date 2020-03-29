#include "math/Doubler.hpp"

Doubler::Doubler(const int num)
  : num(num)
{ }

Doubler::~Doubler() { }

int Doubler::doubled() { return num * 2; }
Matrix<int> Doubler::asMatrix(const size_t rows, const size_t cols) {
  Matrix<int> mat(rows, cols);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      mat[i][j] = num;
    }
  }
  return mat;
}