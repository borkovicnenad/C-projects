#include <stdio.h>

int main (){

    int num = 30;        // Declare an integer variable 'num' and assign it the value 30.
    int *p;              // Declare a pointer to an integer named 'p'.

    printf("%d\n", num); // Print the value of 'num'. Expected output: 30

    p = &num;            // Assign the address of 'num' to the pointer 'p'.
                         // Now 'p' points to the memory location of 'num'.

    printf("%p\n", &num); // Print the address of 'num'.
    printf("%p\n", p);    // Print the value stored in 'p' (which should be the same as &num).

    *p = 20;             // Dereference the pointer 'p' and assign 20 to that memory location.
                         // This effectively changes the value of 'num' to 20.

    printf("%d\n", num); // Print the new value of 'num'. Expected output: 20
}
