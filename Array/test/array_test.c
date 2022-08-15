#include <array.h>
#include <unity/unity.h>

struct Array array;

void init_array(void) {
  Init(&array);
  TEST_ASSERT_EQUAL_INT32(ARRAY_SIZE, array.size);
  TEST_ASSERT_EQUAL_INT32(0, array.length);
  TEST_ASSERT_NOT_NULL(array.arr);
}

void append_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i * 10);
  }
  TEST_ASSERT_EQUAL_INT32(ARRAY_SIZE * 3, array.size);
}

void insert_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i * 10);
  }
  Insert(&array, 0, 14);
  Insert(&array, 3, 5);
  Insert(&array, 6, 1);
  TEST_ASSERT_EQUAL_INT32(14, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(ARRAY_SIZE * 2 + 3, array.length);
}

void linear_search_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i * 10);
  }
  TEST_ASSERT_EQUAL_INT32(1, LinearSearch(&array, 10));
  TEST_ASSERT_EQUAL_INT32(5, LinearSearch(&array, 50));
}

void binary_search_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i);
  }
  TEST_ASSERT_EQUAL_INT32(3, BinarySearch(&array, 3));
  TEST_ASSERT_EQUAL_INT32(-1, BinarySearch(&array, 50));
}

void math_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i);
  }
  TEST_ASSERT_EQUAL_INT32(0, Min(&array));
  TEST_ASSERT_EQUAL_INT32(5, Max(&array));
  TEST_ASSERT_EQUAL_INT32(15, Sum(&array));
  TEST_ASSERT_EQUAL_FLOAT(2.5, Avg(&array));
}

void shift_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i);
  }
  LeftShift(&array);
  TEST_ASSERT_EQUAL_INT32(1, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array.arr[array.length - 1]);
  RightShift(&array);
  TEST_ASSERT_EQUAL_INT32(0, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(5, array.arr[array.length - 1]);
}

void rotate_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i);
  }
  LeftRotate(&array);
  TEST_ASSERT_EQUAL_INT32(1, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array.arr[array.length - 1]);
  RightRotate(&array);
  TEST_ASSERT_EQUAL_INT32(0, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(5, array.arr[array.length - 1]);
}

void sort_array(void) {
  Init(&array);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array, i);
  }

  InsertSort(&array, 6);

  TEST_ASSERT_EQUAL_INT32(6, array.arr[array.length - 1]);

  TEST_ASSERT_TRUE(IsSorted(&array));

  Set(&array, 0, -10);
  Set(&array, 4, -5);

  TEST_ASSERT_FALSE(IsSorted(&array));

  Rearrange(&array);

  TEST_ASSERT_EQUAL_INT32(-10, array.arr[0]);
  TEST_ASSERT_EQUAL_INT32(-5, array.arr[1]);
}

void merge_array(void) {
  struct Array array1;
  struct Array array2;
  Init(&array1);
  Init(&array2);
  for (int i = 0; i < ARRAY_SIZE * 2; i++) {
    Append(&array1, i);
    Append(&array2, i * 3);
  }
  struct Array *array_merged = MergeArray(&array1, &array2);

  TEST_ASSERT_EQUAL_INT32(0, array_merged->arr[0]);
  TEST_ASSERT_EQUAL_INT32(15, array_merged->arr[array_merged->length - 1]);

  struct Array *array_concatenated = ConcatenateArray(&array1, &array2);

  TEST_ASSERT_EQUAL_INT32(0, array_concatenated->arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array_concatenated->arr[6]);

  AppendArray(&array1, &array2);

  TEST_ASSERT_EQUAL_INT32(0, array1.arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array1.arr[6]);

  TEST_ASSERT_TRUE(CompareArray(&array1, &array1));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(init_array);
  RUN_TEST(append_array);
  RUN_TEST(insert_array);
  RUN_TEST(linear_search_array);
  RUN_TEST(binary_search_array);
  RUN_TEST(math_array);
  RUN_TEST(shift_array);
  RUN_TEST(rotate_array);
  RUN_TEST(sort_array);
  RUN_TEST(merge_array);
  return UNITY_END();
}