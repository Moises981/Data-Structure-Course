#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define bool int

extern void ToggleCase(char *const string);
extern void UpperCase(char *const string);
extern void LowerCase(char *const string);
extern void Print(const char *const string);
extern void Println(const char *const string);
extern int CountVowels(const char *const string);
extern int CountWords(const char *const string);
extern bool IsValid(const char *const string);
extern void Reverse(char *const string);
extern int Compare(const char *const string1, const char *const string2);
extern bool Palindrome(const char *const string);

#endif