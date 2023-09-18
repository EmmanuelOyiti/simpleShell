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

/**
<<<<<<< HEAD
 * is_adelim - checks if a character is a delimiter
=======
 * is_delim - checks if a character is a delimiter
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_adelim(char c, char *seperator)
{
<<<<<<< HEAD
    if (!seperator)
        return 0;

    while (*seperator)
    {
        if (*seperator == c)
            return 1;
        seperator++;
=======
    if (!delim)
        return 0;

    while (*delim)
    {
        if (*delim == c)
            return 1;
        delim++;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    }
    return 0;
}

/**
<<<<<<< HEAD
 * is_an_alphabetic - checks if a character is alphabetic
=======
 * is_alphabetic - checks if a character is alphabetic
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 * @c: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
<<<<<<< HEAD
int is_an_alphabet(int c)
=======
int is_alphabetic(int c)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
<<<<<<< HEAD
 * strings_to_integers - converts a string to an integer
 * @_string: the string to be converted
 *
 * Return: 0 if no numbers in the string, the converted number otherwise
 */
int strings_to_integers(char *_string)
=======
 * custom_atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in the string, the converted number otherwise
 */
int custom_atoi(char *s)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

<<<<<<< HEAD
    for (i = 0; _string[i] != '\0' && flag != 2; i++)
    {
        if (_string[i] == '-')
            sign *= -1;

        if (_string[i] >= '0' && _string[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (_string[i] - '0');
=======
    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
<<<<<<< HEAD
        result = -number;
    else
        result = number;

    return result;
=======
        output = -result;
    else
        output = result;

    return output;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
}
