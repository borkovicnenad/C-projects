#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10
#define EXTRA    5

int main(void)
{
    // Current logical length of the array (starts at ARR_SIZE)
    size_t n = ARR_SIZE;

    // Allocate zero-initialized memory for n integers
    // calloc sets all bytes to 0, so initial values will print as 0
    int *p = calloc(n, sizeof *p);
    if (!p) {
        // On allocation failure, print system error message and exit
        perror("calloc");
        return 1;
    }

    puts("Initial values (calloc sets them to 0):");
    for (size_t i = 0; i < n; i++) {
        // %zu is the correct printf specifier for size_t
        // p[i] reads the i-th element (initially 0 because of calloc)
        printf("Element %zu: %d\n", i + 1, p[i]);
    }
    fflush(stdout); // In some IDEs, ensures the text appears immediately

    printf("Allocation successful!\n");
    printf("Insert all elements of the array one by one:\n");

    // Read n integers from stdin into the allocated array
    for (size_t i = 0; i < n; i++) {
        // scanf returns the number of successfully read items
        if (scanf("%d", &p[i]) != 1) {
            fprintf(stderr, "Invalid input at index %zu\n", i);
            free(p);
            return 1;
        }
    }

    puts("Elements of the array:");
    for (size_t i = 0; i < n; i++) {
        printf("Element %zu: %d\n", i + 1, p[i]);
    }

    // ---- REALLOC DEMO: grow the array by EXTRA elements ----
    size_t old_n = n;
    size_t new_n = n + EXTRA;

    // Attempt to resize the allocation to hold new_n integers
    // Note: realloc may move the block; do not use 'p' after this call
    // unless it succeeds and you assign it the returned pointer.
    int *tmp = realloc(p, new_n * sizeof *p);
    if (!tmp) {
        // On failure, the original pointer 'p' remains valid.
        // Clean it up and exit.
        perror("realloc");
        free(p);
        return 1;
    }
    // On success, take ownership of the new pointer and update the length.
    p = tmp;
    n = new_n;

    printf("\nArray resized from %zu to %zu. Enter %zu more elements:\n",
           old_n, n, n - old_n);

    // Fill only the newly added elements (the old ones are preserved by realloc)
    // New memory is NOT guaranteed to be zeroed here (realloc != calloc).
    for (size_t i = old_n; i < n; i++) {
        if (scanf("%d", &p[i]) != 1) {
            fprintf(stderr, "Invalid input at index %zu\n", i);
            free(p);
            return 1;
        }
    }

    puts("All elements after resizing:");
    for (size_t i = 0; i < n; i++) {
        printf("Element %zu: %d\n", i + 1, p[i]);
    }

    // Always free the last valid pointer returned by malloc/calloc/realloc
    free(p);
    return 0;
}
