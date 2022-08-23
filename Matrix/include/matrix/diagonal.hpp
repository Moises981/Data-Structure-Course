#pragma once
#include <iostream>
#include <matrix/base.hpp>
#include <matrix/exceptions.hpp>

namespace Matrix {
class Diagonal : public Matrix {
private:
  int *matrix;

public:
  Diagonal(int size) {
    rows_ = size;
    cols_ = size;
    matrix = new int[size]();
  }
  ~Diagonal() { delete[] matrix; }

  int operator()(int i, int j) const override;
  int &operator()(int i, int j) override;
};

class Symmetric : public Matrix {
private:
  int *matrix;

public:
  Symmetric(int size) {
    rows_ = size;
    cols_ = size;
    matrix = new int[size]();
  }
  ~Symmetric() { delete[] matrix; }
  int operator()(int i, int j) const override;
  int &operator()(int i, int j) override;
};

class Tridiagonal : public Matrix {
private:
  int *matrix;

public:
  Tridiagonal(int size) {
    int length = 3 * size - 2;
    rows_ = size;
    cols_ = size;
    matrix = new int[length]();
  }
  ~Tridiagonal() { delete[] matrix; }

  int operator()(int i, int j) const override;
  int &operator()(int i, int j) override;
};

} // namespace Matrix
