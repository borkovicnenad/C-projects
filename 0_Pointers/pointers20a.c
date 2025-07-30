/*
 * Program Description:
 * --------------------
 * This C program checks whether a user-input character array of fixed size (10) is a palindrome.
 * A palindrome is a sequence that reads the same backward as forward.
 *
 * Components:
 * -----------
 * 1. #define SIZE 10
 *    - Defines the size of the character array to be processed.
 *
 * 2. void inputArray(char *ptr)
 *    - Prompts the user to input SIZE characters one by one.
 *    - Uses " %c" in scanf to ignore whitespace (e.g., newlines, spaces).
 *
 * 3. void printArray(char *ptr)
 *    - Prints the array in a clean format, like: [a, b, c, ..., j]
 *
 * 4. int isPalindrome(char *ptr, int i)
 *    - Recursively checks if the array is a palindrome by comparing characters at mirrored indices.
 *    - Base case: if ptr[i] != ptr[SIZE - 1 - i], it returns 1 (not a palindrome).
 *    - Recursive case: continues comparing inward if no mismatch is found yet.
 *    - Also includes debug print statements to visualize comparison steps.
 *    - Returns 1 if not a palindrome, 0 if it is.
 *
 * 5. int main()
 *    - Declares a character array of size 10.
 *    - Calls inputArray() to get values from the user.
 *    - Calls printArray() to show the entered array.
 *    - Calls isPalindrome() and stores the result.
 *    - Prints whether the array is a palindrome or not based on the result.
 *
 * Sample Run:
 * -----------
 * Enter the value 1: r
 * Enter the value 2: a
 * Enter the value 3: c
 * Enter the value 4: e
 * Enter the value 5: c
 * Enter the value 6: a
 * Enter the value 7: r
 * Enter the value 8: x
 * Enter the value 9: y
 * Enter the value 10: z
 * 
 * Array: [r, a, c, e, c, a, r, x, y, z]
 * is r equal to z?
 * => The array isn't palindrome.
 *
 * Notes:
 * ------
 * - The array size is fixed to 10 and assumes that the user enters exactly 10 characters.
 * - The function uses a hardcoded SIZE macro; it could be improved by passing size dynamically.
 * - The recursive function does not explicitly return a value if the input is a palindrome of odd length.
 *   Adding a final `return 0;` after the second if-statement would ensure all paths return a value.
 */

#include <stdio.h>
#define SIZE 10

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

int isPalindrome(char *ptr, int i)
{
    printf("is %c equal to %c?\n", ptr[i], ptr[SIZE - 1 - i]);
    if (ptr[i] != ptr[SIZE - 1 - i])
        return 1;

    if (SIZE - 1 - i - i >= 1)
    {
        printf("Checking if");
        int flag = isPalindrome(ptr, i + 1);
        printf("Checking flag for %d and %d => %d\n", i, SIZE - 1 - i, flag);
        if (flag == 1)
            return 1;
        else
            return 0;
    }
}

int main()
{
    char array[SIZE];
    inputArray(array);
    printArray(array);
    int flag;
    flag = isPalindrome(array, 0);
    if (flag == 1)
        printf("The array isn't palindrome.\n");
    else if (flag == 0)
        printf("The array is palindrome.\n");
}