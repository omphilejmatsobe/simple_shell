#include "simple_shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: input void char pointer of memory
 * @old_size: input unsigned int size
 * @new_size: input unsigned int size
 * Return: arr or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int x;
	char *arr, *intA;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		arr = malloc(new_size);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	arr = malloc(new_size);
	if (arr == NULL)
		return (NULL);
	intA = ptr;
	for (x = 0; x < old_size; x++)
		*(arr + x) = *(intA + x);
	free(ptr);
	return (arr);
}

/**
 *_memset - fills memory with a constant byte
 *
 *@s: memory where is stored
 *@byt: memory where is copied
 *@n: number of bytes
 *Return: copied memory with n byted changed
 */
char *_memset(char *s, char byt, unsigned int n)
{
	unsigned int z;

	for (z = 0; z < n; z++)
	{
		s[z] = byt;
	}
	return (s);
}

/**
 * _data - frees data
 * @data: the data structure
 *
 * Return: 1if success
 * ------- (Fail) negative number
 */
int _data(sh_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}

/**
 * _memcpy - copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}
