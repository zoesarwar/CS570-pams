/*
 * Authors: Patrick Perrine, Zoe Sarwar
 * Red IDs: 820486635, 820523074
 * Class Accounts: cssc0801, cssc0802
 * CS 570 - Operating Systems, Summer 2019
 * Assignment #2, PAM
 * Filename: pam.cpp
 * Purpose: To function as a program actuator and microshell
 */

#include "pam.h"

//Helper method to run a single process (no-args)
void oneProcess(char p[]) {
    pid_t child_pid;
    child_pid = fork();

    if(child_pid < 0) {
        printf("Error: Forking child process failed\n");
        exit(1);
    }
    else if(child_pid == 0) {
        execlp(p, p, NULL);
        printf("Error\n");
    }
    else {
        wait(NULL);
    }
}

//Helper method to run two processes with a pipe
void pipeProcess(char p1[], char p2[]) {
   int cond[2];

    pipe(cond);

    pid_t pid1;
    pid_t pid2;

    pid1 = fork();
    if(pid1 == 0) {
	close(cond[0]);
	dup2(cond[1], 1);
	execlp(p1, p1, NULL);
    }
    else {
        pid2 = fork();
        if(pid2 == 0) {
            close(cond[1]);
            dup2(cond[0], 0);
            execlp(p2, p2, NULL);
	}

    }

    waitpid(pid1, NULL, 0);
    close(cond[1]);
    waitpid(pid2, NULL, 0);
}

int main(int argc, char *argv[]) {

    char l[] = "ls";  //for testing
    char s[] = "sort";
    
    while(1) {
	char line[512];
    char * line_array [1024];
	printf("cssc0802%% ");
	fgets(line, sizeof(line), stdin); //Intakes line with newline appended
        
	if(strcmp(line,"exit\n") == 0)  //checks for exit before trimming \n
        break;
	
    /*int numPipes = -1;
    char *allTokens[256];
    char *currTok = strtok(line, " "); //test for the first two tokens */
    
    char * token = strtok(line, "| "); //tokenizes
    int numPipes = -1;
    while(token != NULL){
        numPipes++;
        line_array[numPipes] = token;
        token = strtok(NULL, "| ");
    }
        
    int n = 0;
    while(n < numPipes + 1){
        printf("Token: %s\n", line_array[n]);
        n++;
    }

	/*size_t len = strlen(line);
	if(len > 0 && line[len-1] == '\n')
	    line[len] = '\0';		//supposed to trim newline */

	//int numPipes = -1;
//	char *allTokens[256];
//	char *currTok = strtok(line, " "); //test for the first two tokens

//	printf("%s\n", currTok);
        
//	currTok = strtok(NULL, " ");
        
//	printf("%s\b", currTok);
        
        
/*
	while(currTok != NULL) {	//adds tokens to string array
	    numPipes++;
	    allTokens[numPipes] = currTok;
	    currTok = strtok(NULL, " ");
	    printf("%s\n", currTok);
	}
*/	
//	if(numPipes == 0)		//beginning of parse logic, see photo
//	    oneProcess(allTokens[0]);
        
         pipeProcess(l,s);        //two process tester, tests after exit
    }

    return 0;	//End program
}
