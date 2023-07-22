#include <stdio.h>
#include <unistd.h>
/**
 * main - prints the process id of the parent process
 *
 * Return: 0 if success
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();

	printf("%u\n", my_ppid);

	return (0);
}
