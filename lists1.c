#include "shell.h"

/**
 * count_list_elements - determines length of linked list
 * @list_head: pointer to first node
 * Return: size of list
 */
size_t count_list_elements(const list_t *list_head)
{
    size_t count = 0;

    while (list_head)
    {
        list_head = list_head->next;
        count++;
    }
    return count;
}

/**
 * convert_list_to_strings - returns an array of strings of the list->str
 * @list_head: pointer to first node
 *
 * Return: array of strings
 */
char **convert_list_to_strings(list_t *list_head)
{
    list_t *node = list_head;
    size_t element_count = count_elements_in_list(list_head), index;
    char **string_array;
    char *string;

    if (!list_head || !element_count)
        return NULL;

    string_array = malloc(sizeof(char *) * (element_count + 1));
    if (!string_array)
        return NULL;

    for (index = 0; node; node = node->next, index++)
    {
        string = malloc(_strlen(node->str) + 1);
        if (!string)
        {
            for (size_t j = 0; j < index; j++)
                free(string_array[j]);
            free(string_array);
            return NULL;
        }

        string = _strcpy(string, node->str);
        string_array[index] = string;
    }
    string_array[index] = NULL;
    return string_array;
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * find_node_with_prefix - returns node whose string starts with prefix
 * @list_head: pointer to list head
 * @starting_prefix: string to match
 * @char_after_prefix: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *find_node_with_prefix(list_t *list_head, char *starting_prefix, char char_after_prefix)
{
    char *position = NULL;

    while (list_head)
    {
        position = starts_with(list_head->str, starting_prefix);
        if (position && ((char_after_prefix == -1) || (*position == char_after_prefix)))
            return list_head;
        list_head = list_head->next;
    }
    return NULL;
}

/**
 * find_index_of_node - gets the index of a node
 * @list_head: pointer to list head
 * @target_node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t find_index_of_node(list_t *list_head, list_t *target_node)
{
    size_t index = 0;

    while (list_head)
    {
        if (list_head == target_node)
            return index;
        list_head = list_head->next;
        index++;
    }
    return -1;
}