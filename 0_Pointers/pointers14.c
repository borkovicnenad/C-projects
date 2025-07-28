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

int main()
{
    int array[SIZE];
    inputArray(array);
    printArray(array);
    return 0;
}