#include <stdio.h>
#include <string.h>

void ToggleCase(char *const string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (64 < string[i] && string[i] < 91) {
      string[i] += 32;
    } else if (96 < string[i] && string[i] < 123) {
      string[i] -= 32;
    }
  }
}

void UpperCase(char *const string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (96 < string[i] && string[i] < 123) {
      string[i] -= 32;
    }
  }
}

void LowerCase(char *const string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (64 < string[i] && string[i] < 91) {
      string[i] += 32;
    }
  }
}

int CountVowels(const char *const string) {
  int count = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    switch (string[i]) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      count++;
    }
  }
  return count;
}

int CountWords(const char *const string) {
  int count = 0;
  for (int i = 1; string[i] != '\0'; i++) {
    if (string[i] == ' ' && string[i - 1] != ' ') {
      count++;
    }
  }
  return ++count;
}

void Print(const char *const string) {
  for (int i = 0; string[i] != '\0'; i++) {
    printf("%c", string[i]);
  }
}

void Println(const char *const string) {
  Print(string);
  printf("\n");
}

void Swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

bool IsValid(const char *const string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (!(64 < string[i] && string[i] < 91) &&
        !(96 < string[i] && string[i] < 123)) {
      return false;
    }
    return true;
  }
}

int Length(const char *const string) {
  int i;
  for (i = 0; i < string[i] != '\0'; i++) {
  }
  return i;
}

void Reverse(char *const string) {
  int j, k;
  for (j = 0, k = Length(string) - 1; j < k; j++, k--) {
    Swap(&string[j], &string[k]);
  }
}

int Compare(const char *const string1, const char *const string2) {

  int i = 0;
  while (string1[i] != '\0' && string2[i] != '\0') {
    if (string1[i] != string2[i]) {
      break;
    }
    i++;
  }
  if (string1[i] == string2[i]) {
    return 0;
  } else if (string1[i] > string2[i]) {
    return 1;
  } else {
    return -1;
  }
}

void Copy(const char *const from, char *const to) {
  for (int i = 0; from[i] != '\0'; i++) {
    to[i] = from[i];
  }
}

bool Palindrome(const char *const string) {
  char *string2 = (char *)malloc(Length(string) * sizeof(char));
  Copy(string, string2);
  Reverse(string2);
  if (!Compare(string, string2)) {
    free(string2);
    return true;
  } else {
    free(string2);
    return false;
  }
}

int *Duplicated(const char *const string) {
  int *characters = calloc(sizeof(int), 25);
  for (int i = 0; i < string[i] != '\0'; i++) {
    if (64 < string[i] && string[i] < 91) {
      characters[string[i] - 65]++;
    } else if (96 < string[i] && string[i] < 123) {
      characters[string[i] - 97]++;
    }
  }
  return characters;
}