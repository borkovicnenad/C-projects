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

/*
 * Program: Sieve of Eratosthenes
 *
 * Description:
 * This program reads an integer n from the user and prints all prime numbers
 * from 2 up to n using the Sieve of Eratosthenes algorithm.
 *
 * Key Concepts:
 * - A prime number is a number greater than 1 that is divisible only by 1 and itself.
 * - The Sieve of Eratosthenes algorithm efficiently identifies all prime numbers
 *   up to a given limit n.
 *
 * Algorithm Steps:
 * 1. Allocate a dynamic array of size n+1 (`prime[]`), where each index represents
 *    a number from 0 to n. Each element is initialized to 1 (true), indicating
 *    that the number is initially assumed to be prime.
 *
 * 2. Set `prime[0]` and `prime[1]` to 0, because 0 and 1 are not prime numbers.
 *
 * 3. Compute the square root of n (`border = sqrt(n)`) since all non-prime
 *    numbers ≤ n have a prime factor ≤ sqrt(n).
 *
 * 4. For every number i from 2 up to sqrt(n):
 *    - If i is still marked as prime (`prime[i] == 1`),
 *      then mark all of its multiples (starting from i*2) as non-prime by
 *      setting `prime[j] = 0` for j = i*2, i*3, ..., up to n.
 *
 * 5. After completing the sieve, iterate through the `prime[]` array and
 *    print all numbers that remain marked as prime.
 *
 * 6. Free the dynamically allocated memory.
 *
 * Example:
 * Input: 30
 * Output: 2 3 5 7 11 13 17 19 23 29
 *
 * Notes:
 * - The array uses `char` instead of `bool` to save memory.
 * - `malloc` is used for dynamic memory allocation.
 * - `-lm` flag must be used during compilation to link the math library.
 */
