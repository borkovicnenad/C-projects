#include<stdio.h>

int main ()
{
    int a = 10;              // Declare an integer variable 'a' and assign it the value 10

    void *ptr = &a;          // Declare a void pointer and assign it the address of 'a'
                             // A void pointer is a "generic" pointer and doesn't know the type it points to

    // printf("%d\n", *ptr); // This line doesn't compile because you cannot dereference a void pointer directly
                             // The compiler doesn't know what type of data to expect at the memory location

    printf("%d\n", *(int*)ptr); // Correct: cast the void pointer to an int pointer before dereferencing
                                // (int*)ptr tells the compiler: "treat ptr as a pointer to int"
                                // Then, *() dereferences that int pointer to get the value at the address (which is 10)

    return 0;
}
