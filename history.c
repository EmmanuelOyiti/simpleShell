#include "shell.h"

/**
 * get_hstry_file - gets the history file
 * @information: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_hstry_file(information_structure *information)
{
    char *buffer, *directory;

    directory = _getenv(information, "HOME=");
    if (!directory)
        return (NULL);
    buffer = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
    if (!buffer)
        return (NULL);
    buffer[0] = 0;
    _strcpy(buffer, directory);
    _strcat(buffer, "/");
    _strcat(buffer, HIST_FILE);
    return (buffer);
}

/**
 * write_hstry_file - creates a file, or appends to an existing file
 * @information: the parameter struct
 * Return: 1 on success, else -1
 */
int write_hstry_file(information_structure *information)
{
    ssize_t file_descriptor;
    char *file_name = get_history_file_path(information);
    list_t *list_node = NULL;

    if (!file_name)
        return (-1);

    file_descriptor = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(file_name);
    if (file_descriptor == -1)
        return (-1);

    for (list_node = information->history; list_node; list_node = list_node->next)
    {
        _putsfd(list_node->str, file_descriptor);
        _putfd('\n', file_descriptor);
    }
    _putfd(BUF_FLUSH, file_descriptor);
    close(file_descriptor);
    return (1);
}

/**
 * read_hstry_file - reads history from file
 * @information: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_hstry_file(information_structure *information)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(information);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(information, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(information, buf + last, linecount++);
	free(buf);
	information->histcount = linecount;
	while (information->histcount-- >= HIST_MAX)
		delete_node_at_index(&(information->history), 0);
	renumber_history(information);
	return (information->histcount);
}

/**
 * add_entry_hstry_list - adds entry to a history linked list
 * @information: Structure containing potential arguments. Used to maintain
 * @buffer: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int add_entry_hstry_list(information_structure *information, char *buffer, int line_count)
{
    list_t *list_node = NULL;

    if (information->history)
        list_node = information->history;
    add_node_end(&list_node, buffer, line_count);

    if (!information->history)
        information->history = list_node;
    return (0);
}

/**
 * upt_hstry_numbers - renumbers the history linked list after changes
 * @information: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int upt_hstry_numbers(information_structure *information)
{
    list_t *list_node = information->history;
    int index = 0;

    while (list_node)
    {
        list_node->num = index++;
        list_node = list_node->next;
    }
    return (information->histcount = index);
}