#include "simple_shell.h"
/**
 * main - executes all functions
 *
 * Return: if succes 0 ,always
 */
int main(void)
{
	sh_t data;
	int pl;

	_memset((void *)&data, 0, sizeof(data));
	signal(SIGINT, _handler);
	while (1)
	{
		index_cmd(&data);
		if (read_line(&data) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (split(&data) < 0)
		{
			_data(&data);
			continue;
		}
		pl = line_parser(&data);
		if (pl == 0)
		{
			_data(&data);
			continue;
		}
		if (pl < 0)
		{
			print_error(&data);
			continue;
		}
		if (process(&data) < 0)
		{
			print_error(&data);
			break;
		}
		_data(&data);
	}
	_data(&data);
	exit(EXIT_SUCCESS);
}
