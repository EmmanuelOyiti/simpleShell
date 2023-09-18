#include "shell.h"

/**
 * get_env_var - returns the string array copy of our environ
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char *get_env_var(info_t *information)
{
	if (!information->env_var || information->environment_changed)
	{
		information->env_var = list_to_strings(information->env);
		information->environment_changed = 0;
	}

	return (information->env_var);
}

/**
 * remove_env_var - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int remove_env_var(info_t *information, char *var_name)
{
	list_t *node = information->env;
	size_t i = 0;
	char *p;

	if (!node || !var_name)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var_name);
		if (p && *p == '=')
		{
			information->environment_changed = delete_node_at_index(&(information->env), i);
			i = 0;
			node = information->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (information->environment_changed);
}


/**
 * set_env_var - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var_name: the string env var property
 * @var_value: the string env var value
 *  Return: Always 0
 */
int set_env_var(info_t *information, char *var_name, char *var_value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!var_name || !var_value)
		return (0);

	buffer = malloc(_strlen(var_name) + _strlen(var_value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var_name);
	_strcat(buffer, "=");
	_strcat(buffer, var_value);
	node = information->env;
	while (node)
	{
		p = starts_with(node->str, var_name);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			information->environment_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(information->env), buffer, 0);
	free(buffer);
	information->environment_changed = 1;
	return (0);
}
