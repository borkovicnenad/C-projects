#include <stdio.h>

int sumArray(int arr[], int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}



int sumArrayUsingPointer(int *ptr, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + ptr[i];
    }
    return sum;
}

int main()
{
    int grades[3] = {3, 5, 7};
    
    // Call sumArray using standard array notation
    int result = sumArray(grades, 3);
    printf("Sum = %d\n", result);
    
    // Call sumArrayUsingPointer using pointer-style access
    int result1 = sumArrayUsingPointer(grades, 3);
    printf("Sum = %d\n", result1);
    return 0;
}