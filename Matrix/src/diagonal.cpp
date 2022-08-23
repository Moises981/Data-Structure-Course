#include <matrix/diagonal.hpp>

namespace Matrix {
int Diagonal::operator()(int i, int j) const {
  if (j == i) {
    return matrix[i];
  }
  return 0;
}

int &Diagonal::operator()(int i, int j) {
  if (j == i) {
    return matrix[i];
  }
  throw MatrixReadonlyException();
}

int Symmetric::operator()(int i, int j) const {
  if (i > j) {
    return matrix[j];
  } else {
    return matrix[i];
  }
}

int &Symmetric::operator()(int i, int j) {
  if (j == i) {
    return matrix[i];
  }
  throw MatrixReadonlyException();
}

int Tridiagonal::operator()(int i, int j) const {
  switch (i - j) {
  case 0:
    return matrix[cols_ - 1 + i];
  case 1:
    return matrix[2 * cols_ - 1 + j];
  case -1:
    return matrix[i];
  default:
    return 0;
  }
}

int &Tridiagonal::operator()(int i, int j) {
 switch (i - j) {
  case 0:
    return matrix[cols_ - 1 + i];
  case 1:
    return matrix[2 * cols_ - 1 + j];
  case -1:
    return matrix[i];
  }
  throw MatrixReadonlyException();
}

} // namespace Matrix
