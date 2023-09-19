#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int user_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/*
 * is_adelim - checks if a character is a delimiter
=======
 * is_adelim - checks if a character is a delimiter
 * @c: the character to check
 * @seperator: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_adelim(char c, char *seperator)
{

    if (!seperator)
        return 0;

    while (*seperator)
    {
        if (*seperator == c)
            return 1;
        seperator++;}

    if (!seperator)
        return 0;

    while (*seperator)
    {
        if (*seperator == c)
            return 1;
        seperator++;
    }
    return 0;
}

/**
 * is_an_alphabetic - checks if a character is alphabetic
 * @c: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_an_alphabet(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * strings_to_integers - converts a string to an integer
 * @_string: the string to be converted
 *
 * Return: 0 if no numbers in the string, the converted number otherwise
 */
int strings_to_integers(char *_string)
{
    int i, sign = 1, flag = 0, result;
    unsigned int number = 0;

    for (i = 0; _string[i] != '\0' && flag != 2; i++)
    {
        if (_string[i] == '-')
            sign *= -1;

        if (_string[i] >= '0' && _string[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (_string[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        result = -number;
    else
        result = number;

    return result;
}
