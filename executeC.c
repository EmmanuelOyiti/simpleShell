#include "shell.h"

void theExecute_command(const char *command){
	pid_t baby_pid = fork();

	if (baby_pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (baby_pid == 0)
	{
		execlp(command, command, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else {
		wait(NULL);
	}
}