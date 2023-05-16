#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Reports if the given non-empty array of the given length is sorted in a non-decreasing order.
 *
 * Examples:
 *  true  is_sorted([1], 1)
 *  true  is_sorted([1, 2], 2)
 *  false is_sorted([2, 1], 2)
 *  false is_sorted([1, 2, 1], 3)
 */
bool is_sorted(int nums[], int length)
{
    bool answer = false;

    int i = 0;
    while(i < length - 1){
        if(nums[i] <= nums[i+1]){
            answer = true;
        }
        else{
            return false;
        }
        i++;
    }

    return answer;
}

/**
 * @brief Returns the index at which the given `key` is found in the non-decreasing, non-empty array `nums` of size `length`. -1 if `key` is not found. It performs the search using a binary search algorithm and prints the index it is checking in each step.
 *
 * Requires: nums is non-decreasing, non-empty
 *
 * Examples:
 *  0  binary_search([7], 1, 7)
 *  -1 binary_search([7], 1, 6)
 *  1 binary_search([7, 9], 2, 9)
 *  -1 binary_search([7, 9], 2, 8)
 */
int binary_search(int nums[], int length, int key)
{
    const int NOT_FOUND_INDEX = -1;

    int low = 0;
    int high = length - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
        mid = (low + high) / 2;
        printf(" - Checking index %d\n", mid);
        if (nums[mid] == key) {
            return mid;
        }
        else if (nums[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return NOT_FOUND_INDEX;
}

/**
 * @brief Populates the given array with the user's input and returns the number of integers entered. The `operation` parameter is used to customise the prompt.
 *
 */
int get_numbers(int nums[], int operation)
{
    int length = 0;
    printf("How many numbers do you want to enter? ");
    scanf("%d", &length);
    printf("Enter %d integers", length);

    if (operation == 2)
        printf(" in non-decreasing order (no duplicates): ");
    else
        printf(" (duplicates allowed): ");

    for (int i = 0; i < length; ++i)
        scanf("%d", &nums[i]);
    return length;
}

int main()
{
    printf("This program supports TWO operations:\n");
    printf("\t1. Check if the given sequence of integers is in a non-decreasing order,\n");
    printf("\t2. Search a key in a non-decreasing sequcne of integers.\n\n");
    printf("Choose an operation: ");
    int operation = 0;
    scanf("%d", &operation);

    const int MAX_LENGTH = 100;
    int nums[MAX_LENGTH];

    if (operation == 1)
        {
            int length = get_numbers(nums, operation);
            printf("The integers %s in a non-decreasing order.\n",
                   is_sorted(nums, length) ? "are" : "are not");
        }
    else if (operation == 2)
    {
    int length = get_numbers(nums, operation);
    int key = 0;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = binary_search(nums, length, key);

    printf("%d", key);
    if (index >= 0)
        printf(" found at %d\n", index);
    else
        printf(" not found.\n");
}

    return 0;
}
