#include "monty.h"
/**
*get_function - function that returns a function for the appropriate opcode
*@line_number: line number
*@line: line
*Return: function
*/
void (*get_function(char *opcode)) (stack_t **stack,
		unsigned int line_number, int line)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	while (functions[i].opcode)
	{
		if (strcmp(functions[i].opcode, opcode) == 0)
			return (functions[i].f);

		i++;
	}
	return (NULL);
}
