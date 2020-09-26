// Author: Haoyang Cai (hc2283)

// implement your program here
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// Main Function
int main(){

    // Open file
    FILE *ifp; 
    char *mode = "r"; // Set mode
    ifp = fopen("test1.in", mode);

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

    // Initialize variables
    int month, day, hour, minute, seconds;
    int s1, s2, m1, m2, h1, h2, d1, d2, mo1, mo2;

    // Start iteration
    int i;
    for (i = 0; i < num_lines; i++){
        // Get Line
        fgets(buffer, 20, ifp); 
        // printf("Buffer line is: %s", buffer);

        // Get componets of input
        sscanf(buffer, "%d/%d %d:%d:%d", &month, &day, &hour, &minute, &seconds);
        // printf("Month: %d\nDay: %d\nHour: %d\nMinute: %d\nSeconds: %d\n\n", month, day, hour, minute, seconds);

        // Check if valid
        if ((minute > 60) || (minute < 0)){printf("INVALID\n");continue;}
        if ((hour > 23) || (hour < 0)){printf("INVALID\n");continue;}
        if ((seconds > 60) || (seconds < 0)){printf("INVALID\n");continue;}
        if ((month > 12) || (month < 1)){printf("INVALID\n");continue;}
        
        if (month == 1 || month==3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day > 31 || day < 1) {printf("INVALID\n");continue;} 
        } else if (month == 4 || month == 6 || month == 9 || month == 11){
            if (day > 30 || day < 1) {printf("INVALID\n");continue;}
        } else {
            if (day > 28 || day < 1) {printf("INVALID\n");continue;}
        }

        // Move digit to corresponding position
        s1 = seconds % 10;
        s2 = (seconds / 10) << 4;

        m1 = (minute % 10) << 7;
        m2 = (minute / 10) << 11;

        h1 = (hour % 10) << 14;
        h2 = (hour / 10) << 18;

        d1 = (day % 10) << 20;
        d2 = (day / 10) << 24;

        mo1 = (month % 10) << 26;
        mo2 = (month / 10) << 30;

        printf("time: %d\n", s1 + s2 + m1 + m2 + h1 + h2 + d1 + d2 + mo1 + mo2);
    }

    return 0;
}