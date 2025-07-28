#include <stdio.h>
#define SIZE 10

void inputArray(int *ptr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter the value %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
}

void printArray(int *ptr)
{
    printf("Array: [");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("%d]\n", ptr[i]);
        else
            printf("%d, ", ptr[i]);
    }
}

void minMax(int *arrPtr, int *minPtr, int *maxPtr)
{
    *minPtr = arrPtr[0];
    *maxPtr = arrPtr[0];
    for (int i=1; i<SIZE; i++)
    {
        if (*minPtr > arrPtr[i])
            *minPtr = arrPtr[i];
        if (*maxPtr < arrPtr[i])
            *maxPtr = arrPtr[i];
    }
}


int main()
{
    int array[SIZE];
    inputArray(array);
    printArray(array);
    
    int min, max;
    minMax(array, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);
    return 0;
}