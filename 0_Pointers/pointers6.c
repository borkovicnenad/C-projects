#include <stdio.h>


int main (){
    int array[3];
    printf("Size of array is: %ld bytes\n", sizeof(array));
    // Size of array is: 12

    int *ptr1;              // Declare a pointer to an int
    int grade1 = 80;        // Declare an int variable and assign value 80
    ptr1 = &grade1;         // Store the address of grade1 in the pointer

    printf("Size of pointer ptr1 is: %ld bytes\n", sizeof(ptr1));
    // This prints the size of the pointer variable itself, not what it points to.
    // On a 64-bit system, all pointers (regardless of the data type they point to)
    // are typically 8 bytes in size.
    // Output:
    // Size of pointer ptr1 is: 8 bytes

}