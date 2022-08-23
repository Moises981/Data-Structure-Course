#include <matrix/triangular.hpp>

namespace Matrix {
int LowerTriangular::operator()(int i, int j) const {
  if (j <= i) {
    return matrix[(i * (i + 1)) / 2 + j];
  }
  return 0;
}

int &LowerTriangular::operator()(int i, int j) {
  if (j <= i) {
    return matrix[(i * (i + 1)) / 2 + j];
  }
  throw MatrixReadonlyException();
}

int UpperTriangular::operator()(int i, int j) const {
  if (j >= i) {
    return matrix[i * rows_ - (i * (i - 1)) / 2 + (j - i)];
  }
  return 0;
}

int &UpperTriangular::operator()(int i, int j) {
  if (j >= i) {
    return matrix[i * rows_ - (i * (i - 1)) / 2 + (j - i)];
  }
  throw MatrixReadonlyException();
}

int Toeplitz::operator()(int i, int j) const {
  int m = j - i;
  if (m >= 0) {
    return matrix[m];
  } else {
    return matrix[cols_ - m - 1];
  }
}

int &Toeplitz::operator()(int i, int j) {
  int m = j - i;
  if (m >= 0) {
    return matrix[m];
  } else {
    return matrix[cols_ - m - 1];
  }
}
} // namespace Matrix
