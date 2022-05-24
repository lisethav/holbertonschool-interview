#include "lists.h"

/**
 * insert_node - function inserts a number into a sorted singly linked list
 * @head: head of the list
 * @number: number to be inserted
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = NULL;
	listint_t *node = NULL;


	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;

	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
		return (node);
	}

	tmp = *(head);
	if (tmp->n >= number)
	{
		node->next = tmp;
		*(head) = node;
		return (node);
	}
	while (tmp->next != NULL)
	{
		if (tmp->next->n >= number)
		{
			node->next = tmp->next;
			tmp->next = node;
			return (node);
		}
		tmp = tmp->next;
	}
	tmp->next = node;
	node->next = NULL;
	return (node);
}
