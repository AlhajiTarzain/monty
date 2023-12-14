#include "monty.h"

/**
 * mypall - this prints all elements.
 * @head:address head of stack.
 * @line_n: function line.
 *
 * Reutrn: nothing.
 */
void mypall(stack_t **head, unsigned int line_n)
{
	stack_t *current_node = *head;
	(void)line_n;
	if (current_node == NULL)
	{
		return;
	}

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

void mypush(stack_t **head, unsigned int line_n)
{
	int n;
	int i = 0;
	int flag = 0;

	if (m.arg)
	{
		if (m.arg[0] == '-')
			i++;
		for (; m.arg[i] != '\0'; i++)
		{
			if (m.arg[i] > 57 || m.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			fclose(m.file);
			free(m.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(m.arg);
	if (m.stackMode == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}


/**
 * f_stack - print the top stack
 * @head: the head stack
 * @line_n: the line number
 * Return: Return nothing
 */
void mystack(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
	m.stackMode = 0;
}
/**
 * f_pint - print the top
 * @head: the stack head
 * @line_n: the line number
 * Return: Return nothing
 */
void mypint(stack_t **head, unsigned int line_n)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: Can't pint, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
void mypop(stack_t **head, unsigned int line_n)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
