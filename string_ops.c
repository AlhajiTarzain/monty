#include "monty.h"

/**
 * printChar - pull out top elemnt
 * @head: pointer pointer to head
 * @line_n: line number 
 * Return: nothing on suucess
 */
void printChar(stack_t **head, unsigned int line_n)
{
	stack_t *current_node;

	current_node = *head;

	if (!current_node)
	{
		fprintf(stderr, "L%d: can't print, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (current_node->n > 127 || current_node->n < 0)
	{
		fprintf(stderr, "L%d: can't print, stack value out of range\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current_node->n);
}

/**
 * print_topchar - show relemnt at the top
 * @head: pointer pinter to head
 * @line_n: line
 * Return: Return nothing
 */
void print_topchar(stack_t **head, unsigned int line_n)
{
	stack_t *current_node;

	current_node = *head;

	if (!current_node)
	{
		fprintf(stderr, "L%d: Can't print character, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (current_node->n > 127 || current_node->n < 0)
	{
		fprintf(stderr, "L%d: Can't print character, stack out of range\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current_node->n);
}

/**
 * print_string - show the string from benninging
 * @head: stack head
 * @line_n: line
 * Return: success nothing
 */
void print_string(stack_t **head, unsigned int line_n)
{
	stack_t *current_node;
	(void)line_n;

	current_node = *head;

	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
			break;

		printf("%c", current_node->n);
		current_node = current_node->next;
	}

	printf("\n");
}

/**
 * print_sktop -top
 * @head:head
 * @line_n: line number
 * Return: succcesfulm notinh
 */
void print_sktop(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
	m.stackMode = 0;
}
