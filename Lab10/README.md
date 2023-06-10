# Evaluative Lab 10

## Learning objectives

* Working with dynamic memory allocation
* Working with arrays of structure
* Working with pointers to aggregate data types

## Starting point

The given starter code compiles and executes but does not produce expected results at this point. Make sure you understand the given code.

Use the shortcut Ctrl + Shift + V to render the README.md file.

DO NOT CHANGE

* the definition of `path_t`,
* headers of any given functions, or
* body of `main`.

You can add helper functions if you want. You can use any functions in the already `#include`d libraries. DO NOT include any other libraries.

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
gcc YOURBITSID.c -o lab10 -lm
```

(Note the additional `-lm` to ensure your program uses the math library properly.)

and a command to run the compiled program:

```sh
./lab10
```

Here are two sample runs of the program for the same input:

(a) for option 1, display the path:

```txt
Enter the number of points along the path (at least two), followed by the x,y coordinates of each point:
3 0 0 1 0 2 0
This program supports two operations:
        1. Display the given path
        2. Compute the total distance
Enter your choice: 1
Given path: [(0.00,0.00), (1.00,0.00), (2.00,0.00)]
```

(b) for option 2, compute total path distance:

```txt
Enter the number of points along the path (at least two), followed by the x,y coordinates of each point:
3 0 0 1 0 2 0
This program supports two operations:
        1. Display the given path
        2. Compute the total distance
Enter your choice: 2
Total distance: 2.00
```

Study this input and output carefully to understand what is expected of this lab.

### Task 1

Define `point_t` to match its description.

Implement the function `distance`.

Remove the `// TODO` comments once done.

### Task 2

Implement the functions `get_path` and `display_path`. 
Remove the `// TODO` comments once done.

### Task 3

Implement the function `path_distance`.
Remove the `// TODO` comments once done.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab10-tests.json
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
