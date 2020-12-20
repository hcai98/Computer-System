// Author: Haoyang Cai
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h> 
#include<string.h>


// The function return the sum of all digits
int getDigitSum(int num){
    int sum = 0;
    // loop over all digits
    while (1) {
        // printf("the digit is: %i\n", num % 10);
        sum += num % 10; // add current digit to sum
        num = num / 10; // delete the current digit
        if (num == 0){break;} // if reached the last digit, break
    }
    return sum;
}

// the function return 1 if prime, and 0 if not
int isPrime(int num){
    int flag_prime = 1;
    int i;
    for (i=2; i<num; i++){
        if ((num % i) == 0){
            flag_prime = 0;
            break;
        } 
    }
    return flag_prime;
}

// the function clear the output file
void prepare_file(char* FILE_NAME){
    FILE *ifp; 
    char *mode = "w"; // Set mode to write
    ifp = fopen(FILE_NAME, mode); // set file name
    if (ifp == NULL) {    // Check if file opened successfully 
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }    
    fprintf(ifp, ""); // clear file
    fclose(ifp); // close file
}

// this function combines results in 10 files into 1
void combine_results(){
    // clear all previous output
    char *filename_target = "./outputs/output_multiProcess";
    prepare_file(filename_target); 

    // open target file
    FILE *ifp_target; 
    char *mode = "a"; // Set mode to add
    ifp_target = fopen(filename_target, mode);

    // Loop over all files
    int process_counter;
    for (process_counter=0; process_counter<10; process_counter++){
        
        // get output name for the search 
        char filename[50] = "./outputs/output";
        char buffer[10];
        sprintf(buffer, "%i", process_counter);
        strcat(filename, buffer);

        // open source files (single process results)
        FILE *ifp_source = fopen(filename, "r"); 

        // write results into the target file
        char c;
        while ((c = fgetc(ifp_source)) != EOF) {
            fputc(c, ifp_target); 
        }

        fclose(ifp_source); 
    }
    fclose(ifp_target); 
}

// run using a single process
void runSingleProcess(char* FILE_NAME, int searchRangeD, int searchRangeU){

    // prepare file
    prepare_file(FILE_NAME);

    // begin time
    time_t begin_time_single = time(NULL);
    
    // begin number search
    int num;
    for (num=searchRangeD; num<=searchRangeU; num++) {
        if (getDigitSum(num) == 11){ // check if digits add to 11
            if (isPrime(num)==1){  // check if number is prime
                // conditions satisfied, write number to file
                FILE *ifp; 
                char *mode = "a"; // Set mode to add

                ifp = fopen(FILE_NAME, mode); // open file
                fprintf(ifp, "%i\n", num); // add number
                fclose(ifp); // close file
            }
        }
    }
    
    // end time
    time_t end_time_single = time(NULL);
    printf("SearchRange - %d-%d Runtime - %d\n", searchRangeD, searchRangeU, (int) (end_time_single-begin_time_single));

    return;
}

// run with 10 child process
void runMultiProcess(int searchRange){
    pid_t pid;
    int child_status;
    int process_counter;
    int upper, lower;
    int increment = searchRange / 10;
    time_t begin_allprocess = time(NULL); // log time begin

    // distribute job to 10 processes
    for (process_counter=0; process_counter<10; process_counter++){
        pid = fork(); // create child process
        if (pid == 0) {
            
            // set search boundary for each child process
            lower = increment * process_counter + 1;
            upper = lower + increment -1;

            // get output name for the search 
            char filename[50] = "./outputs/output";
            char buffer[10];
            sprintf(buffer, "%i", process_counter);
            strcat(filename, buffer);
            
            // begin search
            runSingleProcess(filename, lower, upper);
            // end search

            exit(0);

        } 
    }
    
    // wait for all children
    while ((pid=waitpid(-1, &child_status, 0))!= -1){}
   
    // combine all results into one file
    combine_results();

    // log time finished
    time_t end_allprocess = time(NULL);
    printf("\nSearch finished. Runtime - %ld\n", end_allprocess - begin_allprocess);

}


int main(){

    // global parameters
    int searchRange = 10000000;
    char* FILE_NAME = "./outputs/output_singleProcess";

    // run entire job with single process and print runtime
    printf("---- Single-Process Search ----\n");
    runSingleProcess(FILE_NAME, 1, searchRange);
    printf("------------- End -------------\n\n");

    //run job with 10 children process
    printf("---- Multi-Process Search ----\n");
    runMultiProcess(searchRange);
    printf("------------- End -------------\n\n");

    return 0;
}