#include "shell.h"

/**
 * convert_to_int - Converts a string to an integer with error handling.
 * @text: The string to be converted.
 * Return: The converted number on success, or -1 on error.
 */
int convert_to_int(char *text)
{
    int i = 0;
    unsigned long int result = 0;

    if (*text == '+')
        text++;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            result *= 10;
            result += (text[i] - '0');
            if (result > INT_MAX)
                return -1; // Integer overflow
        }
        else
        {
            return -1; // Invalid character encountered
        }
    }
    return (int)result;
}

/**
 * show_error_msg - Prints an error message.
 * @information: The info structure.
 * @error_msg: The error message.
 */
void show_error_msg(info_t *information, char *error_msg)
{
    _eputs(information->fname);
    _eputs(": ");
    print_d(information->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(information->argv[0]);
    _eputs(": ");
    _eputs(error_msg);
}


/**
 * shows_int - Prints a decimal (integer) number (base 10).
 * @numb: The number to be printed.
 * @file_desc: The file descriptor to write to.
 * Return: The number of characters printed.
 */
int shows_int(int numb, int file_desc)
{
    int (*print_char)(char) = (file_desc == STDERR_FILENO) ? _eputchar : _putchar;
    int count = 0;
    unsigned int abs_numb, current;

    if (numb < 0)
    {
        abs_numb = -numb;
        print_char('-');
        count++;
    }
    else
    {
        abs_numb = numb;
    }

    current = abs_numb;
    // ... (remainder funct implementation)

    return count;
}
