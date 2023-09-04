#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = line_number;
       	stack_t *tmp = NULL;	
	if (*stack == NULL)
	{
		*stack = node;
		return;
	}
	tmp = *stack;
	node->next = tmp;
	tmp->prev = node;
	*stack = node;
}

void pall(stack_t **stack,__attribute__((unused)) unsigned int line_number)
{
	stack_t *iterator = NULL;
	(void) line_number;
	if (*stack == NULL)
		return;
	iterator = *stack;
	while (iterator != NULL)
	{
		printf("%i\n", iterator->n);
		iterator = iterator->next;
	}
}

void handleErrors(char *opcode, char *number, void (*function)(stack_t **stack, unsigned int line_number), int line)
{	

	int hasAlpha = 0;
	char *numberCopy = number;
	while (*numberCopy)
	{
		if (isalpha(*numberCopy))
		{
			hasAlpha = 1;
			break;
		}
		numberCopy++;
	}
	if ((strcmp(opcode, "push") == 0) && ((strspn(number, "+-0123456789") == 0) || hasAlpha))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (function == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
	

}

