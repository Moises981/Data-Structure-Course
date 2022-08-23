#pragma once
#include <iostream>

namespace Matrix {
class MatrixReadonlyException : std::exception {
  const char *what() const throw() {
    return "Some elements in matrix are readonly";
  }
};
}; // namespace Matrix