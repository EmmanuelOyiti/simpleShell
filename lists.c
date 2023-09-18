#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @list_head: address of pointer to head node
 * @node_string: str field of node
 * @node_index: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **list_head, const char *node_string, int node_index)
{
    list_t *new_head;

    if (!list_head)
        return (NULL);
    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);
    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = node_index;
    if (node_string)
    {
        new_head->str = _strdup(node_string);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }
    new_head->next = *list_head;
    *list_head = new_head;
    return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_str_in_list - prints only the str element of a list_t linked list
 * @list_head: pointer to first node
 *
 * Return: size of list
 */
size_t print_str_in_list(const list_t *list_head)
{
    size_t count = 0;

    while (list_head)
    {
        _puts(list_head->str ? list_head->str : "(nil)");
        _puts("\n");
        list_head = list_head->next;
        count++;
    }
    return (count);
}

/**
 * delete_node_at_specific_index - deletes node at given index
 * @list_head: address of pointer to first node
 * @target_index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_specific_index(list_t **list_head, unsigned int target_index)
{
    list_t *node, *prev_node;
    unsigned int index = 0;

    if (!list_head || !*list_head)
        return (0);

    if (!target_index)
    {
        node = *list_head;
        *list_head = (*list_head)->next;
        free(node->str);
        free(node);
        return (1);
    }
    node = *list_head;
    while (node)
    {
        if (index == target_index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }
        index++;
        prev_node = node;
        node = node->next;
    }
    return (0);
}

/**
 * free_entire_list - frees all nodes of a list
 * @list_head_pointer: address of pointer to head node
 *
 * Return: void
 */
void free_entire_list(list_t **list_head_pointer)
{
    list_t *node, *next_node, *list_head;

    if (!list_head_pointer || !*list_head_pointer)
        return;
    list_head = *list_head_pointer;
    node = list_head;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }
    *list_head_pointer = NULL;
}
