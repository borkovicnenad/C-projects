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

// function to print an operation result
void show(const char *label, int result) {
    printf("%-6s = %4d  (", label, result);
    print_bits(result);
    printf(")\n");
}

int main(void) {
    int a = 5;   // 0000...0101
    int b = 7;   // 0000...0111

    printf("a = %d (", a); print_bits(a); printf(")\n");
    printf("b = %d (", b); print_bits(b); printf(")\n\n");

    show("a & b", a & b);   // AND
    show("a | b", a | b);   // OR
    show("a ^ b", a ^ b);   // XOR
    show("~a", ~a);         // NOT (unary)
    show("a << 1", a << 1); // left shift
    show("b >> 1", b >> 1); // right shift

    return 0;
}
