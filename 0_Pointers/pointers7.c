#include <stdio.h>

/*
 * This function swaps the values of two integers pointed to by pa and pb,
 * without using a temporary variable. It uses arithmetic operations:
 * - First, it adds both values and stores the result in *pa.
 * - Then, it subtracts the new *pa (which is a + b) by *pb to get the original *pa value into *pb.
 * - Finally, it subtracts the new *pb from *pa to retrieve the original *pb into *pa.
 */
void swapFunction(int *pa, int *pb)
{
    *pa = *pa + *pb;  // Step 1: *pa = *pa + *pb
    *pb = *pa - *pb;  // Step 2: *pb = (*pa + *pb) - *pb = original *pa
    *pa = *pa - *pb;  // Step 3: *pa = (*pa + *pb) - original *pa = original *pb
}

int main ()
{
    int a = 5;            // Declare integer variable a and assign value 5
    int b = 7;            // Declare integer variable b and assign value 7

    printf("Variable a contains value %d, and variable b contains value %d.\n", a, b);
    // Output before swap: a = 5, b = 7

    swapFunction(&a, &b); // Call swapFunction with addresses of a and b

    printf("After swap, variable a contains value %d, and variable b contains value %d.\n", a, b);
    // Output after swap: a = 7, b = 5

    return 0;             // Return 0 to indicate successful execution
}
