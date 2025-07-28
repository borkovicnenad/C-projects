#include <stdio.h>
#define SIZE 10

double findAvg(int *ptr)
{

    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += ptr[i];

    printf("%d\n", sum);
    printf("%d\n", SIZE);

    // return sum/SIZE;
    // Both sum and SIZE are integers, so the division result is an integer,
    // and then it's converted to double when returning — causing you to lose the fractional part.
    return (double)sum / SIZE;
}

int main()
{

    int grades[SIZE] = {14, 98, 75, 44, 99, 25, 74, 1, 7, 65};

    printf("Avg grade is: %f\n", findAvg(grades));
}