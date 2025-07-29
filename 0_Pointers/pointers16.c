/*
 * Program: Array Sort Check
 *
 * Description:
 * This C program allows the user to input 10 integer values into an array,
 * then prints the array and checks whether it is sorted in ascending order.
 * The program distinguishes between three possible states:
 *
 * 1. "The array is really sorted." — The array is strictly increasing (each element is less than the next).
 * 2. "The array is sorted." — The array is non-decreasing (equal values allowed, but no decreasing elements).
 * 3. "The array is not sorted." — At least one element is greater than the one following it.
 *
 * Functions:
 * - inputArray(int *ptr): Prompts the user to enter 10 values into the array.
 * - printArray(int *ptr): Prints the array in a formatted way.
 * - isSortedArray(int *ptr, int *isReallySortedPtr):
 *     - Returns 1 if the array is sorted (non-decreasing), 0 otherwise.
 *     - Updates the isReallySortedPtr to 1 only if the array is strictly increasing.
 *
 * Variables:
 * - isSorted: Indicates if the array is sorted in non-decreasing order.
 * - isReallySorted: Indicates if the array is strictly increasing.
 *
 * The program uses pointer notation for array manipulation and
 * pointer-to-int to update the `isReallySorted` flag from within the function.
 */

#include <stdio.h>
#define SIZE 10

void inputArray(int *ptr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter the value %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
}

void printArray(int *ptr)
{
    printf("Array: [");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("%d]\n", ptr[i]);
        else
            printf("%d, ", ptr[i]);
    }
}

int isSortedArray(int *ptr, int *isReallySortedPtr)
{
    int isSorted = 1;

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (ptr[i] > ptr[i + 1])
        {
            *isReallySortedPtr = 0;
            isSorted = 0;

            return isSorted;
        }
        if (ptr[i] < ptr[i + 1] && *isReallySortedPtr != 0)
        {
            *isReallySortedPtr = 1;
            isSorted = 1;
        }
        if (ptr[i] == ptr[i + 1] && isSorted != 0)
        {
            *isReallySortedPtr = 0;
            isSorted = 1;
        }
    }

    return isSorted;
}

int main()
{
    int array[SIZE];
    inputArray(array);
    printArray(array);

    int isSorted = 1, isReallySorted = 1;

    isSorted = isSortedArray(array, &isReallySorted);

    if (isSorted == 1 && isReallySorted == 1)
        printf("The array is really sorted.\n");
    else if (isSorted == 1 && isReallySorted == 0)
        printf("The array is sorted.\n");
    else
        printf("The array is not sorted.\n");

    return 0;
}