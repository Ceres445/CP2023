#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Returns the number of vowels in a given string.
 *
 * Requires: The given string has no spaces. Can contain uppercase, lowercase
 * characters and digits.
 *
 * Examples:
 *  4  num_vowels("BitsPilani")
 *  2  num_vowels("GOA")
 *  0  num_vowels("CSF111")
 */
int num_vowels(char str[]) {
  int count = 0;
  char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int i = 0;
  while (i < strlen(str)) {
    for (int j = 0; j < 5; j++) {
      if (str[i] == vowels[j]) {
        count++;
      }
    }
    i++;
  }

  return count;
}

int helper(char str[], int start, int end) {
  for (int i = start; i < end; i++) {
    if (str[i] == str[end]) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief Prints the longest substring in a given string with no repeating
 * characters. A character in lowercase and uppercase is treated different. ('a'
 * is different than 'A') If there are multiple substrings of the same length,
 * print the substring whose starting index in the original string is higher.
 *
 * Requires: The given string has no spaces. Can contain uppercase, lowercase
 * characters and digits.
 *
 * Examples:
 *  Prints "abcd" for longest_substring("abcd")
 *  Prints "est" for longest_substring("test")
 *  Prints "BITSPilan" for longest_substring("BITSPilaniGoaCampus")
 *  Prints "TSPILAN"  longest_substring("BITSPILANIGOACAMPUS")
 */
void longest_substring(char str[]) {
  char longest[100];

  int i = 0, j = 0, start = 0, length = 0, startMax = 0;
  while (i < strlen(str)) {
    if (helper(str, start, i) != -1) {
      // substring without repeating characters
      if ((i - start) >= length) {
        startMax = start;
        length = i - start;
      }
      // next substring
      start = helper(str, start, i) + 1;
    }
    i++;
  }

  if ((i - start) >= length) {
    startMax = start;
    length = i - start;
  }

  // Your code here
  // printf("%d %d\n", starti[i], endi[i]);
  // printf("%d %d\n", start, end);
  int end = 0;
  j = 0;
  for (int i = startMax; i < startMax + length; i++) {
    longest[j] = str[i];
    j++;
  }
  // Add terminate character to the end of the string
  longest[j] = '\0';

  printf("Longest substring with no repeating characters: %s\n", longest);
}

int main() {
  printf("This program supports TWO operations:\n");
  printf("\t1. Count the number of vowels in a string,\n");
  printf("\t2. Find the longest substring with no repeating characters.\n\n");
  printf("Choose an operation (1 or 2): ");
  int operation = 0;
  scanf("%d", &operation);

  const int MAX_LENGTH = 100;
  char str[MAX_LENGTH];

  printf("Enter the string: ");
  scanf("%s", str);

  if (operation == 1) {
    printf("The number of vowels in %s is %d\n", str, num_vowels(str));
  }

  else if (operation == 2) {
    longest_substring(str);
  }

  return 0;
}
