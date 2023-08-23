#include "shell_functions.h"

/**
 * shell_exit - This exits the shell
 * @info: The structure containing the potential arguments
 * Return: This exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int shell_exit(info_t *info)
{
	int check_exit;

	if (info->argv[1])
	{
		check_exit = _errshell_convert(info->argv[1]);
		if (check_exit == -1)
		{
			info->status = 2;
			print_error(info, "Wrong number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errshell_convert(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * shell_cd - this changes the current directory of the process
 * @info: Structure containing potential arguments to maintain
 * constant function prototype.
 * Return: Always 0
 */
int shell_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int change_dir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd error msg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			change_dir = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			change_dir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		change_dir = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		change_dir = chdir(info->argv[1]);
	if (change_dir == -1)
	{
		print_error(info, "cannot change directory to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * shellhelp - This changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: always 0
 */
int shellhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
