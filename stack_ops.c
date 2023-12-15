#include "monty.h"

/**
 * mypall - this prints all elements.
 * @head:address head.
 * @line_n: line number
 *
 * Reutrn: succefule,nothinh
 */
void mypall(stack_t **head, unsigned int line_n)
{
	stack_t *current;

	(void)line_n;

	current = *head;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
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
 * mystack - print the top stack
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
 * mypint - print  top
 * @head: head
 * @line_n: line number
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
