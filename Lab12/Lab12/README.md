# Evaluative Lab 12

## Learning objectives

* Working with a user-defined datatype - structures
* Working with 2-D arrays
* Dynamically allocating 2-D arrays

## Starting point

Use the shortcut Ctrl + Shift + V to open the README.md file in Preview mode.

The given starter code contains *skeletons* of three functions, the `main` function, and the `get_input` function. It does not compile at this point as there are a few important points missing in the code. Make sure you go through the tasks given below in an orderly manner.

DO NOT CHANGE the `main` function.

DO NOT SEEK HELP FROM ANYONE IN THE LAB, INCLUDING TAs.

# Tasks

## Task 0

First, rename the `.c` file to `YOURBITSID.c`.
Ensure that the YOURBITSID matches your ID on quanta, or in other words, the 'Campus ID' on the lab seating arrangement shared with you.

We will run a script to evaluate these automatically. If it fails, you will receive zero marks.

### Compilation instructions

You should know these by now, but here is a command to compile your program:

```sh
gcc YOURBITSID.c -o lab12
```

and a command to run the compiled program:

```sh
./lab12
```

## Task 1

Add appropriate header files in the program. Only use the header files taught in the course.

## Task 2

* Implement the function `allocate_memory` to match its description (`@brief`).
* After completing the function, check that you are able to take inputs from the user.
* You may write a `display()` to print all the inputs (fname and marks). You should comment this out after you are done testing, else the autograder will fail.

## Task 3

* Implement the function `highest_marks` to match its description (`@brief`).
* Run your code, select the appropriate function and test with examples provided in the description.

## Task 4

* Implement the function `longest_name_alphabetically` to match its description (`@brief`).
* Run your code, select the appropriate function and test with examples provided in the description.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab12-tests.json
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