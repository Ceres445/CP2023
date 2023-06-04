#include <ctype.h>
#include <stdio.h>
#include <string.h>
// Have the correct header files. Enter as many you want.
//
struct student {
  char name[20];
  int rollno;
  int marks[2];
  int total;
};

/*
Display the names of the students starting from index 0 to (len-1).
*/
void display_names(struct student s[], int len) {
  for (int i = 0; i < len; i++)
    printf("%s ", s[i].name);
  printf("\n");
}

/*
Display the roll numbers of the students starting from index 0 to (len-1).
*/
void display_rollno(struct student s[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", s[i].rollno);
  printf("\n");
}

/*
Display all information of all the students.
*/
void display(struct student s[], int len) {
  for (int i = 0; i < len; i++) {
    printf("\nStudent %d\n", i + 1);
    printf("Name: %s\n", s[i].name);
    printf("Roll no: %d\n", s[i].rollno);
    printf("Marks of Subject 1: %d\n", s[i].marks[0]);
    printf("Marks of Subject 2: %d\n", s[i].marks[1]);
    printf("Total: %d\n", s[i].total);
  }
}

/**
 * @brief Returns the number of names that start with a given character (key).
 * The comparison should be performed by ignoring the case of the key.
 * (That is, lower case 'a' and upper case 'A' should be treated the same)
 *
 * Requires: The student names have no spaces. Can contain uppercase, lowercase
 * characters and digits. Names will start with either uppercase or lowercase
 * characters.
 *
 * Example 1:
 *    Structure: {{"ABC", 1, {70, 80}, 150},
 *                {"ACD", 2, {50, 60}, 110},
 *                {"XYZ", 3, {75, 85}, 160}};
 *    key = 'A'
 *    Returns 2
 *
 * Example 2:
 *    Structure: {{"ABC", 1, {70, 80}, 150},
 *                {"aCD", 2, {50, 60}, 110},
 *                {"XYZ", 3, {75, 85}, 160}};
 *    key = 'A'
 *    Returns 2
 *
 * Example 3:
 *    Structure: {{"ABC", 1, {70, 80}, 150},
 *                {"aCD", 2, {50, 60}, 110},
 *                {"XYZ", 3, {75, 85}, 160}};
 *    key = 'Y'
 *    Returns 0
 */
int num_names(struct student s[], int len, char key) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (tolower(s[i].name[0]) == tolower(key))
      count++;
  }

  return count;
}

/**
 * @brief Arranges the students in the descending order of the total marks.
 * Needs to use Insertion Sort algorithm as described in the README.
 * Needs to call display_rollno(s, len) after every iteration.
 *
 * Requires: The total marks for each student is different.
 *
 * Example 1:
 *    Structure: {{"ABC", 1, {70, 80}, 150},
 *                {"ACD", 2, {50, 60}, 110},
 *                {"XYZ", 3, {75, 85}, 160}};
 *    After 1st Iteration:
 *          Structure: {{"ABC", 1, {70, 80}, 150},
 *                      {"ACD", 2, {50, 60}, 110},
 *                      {"XYZ", 3, {75, 85}, 160}};
 *    After 2nd Iteration:
 *          Structure: {{"XYZ", 3, {75, 85}, 160},
 *                      {"ABC", 1, {70, 80}, 150},
 *                      {"ACD", 2, {50, 60}, 110}};
 *
 * Example 2:
 *    Structure: {{"ABC", 1, {50, 60}, 110},
 *                {"aCD", 2, {70, 80}, 150},
 *                {"XYZ", 3, {75, 85}, 160}};
 *    After 1st Iteration:
 *          Structure: {{"aCD", 2, {70, 80}, 150},
 *                      {"ABC", 1, {50, 60}, 110},
 *                      {"XYZ", 3, {75, 85}, 160}};
 *    After 2nd Iteration:
 *          Structure: {{"XYZ", 3, {75, 85}, 160},
 *                      {"aCD", 2, {70, 80}, 150},
 *                      {"ABC", 1, {50, 60}, 110}};
 *
 * Example 3:
 *    Structure: {{"XYZ", 1, {75, 85}, 160},
 *                {"ABC", 2, {70, 80}, 150},
 *                {"aCD", 3, {50, 60}, 110}};
 *    After 1st Iteration:
 *          Structure: {{"XYZ", 1, {75, 85}, 160},
 *                      {"ABC", 2, {70, 80}, 150},
 *                      {"aCD", 3, {50, 60}, 110}};
 *    After 2nd Iteration:
 *          Structure: {{"XYZ", 1, {75, 85}, 160},
 *                      {"ABC", 2, {70, 80}, 150},
 *                      {"aCD", 3, {50, 60}, 110}};
 */

void sort_descending(struct student s[], int len) {
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (s[i].total > s[j].total) {
        struct student temp = s[i];
        temp = s[j];
        s[j] = s[i];

        struct student temp2;
        j++;
        while (j <= i) {
          temp2 = s[j];
          s[j] = temp;
          temp = temp2;
          j++;
        }
      }
    }
    display_rollno(
        s,
        len); // This statement should be called after every iteration.
  }
}

/**
 * @brief Populates the given array of students with the user's input and
 * returns the number of students.
 *
 */

int get_input(struct student s[]) {
  int num;
  printf("Enter the number of students: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    printf("Student %d\n", i + 1);
    printf("Enter Student Name, Roll no, Marks of Subject 1, and Marks of "
           "Subject 2:\n");
    scanf("%s", s[i].name);
    scanf("%d", &s[i].rollno);
    scanf("%d", &s[i].marks[0]);
    scanf("%d", &s[i].marks[1]);
    s[i].total = s[i].marks[0] + s[i].marks[1];
  }

  return num;
}

/**
 * The driver function. Do not alter the main().
 */
int main() {
  const int MAX_STUDENTS = 50;
  struct student s[MAX_STUDENTS];

  int num_students = get_input(s);

  // display(s, num_students);

  printf("This program supports TWO operations:\n");
  printf("\t1. Count the number of names starting with a given character,\n");
  printf(
      "\t2. Sort the students based on descending order of total marks.\n\n");
  printf("Choose an operation (1 or 2): ");
  int operation = 0;
  scanf("%d", &operation);

  if (operation == 1) {
    char key;
    printf("Enter a character: ");
    scanf(" %c", &key);
    int count = num_names(s, num_students, key);
    printf("The number of names starting with character %c: %d\n", key, count);
  }

  else if (operation == 2) {
    sort_descending(s, num_students);
    display_names(s, num_students);
    printf("The highest marks: %d\n", s[0].total);
  }

  return 0;
}
