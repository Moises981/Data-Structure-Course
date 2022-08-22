#include <iostream>

namespace Matrix {
class DiagonalReadonlyException : std::exception {
  const char *what() const throw() {
    return "Non diagonal elements are readonly";
  }
};
}; // namespace Matrix