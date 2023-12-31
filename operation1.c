#include "monty.h"
#include <stdlib.h>

/**
 * push - adds a new node to the beginning of the linked list
 * @head: beginning of linked list
 * @n: value of new node
 * Return: the new node that was added
 */

stack_t *push(stack_t **head, int n)
{
stack_t *new;

new = malloc(sizeof(stack_t));
if (!new)
{
if (*head != NULL)
free_stack(*head);
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new->n = n;
new->next = *head;
new->prev = NULL;

if (*head)
(*head)->prev = new;

*head = new;

return (new);
}

/**
 * pall - prints doubly linked list
 * @stack: start of doubly linked list
 * @line_n: line number
 */

void pall(stack_t **stack, unsigned int line_n)
{
stack_t *h = *stack;

if (!stack)
{
fprintf(stderr, "L%d: can't pall, stack empty\n", line_n);
exit(EXIT_FAILURE);
}
for (; h; h = h->next)
fprintf(stdout, "%d\n", h->n);
}

/**
 * pint - prints first node of linked list
 * @stack: first node of linked list
 * @line_n: line number
 */

void pint(stack_t **stack, unsigned int line_n)
{
stack_t *h = *stack;

if (!h)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
exit(EXIT_FAILURE);
}
fprintf(stdout, "%d\n", h->n);

}

/**
 * pop - removes first node of a linked list
 * @stack: first node of linked list
 * @line_n: line number
 */

void pop(stack_t **stack, unsigned int line_n)
{
stack_t *delete = *stack;

if (!delete)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
exit(EXIT_FAILURE);
}
*stack = delete->next;
free(delete);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: first node of linked list
 * @line_n: line number
 */

void swap(stack_t **stack, unsigned int line_n)
{
int hold = (*stack)->n;

if (!(stack) || !(*stack) || !(*stack)->next)
{
free_stack(*stack);
fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
exit(EXIT_FAILURE);
}
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = hold;
}
