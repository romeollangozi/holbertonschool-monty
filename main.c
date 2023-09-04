#include "monty.h"
#define MAX_SIZE 100
int main(int argc, char **argv)
{
	FILE *file;
	int line = 1;
	stack_t *head = NULL;
	char *opcode;
	char *number = "0";
	char command[MAX_SIZE];
	void (*function)(stack_t **stack, unsigned int line_number);
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
	while(fgets(command, MAX_SIZE, file) != NULL)
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
		handleErrors(opcode, number, function, line);
		function(&head, atoi(number));
		line++;
	}
		return (0);
}
