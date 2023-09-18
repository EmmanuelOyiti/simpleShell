#include "shell.h"

/*
*usage: remove new lines
*/
void reads_command(char *command, size_t size){
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin)) {
			oyiti_print("\n");
			exit(EXIT_SUCCESS);
		} 
	} else {
		oyiti_print("Error reading your input. \n");
		exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")]= '\0'; 
}
