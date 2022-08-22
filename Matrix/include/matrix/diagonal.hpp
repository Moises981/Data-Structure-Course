#include <iostream>
#include <matrix/base.hpp>
#include <matrix/exceptions.hpp>

namespace Matrix {
class Diagonal : public Matrix {
private:
  int *matrix;
  int size;

public:
  Diagonal(int size) {
    rows_ = size;
    matrix = new int[size];
  }
  ~Diagonal() { delete matrix; }

  int operator()(int i, int j) const override {
    if (i == j) {
      return matrix[i];
    }
    return 0;
  }

  int &operator()(int i, int j) override {
    if (i == j) {
      return matrix[i];
    }
    throw DiagonalReadonlyException();
  }

  void Display() const override {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < rows_; j++) {
        std::cout << (*this)(i, j) << " ";
      }
      std::cout << "\b\n";
    }
  }
};
} // namespace Matrix
