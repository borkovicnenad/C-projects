/*
 * Program Description:
 * --------------------
 * This C program counts and displays the frequency of each integer in a fixed-size array.
 * The values in the array are assumed to be within the range [1000, 1499].
 *
 * Components:
 * -----------
 * 1. #include <stdio.h>
 *    - For input/output functions like printf().
 *
 * 2. #include <limits.h>
 *    - Included for completeness (e.g., if INT_MAX is needed), but unused in this program.
 *
 * 3. #define SIZE 10
 *    - Defines the number of elements in the input array.
 *
 * 4. void findFrequency(int *ptr)
 *    - Accepts a pointer to an array of integers.
 *    - Uses a fixed-size auxiliary array `freq[500]` to map and count occurrences.
 *    - Assumes all values in the input array fall within the range [1000, 1499].
 *    - Logic:
 *        • Initializes all 500 frequency counters to 0.
 *        • For each element in the array, calculates the index by subtracting 1000 (i.e., value 1000 maps to index 0).
 *        • Increments the corresponding frequency counter.
 *        • After counting, iterates through the freq array:
 *            - If freq[i] is not zero, it prints the original number (i + 1000) and its frequency.
 *
 * 5. main()
 *    - Initializes an array of 10 integers with sample values between 1000 and 1499.
 *    - Calls findFrequency() to compute and print how many times each number appears.
 *
 * Output Example:
 * ---------------
 * Frequency of 1096 is : 1
 * Frequency of 1113 is : 2
 * Frequency of 1120 is : 1
 * Frequency of 1268 is : 1
 * Frequency of 1389 is : 3
 * Frequency of 1452 is : 1
 * Frequency of 1498 is : 1
 *
 * Notes:
 * ------
 * - The program assumes all array values are within [1000, 1499].
 *   If any value falls outside this range, it will cause an out-of-bounds access (undefined behavior).
 * - The approach is efficient (O(n) time) and works well for fixed, known value ranges.
 */

#include <stdio.h>
#include <limits.h> // Required for INT_MAX
#define SIZE 10


void findFrequency(int *ptr)
{
    int freq[500];
    for (int i = 0; i < 500; i++)
        freq[i] = 0;

    for (int i = 0; i < SIZE; i++)
        freq[ptr[i]-1000]++;

    for (int i = 0; i < 500; i++)
    {
        if (freq[i] != 0)
        {
            printf("Frequency of %d is : %d\n", i+1000, freq[i]);
        }
    }
}

int main()
{
    // let's suppose that array contains elements in range between 1000 and 1499
    int array[SIZE] = {1452, 1389, 1120, 1389, 1498, 1113, 1389, 1096, 1113, 1268};
    findFrequency(array);
    return 0;
}
