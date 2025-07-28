#include <stdio.h>
#include <stdbool.h>

bool containsNumber(int *ptr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == num)
            return true;
    }
    return false;
}

int main()
{

    int array[10] = {11, 25, 14, 98, 54, 65, 22, 58, 47, 66};
    int size = sizeof(array) / sizeof(int);

    if (containsNumber(array, size, 47))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}

//You must pass the size when dealing with arrays as function arguments in C, 
//because arrays decay into pointers, and pointer arguments don't retain size information.