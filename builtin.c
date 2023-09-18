#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * my_exit - Exits the shell with a given exit status.
 * @info: Pointer to the info_t structure.
 * Return: Exits the shell with the specified status.
 */
int my_exit(info_t *info)
{
    int exit_status;

    if (info->argv[1])
    {
        exit_status = _erratoi(info->argv[1]);
        if (exit_status == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return 1;
        }
        info->err_num = exit_status;
        return -2;
    }
    info->err_num = -1;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    return -2;
}

/**
<<<<<<< HEAD
 * change_directory_command - Changes the current directory of the process.
 * @information: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int change_directory_command(info_t *info)
=======
 * my_cd - Changes the current directory of the process.
 * @info: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int my_cd(info_t *info)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
{
    char *current_dir, *target_dir, buffer[1024];
    int chdir_ret;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        _puts("TODO: >>getcwd failure emsg here<<\n");

<<<<<<< HEAD
    if (!information->argv[1])
    {
        target_dir = _getenv(information, "HOME=");
=======
    if (!info->argv[1])
    {
        target_dir = _getenv(info, "HOME=");
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
        if (!target_dir)
        {
            // Handle the case where target directory is not found.
        }
        else
        {
            chdir_ret = chdir(target_dir);
        }
    }
<<<<<<< HEAD
    else if (_strcmp(information->argv[1], "-") == 0)
=======
    else if (_strcmp(info->argv[1], "-") == 0)
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    {
        // Handle changing to the previous directory.
    }
    else
    {
<<<<<<< HEAD
        chdir_ret = chdir(information->argv[1]);
=======
        chdir_ret = chdir(info->argv[1]);
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    }

    // Handle chdir_ret, update PWD and OLDPWD variables.

    return 0;
}

/**
<<<<<<< HEAD
 * show_help - Displays help information for shell commands.
 * @information: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int show_help(info_t *information)
{
    char **arg_array;

    arg_array = information->argv;
=======
 * my_help - Displays help information for shell commands.
 * @info: Pointer to the info_t structure.
 * Return: Always returns 0.
 */
int my_help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
>>>>>>> 5d03b7645364030041db075396d5d1c16607bbbd
    _puts("Help information not yet implemented.\n");

    // Temporary workaround to avoid "unused variable" warning.
    if (*arg_array)
    {
        // Do something with arg_array if necessary.
    }

    return 0;
}
