#pragma once
#include <stdio.h>

namespace Matrix {
class Matrix {
protected:
  int rows_;
  int cols_;

public:
  virtual ~Matrix() {}
  void Display() const;
  virtual int &operator()(int i, int j) = 0;
  virtual int operator()(int i, int j) const = 0;
};
} // namespace Matrix