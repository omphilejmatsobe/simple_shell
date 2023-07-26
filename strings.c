#include "simple_shell.h"

/**
 * _strcat - concatenates two string in a path form
 * @first: the first given destination
 * @second: the second given source
 *
 * Return: (Success) to the newly string
 * ------- (Fail) if it failed
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}

/**
 * _strlen - returns the lenth of a string
 *
 * @s: the input argument type string
 * Return: number of char , lenth of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++ != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: input string 1 to be compared
 * @s2: input string 2 to be compared
 *
 * Return: 0 if the strins are the same
 * negative if comparison is less and positive if greater
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

		i++;
	}

	return (0);
}


/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 *
 * Return: 1 if success
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}

/**
 * _strdup - dupicates string
 * @str: the given string
 *
 * Return: 1 if success
 */
char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
		return (NULL);
	_strcpy(dupl, str);
	return (dupl);
}
