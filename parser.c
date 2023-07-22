#include "simple_shell.h"
#define DELIMITER ":"
/**
 * parse_line - parses arguments to valid command
 * @data: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int parse_line(sh_t *data)
{

	if (is_path_form(data) > 0)
		return (SUCCESS);

	if (is_builtin(data) > 0)
	{
		if (handle_builtin(data) < 0)
			return (FAIL);
		return (NEUTRAL);
	}

	is_short_form(data);

	return (SUCCESS);
}
#undef DELIMITER
