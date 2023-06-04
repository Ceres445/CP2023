# Evaluative Lab 8

## Learning objectives

* Working with a user-defined datatype - structures
* Sorting an array of structures

## Starting point

Use the shortcut Ctrl + Shift + V to open the README.md file in Preview mode.

The given starter code contains *skeletons* of two functions, the `main` function, `get_input` function, and 3 `display` functions. It does not compile at this point as there are a few important points missing in the code. Make sure you go through the tasks given below in an orderly manner.

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
gcc YOURBITSID.c -o lab08
```

and a command to run the compiled program:

```sh
./lab08
```

## Task 1

Add appropriate header files in the program.

## Task 2
Define a user-defined datatype (structure) called `student`. The fields in `student` are:

* `name`: A string to store the student's name. The maximum length of the name can be 19.
* `rollno`: An integer that stores the roll number of a student.
* `marks`: An array that can store the marks of 2 subjects scored by a student. Marks are integer values.
* `total`: An integer that stores the total marks `(marks in subject 1 + marks in subject 2)` obtained by a student. 

Hint: You can take a look at the `display()` to see the fields needed in the `student` type.

## Task 3
`get_input()` has a logical error in the function. 

Modify the statement `s[i].total = 0;` to store the correct value in a student's `total`.

Hint: After this step, you can uncomment `display(s, num_students);` in `main()` to check if your code compiles and executes correctly till this step. 

You SHOULD comment out `display(s, num_students);` in `main()` after you are done checking so that the autograder can match outputs correctly.

## Task 4

Calculate the number of students whose names start with a given character (key). The comparison should be performed by ignoring the case of the key. (That is, lower case 'a' and upper case 'A' should be treated the same)

* Implement the function `num_names` to match its description (`@brief`).
* You can use functions provided in `string.h` and `ctype.h`
* Run your code, select the appropriate function and test it with examples provided in the description.

## Task 5

Arrange the students in the descending order (high to low) of the total marks.

The sorting algorithm that you need to use for this function is INSERTION SORT.

Insertion sort to sort elements in descending order works similar to the sorting of playing cards in hands. It is assumed that the first card is already sorted in the card game, and then we select an unsorted card. If the selected unsorted card is lesser than the first card, it will be placed at the right side; otherwise, it will be placed at the left side. Similarly, all unsorted cards are taken and put in their exact place.

Algorithm Example:
* Let the intial set of elements in an array be `10, 30, 20, 40, 50` and you need to sort these elements in the descending order.
* Iteration 1: `10` and `30` will be compared. `30` will be placed in the right position. Array after iteration 1: `30, 10, 20, 40, 50`
* Iteration 2: `30`, `10`, and `20` will be compared. `20` will be placed in the right position. Array after iteration 2: `30, 20, 10, 40, 50`
* Iteration 3: `30`, `20`, `10` and `40` will be compared. `40` will be placed in the right position. Array after iteration 3: `40, 30, 20, 10, 50`
* Iteration 4: `40`, `30`, `20`, `10` and `50` will be compared. `50` will be placed in the right position. Array after iteration 4: `50, 40, 30, 20, 10`

This video will help you get a pictorial explanation of insertion sort where the array is sorted in an ascending order.
<https://www.youtube.com/watch?v=JU767SDMDvA>

Now that you know how insertion sort works, do the following.

* Implement the function `sort_descending` to match its description (`@brief`).
* Note: You need to call `display_rollno` function after every iteration to print the roll numbers. This is to ensure that the insertion sort is happening correctly.
* Note: After the sorting is complete, in `main()`, we are printing the `display_names()` and the `highest total`
* Do NOT use any functions supplied from `stdlib.h`.
* You can use functions provided in `string.h` and `ctype.h`
* Run your code, select the appropriate function and test with examples provided in the description.

## Submit

We have provided some test cases with the code.
You can test your program against these by running the following command in the terminal:

```python
python3 autograder.py YOURBITSID.c Lab08-tests.json
```

We will run your submission against several test cases - you should test your code for other input combinations before submitting.

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