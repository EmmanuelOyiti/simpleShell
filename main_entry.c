#include "shell.h"
 
/**
 * main - entry point
 * Return: 0 on success, 1 on error
 */

int main(void){
    char command[128];

    while (1)
    {
        show_the_prompt();
        reads_command(command, sizeof(command));
        theExecute_command(command);
    }
    
    return 0;
}