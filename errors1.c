#include "shell.h"

/**
<<<<<<< HEAD
 * convert_to_int - Converts a string to an integer with error handling.
 * @text: The string to be converted.
 * Return: The converted number on success, or -1 on error.
 */
int convert_to_int(char *text)
=======
 * err_atoi - Converts a string to an integer with error handling.
 * @s: The string to be converted.
 * Return: The converted number on success, or -1 on error.
 */
int err_atoi(char *s)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
{
    int i = 0;
    unsigned long int result = 0;

<<<<<<< HEAD
    if (*text == '+')
        text++;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            result *= 10;
            result += (text[i] - '0');
=======
    if (*s == '+')
        s++;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
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
<<<<<<< HEAD
 * show_error_msg - Prints an error message.
 * @information: The info structure.
 * @error_msg: The error message.
=======
 * print_error - Prints an error message.
 * @info: The info structure.
 * @estr: The error message.
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 */
void show_error_msg(info_t *information, char *error_msg)
{
<<<<<<< HEAD
    _eputs(information->fname);
    _eputs(": ");
    print_d(information->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(information->argv[0]);
    _eputs(": ");
    _eputs(error_msg);
=======
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
}


/**
<<<<<<< HEAD
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
=======
 * print_decimal - Prints a decimal (integer) number (base 10).
 * @input: The number to be printed.
 * @fd: The file descriptor to write to.
 * Return: The number of characters printed.
 */
int print_decimal(int input, int fd)
{
    int (*print_char)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
    int count = 0;
    unsigned int abs_input, current;

    if (input < 0)
    {
        abs_input = -input;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        print_char('-');
        count++;
    }
    else
    {
<<<<<<< HEAD
        abs_numb = numb;
    }

    current = abs_numb;
=======
        abs_input = input;
    }

    current = abs_input;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    // ... (rest of the function implementation)

    return count;
}
<<<<<<< HEAD
=======

>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
