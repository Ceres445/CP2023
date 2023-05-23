# Evaluative Lab 7

## Learning objectives

* Working with strings as character arrays
* Working with <string.h>

## Starting point

The given starter code contains *skeletons* of two functions, and the `main` function. It compiles and executes but does not produce expected results at this point. Make sure you understand the given code.

Use the shortcut Ctrl + Shift + V to render the README.md file.

DO NOT CHANGE the `main` function.

DO NOT SEEK HELP FROM ANYONE, INCLUDING TAs.

## Tasks

## Task 0

First, rename the `.c` file to `YOURBITSID.c`.
Ensure that the YOURBITSID matches your ID on quanta, or in other words, the 'Campus ID' on the lab seating arrangement shared with you.

You should add appropriate header files in the program.

We will run a script to evaluate these automatically. If it fails, you will receive zero marks.

### Compilation instructions

You should know these by now, but here is a command to compile your program:

```sh
gcc YOURBITSID.c -o lab07
```

and a command to run the compiled program:

```sh
./lab07
```

### Task 1

Given a string, you are required to count the number of vowels in the string.

Do not use `break` or `continue` or any constructs not introduced in class.

* Implement the function `num_vowels` to match its description (`@brief`).
* You can use functions provided in string.h
* Run your code, select the appropriate function and test it with examples provided in the description.

### Task 2

You need to print the longest substring in a given string with no repeating characters.

Note that a character in lowercase and uppercase is treated different, that is, 'a' is different than 'A'

If there are multiple substrings of the same length, print the substring whose starting index in the original string is higher. 
 
* Implement the function `longest_substring` to match its description (`@brief`).
* Do not use `break` or `continue` or any constructs not introduced in class.
* You can use functions provided in string.h
* Run your code, select the appropriate function and test with examples provided in the description.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab07-tests.json
```

We will run your submission against several other test cases - you should test your code for other input combinations before submitting.

### Prepare Submission

1. First, make sure the .c file is renamed properly and works as expected.
2. Run the following command in the terminal to make the program to prepare submission an executable:

   ```sh
   chmod 700 prepare_submission
   ```

3. Execute that program to produce the submission file `YOURBITSID.tar.gz`:

   ```sh
   ./prepare_submission
   ```

4. Upload the created file to the appropriate assignment on <https://quanta.bits-goa.ac.in/>.
   Be sure to leave the 'Save As' option blank while uploading the your solution on quanta.
