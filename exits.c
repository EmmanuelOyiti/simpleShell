#include "shell.h"

/**
 * cpy_part_string - Copies a string.
 * @dest_str: The destination string to be copied to.
 * @src_str: The source string.
 * @umb_of_chars: The number of characters to be copied.
 * Return: A pointer to the concatenated string.
 */
char *cpy_part_string(char *dest_str, char *src_str, int numb_of_chars)
{
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
 * Return: A pointer to the concatenated string.
 */
char *combine_strings(char *dest_str, char *src_str, int maximum_chars)
{
    int i, j;
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
 * Return: A pointer to the first occurrence of c in s, or NULL if not found.
 */
char *find_char(char *str, char char)
{
    if (str == NULL)
    {
        return NULL;
    }

    do
    {
        if (*str == char)
        {
            return str;
        }
    } while (*str++ != '\0');

    return NULL;
}
