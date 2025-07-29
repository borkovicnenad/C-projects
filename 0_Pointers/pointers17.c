/*
 * Program: Character Array Reverser
 *
 * Description:
 * This program reads 11 characters from the user into an array,
 * prints the array, then reverses its contents using recursion,
 * and finally prints the reversed array.
 *
 * Key Features:
 * - Handles character input safely using `scanf(" %c", ...)` to skip whitespace.
 * - Uses pointer arithmetic and indexing for character manipulation.
 * - Demonstrates recursion by reversing the array in-place.

 * Functions:
 * 
 * 1. inputArray(char *ptr)
 *    - Prompts the user to input SIZE (11) characters, one at a time.
 *    - The space before `%c` in `scanf(" %c", &ptr[i])` ensures that whitespace
 *      characters like newline (`\n`) from previous input are ignored.
 *
 * 2. printArray(char *ptr)
 *    - Prints the contents of the character array in a nicely formatted way,
 *      with commas separating characters and square brackets enclosing the list.
 *
 * 3. swapChars(char *ptr1, char *ptr2)
 *    - Swaps two characters at the memory locations pointed to by `ptr1` and `ptr2`.
 *    - Uses a temporary variable of type `char` to perform the swap safely.
 *
 * 4. reverseArray(char *ptr, int i)
 *    - Recursively swaps elements from the beginning and end of the array,
 *      moving toward the center, effectively reversing the array.
 *    - Uses `swapChars()` for each symmetric pair: `ptr[i]` with `ptr[SIZE - 1 - i]`.
 *    - The recursion continues while the two indices haven't crossed or met.
 *
 * Main Function:
 * - Declares a character array of size 11.
 * - Calls `inputArray()` to read user input.
 * - Calls `printArray()` to show the original array.
 * - Calls `reverseArray()` with initial index `0` to reverse the array in place.
 * - Calls `printArray()` again to show the reversed array.
 *
 * Example Execution:
 * Input:  A B C D E F G H I J K
 * Output:
 *   Array: [A, B, C, D, E, F, G, H, I, J, K]
 *   Array: [K, J, I, H, G, F, E, D, C, B, A]
 */


#include <stdio.h>
#define SIZE 11

void inputArray(char *ptr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter the value %d: ", i + 1);
        scanf(" %c", &ptr[i]); // space before %c tells scanf to skip whitespace
    }
    printf("\n");
}

void printArray(char *ptr)
{
    printf("Array: [");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("%c]\n", ptr[i]);
        else
            printf("%c, ", ptr[i]);
    }
}

void swapChars(char *ptr1, char *ptr2)
{
    // char *ptrtmp = *ptr1;  This is incorrect: you're assigning a char to a char*
    char tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void reverseArray(char *ptr, int i)
{
    swapChars(&ptr[i], &ptr[SIZE - 1 - i]);
    if (SIZE - 1 - i - i > 1)
    {
        i++;
        reverseArray(ptr, i);
    }
}

int main()
{
    char array[SIZE];
    inputArray(array);
    printArray(array);
    reverseArray(array, 0);
    printArray(array);

    return 0;
}
