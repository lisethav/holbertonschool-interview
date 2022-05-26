#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: palindrome head
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *auxh = *head;
	int first_node = 0, second_node = 0, len, status = 0;
	int array_of_num[BUFSIZ];

	while (auxh)
	{
		array_of_num[first_node] = auxh->n;
		auxh = auxh->next;
		first_node += 1;
	}
	if (first_node == 0 || first_node == 1)
		return (1);
	first_node -= 1;
	len = first_node;
	while (second_node < len)
	{
		if (array_of_num[second_node++] == array_of_num[first_node--])
			status = 1;
		else
			return (0);
	}
	return (status);
}
