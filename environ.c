#include "shell.h"

/**
 * _myenv - prints the current environment
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int show_environment(info_t *information)
{
    print_list_str(information->env);
    return (0);
}

/**
 * _get_var_value - gets the value of an environ variable
 * @information: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *get_var_value(info_t *information, const char *variable_name)
{
    list_t *node = information->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, variable_name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}

/**
 * set_my_variable - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int set_my_variable(info_t *information)
{
    if (information->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return (1);
    }
    if (_setenv(information, information->argv[1], information->argv[2]))
        return (0);
    return (1);
}


/**
 * unset_my_variable - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int unset_my_variable(info_t *information)
{
    int i;

    if (information->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return (1);
    }
    for (i = 1; i <= information->argc; i++)
        _unsetenv(information, information->argv[i]);

    return (0);
}

/**
 * create_my_variable_ls - creates env linked list
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int create_my_variable_ls(info_t *information)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    information->env = node;
    return (0);
}
