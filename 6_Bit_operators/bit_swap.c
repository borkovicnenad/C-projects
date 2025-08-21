#include <stdio.h>
#include <limits.h>  // for CHAR_BIT

// helper function to print an integer in binary
void print_bits(int value) {
    int bits = sizeof(int) * CHAR_BIT;  // usually 32 bits
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" "); // spacing every byte
    }
}

void swap(int *x, int *y) {
    if (x != y) {
        printf("Initial state:\n");
        printf("  x (address) = %p, *x = %d, bits = ", (void*)x, *x);
        print_bits(*x);
        printf("\n");
        printf("  y (address) = %p, *y = %d, bits = ", (void*)y, *y);
        print_bits(*y);
        printf("\n\n");

        *x = *x ^ *y;
        printf("After step 1 (x = x ^ y):\n");
        printf("  x = %d, bits = ", *x);
        print_bits(*x);
        printf("\n");
        printf("  y = %d, bits = ", *y);
        print_bits(*y);
        printf("\n\n");

        *y = *x ^ *y;
        printf("After step 2 (y = x ^ y):\n");
        printf("  x = %d, bits = ", *x);
        print_bits(*x);
        printf("\n");
        printf("  y = %d, bits = ", *y);
        print_bits(*y);
        printf("\n\n");

        *x = *x ^ *y;
        printf("After step 3 (x = x ^ y):\n");
        printf("  x = %d, bits = ", *x);
        print_bits(*x);
        printf("\n");
        printf("  y = %d, bits = ", *y);
        print_bits(*y);
        printf("\n\n");
    }
}

int main(void) {
    int a = 5, b = 7;

    printf("Main program before swap: a = %d, b = %d\n\n", a, b);

    swap(&a, &b);

    printf("Main program after swap: a = %d, b = %d\n", a, b);

    return 0;
}
