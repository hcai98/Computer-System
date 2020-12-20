// Author: Haoyang Cai
#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 
#include <signal.h>
#include<string.h>


int getCorrectAnswer(int num1, int num2, int op) {
    if (op == 0) {return num1 + num2;}
    if (op == 1) {return num1 - num2;}
    if (op == 2) {return num1 * num2;}
}

char getOpChar(int op){
    if (op == 0) {return '+';}
    if (op == 1) {return '-';}
    if (op == 2) {return '*';}
}

// Global Variables
pid_t pid;

int timeup = 0;;
int count_correctAns = 0;
int count_wrongAns = 0;
int count_missedQ = 0;


void handle_sigint(int sig) { 
        printf(">> Enter a random number to continue: \n");
        count_missedQ ++; // question missed! 
        timeup = 1; // raise timeup flag
} 



int main(int argc, char **argv) {
    
    signal(SIGINT, handle_sigint);

    // Game paremeters
    int lowerBound = -10;
    int upperBound = 10;

    // declare and initialize parameters
    int num1, num2, op, answer_user, 
        answer_correct, interval,
        child_status, num_games;
    char opChar;
    char answer_user_string[50];

    // prompt user for the number of games
    printf(">> Enter the number of games to play: ");
    scanf("%d", &num_games);
    printf("\n");


    for (int game=1; game<=num_games; game++){

        // new question, reset timmer flag
        timeup = 0;

        // Create a child process for countdown
        pid = fork();
        if (pid == 0) {
            pid = execve("Timer", NULL, NULL);
        }

        // generate two random numbers
        srand(time(NULL));
        interval = upperBound - lowerBound;
        num1 = rand() % interval + lowerBound; 
        num2 = rand() % interval + lowerBound; 

        // genrate a random operation (0:+, 1:-, 2:*)
        op = rand() % 3;
        opChar = getOpChar(op); // get char representation of ops
        
        // initialize answer variables
        answer_correct = getCorrectAnswer(num1, num2, op);
        answer_user = answer_correct + 1; // initialize user input to be wrong

        // prompt the quiz question
        printf("\n\n-----------------Game %d------------------\n", game);
        printf("[Q%d]  %d %c (%d) = ? \n\n", game, num1, opChar, num2);
        printf(">> Type your answer (You have 5 second to answer) : \n");


        // User Input
        while ((answer_user != answer_correct)) {
            
            // prompt the user for answer
            scanf("%s", &answer_user_string); 

            // if timeup flag raised, end currect
            if (timeup) {
                if (game<num_games) {
                    printf(">> Loading Next Question...\n\n");
                    sleep(1); 
                }
                break;
            }
            answer_user = atoi(answer_user_string);

            // check if answer is correct
            if (answer_user == answer_correct) {
                printf("****** Correct! ******\n\n");
                count_correctAns ++; // count correct answers
                kill(pid, SIGINT);
            } else {
                printf("***** Wrong! Try again ***** \n");
                count_wrongAns ++; //count incorrect answers
            }

        }

        kill(pid, SIGKILL); // Question done, kill timer process
    }

    printf(">> Quiz Done! Thanks for playing!\n\n");
    printf("\n------------Stats------------\n");
    printf("Correct Answers: %d\n", count_correctAns);
    printf("Wrong Answers: %d\n", count_wrongAns);
    printf("Missed Questions: %d\n", count_missedQ);
    printf("-----------------------------");




    
    return 0;
}