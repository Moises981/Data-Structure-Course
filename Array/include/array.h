#ifndef ARRAY_H
#define ARRAY_H
#define ARRAY_SIZE 3
#define ARRAY_MULT 3

#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *arr;
  int size;
  int length;
};

extern void Init(struct Array *array);
extern void Reserve(struct Array *array, int size);
extern void Display(const struct Array *const array);
extern void Append(struct Array *array, int item);
extern void Insert(struct Array *const array, int index, int item);
extern int LinearSearch(const struct Array *const array, int item);
extern int BinarySearch(const struct Array *const array, int item);
extern int Get(const struct Array *const array, int index);
extern void Set(struct Array *const array, int index, int item);
extern int Max(const struct Array *const array);
extern int Min(const struct Array *const array);
extern float Avg(const struct Array *const array);
extern int Sum(const struct Array *const array);
extern void Reverse(struct Array *const array);
extern void LeftShift(struct Array *const array);
extern void RightShift(struct Array *const array);
extern void LeftRotate(struct Array *const array);
extern void RightRotate(struct Array *const array);
extern int IsSorted(const struct Array *const array);
extern void InsertSort(struct Array *array, int item);
extern void Rearrange(struct Array *const array);
extern struct Array *MergeArray(const struct Array *array1,
                                const struct Array *array2);
extern struct Array *ConcatenateArray(const struct Array *array1,
                                      const struct Array *array2);
extern void AppendArray(struct Array *base, struct Array *arr);
extern void CopyArray(struct Array *from, struct Array *to);
extern int CompareArray(struct Array *arr1, struct Array *arr2);
extern struct Array *Union(struct Array *arr1, struct Array *arr2);
extern struct Array *Intersection(struct Array *arr1, struct Array *arr2);
extern struct Array *Difference(struct Array *arr1, struct Array *arr2);
extern struct Array *Difference(struct Array *arr1, struct Array *arr2);

#endif