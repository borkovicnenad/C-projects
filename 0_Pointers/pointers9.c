#include <stdio.h>   // For printf()
#include <string.h>  // For memcpy()
#include <stdlib.h>  // For malloc() and free()

/*
 * Function: genericSwap
 * ---------------------
 * Swaps the values of two variables of any type.
 *
 * Parameters:
 *   pa   - pointer to the first variable
 *   pb   - pointer to the second variable
 *   size - size (in bytes) of the type to swap
 *
 * The function:
 *   1. Allocates temporary memory of given size.
 *   2. Copies the contents of *pa to temporary memory.
 *   3. Copies the contents of *pb to *pa.
 *   4. Copies the temporary memory (original *pa) to *pb.
 */
void genericSwap(void *pa, void *pb, int size)
{
    void *tmpMemory = malloc(size); // Allocate temporary buffer of size 'size'
    
    // Copy content of *pa to temporary memory
    memcpy(tmpMemory, pa, size);

    // Copy content of *pb to *pa
    memcpy(pa, pb, size);

    // Copy original *pa (from tmpMemory) to *pb
    memcpy(pb, tmpMemory, size);

    // NOTE: This version has a memory leak! tmpMemory is never freed.
    // A call to free(tmpMemory); is missing here.
    free(tmpMemory);
}

/*
 * Function: main
 * --------------
 * Demonstrates the use of the genericSwap function with different data types:
 * int, char, and double.
 */
int main ()
{
    // Declare and initialize some test variables
    int a = 5, b = 7;              // Two integers
    char c = 'c', d = 'd';         // Two characters
    double e = 14.7, f = 15.7;     // Two doubles

    // Swap integers using genericSwap
    genericSwap(&a, &b, sizeof(int));

    // Swap characters using genericSwap
    genericSwap(&c, &d, sizeof(char));

    // Swap doubles using genericSwap
    genericSwap(&e, &f, sizeof(double));

    // Print swapped results
    printf("%d, %d\n", a, b);      // Should print: 7, 5
    printf("%c, %c\n", c, d);      // Should print: d, c
    printf("%f, %f\n", e, f);      // Should print: 15.700000, 14.700000

    return 0;                      // Exit program
}
