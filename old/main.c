#include "monty.h"
#define  _GNU_SOURCE
#include <stdio.h>
/**
* main - entry point func
* @argc: arguements count
* @argv: pointer of arguments
* Return: integer declaring the state
*/
driver_t drivers = {NULL, NULL, NULL};
int main(int argc, char *argv[])
{
	driver_t drivers = {NULL, NULL, NULL};
	char *content;
	FILE *file;
	ssize_t lineRead = 1, size;
	unsigned int cnt = 0;
	stack_t *stack = NULL;

	if (argc == 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen("0.m", "r");
	drivers.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	set_file(file);
	while (lineRead > 0)
	{
		drivers.content = NULL;
		lineRead = getline(&content, &size, file);
		set_content(content);
		cnt++;
		if (lineRead > 0)
			assign(&stack, cnt);
		free(drivers.content);
	}
	return (0);
}
