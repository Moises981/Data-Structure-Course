#include <array.hpp>
#include <gtest/gtest.h>

struct ArrayTest : public testing::Test {
  Array *arr;
  void SetUp() override { arr = new Array(); }
  void TearDown() override { delete arr; }
};

TEST_F(ArrayTest, BasicOperations) {
  arr->Append(5);
  EXPECT_EQ(arr->Get(0), 5);

  arr->Insert(0, 2);
  EXPECT_EQ(arr->Get(0), 2);
}

TEST_F(ArrayTest, SearchOperations) {

  for (int i = 0; i < 6; i++) {
    arr->Append(i);
  }

  EXPECT_EQ(arr->BinarySearch(4), 4);
  EXPECT_EQ(arr->BinarySearch(40), -1);

  EXPECT_EQ(arr->LinearSearch(4), 4);
  EXPECT_EQ(arr->LinearSearch(40), -1);
}

TEST_F(ArrayTest, MathOperations) {
  for (int i = 0; i < 6; i++) {
    arr->Append(i);
  }
  EXPECT_EQ(arr->Min(), 0);
  EXPECT_EQ(arr->Max(), 5);
  EXPECT_EQ(arr->Sum(), 15);
  EXPECT_EQ(arr->Avg(), 2.5f);
}

TEST_F(ArrayTest, MoveOperations) {
  for (int i = 0; i < 6; i++) {
    arr->Append(i);
  }

  arr->LeftShift();
  EXPECT_EQ(arr->Get(arr->length() - 1), 0);

  arr->RightShift();
  EXPECT_EQ(arr->Get(0), 0);

  arr->LeftRotate();
  EXPECT_EQ(arr->Get(0), 1);

  arr->RightRotate();
  EXPECT_EQ(arr->Get(0), 0);

  arr->Reverse();
  EXPECT_EQ(arr->Get(0), 5);

  arr->Append(-4);
  arr->Append(-12);
  arr->Rearrange();
}

TEST_F(ArrayTest, SortOperations) {
  for (int i = 0; i < 6; i++) {
    arr->Append(i);
  }

  EXPECT_TRUE(arr->IsSorted());

  arr->InsertSort(-2);

  EXPECT_EQ(arr->Get(0), -2);
}

TEST_F(ArrayTest, MergeOperations) {
  for (int i = 0; i < 6; i++) {
    arr->Append(i);
  }

  EXPECT_TRUE(arr->IsSorted());

  arr->InsertSort(-2);

  EXPECT_EQ(arr->Get(0), -2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}