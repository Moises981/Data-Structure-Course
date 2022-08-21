#include <stdlib.h>
#include <string.h>
#include <unity/unity.h>

char *string;
const char word[12] = "hEllO WoRlD";

void string_cases() {
  ToggleCase(string);
  TEST_ASSERT_EQUAL_STRING("HeLLo wOrLd", string);

  LowerCase(string);
  TEST_ASSERT_EQUAL_STRING("hello world", string);

  UpperCase(string);
  TEST_ASSERT_EQUAL_STRING("HELLO WORLD", string);

  TEST_ASSERT_EQUAL_INT32(3, CountVowels(string));
  TEST_ASSERT_EQUAL_INT32(2, CountWords(string));
  TEST_ASSERT_TRUE(IsValid(string));

  Reverse(string);
  TEST_ASSERT_EQUAL_STRING("DLROW OLLEH", string);

  TEST_ASSERT_EQUAL_INT32(0, Compare(string, string));
  TEST_ASSERT_EQUAL_INT32(-1, Compare(string, word));

  TEST_ASSERT_EQUAL_INT32(0, Palindrome(string));

  TEST_ASSERT_EQUAL_INT32(1, Palindrome("madam"));

  int *dup = Duplicated(string);
  int values[25] = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 3, 0,
                    0, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
  TEST_ASSERT_EQUAL_INT32_ARRAY(values, dup, 25);
  free(dup);

  TEST_ASSERT_EQUAL_INT32(4343960, DuplicatedBitwise(string));
}

void setUp() {
  string = (char *)malloc(sizeof(char) * 15);
  for (int i = 0; word[i] != '\0'; i++) {
    string[i] = word[i];
  }
}
void tearDown() { free(string); }

int main() {
  UNITY_BEGIN();
  RUN_TEST(string_cases);
  return UNITY_END();
}