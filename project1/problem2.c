// Author: Haoyang Cai (hc2283)
// Purpose: read the three values representing the three separate colors and produce a single hexadecimal value.

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {

    // Open file
    FILE *ifp; 
    char *mode = "r"; // Set mode
    ifp = fopen("test2.in", mode);

    // Check if file opened successfully 
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    // Read first line of document to get number of rows;
    int num_lines;
    char buffer[20]; 
    fgets(buffer, 20, ifp); // store first line to a buffer
    sscanf(buffer, "%d", &num_lines); // Scan  number from buffer;

    // Initialize values
    int r, g, b;
    int i;
    for (i = 0; i < num_lines; i++) {
        
        // Get Line
        fgets(buffer, 20, ifp); 

        // Scan color
        sscanf(buffer, "%d, %d, %d", &r, &g, &b);

        // Check if input is valid
        if ((r <= 255) && (r >= 0) 
        && (g <= 255) && (g >= 0) 
        && (b <= 255) && (b >= 0)) {
            printf("#%02x%02x%02x\n", r, g, b);
        } else {
            printf("INVALID\n");
            continue;
        }

    }

}