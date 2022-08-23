#pragma once
#include <matrix/base.hpp>
#include <matrix/exceptions.hpp>

namespace Matrix {
class Triangular : public Matrix {
protected:
  int *matrix;

public:
  Triangular(int size) {
    int length = (size * (size + 1)) / 2;
    rows_ = size;
    cols_ = size;
    matrix = new int[length]();
  }
  ~Triangular() { delete[] matrix; }
  virtual int operator()(int i, int j) const = 0;
  virtual int &operator()(int i, int j) = 0;
};

class LowerTriangular : public virtual Triangular {
public:
  LowerTriangular(int size) : Triangular(size) {}
  int operator()(int i, int j) const;
  int &operator()(int i, int j);
};

class UpperTriangular : public virtual Triangular {
public:
  UpperTriangular(int size) : Triangular(size) {}
  int operator()(int i, int j) const;
  int &operator()(int i, int j);
};

class Toeplitz : public Matrix {
  int *matrix;

public:
  Toeplitz(int size) {
    rows_ = size;
    cols_ = size;
    matrix = new int[2 * size - 1]();
  }
  int operator()(int i, int j) const;
  int &operator()(int i, int j);
};
} // namespace Matrix