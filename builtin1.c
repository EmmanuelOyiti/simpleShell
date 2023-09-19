#include "shell.h"

/**
 * show_the_alias - prints a single alias entry.
 * @shortcuts_entry: The alias entry to be printed.
 */
void show_the_alias(list_t *shortcuts_entry)
{
    char *p = NULL;

    if (shortcuts_entry)
    {
        p = _strchr(shortcuts_entry->str, '=');
        for (char *a = shortcuts_entry->str; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
    }
}

/**
 * _the_alias - Implements the alias command.
 * @information: Structure containing potential arguments.
 * Return: Always 0.
 */
int _the_alias(info_t *information)
{
    if (information->argc == 1)
    {
        list_t *shortcuts_entry = information->alias;
        while (shortcuts_entry)
        {
            show_the_alia(shortcuts_entry);
            shortcuts_entry = shortcuts_entry->next;
        }
        return 0;
    }

    for (int i = 1; information->argv[i]; i++)
    {
        char *p = _strchr(information->argv[i], '=');
        if (p)
        {
            set_alias(information, information->argv[i]);
        }
        else
        {
            list_t *alias_entry = node_starts_with(information->alias, information->argv[i], '=');
            show_the_alia(alias_entry);
        }
    }

    return 0;
}
