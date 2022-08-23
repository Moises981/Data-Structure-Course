#include <iostream>
#include <matrix/base.hpp>

namespace Matrix {
void Matrix::Display() const {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << (*this)(i, j) << " ";
    }
    std::cout << "\b\n";
  }
}
} // namespace Matrix