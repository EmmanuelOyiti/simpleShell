#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

void show_the_prompt(void);
void oyiti_print(const char *print_Function);
void theExecute_command(const char *command);
void reads_command(char *command, size_t size);

#endif /*_SHELL_H_*/
