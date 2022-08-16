#include <array.h>
#include <unity/unity.h>

struct Array *array;
struct Array *array1;
struct Array *array2;

void insert_array(void) {
  Insert(array, 0, 14);
  Insert(array, 2, 5);
  Insert(array, 4, 1);
  TEST_ASSERT_EQUAL_INT32(14, array->arr[0]);
  TEST_ASSERT_EQUAL_INT32(1, array->arr[4]);
}

void linear_search_array(void) {
  TEST_ASSERT_EQUAL_INT32(1, LinearSearch(array1, 1));
  TEST_ASSERT_EQUAL_INT32(5, LinearSearch(array1, 5));
}

void binary_search_array(void) {
  TEST_ASSERT_EQUAL_INT32(3, BinarySearch(array1, 3));
  TEST_ASSERT_EQUAL_INT32(-1, BinarySearch(array1, 10));
}

void math_array(void) {
  TEST_ASSERT_EQUAL_INT32(0, Min(array1));
  TEST_ASSERT_EQUAL_INT32(5, Max(array1));
  TEST_ASSERT_EQUAL_INT32(15, Sum(array1));
  TEST_ASSERT_EQUAL_FLOAT(2.5, Avg(array1));
}

void move_array(void) {
  LeftShift(array1);
  TEST_ASSERT_EQUAL_INT32(1, array1->arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array1->arr[array1->length - 1]);
  RightShift(array1);
  TEST_ASSERT_EQUAL_INT32(0, array1->arr[0]);
  TEST_ASSERT_EQUAL_INT32(5, array1->arr[array1->length - 1]);

  LeftRotate(array1);
  TEST_ASSERT_EQUAL_INT32(1, array1->arr[0]);
  TEST_ASSERT_EQUAL_INT32(0, array1->arr[array->length - 1]);
  RightRotate(array1);
  TEST_ASSERT_EQUAL_INT32(0, array1->arr[0]);
  TEST_ASSERT_EQUAL_INT32(5, array1->arr[array->length - 1]);
}

void sort_array(void) {

  TEST_ASSERT_EQUAL_INT32(5, array1->arr[array1->length - 1]);

  TEST_ASSERT_TRUE(IsSorted(array1));

  Set(array1, 0, -10);
  Set(array1, 4, -5);

  TEST_ASSERT_FALSE(IsSorted(array1));

  Rearrange(array1);

  TEST_ASSERT_EQUAL_INT32(-10, array1->arr[0]);
  TEST_ASSERT_EQUAL_INT32(-5, array1->arr[1]);
}

void merge_array(void) {

  struct Array array_merged = MergeArray(array1, array2);

  TEST_ASSERT_EQUAL_INT32(array_merged.length, 9);

  struct Array array_concatenated = ConcatenateArray(array1, array2);

  TEST_ASSERT_EQUAL_INT32(array_concatenated.length, 12);

  AppendArray(array1, array2);

  TEST_ASSERT_EQUAL_INT32(array_concatenated.length, 12);
}

void set_operations_array(void) {

  struct Array intersectArray = Intersection(array1, array2);
  TEST_ASSERT_EQUAL_INT32(3, intersectArray.length);

  struct Array unitedArray = Union(array1, array2);
  TEST_ASSERT_EQUAL_INT32(9, unitedArray.length);
}

void setUp(void) {
  array = (struct Array *)malloc(sizeof(struct Array));
  array1 = (struct Array *)malloc(sizeof(struct Array));
  array2 = (struct Array *)malloc(sizeof(struct Array));
  Init(array);
  Init(array1);
  Init(array2);

  for (int i = 0; i < 6; i++) {
    Append(array1, i);
  }

  for (int i = 0; i < 6; i++) {
    Append(array2, i * 2);
  }
}

void tearDown(void) {
  free(array->arr);
  free(array);
  free(array1->arr);
  free(array1);
  free(array2->arr);
  free(array2);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(insert_array);
  RUN_TEST(linear_search_array);
  RUN_TEST(binary_search_array);
  RUN_TEST(math_array);
  RUN_TEST(move_array);
  RUN_TEST(sort_array);
  RUN_TEST(merge_array);
  RUN_TEST(set_operations_array);
  return UNITY_END();
}