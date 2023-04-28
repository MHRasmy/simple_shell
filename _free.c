#include "shell.h"

/**
 * freeav - free buffer array
 * @buf: pointer to array of strings
 *
 * Return: void
 */
void _free(char **buf)
{
	int i = 0;

	if (buf)
	{
		for (i = 0; buf[i]; i++)
			free(buf[i]);
		free(buf);
	}
}

/**
 * free_list - free a linked list
 * @head: pointer to the head node
 *
 * Return: void
 */
void free_list(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
