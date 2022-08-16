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
    Reserve(&buffer, size_ * ARRAY_MULT);
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
