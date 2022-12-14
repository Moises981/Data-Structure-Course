#include <array.h>

void Init(struct Array *array) {
  array->size = ARRAY_SIZE;
  array->length = 0;
  array->arr = (int *)calloc(array->size, sizeof(int));
}

static void VerifySize(struct Array *array) {
  if (array->length >= array->size) {
    array->size *= ARRAY_MULT;
    Reserve(array, array->size);
  }
}

static void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Display(const struct Array *const array) {
  printf("\nArray : ");
  if (array->length > 0) {
    printf("[");
    for (int i = 0; i < array->length; i++) {
      printf("%i, ", array->arr[i]);
    }
    printf("\b\b]\n");
  } else {
    printf("[]");
  }
}

void Reserve(struct Array *array, int size) {
  array->arr = (int *)realloc(array->arr, sizeof(int) * size);
  for (int i = array->size; i < size; i++) {
    array->arr[i] = 0;
  }
  array->size = size;
}

void Append(struct Array *array, int item) {
  VerifySize(array);
  array->arr[array->length++] = item;
}

void Insert(struct Array *const array, int index, int item) {
  if (0 <= index && index <= array->length) {
    VerifySize(array);
    for (int i = array->length; i > index; i--) {
      array->arr[i] = array->arr[i - 1];
    }
    array->arr[index] = item;
    array->length++;
  }
}

void Delete(struct Array *const array, int index) {
  if (0 <= index && index <= array->length) {
    for (int i = index; i < array->length; i++) {
      array->arr[i] = array->arr[i + 1];
    }
    array->length--;
  }
}

int LinearSearch(const struct Array *const array, int item) {
  for (int i = 0; i < array->length; i++) {
    if (array->arr[i] == item) {
      Swap(&array->arr[i], &array->arr[0]);
      return i;
    }
  }
  return -1;
}

