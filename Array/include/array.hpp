#pragma once
#define ARRAY_SIZE 3
#define ARRAY_MULT 3

class Array {
private:
  int size_;
  int length_;
  int *arr_ = nullptr;

public:
  Array() : length_{0} { Reserve(&arr_, ARRAY_SIZE); }
  ~Array() { delete arr_; }
  inline int length() { return length_; }
  void Display() const;
  void Append(int item);
  void Insert(int index, int item);
  int LinearSearch(int item);
  int BinarySearch(int item) const;
  int Get(int index) const;
  void Set(int index, int item);
  int Max() const;
  int Min() const;
  int Sum() const;
  float Avg() const { return (float)Sum() / length_; }
  void Reverse();
  void LeftShift();
  void RightShift();
  void LeftRotate();
  void RightRotate();
  bool IsSorted() const;
  void InsertSort(int item);
  void Rearrange();

private:
  void Swap(int *a, int *b);
  void VerifySize();
  inline void Reserve(int **arr, int size) {
    size_ = size;
    *arr = new int[size];
  }
};