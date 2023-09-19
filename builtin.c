#include "shell.h"

/**
 * exit_command - Exits the shell with a given exit status.
 * @information: Pointer to the info_t structure.
 * Return: Exits the shell with the specified status.
 */
int exit_command(info_t * information)
{
    int exit_status;

    if (information->argv[1])
    {
        exit_status = _erratoi(information->argv[1]);
        if (exit_status == -1)
        {
            information->status = 2;
            print_error(information, "Illegal number: ");
            _eputs(information->argv[1]);
            _eputchar('\n');
            return 1;
        }
        information->err_num = exit_status;
        return -2;
    }
    information->err_num = -1;
    return -2;
}

/**
 * change_directory_command - Changes the current directory of the process.
 * @information: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int change_directory_command(info_t *information)
{
    char *current_dir, *target_dir, buffer[1024];
    int chdir_ret;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        _puts("TODO: >>getcwd failure emsg here<<\n");

    if (!information->argv[1])
    {
        target_dir = _getenv(information, "HOME=");
        if (!target_dir)
        {
            // Handle the case where target directory is not found.
        }
        else
        {
            chdir_ret = chdir(target_dir);
        }
    }
    else if (_strcmp(information->argv[1], "-") == 0)
    {
        // Handle changing to the previous directory.
    }
    else
    {
        chdir_ret = chdir(information->argv[1]);
    }

    // Handle chdir_ret, update PWD and OLDPWD variables.

    return 0;
}

/**
 * show_help - Displays help information for shell commands.
 * @information: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int show_help(info_t *information)
{
    char **arg_array;

    arg_array = information->argv;
    _puts("Help information not yet implemented.\n");

    // Temporary workaround to avoid "unused variable" warning.
    if (*arg_array)
    {
        // Do something with arg_array if necessary.
    }

    return 0;
}
