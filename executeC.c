#include "shell.h"

/**
<<<<<<< HEAD
 * theExecute_command - Execute a command in a child process
 * @command: The command to execute
 */

void theExecute_command(const char *command){
	pid_t baby_pid = fork();
=======
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
>>>>>>> 78b8e1602a65450cf9fb24a2dc4e7155ad39e1f9

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
