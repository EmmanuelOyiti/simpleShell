#include "shell.h"

/**
 * oyiti_print - Prints a string to the standard output (stdout).
 * @print_Function: The string to be printed.
 * This function writes the given string to the standard output (stdout).
 * Return: None.
 */
void oyiti_print(const char *print_Function){
    write (STDOUT_FILENO, print_Function, strlen(print_Function));
}

