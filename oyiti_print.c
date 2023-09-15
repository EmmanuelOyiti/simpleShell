#include "shell.h"

void oyiti_print(const char *print_Function){
    write (STDOUT_FILENO, print_Function, strlen(print_Function));
}

