#include <stdio.h>

int main (){

    int *ptr;
    int grades[3] = {100, 80, 60};
    printf("Grades start at address: %p\n", grades);
    printf("Grades start at address: %p\n", &grades[0]);
    printf("Grades start at address: %p\n", &grades[0] + 1);
    printf("Grades start with value: %d\n", *grades);

    // Grades start at address: 0x7ffd1b75889c
    // Grades start at address: 0x7ffd1b75889c
    // Grades start at address: 0x7fffedd72fc0
    // Grades start with value: 100
}



/*
This code prints the memory addresses of two elements in the 'grades' array:

    printf("Grades start at address: %p\n", &grades[0]);
    printf("Grades start at address: %p\n", &grades[0] + 1);

Explanation:

1. &grades[0] retrieves the address of the first element in the array.
2. &grades[0] + 1 advances the pointer by one element, not one byte.

   That means it points to the memory location of the second element in the array.

Example Output:

    Grades start at address: 0x7fffedd72fbc
    Grades start at address: 0x7fffedd72fc0

Address difference:

    0x7fffedd72fc0 - 0x7fffedd72fbc = 0x4 bytes (i.e., 4 bytes apart)

Conclusion:

- Each element in the 'grades' array occupies 4 bytes.
- This implies the array is likely of type 'int', since 'int' typically uses 4 bytes on most systems.
- Pointer arithmetic accounts for the size of the type it points to, not raw bytes.
*/
