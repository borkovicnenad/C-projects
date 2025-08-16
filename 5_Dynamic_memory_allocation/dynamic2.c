#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int main(void)
{
    int *p = calloc(ARR_SIZE, sizeof *p);
    if (!p) {
        perror("calloc");
        return 1;
    }

    puts("Initial values (calloc sets them to 0):");
    for (size_t i = 0; i < ARR_SIZE; i++) {
        printf("Element %zu: %d\n", i + 1, p[i]);
    }
    fflush(stdout);

    printf("Allocation successful!\n");
    printf("Insert all elements of the array one by one:\n");

    for (size_t i = 0; i < ARR_SIZE; i++) {
        if (scanf("%d", &p[i]) != 1) {
            fprintf(stderr, "Invalid input at index %zu\n", i);
            free(p);
            return 1;
        }
    }

    puts("Elements of the array:");
    for (size_t i = 0; i < ARR_SIZE; i++) {
        printf("Element %zu: %d\n", i + 1, p[i]);
    }

    free(p);
    return 0;
}
