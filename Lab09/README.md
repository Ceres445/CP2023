# Evaluative Lab 9

## Learning objectives

* Working with a user-defined datatype - structures
* Pointers to structures
* Arrays as Pointers
* Returning multiple values from functions using output parameters

## Starting point

Use the shortcut Ctrl + Shift + V to open the README.md file in Preview mode.

The given starter code contains *skeletons* of three functions, the `main` function, `get_input` function, and the `display` function. It does not compile at this point as there are a few important points missing in the code. Make sure you go through the tasks given below in an orderly manner.

DO NOT CHANGE the `main` function.

DO NOT use `break` or `continue` or any constructs not introduced in class.

DO NOT SEEK HELP FROM ANYONE IN THE LAB, INCLUDING TAs.

# Tasks

## Task 0

First, rename the `.c` file to `YOURBITSID.c`.
Ensure that the YOURBITSID matches your ID on quanta, or in other words, the 'Campus ID' on the lab seating arrangement shared with you.

We will run a script to evaluate these automatically. If it fails, you will receive zero marks.

### Compilation instructions

You should know these by now, but here is a command to compile your program:

```sh
gcc YOURBITSID.c -o lab09
```

and a command to run the compiled program:

```sh
./lab09
```

## Task 1

Add appropriate header files in the program.

## Task 2
Define a user-defined datatype (structure) called `Employee`. The fields in `Employee` are:

* `id`: An integer that stores the id of an employee.
* `salary`: An integer that stores the salary of an employee.
* `fav_quote`: A string to store the favourite quote of an employee. The maximum length of the quote can be 49. [The quote will have '\_' (underscore) as word separators and '.' (period/full stop) as the end of the quote. Assume that words are non empty. That is, quote will not be "\_." Words contain only alphabets and digits.]

* `sick_leaves`: An array that can store the sick leaves per month taken by an employee in 6 months. Each entry is an integer value.

Create an alias type `emp` for the datatype `struct Employee`. (HINT: Use `typedef`).

HINT: You can take a look at the `display()` to see the fields needed in the `emp` type.

## Task 3

Among 2 employees, return the employee with the highest salary. If both have the same salary, return the employee with the higher employee id. Each employee has a unique employee id.

* Complete the function header for the function `max_salary` to match the arguments in the function call from `main()`.
* Implement the function `max_salary` to match its description (`@brief`).
* Run your code, select the appropriate function and test it with examples provided in the description.

HINT: To check that your code is running correctly in a time-efficient manner:
* In `main()`, comment out the two statements to initialize `e1` and `e2` from `get_input()`.
* Then, uncomment the code block, which hardcodes values for `e1` and `e2`. 
* This will help you in testing your code for various inputs without needing to tirelessly adding user inputs upon execution.
* Make sure to revert all the changes in main() before the final evaluation with autograder.

## Task 4

For the employee which has the highest salary, find out the longest word in the favorite quote. If there are more than 1 word having the same longest length, then print the word that starts at the higher index.

* Implement the function `longest_word` to match its description (`@brief`).
* Note: After the search for the longest word is done, it needs to be printed in the function. The print statement is already given. Do not change it.
* You can use functions provided in `string.h` and `ctype.h`
* Run your code, select the appropriate function and test with examples provided in the description.

## Task 5

For the employee which has the highest salary, find the number of sick leaves that appears the most (i.e. mode) and the average number of sick leaves taken across a period of 6 months. The mode and the average will be returned via output parameters.
 
* Complete the function header for the function `cal_sick_leaves` to match the arguments in the function call from `main()`.
* Implement the function `cal_sick_leaves` to match its description (`@brief`).
* Note: If there are multiple modes, select the one whose first occurence starts the latest. Also, the average will be printed by ".`1lf`" format specifier in main().
* Run your code, select the appropriate function and test with examples provided in the description.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab09-tests.json
```

We will run your submission against several other test cases - you should test your code for other input combinations before submitting.

## Prepare Submission

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

   Also, check that the correct .tar.gz file has been uploaded before logging out from quanta.