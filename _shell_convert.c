#include "shell_functions.h"

/**
 * interact - this will return true if shell is in an interact mode
 * @info: this is the struct address
 * Return: 1 if in interact mode and 0 if otherwise
 */

int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_a_delimeter - this will check if character is a delimeter
 * @cha: the char to be checked
 * @delimeter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_a_delimeter(char cha, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == cha)
			return (1);
	return (0);
}

/**
 * is_an_alpha - this checks for alphabetic character
 * @cha: The character to input
 * Return: 1 if c is alphabetic and 0 if otherwise
 */

int is_an_alpha(int cha)
{
	if ((cha >= 'a' && cha <= 'z') || (cha >= 'A' && cha <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _shell_convert - this converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string or converted number if otherwise
 */

int _shell_convert(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
