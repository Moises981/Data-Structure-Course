#include <array.hpp>
#include <gtest/gtest.h>

struct ArrayTest : public testing::Test {
  Array<float> *arr;
  Array<float> *arr1;
  Array<float> *arr2;
  void SetUp() override {
    // Empty
    arr = new Array<float>();
    // Fill with 0-6 (1)
    arr1 = new Array<float>();
    for (int i = 0; i < 6; i++) {
      arr1->Append(i);
    }
    // Fill with 0-12 (2)
    arr2 = new Array<float>();
    for (int i = 0; i < 6; i++) {
      arr2->Append(i * 2);
    }
  }
  void TearDown() override {
    delete arr;
    delete arr1;
    delete arr2;
  }
};

TEST_F(ArrayTest, BasicOperations) {
  arr->Append(5);
  EXPECT_EQ(arr->Get(0), 5);

  arr->Insert(0, 2);
  EXPECT_EQ(arr->Get(0), 2);
}

TEST_F(ArrayTest, SearchOperations) {
  EXPECT_EQ(arr1->BinarySearch(4), 4);
  EXPECT_EQ(arr1->BinarySearch(40), -1);

  EXPECT_EQ(arr1->LinearSearch(4), 4);
  EXPECT_EQ(arr1->LinearSearch(40), -1);
}

TEST_F(ArrayTest, MathOperations) {
  EXPECT_EQ(arr1->Min(), 0);
  EXPECT_EQ(arr1->Max(), 5);
  EXPECT_EQ(arr1->Sum(), 15);
  EXPECT_EQ(arr1->Avg(), 2.5f);
}

TEST_F(ArrayTest, MoveOperations) {
  arr1->LeftShift();
  EXPECT_EQ(arr1->Get(arr1->length() - 1), 0);

  arr1->RightShift();
  EXPECT_EQ(arr1->Get(0), 0);

  arr1->LeftRotate();
  EXPECT_EQ(arr1->Get(0), 1);

  arr1->RightRotate();
  EXPECT_EQ(arr1->Get(0), 0);

  arr1->Reverse();
  EXPECT_EQ(arr1->Get(0), 5);

  arr1->Append(-4);
  arr1->Append(-12);
  arr1->Rearrange();
  EXPECT_LT(arr1->Get(0), 0);
  EXPECT_GE(arr1->Get(arr1->length() - 1), 0);
}

TEST_F(ArrayTest, CombinationOperations) {
  arr1->Copy(*arr);
  EXPECT_TRUE(arr->Compare(*arr1));

  Array<float> arrMerged = arr->Merge(*arr2);
  EXPECT_EQ(arrMerged.length(), 9);

  Array<float> arrConcatenated = arr->Concatenate(*arr2);
  EXPECT_EQ(arrConcatenated.length(), 12);

  arr->Append(arrConcatenated);
  EXPECT_EQ(arr->length(), 18);
}

TEST_F(ArrayTest, SetOperations) {
  Array<float> arrIntersection = arr1->Intersection(*arr2);
  EXPECT_EQ(arrIntersection.length(), 3);

  Array<float> arrUnion = arr1->Union(*arr2);
  EXPECT_EQ(arrUnion.length(), 9);

  Array<float> arrDifference = arr1->Difference(*arr2);
  EXPECT_EQ(arrDifference.length(), 6);
}

TEST_F(ArrayTest, SortOperations) {
  EXPECT_TRUE(arr1->IsSorted());

  arr1->InsertSort(-2);

  EXPECT_EQ(arr1->Get(0), -2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}