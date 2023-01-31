#include "lists.h"

/**
 * find_listint_loop - encuentra el bucle en una lista enlazada.
 * @head: puntero a un puntero a una lista al primer elemento de una lista.
 * Retorno: dirección del nodo donde comienza el bucle, o NULL si no hay nodo.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *f;
	listint_t *s;

	if (head == NULL)
		return (NULL);

	f = head;
	s = head;

	while (f != NULL && f->next != NULL && f->next->next != NULL)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
		{
			s = head;
			while (s != f)
			{
				s = s->next;
				f = f->next;
			}
			return (f);
		}
	}
	return (NULL);
}