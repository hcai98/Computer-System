// Author: Haoyang Cai (hc2283)

// implement your program here
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int convert(){

}


// Main Function
int main(){


    int num_row = 3;

    FILE *ifp;
    char *mode = "r";
    ifp = fopen("test1.in", mode);

    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }
    
    int num;
    fscanf(ifp, "%d", &num);
    printf("Number is: %d\n", num);

    char line[20];
    fgets(line, 20, ifp);
    line[strlen(line)-1]='\0';   
    printf("Line is: %s\n", line);

    fgets(line, 20, ifp);
    line[strlen(line)-1]='\0';
    printf("Line is: %s\n", line);


    fclose(ifp);

    return 0;
}