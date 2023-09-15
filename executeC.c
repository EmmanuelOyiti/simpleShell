#include "shell.h"

/**
*void theExecute_command(const char *command){
*	pid_t baby_pid = fork();
*
*	if (baby_pid == -1){
*		perror("fork");
*		exit(EXIT_FAILURE);
*	}
*	else if (baby_pid == 0)
*	{
*		execlp(command, command, (char *)NULL);
*		perror("execlp");
*		exit(EXIT_FAILURE);
*	}
*	else {
*		wait(NULL);
*	}
*}
**/

void theExecute_command(const char *command){
        pid_t baby_pid = fork();

        if (baby_pid == -1){
                oyiti_print("Error forking process");
                exit(EXIT_FAILURE);
        }
        else if (baby_pid == 0)
        {
		/** child process**/
		char *args[140];
		int arg_counts = 0; 
                char *token = strok((char *)command,"");
		while (token != NULL){
		args[arg_counts++] = token;
		token = strtok(NULL," ");
		}
		args[arg_counts] = NULL;

		execvp(args[0], args);

		oyiti_print("Error executing command"\n);
		exit(EXIT_FAILURE);
        }
        else {
                wait(NULL);
        }
}
