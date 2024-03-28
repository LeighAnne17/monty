#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file where the push opcode is encountered
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
    {
        fprintf(stderr, "L%u: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (operand == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(operand);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }


    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}


/**
 * pall - Prints all the values on the stack, starting from the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file where the pall opcode is encountered
 */

void pall(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        return;
    }

    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
