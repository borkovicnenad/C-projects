#include <stdio.h>
#define SIZE 10

int findMax(int *ptr)
{

    int max = ptr[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    return max;
}

int main()
{

    int grades[SIZE] = {14, 98, 75, 44, 99, 25, 74, 1, 7, 65};

    printf("Max number is: %d\n", findMax(grades));

}