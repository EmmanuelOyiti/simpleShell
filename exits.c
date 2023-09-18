#include "shell.h"

/**
<<<<<<< HEAD
 * cpy_part_string - Copies a string.
 * @dest_str: The destination string to be copied to.
 * @src_str: The source string.
 * @umb_of_chars: The number of characters to be copied.
=======
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to be copied.
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 * Return: A pointer to the concatenated string.
 */
char *cpy_part_string(char *dest_str, char *src_str, int numb_of_chars)
{
<<<<<<< HEAD
    int i;
    char *result = dest_str;

    for (i = 0; src_str[i] != '\0' && i < numb_of_chars - 1; i++)
    {
        dest_str[i] = src_str[i];
    }

    while (i < numb_of_chars)
    {
        dest_str[i] = '\0';
        i++;
    }

       return result;
}

/**
 * combine_strings - Concatenates two strings.
 * @dest_str: The first string.
 * @src: The second string.
 * @maximum_chars: The maximum number of bytes to be used from src.
=======
    int i, j;
    char *s = dest;

    for (i = 0; src[i] != '\0' && i < n - 1; i++)
    {
        dest[i] = src[i];
    }

    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return s;
}

/**
 * _strncat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used from src.
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 * Return: A pointer to the concatenated string.
 */
char *combine_strings(char *dest_str, char *src_str, int maximum_chars)
{
    int i, j;
<<<<<<< HEAD
    char *result = dest_str;

    for (i = 0; dest_str[i] != '\0'; i++)
    {
    }

    for (j = 0; src_str[j] != '\0' && j < maximum_chars; i++, j++)
    {
        dest_str[i] = src_str[j];
    }

    dest_str[i] = '\0';

    return result;
}

/**
 * find_char - Locates a character in a string.
 * @str: The string to be parsed.
 * @char: The character to look for.
=======
    char *s = dest;

    for (i = 0; dest[i] != '\0'; i++)
    {
    }

    for (j = 0; src[j] != '\0' && j < n; i++, j++)
    {
        dest[i] = src[j];
    }

    dest[i] = '\0';

    return s;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
 * Return: A pointer to the first occurrence of c in s, or NULL if not found.
 */
char *find_char(char *str, char char)
{
<<<<<<< HEAD
    if (str == NULL)
=======
    if (s == NULL)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    {
        return NULL;
    }

    do
    {
<<<<<<< HEAD
        if (*str == char)
        {
            return str;
        }
    } while (*str++ != '\0');

    return NULL;
}
=======
        if (*s == c)
        {
            return s;
        }
    } while (*s++ != '\0');

    return NULL;
}
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
