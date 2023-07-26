#include "simple_shell.h"

/**
 * read_line - read a line from the standard input
 * @input: a pointer to the struct of data
 *
 * Return: 1 if success
 */
int read_line(sh_t *input)
{
	char *csr, *end, c;
	size_t size = BUFFSIZE;
	size_t read_st, len, new_size;

	input->line = malloc(size * sizeof(char));
	if (input->line == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		PRINT(PROMPT);
	for (csr = input->line, end = input->line + size;;)
	{
		read_st = read(STDIN_FILENO, &c, 1);
		if (read_st == 0)
			return (-1);
		*csr++ = c;
		if (c == '\n')
		{
			*csr = '\0';
			return (1);
		}
		if (csr + 2 >= end)
		{
			new_size = size * 2;
			len = csr - input->line;
			input->line = _realloc(input->line, size * sizeof(char),
						new_size * sizeof(char));
			if (input->line == NULL)
				return (-1);
			size = new_size;
			end = input->line + size;
			csr = input->line + len;
		}
	}
}

#define DELIMITER " \n\t\r\a\v"
/**
 * split_line - splits line to tokens
 * @input: a pointer to the struct of data
 *
 * Return: 1 if success
 */
int split(sh_t *input)
{
	char *token;
	size_t size = TOKENSIZE, new_size, x;

	x = 0;

	if (_strcmp(input->line, "\n") == 0)
		return (-1);

	input->args = malloc(size * sizeof(char *));
	if (input->args == NULL)
		return (-1);

	token = strtok(input->line, DELIMITER);
	if (token == NULL)
		return (-1);
	while (token)
	{
		input->args[x++] =  token;
		if (x + 2 >= size)
		{
			new_size = size * 2;
			input->args = _realloc(input->args, size * sizeof(char *),
					new_size * sizeof(char *));

			if (input->args == NULL)
				return (-1);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	input->args[x] = NULL;
	return (0);
}
#undef DELIMITER

#define DELIMITER ":"
/**
 * parse_line - parses arguments to valid command
 * @input: a pointer to the struct of data
 *
 * Return: 1 if success,
 */
int line_parser(sh_t *input)
{
	if (is_path_form(input) > 0)
		return (1);
	if (is_builtin(input) > 0)
	{
		if (handle_builtin(input) < 0)
			return (-1);
		return (0);
	}
	is_short_form(input);
	return (1);
}
#undef DELIMITER
/**
 * process_cmd - process command and execute process
 * @input: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 */
int process(sh_t *input)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(input->cmd, input->args, environ) < 0)
		input->error_msg = _strdup("not found\n");
			return (-1);
	}
	else
	{
		waitpid(pid, &stat, WUNTRACED);
	}
	return (0);
}
