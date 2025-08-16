#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 10

int main()
{

    int *p;
    p = (int *)malloc(sizeof(int) * ARR_SIZE);

    if (p != NULL)
        printf("Allocation successfull!\n");
    else
        printf("Allocation failed!\n");

    printf("Insert all elements of the array one by one:\n");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Elements of the array:\n");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("Element %d: %d\n", i+1, p[i]);
    }

    return 0;
}