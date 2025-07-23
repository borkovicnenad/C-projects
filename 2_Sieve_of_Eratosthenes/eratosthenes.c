/*
 * Task: Implement the Sieve of Eratosthenes in C
 *
 * Description:
 * Write a C program that uses the Sieve of Eratosthenes algorithm to find all 
 * prime numbers up to a given positive integer N (e.g., 100).
 *
 * Requirements:
 * - The program should prompt the user to input a value for N.
 * - Create an array of boolean values initialized to true.
 * - Use the Sieve algorithm to mark non-prime numbers in the array.
 * - Print all prime numbers up to N.
 *
 * Bonus:
 * - Use dynamic memory allocation for the array.
 * - Measure and print the time taken to execute the sieve.
 * - Validate that N is greater than or equal to 2.
 *
 * Example Output:
 * Enter the upper limit (N): 30
 * Prime numbers up to 30:
 * 2 3 5 7 11 13 17 19 23 29
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    
    int i,j;
    char *prime;
    int n;
    int border;

    scanf("%d", &n);
    prime=malloc(sizeof(char)*(n+1));

    for (int i=0; i<=n; i++){
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;

    border=sqrt(n);
    for(i=2; i<=border; i++){
        if(prime[i]){
            for(j=i*2; j<=n; j+=i){
               prime[j]=0; 
            }
        }
    }

    for (i=0; i<=n; i++){
        if (prime[i]){
            printf("%d ",i);
        }
    }
    printf("\n");

    free(prime);
    return 0;
}