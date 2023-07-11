
---
tag: clang, cp2023, acads
---

## Important ASCII values
 - 0 -> '\\0'
 - 10 - '\\n'
 - 32 - space
 - 48 - '0'
 - 57 - '9'
 - 65 - 'A'
 - 90 - 'Z'
 - 97 - 'a'
 - 120 - 'z'

## Formatting with scanf and printf
 ### Format codes
 - %c - char 
 - %d - int 
 - %f - float 
 - %lf - double 
 - %p - address
 - %u - unsigned int
 - %s - string 
 ### Formatting numbers 
  - %nf => pad the number with spaces so that the total characters used is at least n ( %0nf pads with zeroes instead of spaces).
  - Examples: 
	  - `printf("%6d", 20)` -> `    20`
	  - `printf("%06d", 20)` -> `000020.000000` 
  - %.df => number of digits to print after the decimal point 
  - Examples: 
	  - `printf("%.2f", 20.0)` -> `20.00`
	  - `printf("6.2f", 35.556)` -> ` 35.55`
  - Default `n` value is 0
  - Default `d` value is 6

## Operators 
 ### Precedence 
	1. (suffix)++, --, () 
	2. ++, --,!, (type) 
	3. *, /, %
	4. +, -
	5. <, >, <=, >=
	6. ==, !=
	7. &&
	8. || 
	9. =, +=, -=
 
 ### Direction 
	== -> Evaluates from left to right 
	All other operators evaulate from right to left.
 

## Common functions from libraries

```c 
#include <ctype.h>
isalpha(char)
isspace(char)
isnum(char)

#include <string.h>
strlen(*char) // from *char to '\0'
strcmp(*char1, *char2) // returns 0 if both are same
strcpy(*destination, *source)

```

 ```c
 #include <stdio.h>
// Definitions 
FILENAME_MAX = 1024 // Maximum length of a filename

printf("%d", 10);
scanf("%d", &integer);
scanf("%s", string);
fp = fopen("filename", "r") // Possible modes are r, w, a, r+, w+, a+
char c = fgetc(fp); // Can only be done with a mode supporting read
fputc(c, fp); // Can o>nly be done with a mode supporting write
char line[100];
fgets(line, n, fp); // Reads n - 1 characters
fputs(line, fp);
fscanf(fp, "%d", &integer);
fprintf(fp, "%s", string);
rewind(fp); // Moves cursor to start
fseek(fp, offset, SEEK_CUR); // moves cursor to offset from SEEK_CUR 
// SEEK_CUR => Current position 
// SEEK_END => EOF
// SEEK_SET => Start

// Commonly used filestreams
stdin => standard input 
stdout => standard output 
stderr => standard error
// printf and scanf operate on stdout and stdin respectively
```

```c
#include <stdlib.h>
// NULL is a pointer with size 8

int *var = malloc(n * sizeof(int)); // Returns the address of the allocated memory
int *var = calloc(n, sizeof(int));
free(var);


// Type conversions
char *c = "12";
int n= atoi(c);
float m = atof(c);
```

```c
#include <stdbool.h>
true, false

#include <limits.h>
INT_MAX, INT_MIN

#include <math.h>
pow(a, b) == a^b
sqrt, ceil, floor
PI
```

## Struct 
```c
struct Student {
	char name[20];
	int id;
};

typedef struct Prof { // Prof is optional
	char *name; // To allow for dynamic memory allocation
	int id;
} prof;

// Usage 
struct Student John = {"John", 22}; // need to write struct
prof Kundu = {.name = "Kundu", .id = 23}; // Alternate way of defining 

```

## Multidimensional arrays

```c
int arr2d[][2] = {{1},{2},{3}};
// Following wont work as number of columns needs to be specified
// int arr2d[3][] = {{1},{2},{3}};

// Heap 
int **m = calloc(num_rows, sizeof(int *));
for (int i = 0; i < num_rows; ++i)
	m[i] = calloc(num_cols, sizeof(int));
```


## Macros 
 ### Define 
  - `#define KEY value` => sets key to value 
  - You can think of this as substituting key with value whenever we specify value. 
  
```c
#define square(x) x * x 
printf("%d", 25 / square(5)) // prints 25

// Compiles to this 
printf("%d", 25 / 5 * 5)
```


 ### Conditional compilation
```c
#ifdef VALUE
<Code>
#endif
```
 - Code will be included for compilation if `#define VALUE exists` or code is compiled with the value in D flag. `gcc code.c -D VALUE`

## CLI

```c
int main(int argc, char **argv){
}
```
 - `argc` is the number of arguments (Always >= 1)
 - `argv` is a two dimensional character array 
 - argv[0] is the name of the file that was executed ( Hence `argc` >= 1)
