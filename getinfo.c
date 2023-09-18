#include "shell.h"

/**
 * init_info_struct - initializes info_t struct
 * @information: struct address
 */
void init_info_struct(info_t *information)
{
    information->arg = NULL;
    information->argv = NULL;
    information->path = NULL;
    information->argc = 0;
}

/**
 * init_info_args - initializes info_t struct
 * @information: struct address
 * @arg_vect: argument vector
 */
void init_info_args(info_t *information, char **arg_vect)
{
    int i = 0;

    information->fname = argument_vector[0];
    if (information->arg)
    {
        information->argv = strtow(information->arg, " \t");
        if (!information->argv)
        {
            information->argv = malloc(sizeof(char *) * 2);
            if (information->argv)
            {
                information->argv[0] = _strdup(information->arg);
                information->argv[1] = NULL;
            }
        }
        for (i = 0; information->argv && information->argv[i]; i++)
            ;
        information->argc = i;

        replace_alias(information);
        replace_vars(information);
    }
}
/**
 * free_info_fields - frees info_t struct fields
 * @information: struct address
 * @free_fields: true if freeing all fields
 */
void free_info_fields(info_t *information, int free_fields)
{
    ffree(information->argv);
    information->argv = NULL;
    information->path = NULL;
    if (free_all_fields)
    {
        if (!information->cmd_buf)
            free(information->arg);
        if (information->env)
            free_list(&(information->env));
        if (information->history)
            free_list(&(information->history));
        if (information->alias)
            free_list(&(information->alias));
        ffree(information->environ);
        information->environ = NULL;
        bfree((void **)information->cmd_buf);
        if (information->readfd > 2)
            close(information->readfd);
        _putchar(BUF_FLUSH);
    }
}
