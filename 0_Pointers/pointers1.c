#include <stdio.h>

int main (){

    int num1 = 5, num2 = 7;       // Initialize two integers: num1 = 5, num2 = 7
    int *ptrA, *ptrB;             // Declare two integer pointers

    printf("num1 = %d, num2 = %d \n", num1, num2);
    // Output: num1 = 5, num2 = 7

    ptrA = &num1;                 // ptrA now points to the memory address of num1
    ptrB = &num2;                 // ptrB now points to the memory address of num2

    printf("num1 = %d, num2 = %d \n", num1, num2);
    // Still unchanged: num1 = 5, num2 = 7

    *ptrA = *ptrA + 1;            // Increment the value pointed to by ptrA (num1) by 1 → num1 = 6
    *ptrB = *ptrB + 3;            // Increment the value pointed to by ptrB (num2) by 3 → num2 = 10

    printf("num1 = %d, num2 = %d \n", num1, num2);
    // Output after modifications: num1 = 6, num2 = 10

    ptrA = ptrB;                  // ptrA now points to the same location as ptrB (i.e., &num2)
    ptrB = ptrA;                  // ptrB remains pointing to &num2 (same as before)

    printf("num1 = %d, num2 = %d \n", num1, num2);
    printf("*ptrA = %d, *ptrB = %d \n", *ptrA, *ptrB);
    // Both ptrA and ptrB point to num2 → *ptrA = *ptrB = 10

    num1 = *ptrB;                 // num1 is assigned the value at ptrB → num1 = 10
    num2 = num1 - 3;              // num2 is now 10 - 3 → num2 = 7

    printf("num1 = %d, num2 = %d \n", num1, num2);
    // Final values: num1 = 10, num2 = 7
}
