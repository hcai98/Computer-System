#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <sys/wait.h>
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
 
  void handle_sigint(int sig) 
{ 
       secs = 0;

} 
int main(int argc, char **argv)
{
sleep(1);
signal(SIGINT, handle_sigint);
     int i;   
  int  j ;
 printf("\n");
  while(secs<10) {
     printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      printf("\r\b\r");
  }

  return 0;
}
 
