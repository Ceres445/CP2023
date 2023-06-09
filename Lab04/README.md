# Evaluative Lab 4

## Learning objectives

* Defining and calling functions
* Thinking recursively to solve problems.

## Starting point

The given starter code contains *skeletons* of four functions. It compiles and executes but does not produce expected results at this point. Make sure you understand the given code.

Use the shortcut Ctrl + Shift + V to render the README.md file.

DO NOT CHANGE THE MAIN FUNCTION.

DO NOT SEEK HELP FROM ANYONE, INCLUDING TAs.

## Tasks

## Task 0

First, rename the `.c` file to `YOURBITSID.c`.
Ensure that the YOURBITSID matches your ID on quanta, or in other words, the 'Campus ID' on the lab seating arrangement shared with you.

Next, in the top level comments in the `.c` file, replace `YOURBITSID (NAME)` in front of the `@author` tag with the appropriate values.

We will run a script to evaluate these automatically. If it fails, you will receive zero marks.

### Compilation instructions

You should know these by now, but here is a command to compile your program:

```sh
gcc YOURBITSID.c -o lab04
```

and a command to run the compiled program:

```sh
./lab04
```

### Task 1

Read the description (`@brief`) of the `repeat` function and the given examples.

Implement the function `repeat` based on this.

Run your code, select option `repeat` and test your function.

### Task 2

Implement and run the function `enumerate` as done above.

### Task 3

Implement and run the function `double_enumerate` as done above.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab04-tests.json
```

We will run your submission against several other test cases - you should test your code for other input combinations before submitting.

### Prepare Submission

1. First, make sure the .c file is renamed properly and works as expected.
2. Run the following command in the terminal to make the program to prepare submission an executable:

   ```sh
   chmod +x prepare_submission
   ```

3. Execute that program to produce the submission file `YOURBITSID.tar.gz`:

   ```sh
   ./prepare_submission
   ```

4. Upload the created file to the appropriate assignment on <https://quanta.bits-goa.ac.in/>.
