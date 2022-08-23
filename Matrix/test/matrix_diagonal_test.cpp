#include <gtest/gtest.h>
#include <matrix/diagonal.hpp>
#include <matrix/triangular.hpp>

struct DiagonalTest : testing::Test {
  Matrix::Diagonal *matrixDiagonal;
  Matrix::LowerTriangular *matrixLowerTriangular;
  Matrix::UpperTriangular *matrixUpperTriangular;
  Matrix::Symmetric *matrixSymmetric;
  Matrix::Tridiagonal *matrixTridiagonal;
  Matrix::Toeplitz *matrixToeplitz;

  void SetUp() override {
    matrixDiagonal = new Matrix::Diagonal(5);
    matrixLowerTriangular = new Matrix::LowerTriangular(5);
    matrixUpperTriangular = new Matrix::UpperTriangular(5);
    matrixSymmetric = new Matrix::Symmetric(5);
    matrixTridiagonal = new Matrix::Tridiagonal(5);
    matrixToeplitz = new Matrix::Toeplitz(5);
  }

  void TearDown() override {
    delete matrixDiagonal;
    delete matrixLowerTriangular;
    delete matrixUpperTriangular;
    delete matrixSymmetric;
    delete matrixTridiagonal;
    delete matrixToeplitz;
  }
};

TEST_F(DiagonalTest, Display) {
  // (*matrixDiagonal)(0, 0) = 2;
  // matrixDiagonal->Display();

  // (*matrixLowerTriangular)(0, 0) = 2;
  // matrixLowerTriangular->Display();

  (*matrixToeplitz)(0, 0) = 2;
  (*matrixToeplitz)(0, 1) = 3;
  (*matrixToeplitz)(0, 2) = 4;
  (*matrixToeplitz)(2, 0) = 8;
  // (*matrixTridiagonal)(1, 1) = 3;
  // (*matrixTridiagonal)(2, 2) = 4;
  // (*matrixTridiagonal)(3, 3) = 5;
  // (*matrixTridiagonal)(4, 4) = 7;
  // (*matrixTridiagonal)(0, 1) = 7;
  // (*matrixTridiagonal)(2, 1) = 9;
  // matrixUpperTriangular->Display();

  // matrixSymmetric->Display();

  // matrixTridiagonal->Display();

  matrixToeplitz->Display();
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}