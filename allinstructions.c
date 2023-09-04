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
