#include <stdio.h>

int main() {
    int a;
    printf("Size of int: %ld bytes\n", sizeof(a));

    short b;
    printf("Size of short: %ld bytes\n", sizeof(b));

    long c;
    printf("Size of long: %ld bytes\n", sizeof(c));

    long long d;
    printf("Size of long long: %ld bytes\n", sizeof(d));

    unsigned int e;
    printf("Size of unsigned int: %ld bytes\n", sizeof(e));

    unsigned short f;
    printf("Size of unsigned short: %ld bytes\n", sizeof(f));

    unsigned long g;
    printf("Size of unsigned long: %ld bytes\n", sizeof(g));

    unsigned long long h;
    printf("Size of unsigned long long: %ld bytes\n", sizeof(h));

    char i;
    printf("Size of char: %ld bytes\n", sizeof(i));

    unsigned char j;
    printf("Size of unsigned char: %ld bytes\n", sizeof(j));

    float k;
    printf("Size of float: %ld bytes\n", sizeof(k));

    double l;
    printf("Size of double: %ld bytes\n", sizeof(l));

    long double m;
    printf("Size of long double: %ld bytes\n", sizeof(m));

    void *n;
    printf("Size of void pointer: %ld bytes\n", sizeof(n));

    return 0;
}
/*
Size of int: 4 bytes
Size of short: 2 bytes
Size of long: 8 bytes
Size of long long: 8 bytes
Size of unsigned int: 4 bytes
Size of unsigned short: 2 bytes
Size of unsigned long: 8 bytes
Size of unsigned long long: 8 bytes
Size of char: 1 bytes
Size of unsigned char: 1 bytes
Size of float: 4 bytes
Size of double: 8 bytes
Size of long double: 16 bytes
Size of void pointer: 8 bytes
*/