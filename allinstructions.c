#include "monty.h"
/**
 * push - function that pushes a new node into the stack
 * @stack: stack
 *@line_number: line number
 *@line: line
 */
void push(stack_t **stack, unsigned int line_number, int line)
{
	stack_t *node = malloc(sizeof(stack_t));
	(void) line;

	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = line_number;
	node->next = NULL;
	node->prev = NULL;
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
/**
 * pall - function that prints all the elements of the stack
 * @stack: stack
 * @line_number: line number
 * @line: line
 */
void pall(stack_t **stack, unsigned int line_number, int line)
{
	stack_t *iterator = *stack;
	(void) line;
	(void) line_number;

	if (*stack == NULL)
		return;
	while (iterator != NULL)
	{
		printf("%i\n", iterator->n);
		iterator = iterator->next;
	}
}
/**
 * handleErrors - function that handle all errors
 *@opcode: opcode
 *@number: number
 *@function: function
 *@line: line
 *@stack: stack
 *@file: file
 */
void handleErrors(char *opcode, char *number,
void (*function)(stack_t **stack, unsigned int line_number, int line),
int line, stack_t *stack, FILE *file)
{
	int hasAlpha = 0;
	char *numberCopy = number;
	(void) line;

	while (*numberCopy)
	{
		if (isalpha(*numberCopy))
		{
			hasAlpha = 1;
			break;
		}
		numberCopy++;
	}
	if ((strcmp(opcode, "push") == 0) &&
	((strspn(number, "+-0123456789") == 0) || hasAlpha))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (function == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line, opcode);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_stack - frees all allocated memory
 *@stack: stack
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	if (stack->next != NULL)
	{
		free_stack(stack->next);
	}
	free(stack);
}
/**
 * pint - function tha prints the value at the top of the stack
 * @stack: stack
 * @line_number: line_number
 * @line: line
 */

void pint(stack_t **stack, unsigned int line_number, int line)
{
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

