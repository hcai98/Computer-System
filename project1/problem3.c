// implement your program here

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int split(int num, int *aa, int *bb){

    int a, b;
    int zeroBit;
    int isAddToA;
    int mask = 1;
    int counter_current_bit;

    isAddToA = 1;
    counter_current_bit = 0;
    a = 0; b = 0;
    while (num != 0) { // iterate though bits of the number until it is zero
        zeroBit = num & 0b1; // use mask to get current right-most bit

        if (zeroBit == 1) {
            if (isAddToA) {
                a = a | (1 << counter_current_bit);
                isAddToA = 0;
            } else {
                b = b | (1 << counter_current_bit);
                isAddToA = 1;
            }
            
        }
        
        num = num >> 1; // Shift bit
        counter_current_bit ++;
    }

    *aa = a;
    *bb = b;

    return 0;

}



int main() {


    // Open file
    FILE *ifp; 
    char *mode = "r"; // Set mode
    ifp = fopen("test3.in", mode);

    // Check if file opened successfully 
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    // char buffer[20];
    // while (fscanf(stream, "%s", buffer) == 1) // expect 1 successful conversion
    // {
    // // process buffer
    // }


    int num = 6;
    int a; 
    int b;

    split(num, &a, &b);

    
    printf("a: %i\n", a);
    printf("b: %i\n", b);


    return 0;

}