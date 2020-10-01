// implement your program here

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main() {

    int num;
    int a, b;
    int zeroBit;
    int isAddToA;
    int mask = 1;
    int counter_current_bit;

    num = 13;


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

    printf("a: %i\n", a);
    printf("b: %i\n", b);


}