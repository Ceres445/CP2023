// Have the correct header files. Enter as many you want.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition of Struct.
 * Do NOT change.
 */
typedef struct {
  char **fname;
  double **marks;
} class_t;

/**
 * @brief Dynamically allocates the required memory for the 2-D arrays - fname
 * and marks
 *
 * The function parameters are the total number of students (num) and the
 * maximum length of a student's name (len). Each row in fname and marks
 * corresponds to a student in the class. The size of each row of fname should
 * be sufficiently large to hold a student's name whose length <= len. Each row
 * of the marks array should be able to hold the marks of 3 subjects for a
 * student.
 */
void allocate_memory(class_t *c, int num, int len) {
  c->marks = malloc(num * sizeof(double *));
  c->fname = malloc(num * sizeof(char *));
  for (int i = 0; i < num; i++) {
    c->marks[i] = malloc(sizeof(double) * 3);
    c->fname[i] = malloc(sizeof(char) * len);
  }
}

/**
 * @brief Takes all inputs from the user.
 *
 * Requires: Student names contains only upper case and lower case characters.
 * Assume that the length of all entered names are <= len (that is, no invalid
 * input will be provided)
 */
void get_input(class_t *c, int num) {
  for (int i = 0; i < num; i++) {
    printf("Enter name and marks of 3 subjects:\n");
    scanf("%s", c->fname[i]);
    scanf("%lf", &c->marks[i][0]);
    scanf("%lf", &c->marks[i][1]);
    scanf("%lf", &c->marks[i][2]);
  }
}

/**
 * @brief Returns the index of the student with the highest total marks.
 * (Subject 1 + Subject 2 + Subject 3) If more than one student get the same
 * highest total marks, then return the larger index.
 *
 * Assume that the student index start from 0 in both the 2-D arrays.
 *
 * Examples:
 *      marks = {{10.0, 20.0, 30.0}, {30.0, 40.0, 50.0}}
 *          index = 1
 *
 *      marks = {{10.0, 20.0, 30.0}, {20.0, 10.0, 30.0}}
 *          index = 1
 */
int highest_marks(class_t *c, int num) {
  int total = 0;
  int index = num - 1;
  for (int i = 0; i < num; i++) {
    if (c->marks[i][0] + c->marks[i][1] + c->marks[i][2] >= total) {
      total = c->marks[i][0] + c->marks[i][1] + c->marks[i][2];
      index = i;
    }
  }
  return index;
}

/**
 * @brief Returns the index of the student with the longest name after
 * rearranging the corresponding index's fname's alphabets in alphabetical
 * order.
 *
 * If there are multiple students's names with the same longest length,
 * then arrange the name present at the lower index. Return the index.
 *
 * While arranging the characters of a name in alphabetical order (a-z),
 * for the same character, upper case should come alphabetically earlier than
 * the lower case.
 *
 * Examples:
 *      fname = {"abBA", "abc", "aBBa"}
 *          index = 0
 *          fname[0] = "AaBb"
 *
 *      fname = {"abB", "abc", "aBBa"}
 *          index = 2
 *          fname[2] = "aaBB"
 */
int longest_name_alphabetically(class_t *c, int num) {
  int index = 0;
  for (int i = 0; i < num; i++) {
    if (strlen(c->fname[index]) < strlen(c->fname[i])) {
      index = i;
    }
  }
  int hash[256] = {0};
  for (int i = 0; c->fname[index][i] != '\0'; i++) {
    hash[c->fname[index][i]]++;
  }
  char *new = malloc(sizeof(char) * strlen(c->fname[index]));
  int k = 0;
  for (int i = 65; i < 91; i++) {
    if (hash[i] != 0) {
      // printf("%c %d", i, i);
      for (int j = 0; j < hash[i]; j++) {

        new[k] = (char)i;
        k++;
      }
    }
    if (hash[i + 32] != 0) {
      // printf("%c %d %c", i, i, i + 32);
      for (int j = 0; j < hash[i + 32]; j++) {

        new[k] = (char)i + 32;
        k++;
      }
    }
  }
  new[k] = '\0';
  c->fname[index] = new;
  return index;
}

/**
 * The driver function of the code. Do not modify it.
 */
int main() {
  class_t *c = malloc(sizeof(class_t));
  int num, len;
  printf("Enter the number of students: ");
  scanf("%d", &num);
  printf("Enter the maximum length of a student's first name: ");
  scanf("%d", &len);
  allocate_memory(c, num, len);
  get_input(c, num);
  printf("This program supports TWO operations:\n");
  printf("\t1. Print the student's name with the highest total marks,\n");
  printf("\t2. Print all characters of the longest name in alphabetical "
         "order.\n\n");
  printf("Choose an operation (1 or 2): ");
  int operation = 0;
  scanf("%d", &operation);

  if (operation == 1) {
    int index = highest_marks(c, num);
    printf("The student with the highest total marks is %s\n", c->fname[index]);
  }

  else if (operation == 2) {
    int index = longest_name_alphabetically(c, num);
    printf("The characters in the longest student's name in alphabetical order "
           "are %s\n",
           c->fname[index]);
  }

  return 0;
}