int BinarySearch(const struct Array *const array, int item) {
  int h = array->length - 1;
  int l = 0;
  int m;

  while (l <= h) {
    m = (h + l) / 2;
    if (array->arr[m] == item) {
      return m;
    } else if (array->arr[m] > item) {
      h = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

int Get(const struct Array *const array, int index) {
  if (index < 0 || index >= array->length)
    return -1;
  return array->arr[index];
}

void Set(struct Array *const array, int index, int item) {
  if (index < 0 || index >= array->length)
    return;
  array->arr[index] = item;
}

int Max(const struct Array *const array) {
  if (array->length > 0) {
    int max = array->arr[0];
    for (int i = 1; i < array->length; i++) {
      if (array->arr[i] > max) {
        max = array->arr[i];
      }
    }
    return max;
  }
  return -1;
}

int Min(const struct Array *const array) {
  if (array->length > 0) {
    int min = array->arr[0];
    for (int i = 1; i < array->length; i++) {
      if (array->arr[i] < min) {
        min = array->arr[i];
      }
    }
    return min;
  }
  return -1;
}

float Avg(const struct Array *const array) {
  return (float)Sum(array) / array->length;
}

int Sum(const struct Array *const array) {
  int sum = 0;
  for (int i = 0; i < array->length; i++) {
    sum += array->arr[i];
  }
  return sum;
}

void Reverse(struct Array *const array) {
  int j = array->length;
  for (int i = 0; i < j; i++, j--) {
    Swap(&array->arr[i], &array->arr[j]);
  }
}

void LeftShift(struct Array *const array) {
  for (int i = 0; i < array->length - 1; i++) {
    array->arr[i] = array->arr[i + 1];
  }
  array->arr[array->length - 1] = 0;
}

void RightShift(struct Array *const array) {
  for (int i = array->length - 1; i > 0; i--) {
    array->arr[i] = array->arr[i - 1];
  }
  array->arr[0] = 0;
}

void LeftRotate(struct Array *const array) {
  int temp = array->arr[0];
  LeftShift(array);
  array->arr[array->length - 1] = temp;
}

void RightRotate(struct Array *const array) {
  int temp = array->arr[array->length - 1];
  RightShift(array);
  array->arr[0] = temp;
}

int IsSorted(const struct Array *const array) {
  for (int i = 0; i < array->length - 1; i++) {
    if (array->arr[i] > array->arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void Rearrange(struct Array *const array) {
  int i = 0;
  int j = array->length - 1;
  while (i < j) {
    while (array->arr[i] < 0) {
      i++;
    }
    while (array->arr[j] >= 0) {
      j--;
    }
    if (i < j) {
      Swap(&array->arr[i], &array->arr[j]);
    }
  }
}

void InsertSort(struct Array *array, int item) {
  VerifySize(array);
  int i = array->length++;
  while (array->arr[i] > item) {
    array->arr[i] = array->arr[i - 1];
    i--;
  }
  array->arr[i + 1] = item;
}

struct Array MergeArray(const struct Array *const arr1,
                        const struct Array *const arr2) {
  struct Array buffer;
  Init(&buffer);
  Reserve(&buffer, arr1->length + arr2->length);

  int i, j, k;
  i = j = k = 0;

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      buffer.arr[k++] = arr1->arr[i++];
    } else {
      buffer.arr[k++] = arr2->arr[j++];
      i++;
    }
  }

  for (; i < arr1->length; i++) {
    buffer.arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    buffer.arr[k++] = arr2->arr[j];
  }

  buffer.length = k;

  return buffer;
}

struct Array ConcatenateArray(const struct Array *const array1,
                              const struct Array *const array2) {
  struct Array buffer;
  Init(&buffer);
  int size = array1->length + array2->length;

  Reserve(&buffer, size);
  buffer.length = size;

  int k = 0;
  for (int i = 0; i < array1->length; i++) {
    buffer.arr[k++] = array1->arr[i];
  }
  for (int i = 0; i < array2->length; i++) {
    buffer.arr[k++] = array2->arr[i];
  }
  return buffer;
}

void AppendArray(struct Array *base, struct Array *arr) {
  struct Array buffer = ConcatenateArray(base, arr);
  free(base->arr);
  CopyArray(&buffer, base);
}

void CopyArray(const struct Array *const from, struct Array *const to) {
  to->length = from->length;
  to->size = from->size;
  to->arr = (int *)malloc(sizeof(int) * from->size);
  for (int i = 0; i < from->length; i++) {
    to->arr[i] = from->arr[i];
  }
}

int CompareArray(const struct Array *const arr1,
                 const struct Array *const arr2) {
  if (arr1->length != arr2->length)
    return 0;

  for (int i = 0; i < arr1->length; i++) {
    if (arr1->arr[i] != arr2->arr[i]) {
      return 0;
    }
  }

  return 1;
}

struct Array Union(const struct Array *const arr1,
                   const struct Array *const arr2) {
  int i, j, k;
  i = j = k = 0;

  struct Array buffer;
  Init(&buffer);
  Reserve(&buffer, arr1->length + arr2->length);

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      buffer.arr[k++] = arr1->arr[i++];
    } else {
      buffer.arr[k++] = arr2->arr[j++];
      i++;
    }
  }

  for (; i < arr1->length; i++) {
    buffer.arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    buffer.arr[k++] = arr2->arr[j];
  }

  buffer.length = k;

  return buffer;
}

struct Array Intersection(const struct Array *const arr1,
                          const struct Array *const arr2) {
  int i = 0;
  int j = 0;
  int k = 0;
  struct Array buffer;
  Init(&buffer);
  Reserve(&buffer, arr1->length + arr2->length);
  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      i++;
    } else if (arr1->arr[i] > arr2->arr[j]) {
      j++;
    } else {
      buffer.arr[k++] = arr1->arr[i++];
      j++;
    }
  }

  buffer.length = k;
  return buffer;
}

struct Array Difference(const struct Array *const arr1,
                        const struct Array *arr2) {
  int i, j, k;
  i = j = k = 0;

  struct Array buffer;
  Init(&buffer);
  Reserve(&buffer, arr1->length + arr2->length);

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      buffer.arr[k++] = arr1->arr[i++];
    } else if (arr1->arr[i] > arr2->arr[j]) {
      buffer.arr[k++] = arr2->arr[j++];
    } else {
      i++;
      j++;
    }
  }

  for (; i < arr1->length; i++) {
    buffer.arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    buffer.arr[k++] = arr2->arr[j];
  }

  buffer.length = k;

  return buffer;
}

int FindMissingItem(const struct Array const *arr) {
  int offset = arr->arr[0];
  for (int i = 0; i < arr->length; i++) {
    if (arr->arr[i] > offset++) {
      return i;
    }
  }
}

int FindMissingItemGauss(const struct Array const *arr) {
  int sum = arr->length * (arr->length + 1) * 0.5f;
  return sum - Sum(arr);
}

struct Array FindMultipleItems(const struct Array const *arr) {
  struct Array arrItems;
  Init(&arrItems);
  int offset = arr->arr[0];
  for (int i = 0; i < arr->length; i++) {
    int res = arr->arr[i] - offset++;
    for (int j = 0; j < res; j++) {
      Append(&arrItems, i + j);
    }
  }
  return arrItems;
}

