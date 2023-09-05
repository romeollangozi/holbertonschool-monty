#include "monty.h"
#define MAX_SIZE 100
/**
 * main- ENTRY POINT
 * @argc: arg count
 * @argv: list of arguments
 *Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int line = 1;
	stack_t *head = NULL;
	char *opcode = NULL, *number = "0", command[MAX_SIZE];
	void (*function)(stack_t **stack, unsigned int line_number) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, MAX_SIZE, file) != NULL)
	{
		opcode = strtok(command, " \n");
		if (opcode == NULL)
		{
			line++;
			continue;
		}
		number = strtok(NULL, " \n");
		if (number == NULL)
			number = "s";

		function = get_function(opcode);
		handleErrors(opcode, number, function, line, head, file);
		function(&head, atoi(number));
		line++;
	}
	fclose(file);
	free_stack(head);
	return (0);
}
