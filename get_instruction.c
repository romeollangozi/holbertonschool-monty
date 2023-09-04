#include "monty.h"

instruction_t functions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

void (*get_function(char *opcode)) (stack_t **stack, unsigned int line_number)
{
	int i = 0;

	while (functions[i].opcode)
	{
		if (strcmp(functions[i].opcode, opcode) == 0)
			return (functions[i].f);

		i++;
	}
	return (NULL);
}
