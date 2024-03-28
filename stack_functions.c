#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to be pushed onto the stack
 */

void push(stack_t **stack, int value)
{
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
 * pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @return: Value of the removed element
 */

int pop(stack_t **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: cannot pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }

    int value = (*stack)->n;
    stack_t *temp = *stack;

    *stack = (*stack)->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }
    free(temp);

    return value;
}


/**
 * print_stack - Prints all the elements of the stack
 * @stack: Pointer to the top of the stack
 */

void print_stack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

