// implement your program here

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// input parameter: 1. number to split 2. address of a 3. address of b
int split(int num, int *aa, int *bb){

    int a = 0, b = 0; // arrays to store splitted values temporarily
    int zeroBit; // temp value to store the 0 bit of num after shifting
    int isAddToA = 1; // check whether add to a or b
    int counter_current_bit = 0; // log where to put the 1 detected

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
        
        num = num >> 1; // shift bit
        counter_current_bit ++;
    }

    // pass values of a and b to main by reference
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

    // Initialize variables
    int num, a, b;

    // start iteration
    while (!feof(ifp)) {

        // read input
        fscanf(ifp, "%d", &num);

        // check exit condition
        if (num == 0){break;}

        // split num into a and b
        split(num, &a, &b);

        // output values
        printf("%d %d\n", a, b);
    }

    // close file
    fclose(ifp);

    return 0;

}