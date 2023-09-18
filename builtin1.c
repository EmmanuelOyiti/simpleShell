#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * print_alias_entry - prints a single alias entry.
 * @alias_entry: The alias entry to be printed.
 */
void print_alias_entry(list_t *alias_entry)
{
    char *p = NULL;

    if (alias_entry)
    {
        p = _strchr(alias_entry->str, '=');
        for (char *a = alias_entry->str; a <= p; a++)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
    }
}

/**
<<<<<<< HEAD
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
=======
 * _myalias - Implements the alias command.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myalias(info_t *info)
{
    if (info->argc == 1)
    {
        list_t *alias_entry = info->alias;
        while (alias_entry)
        {
            print_alias_entry(alias_entry);
            alias_entry = alias_entry->next;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        }
        return 0;
    }

<<<<<<< HEAD
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
=======
    for (int i = 1; info->argv[i]; i++)
    {
        char *p = _strchr(info->argv[i], '=');
        if (p)
        {
            set_alias(info, info->argv[i]);
        }
        else
        {
            list_t *alias_entry = node_starts_with(info->alias, info->argv[i], '=');
            print_alias_entry(alias_entry);
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        }
    }

    return 0;
}
