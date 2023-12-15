#include "monty.h"
/**
 * free_stack - release list
 * @head: stack head
 */
void free_stack(stack_t *head)
{
        if (head)
        {
                free_stack(head->next);
                free(head);
        }
}
