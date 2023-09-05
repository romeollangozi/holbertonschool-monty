#include "monty.h"
/**
 * pop - function tha prints the value at the top of the stack
 * @stack: stack
 * @line_number: line_number
 * @line: line
 */

void pop(stack_t **stack, unsigned int line_number, int line)
{
	(void) line_number;
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

/**
 * swap - function tha prints the value at the top of the stack
 * @stack: stack
 * @line_number: line_number
 * @line: line
 */

void swap(stack_t **stack, unsigned int line_number, int line)
{
	(void) line_number;
	stack_t *tmp = *stack;
	int length = 0;
	int n = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
/**
 * add - function tha prints the value at the top of the stack
 * @stack: stack
 * @line_number: line_number
 * @line: line
 */

void add(stack_t **stack, unsigned int line_number, int line)
{
	(void) line_number;
	stack_t *tmp = *stack;
	int length = 0;
	int n = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	n += (*stack)->next->n;
	(*stack)->next->n = n;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
