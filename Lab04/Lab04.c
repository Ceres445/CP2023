#include <stdio.h>

/**
 * @author YOURBITSID (NAME)
 */

/**
 * @brief Print a character a fixed number of times.j
 * Example:
 *    repeat('*',3) must print "***" on the console.
 *    repeat('+',2) must print "++" on the console.
 * Assume:
 *    The integer parameter is non-negative.
 */
void repeat(char c, int count) {
    if (count == 1)
        printf("%c", c);
    else {
        printf("%c", c);
        repeat(c, count - 1);
    }
}

/**
 * @brief Enumerate all letters (of the english alphabet) before a particular
 * letter.
 *
 * Example:
 *    enumerate('c') must print "cba" on the console.
 *    enumerate('f') must print "fedcba" on the console.
 * Assume:
 *    The character parameter is one of 'a','b','c',....,'z'
 */
void enumerate(char c) {
    if (c == 'a')
        printf("%c", c);
    else {
        printf("%c", c);
        enumerate(c - 1);
    }
}

/**
 * @brief Enumerate all letters before a particular letter in descending as well
 * as ascending order.
 *
 * Example:
 *    double_enumerate('c') must print "cbabc" on the console.
 *    double_enumerate('f') must print "fedcbabcdef" on the console.
 * Assume:
 *    The character parameter is one of 'a','b','c',....,'z'
 */
void double_enumerate(char c) {
    if (c == 'a')
        printf("%c", c);
    else {
        printf("%c", c);
        double_enumerate(c - 1);
        printf("%c", c);
    }
}

int main() {
    printf("1. repeat.  2. enumerate  3. double_enumerate \n");
    printf("Which function do you want to test? Enter 1,2,3 accordingly.\n");

    int option;
    scanf(" %d", &option);

    if (option == 1) {
        char c;
        int n;
        printf("Enter character: ");
        scanf(" %c", &c);
        printf("Enter count: ");
        scanf(" %d", &n);
        repeat(c, n);
    } else if (option == 2) {
        char c;
        printf("Enter character: ");
        scanf(" %c", &c);
        enumerate(c);
    } else if (option == 3) {
        char c;
        printf("Enter character: ");
        scanf(" %c", &c);
        double_enumerate(c);
    }
    return 0;
}
