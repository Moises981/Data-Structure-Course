#include <iostream>

#pragma once
#define ARRAY_SIZE 3
#define ARRAY_MULT 3

template <typename T> class Array {
private:
  int size_;
  int length_;
  T *arr_ = nullptr;

public:
  Array() : length_{0} { Reserve(ARRAY_SIZE); }
  ~Array() { delete arr_; }
  inline int length() { return length_; }
  void Display() const;
  void Append(T item);
  void Insert(int index, T item);
  void Delete(int index);
  int LinearSearch(int item);
  int BinarySearch(int item) const;
  int Get(int index) const;
  void Set(int index, T item);
  T Max() const;
  T Min() const;
  T Sum() const;
  float Avg() const { return (float)Sum() / length_; }
  void Reverse();
  void LeftShift();
  void RightShift();
  void LeftRotate();
  void RightRotate();
  bool IsSorted() const;
  void InsertSort(int item);
  void Rearrange();
  Array Merge(const Array &array) const;
  Array Concatenate(const Array &array) const;
  void Append(const Array &array);
  void Copy(Array &array) const;
  bool Compare(const Array &array) const;
  Array Union(const Array &array);
  Array Intersection(const Array &array);
  Array Difference(const Array &array);

private:
  inline void Swap(T *a, T *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  void VerifySize();
  inline void Reserve(int size) {
    delete arr_;
    size_ = size;
    arr_ = new T[size];
  }
};

template <typename T> void Array<T>::Display() const {
  std::cout << "\nArray : ";
  if (length_ > 0) {
    std::cout << "[";
    for (int i = 0; i < length_; i++) {
      std::cout << arr_[i] << ", ";
    }
    std::cout << "\b\b]\n";
  } else {
    std::cout << "[ ]";
  }
}

template <typename T> void Array<T>::Append(T item) {
  VerifySize();
  arr_[length_++] = item;
}

template <typename T> void Array<T>::Insert(int index, T item) {
  if (0 <= index && index < length_) {
    VerifySize();
    for (int i = length_; i > index; i--) {
      arr_[i] = arr_[i - 1];
    }
    arr_[index] = item;
    length_++;
  }
}

template <typename T> void Array<T>::Delete(int index) {
  if (0 <= index && index <= length_) {
    for (int i = length_; i > index; i--) {
      arr_[i] = arr_[i - 1];
    }
    length_--;
  }
}

template <typename T> int Array<T>::LinearSearch(int item) {
  for (int i = 0; i < length_; i++) {
    if (item == arr_[i]) {
      Swap(&arr_[i], &arr_[0]);
      return i;
    }
  }
  return -1;
}

template <typename T> int Array<T>::BinarySearch(int item) const {
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

template <typename T> void Array<T>::VerifySize() {
  if (length_ >= size_) {
    size_ *= ARRAY_MULT;
    T *buffer = new T[size_];
    for (int i = 0; i < length_; i++) {
      buffer[i] = arr_[i];
    }
    delete arr_;
    arr_ = buffer;
  }
}

template <typename T> int Array<T>::Get(int index) const {
  if (0 <= index && index < length_) {
    return arr_[index];
  }
  return -1;
}

template <typename T> void Array<T>::Set(int index, T item) {
  if (0 < index && index < length_) {
    arr_[index] = item;
  }
}

template <typename T> T Array<T>::Max() const {
  int max = arr_[0];
  for (int i = 1; i < length_; i++) {
    if (arr_[i] > max) {
      max = arr_[i];
    }
  }
  return max;
}

template <typename T> T Array<T>::Min() const {
  int min = arr_[0];
  for (int i = 1; i < length_; i++) {
    if (arr_[i] < min) {
      min = arr_[i];
    }
  }
  return min;
}

template <typename T> T Array<T>::Sum() const {
  int sum = 0;
  for (int i = 0; i < length_; i++) {
    sum += arr_[i];
  }
  return sum;
}

template <typename T> void Array<T>::Reverse() {
  for (int i = 0; i < length_ - i - 1; i++) {
    Swap(&arr_[i], &arr_[length_ - i - 1]);
  }
}

template <typename T> void Array<T>::LeftShift() {
  for (int i = 0; i < length_ - 1; i++) {
    arr_[i] = arr_[i + 1];
  }
  arr_[length_ - 1] = 0;
}

template <typename T> void Array<T>::RightShift() {
  for (int i = length_ - 1; i > 0; i--) {
    arr_[i] = arr_[i - 1];
  }
  arr_[0] = 0;
}

template <typename T> void Array<T>::LeftRotate() {
  int temp = arr_[0];
  LeftShift();
  arr_[length_ - 1] = temp;
}

template <typename T> void Array<T>::RightRotate() {
  int temp = arr_[length_ - 1];
  RightShift();
  arr_[0] = temp;
}

template <typename T> bool Array<T>::IsSorted() const {
  for (int i = 0; i < length_ - 1; i++) {
    if (arr_[i] > arr_[i + 1]) {
      return false;
    }
  }
  return true;
}

template <typename T> void Array<T>::InsertSort(int item) {
  VerifySize();
  int i = 0;
  while (arr_[i] < item) {
    i++;
  }
  Insert(i, item);
}

template <typename T> void Array<T>::Rearrange() {
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

template <typename T> Array<T> Array<T>::Merge(const Array<T> &array) const {
  Array buffer;
  buffer.Reserve(length_ + array.length_);
  int i, j, k;
  i = j = k = 0;

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer.arr_[k++] = arr_[i++];
    } else {
      buffer.arr_[k++] = array.arr_[j++];
      i++;
    }
  }

  for (; i < length_; i++) {
    buffer.arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer.arr_[k++] = array.arr_[j];
  }

  buffer.length_ = k;

  return buffer;
}

template <typename T>
Array<T> Array<T>::Concatenate(const Array<T> &array) const {
  Array buffer;
  buffer.Reserve(length_ + array.length_);
  int k = 0;
  for (int i = 0; i < length_; i++) {
    buffer.arr_[k++] = arr_[i];
  }
  for (int i = 0; i < array.length_; i++) {
    buffer.arr_[k++] = array.arr_[i];
  }
  buffer.length_ = k;
  return buffer;
}

template <typename T> void Array<T>::Append(const Array<T> &array) {
  Array buffer = Concatenate(array);
  buffer.Copy(*this);
}

template <typename T> void Array<T>::Copy(Array<T> &array) const {
  array.length_ = length_;
  array.size_ = size_;
  delete array.arr_;
  array.arr_ = new T[size_];
  for (int i = 0; i < length_; i++) {
    array.arr_[i] = arr_[i];
  }
}

template <typename T> bool Array<T>::Compare(const Array<T> &array) const {
  if (length_ != array.length_)
    return false;

  for (int i = 0; i < array.length_; i++) {
    if (arr_[i] != array.arr_[i]) {
      return false;
    }
  }

  return true;
}

template <typename T> Array<T> Array<T>::Union(const Array<T> &array) {
  int i, j, k;
  i = j = k = 0;

  Array buffer;
  buffer.Reserve(array.length_ + length_);

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer.arr_[k++] = arr_[i++];
    } else {
      buffer.arr_[k++] = array.arr_[j++];
      i++;
    }
  }

  for (; i < length_; i++) {
    buffer.arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer.arr_[k++] = array.arr_[j];
  }

  buffer.length_ = k;

  return buffer;
}

template <typename T> Array<T> Array<T>::Intersection(const Array<T> &array) {
  int i = 0;
  int j = 0;
  int k = 0;
  Array buffer;
  buffer.Reserve(array.length_ + length_);
  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      i++;
    } else if (arr_[i] > array.arr_[j]) {
      j++;
    } else {
      buffer.arr_[k++] = arr_[i++];
      j++;
    }
  }

  buffer.length_ = k;
  return buffer;
}

template <typename T> Array<T> Array<T>::Difference(const Array<T> &array) {
  int i, j, k;
  i = j = k = 0;

  Array buffer;
  buffer.Reserve(length_ + length_);

  while (i < length_ && j < array.length_) {
    if (arr_[i] < array.arr_[j]) {
      buffer.arr_[k++] = arr_[i++];
    } else if (arr_[i] > array.arr_[j]) {
      buffer.arr_[k++] = array.arr_[j++];
    } else {
      i++;
      j++;
    }
  }

  for (; i < length_; i++) {
    buffer.arr_[k++] = arr_[i];
  }

  for (; j < array.length_; j++) {
    buffer.arr_[k++] = array.arr_[j];
  }

  buffer.length_ = k;

  return buffer;
}