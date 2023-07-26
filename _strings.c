#include "simple_shell.h"
/**
 * _strcpy - copies the string pointed to by src
 *
 * @dest: the copying string
 * @src: the string being copied
 * Return: the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}

	if (*src == '\0')
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 *  _isalpha - checks for alphabetic character
 * @c: the character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 93 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
