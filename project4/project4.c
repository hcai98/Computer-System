// Author Name: Haoyang Cai
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){

    // Open file
    FILE *ifp; 
    char *mode = "r"; // Set mode
    ifp = fopen("Project4Input.txt", mode); // set file name

    // Check if file opened successfully 
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    int num_lines = 30;
    char buffer[50];
    char * token;

    // initialize the tables
    const int max_row = 100;
    int TLB[max_row][3] = {0};
    int VPT[max_row][2] = {0};
    int PPC[max_row][6] = {0};
    int size_TLB = 0;
    int size_VPT = 0;
    int size_PPC = 0;

    // Start Reading Input files
    int i;
    while (1) {
        // Get Line
        fgets(buffer, 50, ifp); 
        if (strcmp(buffer, "DONE") == 0){break;} // end reading file

        // Extract the first token
        token = strtok(buffer, ",");

        // read the table of according type
        int temp = -1;
        if (strcmp(token, "TLB") == 0){
            for (int i = 0; i < 3; i++){
                token = strtok(NULL, ",");
                temp = (int)strtol(token, NULL, 16); // convert hex string to int
                TLB[size_TLB][i] = temp; // store value
            }
            size_TLB ++; // increment the table size
        }
        if (strcmp(token, "Page") == 0){
            for (int i = 0; i < 2; i++){
                token = strtok(NULL, ",");
                temp = (int)strtol(token, NULL, 16); // convert hex string to int
                VPT[size_VPT][i] = temp;
            }
            size_VPT ++; // increment the table size
        }
        if (strcmp(token, "Cache") == 0){
            for (int i = 0; i < 6; i++){
                token = strtok(NULL, ",");
                temp = (int)strtol(token, NULL, 16); // convert hex string to int
                PPC[size_PPC][i] = temp; // store value
            }
            size_PPC ++; // increment the table size
        }

    }

    // close file
    fclose(ifp);

    // read virtual address
    int va;
    printf("Enter Virtual Address: ");
    scanf ("%X",&va);
    
    // split virtual address
    int vpo = va & 0b111111;
    int vpn = va >> 6;

    // split vpn
    int tlbi = vpn & 0b11;
    int tlbt = vpn >> 2;

    // search in TLB
    int isHit_TLB = 0;
    int ppn = -1;
    for(i=0; i<size_TLB; i++){
        if (TLB[i][0] == tlbi) { // if set index match, check tag
            if (TLB[i][1] == tlbt) { // if tag match, hit
                ppn = TLB[i][2];
                isHit_TLB = 1;
            }
        }
    }

    // if miss in TLB, check VPT
    int isHit_VPT = 0;
    if (!isHit_TLB){ 
        // iterate over VPT
        for(i = 0; i < size_VPT; i++){
            if (VPT[i][0] == vpn) { // if vpn match, retrieve PPN 
                ppn = VPT[i][1];
                isHit_VPT = 1;
            }
        }
    }

    // if physical address is obtained, check PPC
    int isHit_PPC = 0;
    int cache = -1;
    if (isHit_TLB || isHit_VPT){
        int ppo = vpo;
        int ct = ppn;
        int co = ppo & 0b11; // get cache offset
        int ci = ppo >> 2; // get cache index

        // check PPC to get cache
        for(i = 0; i < size_PPC; i++){
            // check if index hit
            if (PPC[i][0] == ci){
                // if index hit, check if tag match
                if (PPC[i][1] == ct){
                    // if tag match, retrieve value
                    cache = PPC[i][co+2];
                    isHit_PPC = 1;
                    printf("HIT! Value: %X\n", cache);
                }
            }
        }

    } else { // if ppn not retrived, search fail
        printf("Can not be determined\n");
        printf("Program Exiting...\n");
        return 0;
    }

    if(!isHit_PPC){
        printf("Can not be determined\n");
        printf("Program Exiting...\n");
    }

    // Test prints
    // printf("\nisHit_TLB: %d\n", isHit_TLB);
    // printf("isHit_VPT: %d\n", isHit_VPT);
    // printf("isHit_PPC: %d\n", isHit_PPC);
    // printf("ppn: %X\n", ppn);
    // printf("Program Ends.\n");

    return 0;

}