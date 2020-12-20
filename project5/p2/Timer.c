// Author: Haoyang Cai
#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 
#include <signal.h>

// global variables
int secs = 0;

void handle_sigint(int sig) { 
       secs = 0;
} 

int main(int argc, char **argv){
    sleep(1);
    signal(SIGINT, handle_sigint);
    
    int i, j;
    int time_limit = 5;

    while (secs < time_limit) {
        // printf("(Time Remaining: %i)\n", time_limit - secs);
        fflush(0);

        sleep(1);
        secs ++;

        if (secs == time_limit) {
          printf("\n>> Time's up!!!! \n");
          pid_t parent_id = getppid();
          kill(parent_id, SIGINT);
        }
    }

  return 0;
}
 
