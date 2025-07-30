/*
 * Program Description:
 * --------------------
 * This C program reads 10 integer values from the user, stores them in an array,
 * and finds the second smallest distinct integer among them.
 *
 * Main Components:
 * ----------------
 * 1. #define SIZE 10
 *    - Defines the size of the array used throughout the program.
 *
 * 2. inputArray(int *ptr)
 *    - Prompts the user to input SIZE integers.
 *    - Stores the input values into the array pointed to by 'ptr'.
 *
 * 3. printArray(int *ptr)
 *    - Prints the entire array in a formatted manner: [val1, val2, ..., val10]
 *
 * 4. printSecondSmallestInt(int *ptr)
 *    - Finds and prints the second smallest **distinct** integer in the array.
 *    - Uses INT_MAX from <limits.h> to initialize sentinel values for comparison.
 *    - Logic:
 *        • Iterate through the array once.
 *        • If current element < smallest, update both smallest and secondSmallest.
 *        • If current element is between smallest and secondSmallest, update secondSmallest.
 *    - Only considers values greater than the current smallest to avoid duplicates.
 *
 * 5. main()
 *    - Declares an array of SIZE.
 *    - Calls functions to input, print, and process the array.
 *    - Returns 0 on successful execution.
 *
 * Note:
 * -----
 * - If no distinct second smallest value exists (e.g., all values equal),
 *   the result will be INT_MAX, which may not be meaningful to the user.
 *   Consider adding validation or fallback messaging in production code.
 */

#include <stdio.h>
#include <limits.h> // Required for INT_MAX
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

void printSecondSmallestInt(int *ptr)
{
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < SIZE; i++)
    {
        if (ptr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = ptr[i];
        }
        else if (ptr[i] > smallest && ptr[i] < secondSmallest)
        {
            secondSmallest = ptr[i];
        }
    }
    printf("Second smallest: %d\n", secondSmallest);
}

int main()
{
    int array[SIZE];
    inputArray(array);
    printArray(array);
    printSecondSmallestInt(array);
    return 0;
}
