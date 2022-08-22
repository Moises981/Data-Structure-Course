#include <gtest/gtest.h>
#include <matrix/diagonal.hpp>

struct DiagonalTest : testing::Test {
  Matrix::Diagonal *matrix;

  void SetUp() override { matrix = new Matrix::Diagonal(5); }

  void TearDown() override { delete matrix; }
};

TEST_F(DiagonalTest, Display) {
  (*matrix)(0, 0) = 2;
  matrix->Display();
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}