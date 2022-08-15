#include <array.h>

void Init(struct Array *array) {
  array->size = ARRAY_SIZE;
  array->length = 0;
  array->arr = (int *)malloc(sizeof(int) * array->size);
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
  printf("\nArray : [");
  for (int i = 0; i < array->length; i++) {
    printf("%i, ", array->arr[i]);
  }
  printf("\b\b]\n");
}

void Reserve(struct Array *array, int size) {
  array->size = size;
  array->arr = (int *)realloc(array->arr, sizeof(int) * size);
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
  int h = array->length;
  int l = 0;
  int m;

  while (h != l) {
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
  for (int i = 0; j >= 0; i++, j--) {
    Swap(&array->arr[i], &array->arr[j]);
  }
}

void LeftShift(struct Array *const array) {
  for (int i = 1; i < array->length; i++) {
    Swap(&array->arr[i - 1], &array->arr[i]);
  }
  array->arr[array->length - 1] = 0;
}

void RightShift(struct Array *const array) {
  for (int i = array->length - 1; i >= 0; i--) {
    Swap(&array->arr[i - 1], &array->arr[i]);
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

struct Array *MergeArray(const struct Array *arr1, const struct Array *arr2) {
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  Init(arr3);
  Reserve(arr3, arr1->length + arr2->length);

  int i, j, k;
  i = j = k = 0;

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      arr3->arr[k++] = arr1->arr[i++];
    } else {
      arr3->arr[k++] = arr2->arr[j++];
    }
  }

  for (; i < arr1->length; i++) {
    arr3->arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    arr3->arr[k++] = arr2->arr[j];
  }

  arr3->length = arr1->length + arr2->length;

  return arr3;
}

struct Array *ConcatenateArray(const struct Array *array1,
                               const struct Array *array2) {
  struct Array *array3 = (struct Array *)malloc(sizeof(struct Array));
  Init(array3);
  int size = array1->length + array2->length;

  Reserve(array3, size);
  array3->length = size;

  int k = 0;
  for (int i = 0; i < array1->length; i++) {
    array3->arr[k++] = array1->arr[i];
  }
  for (int i = 0; i < array2->length; i++) {
    array3->arr[k++] = array2->arr[i];
  }
  return array3;
}

void AppendArray(struct Array *base, struct Array *arr) {
  struct Array *array3 = ConcatenateArray(base, arr);
  free(base->arr);
  CopyArray(array3, base);
  free(array3);
}

void CopyArray(struct Array *from, struct Array *to) {
  to->length = from->length;
  to->size = from->size;
  to->arr = (int *)malloc(sizeof(int) * from->size);
  *to->arr = *from->arr;
}

int CompareArray(struct Array *arr1, struct Array *arr2) {
  if (arr1->length != arr2->length)
    return 0;

  for (int i = 0; i < arr1->length; i++) {
    if (arr1->arr[i] != arr2->arr[i]) {
      return 0;
    }
  }

  return 1;
}

struct Array *Union(struct Array *arr1, struct Array *arr2) {
  int i, j, k;
  i = j = k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  Init(arr3);
  Reserve(arr3, arr1->length + arr2->length);

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      arr3->arr[k++] = arr1->arr[i++];
    } else {
      arr3->arr[k++] = arr2->arr[j++];
    }
  }

  for (; i < arr1->length; i++) {
    arr3->arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    arr3->arr[k++] = arr2->arr[j];
  }

  arr3->length = k;

  return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;
  struct Array *arr3 = NULL;
  Init(arr3);
  Reserve(arr3, arr1->length + arr2->length);
  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      i++;
    } else if (arr1->arr[i] > arr2->arr[j]) {
      j++;
    } else {
      arr3->arr[k++] = arr1->arr[i++];
      j++;
    }
  }

  arr3->length = k;
  return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2) {
  int i, j, k;
  i = j = k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  Init(arr3);
  Reserve(arr3, arr1->length + arr2->length);

  while (i < arr1->length && j < arr2->length) {
    if (arr1->arr[i] < arr2->arr[j]) {
      arr3->arr[k++] = arr1->arr[i++];
    } else if (arr1->arr[i] > arr2->arr[j]) {
      arr3->arr[k++] = arr2->arr[j++];
    } else {
      i++;
      j++;
    }
  }

  for (; i < arr1->length; i++) {
    arr3->arr[k++] = arr1->arr[i];
  }

  for (; j < arr2->length; j++) {
    arr3->arr[k++] = arr2->arr[j];
  }

  arr3->length = k;

  return arr3;
}