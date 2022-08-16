#include <array.hpp>
#include <iostream>

void Array::Display() const {
  printf("\nArray : [");
  for (int i = 0; i < length_; i++) {
    printf("%i, ", arr_[i]);
  }
  printf("\b\b]\n");
}

void Array::VerifySize() {
  if (length_ >= size_) {
    int *buffer;
    size_ *= ARRAY_MULT;
    buffer = new int[size_];
    for (int i = 0; i < length_; i++) {
      buffer[i] = arr_[i];
    }
    delete arr_;
    arr_ = buffer;
  }
}

void Array::Append(int item) {
  VerifySize();
  arr_[length_++] = item;
}

void Array::Insert(int index, int item) {
  if (0 <= index && index < length_) {
    VerifySize();
    for (int i = length_; i > index; i--) {
      arr_[i] = arr_[i - 1];
    }
    arr_[index] = item;
    length_++;
  }
}

void Array::Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Array::LinearSearch(int item) {
  for (int i = 0; i < length_; i++) {
    if (item == arr_[i]) {
      Swap(&arr_[i], &arr_[0]);
      return i;
    }
  }
  return -1;
}

int Array::BinarySearch(int item) const {
  int h = length_ - 1;
  int l = 0;
  int m;
  while (l <= h) {
    m = (h + l) / 2;
    if (arr_[m] == item) {
      return m;
    } else if (arr_[m] > item) {
      h = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

int Array::Get(int index) const {
  if (0 <= index && index < length_) {
    return arr_[index];
  }
  return -1;
}

void Array::Set(int index, int item) {
  if (0 < index && index < length_) {
    arr_[index] = item;
  }
}

int Array::Max() const {
  int max = arr_[0];
  for (int i = 1; i < length_; i++) {
    if (arr_[i] > max) {
      max = arr_[i];
    }
  }
  return max;
}

int Array::Min() const {
  int min = arr_[0];
  for (int i = 1; i < length_; i++) {
    if (arr_[i] < min) {
      min = arr_[i];
    }
  }
  return min;
}

int Array::Sum() const {
  int sum = 0;
  for (int i = 0; i < length_; i++) {
    sum += arr_[i];
  }
  return sum;
}

void Array::Reverse() {
  for (int i = 0; i < length_ - i - 1; i++) {
    Swap(&arr_[i], &arr_[length_ - i - 1]);
  }
}

void Array::LeftShift() {
  for (int i = 0; i < length_ - 1; i++) {
    arr_[i] = arr_[i + 1];
  }
  arr_[length_ - 1] = 0;
}

void Array::RightShift() {
  for (int i = length_ - 1; i > 0; i--) {
    arr_[i] = arr_[i - 1];
  }
  arr_[0] = 0;
}

void Array::LeftRotate() {
  int temp = arr_[0];
  LeftShift();
  arr_[length_ - 1] = temp;
}

void Array::RightRotate() {
  int temp = arr_[length_ - 1];
  RightShift();
  arr_[0] = temp;
}

bool Array::IsSorted() const {
  for (int i = 0; i < length_ - 1; i++) {
    if (arr_[i] > arr_[i + 1]) {
      return false;
    }
  }
  return true;
}

void Array::InsertSort(int item) {
  VerifySize();
  int i = 0;
  while (arr_[i] < item) {
    i++;
  }
  Insert(i, item);
}

void Array::Rearrange() {
  int i = 0;
  int j = length_ - 1;
  while (i < j) {
    while (arr_[i] < 0)
      i++;
    while (arr_[j] >= 0)
      j--;
    if (i < j) {
      Swap(&arr_[i], &arr_[j]);
    }
  }
}

Array *Array::Merge(const Array &array) const {
  Array *buffer = new Array();
  buffer->Reserve(length_ + array.length_);
  int i, j, k;
  i = j = k = 0;

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer->arr_[k++] = arr_[i++];
    } else {
      buffer->arr_[k++] = array.arr_[j++];
      i++;
    }
  }

  for (; i < length_; i++) {
    buffer->arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer->arr_[k++] = array.arr_[j];
  }

  buffer->length_ = k;

  return buffer;
}

Array *Array::Concatenate(const Array &array) const {
  Array *buffer = new Array();
  buffer->Reserve(length_ + array.length_);
  int k = 0;
  for (int i = 0; i < length_; i++) {
    buffer->arr_[k++] = arr_[i];
  }
  for (int i = 0; i < array.length_; i++) {
    buffer->arr_[k++] = array.arr_[i];
  }
  buffer->length_ = k;
  return buffer;
}

void Array::Append(const Array &array) {
  Array *buffer = Concatenate(array);
  buffer->Copy(*this);
  delete buffer;
}

void Array::Copy(Array &array) const {
  array.length_ = length_;
  array.size_ = size_;
  delete array.arr_;
  array.arr_ = new int[size_];
  for (int i = 0; i < length_; i++) {
    array.arr_[i] = arr_[i];
  }
}

bool Array::Compare(const Array &array) const {
  if (length_ != array.length_)
    return false;

  for (int i = 0; i < array.length_; i++) {
    if (arr_[i] != array.arr_[i]) {
      return false;
    }
  }

  return true;
}

Array *Array::Union(const Array &array) {
  int i, j, k;
  i = j = k = 0;

  Array *buffer = new Array();
  buffer->Reserve(array.length_ + length_);

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer->arr_[k++] = arr_[i++];
    } else {
      buffer->arr_[k++] = array.arr_[j++];
      i++;
    }
  }

  for (; i < length_; i++) {
    buffer->arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer->arr_[k++] = array.arr_[j];
  }

  buffer->length_ = k;

  return buffer;
}

Array *Array::Intersection(const Array &array) {
  int i = 0;
  int j = 0;
  int k = 0;
  Array *buffer = new Array();
  buffer->Reserve(array.length_ + length_);
  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      i++;
    } else if (arr_[i] > array.arr_[j]) {
      j++;
    } else {
      buffer->arr_[k++] = arr_[i++];
      j++;
    }
  }

  buffer->length_ = k;
  return buffer;
}

Array *Array::Difference(const Array &array) {
  int i, j, k;
  i = j = k = 0;

  Array *buffer = new Array();
  buffer->Reserve(length_ + length_);

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer->arr_[k++] = arr_[i++];
    } else if (arr_[i] > array.arr_[j]) {
      buffer->arr_[k++] = array.arr_[j++];
    } else {
      i++;
      j++;
    }
  }

  for (; i < length_; i++) {
    buffer->arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer->arr_[k++] = array.arr_[j];
  }

  buffer->length_ = k;

  return buffer;
}