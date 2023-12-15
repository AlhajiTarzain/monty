#include "monty.h"


/**
 * myadd - to the top of the satck adds teo elemnts
 * @head: the stack head
 * @line_n: the line
 * Return:  nothing on success
 */
void myadd(stack_t **head, unsigned int line_n)
{
        stack_t *alpha, *beta;

        if ((*head == NULL) || ((*head)->next == NULL))
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
                fclose(m.file);
                free(*head);
                exit(EXIT_FAILURE);
        }
        else
        {
                alpha = *head;
                beta = alpha->next;
                beta->n += alpha->n;
                *head = beta;
                (*head)->prev = NULL;
                free(alpha);
        }
}


/**
 * mydiv - separets top 2 elemts
 * @head: stack head
 * @line_n: the line
 * Return: nothing on success
 */
void mydiv(stack_t **head, unsigned int line_n)
{
        stack_t *top;
        int clone;
        int span = 0;

        top = *head;
        while (top)
        {
                top = top->next;
                span++;
        }
        if (span < 2)
        {
                fprintf(stderr, "L%d: Can't divide, stack too short\n", line_n);
                fclose(m.file);
                free(m.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        top = *head;
        if (top->n == 0)
        {
                fprintf(stderr, "L%d: diving by zero\n", line_n);
                fclose(m.file);
                free(m.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        clone = top->next->n / top->n;
        top->next->n = clone;
        *head = top->next;
        free(top);
}

/**
 * mysub -removes last two from stack
 * @head: sytack beginning
 * @line_n:e line number shows
 * Return: upon success nothing
 */
void mysub(stack_t **head, unsigned int line_n)
{
        stack_t *clone;
        int diff;
        int joints;

        clone = *head;
        for (joints = 0; clone != NULL; joints++)
                clone = clone->next;
        if (joints < 2)
        {
                fprintf(stderr, "L%d: Can't  do subtract, stack short\n", line_n);
                fclose(m.file);
                free(m.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        clone = *head;
        diff = clone->next->n - clone->n;
        clone->next->n = diff;
        *head = clone->next;
        free(clone);
}

