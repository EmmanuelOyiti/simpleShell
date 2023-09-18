#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * eputs - Prints a string to stderr.
 * @str: The string to be printed.
 */
void eputs(char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != '\0')
    {
        eputchar(str[i]);
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        i++;
    }
}

/**
<<<<<<< HEAD
 * write_error_char - Writes a character to stderr.
 * @charr: The character to be written.
 */
void write_error_char(char charr)
{
    static int i = 0;
    static charr buf[WRITE_BUF_SIZE];

    if (charr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
=======
 * eputchar - Writes a character to stderr.
 * @c: The character to be written.
 */
void eputchar(char c)
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    {
        write(2, buf, i);
        i = 0;
    }

<<<<<<< HEAD
    if (charr != BUF_FLUSH)
        buf[i++] = charr;
}

/**
 * write_to_des - Writes a character to the given file descriptor.
 * @charr: The character to be written.
 * @file_desc: The file descriptor to write to.
 */
void write_to_desc(char charr, int file_desc)
=======
    if (c != BUF_FLUSH)
        buf[i++] = c;
}

/**
 * putfd - Writes a character to the given file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor to write to.
 */
void putfd(char c, int fd)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

<<<<<<< HEAD
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
=======
    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;
}

/**
 * putsfd - Prints a string to the given file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 * @return: The number of characters written.
 */
int putsfd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return 0;

    while (str[i])
    {
        putfd(str[i], fd);
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        i++;
    }

    return i;
}