struct Array FindMultipleItemsHash(const struct Array const *arr) {
  struct Array arr_items;
  struct Array arr_hash;
  Init(&arr_items);
  Init(&arr_hash);

  int h = Max(arr);
  int l = Min(arr);

  arr_hash.length = h + l;
  Reserve(&arr_hash, arr_hash.length);

  for (int i = 0; i < arr->length; i++) {
    arr_hash.arr[arr->arr[i] - l]++;
  }

  for (int i = 0; i < arr_hash.length; i++) {
    if (!arr_hash.arr[i]) {
      Append(&arr_items, i + l);
    }
  }

  return arr_items;
}

struct Array FindDuplicateItems(const struct Array const *arr) {
  struct Array arr_items;
  Init(&arr_items);

  int lastDuplicated = arr->arr[0];

  for (int i = 0; i < arr->length - 1; i++) {
    if (arr->arr[i] == arr->arr[i + 1]) {
      lastDuplicated = arr->arr[i];
      Append(&arr_items, lastDuplicated);
    }
    while (arr->arr[i] == arr->arr[i + 1]) {
      i++;
    }
  }

  return arr_items;
}

struct Array FindDuplicateItemsHash(const struct Array const *arr) {
  struct Array arr_items;
  struct Array arr_hash;
  Init(&arr_items);
  Init(&arr_hash);

  int h = Max(arr);
  int l = Min(arr);

  arr_hash.length = h + l;
  Reserve(&arr_hash, arr_hash.length);

  for (int i = 0; i < arr->length; i++) {
    arr_hash.arr[arr->arr[i] - l]++;
  }

  for (int i = 0; i < arr_hash.length; i++) {
    if (arr_hash.arr[i] > 1) {
      Append(&arr_items, i + l);
    }
  }

  return arr_items;
}

struct Array FindDuplicateItemsUnsorted(const struct Array *const arr) {
  struct Array arr_items;
  struct Array arr_data;
  Init(&arr_items);
  Init(&arr_data);
  CopyArray(arr, &arr_data);

  for (int i = 0; i < arr_data.length; i++) {
    int count = 0;
    if (arr_data.arr[i] != -1) {
      for (int j = i + 1; j < arr_data.length; j++) {
        if (arr_data.arr[i] == arr_data.arr[j]) {
          arr_data.arr[j] = -1;
          count++;
        }
      }
      if (count > 0) {
        Append(&arr_items, arr_data.arr[i]);
      }
    }
  }

  return arr_items;
}

struct Array FindItemsThatSum(const struct Array *const arr, int sum) {
  struct Array arr_items;
  Init(&arr_items);

  for (int i = 0; i < arr->length; i++) {
    for (int j = i + 1; j < arr->length; j++) {
      if (arr->arr[j] + arr->arr[i] == sum) {
        Append(&arr_items, arr->arr[i]);
        Append(&arr_items, arr->arr[j]);
        return arr_items;
      }
    }
  }

  return arr_items;
}

struct Array FindItemsThatSumHash(const struct Array *const arr, int sum) {
  struct Array arr_items;
  struct Array arr_hash;
  Init(&arr_items);
  Init(&arr_hash);

  int h = Max(arr);
  int l = Min(arr);

  arr_hash.length = h + l;
  Reserve(&arr_hash, arr_hash.length);

  for (int i = 0; i < arr->length; i++) {
    arr_hash.arr[arr->arr[i] - l]++;
  }

  for (int i = 0; i < arr->length; i++) {
    if (arr_hash.arr[sum - arr->arr[i]] > 0) {
      Append(&arr_items, arr->arr[i]);
      Append(&arr_items, sum - arr->arr[i]);
      return arr_items;
    }
  }

  return arr_items;
}

struct Array FindItemsThatSumSorted(const struct Array *const arr, int sum) {
  struct Array arr_items;
  Init(&arr_items);

  int j = arr->length - 1;
  int i = 0;
  while (i < j) {
    int total = arr->arr[i] + arr->arr[j];
    if (total > sum) {
      j--;
    } else if (total < sum) {
      i++;
    } else {
      Append(&arr_items, arr->arr[i]);
      Append(&arr_items, arr->arr[j]);
      return arr_items;
    }
  }

  return arr_items;
}

struct Array FindMaxAndMin(const struct Array *const arr) {
  int max = arr->arr[0];
  int min = max;

  for (int i = 1; i < arr->length; i++) {
    if (arr->arr[i] > max) {
      max = arr->arr[i];
    }
    if (arr->arr[i] < min) {
      min = arr->arr[i];
    }
  }
}
