#include "shell.h"

/**
 * print_error_msg - Prints a string to stderr.
 * @str: The string to be printed.
 */
void print_error_msg(char *error_msg)
{
    int i = 0;

    if (!error_msg)
        return;

    while (error_msg[i] != '\0')
    {
        write_error_character(error_msg[i]);
        i++;
    }
}

/**
 * write_error_char - Writes a character to stderr.
 * @charr: The character to be written.
 */
void write_error_char(char charr)
{
    static int i = 0;
    static charr buf[WRITE_BUF_SIZE];

    if (charr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(2, buf, i);
        i = 0;
    }

    if (charr != BUF_FLUSH)
        buf[i++] = charr;
}

/**
 * write_to_des - Writes a character to the given file descriptor.
 * @charr: The character to be written.
 * @file_desc: The file descriptor to write to.
 */
void write_to_desc(char charr, int file_desc)
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

    if (charr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(file_desc, buf, i);
        i = 0;
    }

    if (charr != BUF_FLUSH)
        buf[i++] = charr;
}

/**
 * print_to_desc - Prints a string to the given file descriptor.
 * @string: The string to be printed.
 * @file_desc: The file descriptor to write to.
 * @return: The number of characters written.
 */
int print_to_desc(char *string, int file_desc)
{
    int i = 0;

    if (!string)
        return 0;

    while (string[i])
    {
        write_to_desc(string[i], file_desc);
        i++;
    }

    return i;
}
