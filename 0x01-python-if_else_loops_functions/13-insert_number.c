#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_node - Insert node in order mode to linkedlist
 * @head: head
 * @number: num to be added
 * Return: the head of node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *actual;

	if (!new)
		return (NULL);

	new->n = number;
	actual = *head;

	if (number < actual->n || !actual)
	{
		new->next = actual;
		*head = new;
		return (new);
	}

	while (actual && actual->next)
	{
		if (number <= (actual->next)->n)
		{
			new->next = actual->next;
			actual->next = new;
			return (new);
		}
		actual = actual->next;
	}

	new->next = NULL;;
	actual->next = new;

	return (new);
}
