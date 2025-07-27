#include <stdio.h>

// This function uses pass-by-value:
// The values of n1 and n2 are copied from the arguments a and b.
// Changes to n1 and n2 inside this function do not affect the original variables.
int findMax(int n1, int n2){
    if (n1 > n2)
        return n1;  // Return the greater of the two
    else 
        return n2;
}

// This function uses pass-by-reference via pointers:
// Instead of returning values, it modifies the values at the addresses pointed to by pMax and pMin.
void findMinAndMax(int n1, int n2, int *pMax, int *pMin){
    if (n1 > n2){
        *pMin = n2;  // Store n2 in the memory location pointed to by pMin
        *pMax = n1;  // Store n1 in the memory location pointed to by pMax
    }
    else{ 
        *pMin = n1;
        *pMax = n2;
    }
}

void main (){
    int a = 5, b = 7;

    // Pass-by-value example
    int max;
    max = findMax(a,b);  // a and b are passed by value (copied into n1 and n2)
    printf("Max between %d and %d is %d\n", a, b, max);

    // Pass-by-reference using addresses of local variables
    int minResult, maxResult;
    findMinAndMax(a, b, &maxResult, &minResult);
    printf("Max is: %d, and Min is: %d\n", maxResult, minResult);
}
