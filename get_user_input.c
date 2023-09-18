#include "shell.h"

/**
 * reads_command - Reads a command from standard input.
 * @command:    Pointer to a buffer where the command will be stored.
 * @size:       The maximum size of the command buffer.
*/
void reads_command(char *command, size_t size){
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin)) {
			oyiti_print("\n");
			exit(EXIT_SUCCESS);
		} 
	} else {
		oyiti_print("Error reading your input.");
		exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")]= '\0'; 
}