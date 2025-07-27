#include <stdio.h>

void swap(){

}


int main() {
    
    int a; // variable int
    a=5;
    printf("This is a value of variable a: %d\n",a);
    printf("This is address of variable a: %p\n",&a);

    // This is a value of variable a: 5
    // This is address of variable a: 0x7ffd41322d7c
    


    int *p; //pointer to int
    //printf("This is the pointer p: %p\n", p);
    //printf("This is the value of pointer p: %d\n", *p);

    // This is the value of pointer p: 2083364992
    // The pointer 'p' is declared but not initialized, meaning it points to an unknown memory location.
    // Dereferencing '*p' tries to read the value stored at that unknown location.
    // Since the memory address is arbitrary and not allocated by the program, the value is unpredictable — often called a "garbage" or "random" value.
    // This is undefined behavior and can potentially lead to crashes or security issues.
    // Always initialize pointers before dereferencing them.

    int b = 10; 
    int *p1 = &b; 
    printf("This is the value of pointer p1: %d\n", *p1); 
    // This is the value of pointer p1: 10


    int c;
    int *p2;

    c = 3;
    p2 = &c;
    printf("This is the initial value of variable c: %d\n", c);
    *p2 = 6;
    printf("This is the changed value of variable c: %d\n", c);

    // This is the initial value of variable c: 3
    // This is the changed value of variable c: 6


}