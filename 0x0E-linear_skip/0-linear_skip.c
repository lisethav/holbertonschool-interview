#include "search.h"
/**
 * print_found - imprimir mensaje
 * @f_idx: primer_idx
 * @s_idx: segundo_idx
 * @end: saber si el ultimo en linea express
 *
 * Retorno: nada
 */
void print_found(size_t f_idx, size_t s_idx, skiplist_t *end)
{
	if (end != NULL)
	{
		while (end->next != NULL)
			end = end->next;
		s_idx = end->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", f_idx, s_idx);
}
/**
 * print_check - imprimir mensaje
 * @idx: índice
 * @valor: valor
 *
 * Retorno: nada
 */
void print_check(size_t idx, int value)
{
	printf("Value checked at index [%lu] = [%i]\n", idx, value);
}
/**
 * find_each - comprobar siguiente por siguiente
 * @head: nodo de línea expresa
 * @value: valor a comparar
 *
 * Retorno: nodo encontrado
 */
skiplist_t *find_each(skiplist_t *head, int value)
{
	skiplist_t *current = head;

	if (head == NULL)
		printf("n head nullll");
	for (; current; current = current->next)
	{
		print_check(current->index, current->n);
		if (current->n == value)
			return (current);
	}
	return (NULL);
}
/**
 * linear_skip - encontró un valor en la lista de saltos
 * @head: nodo de línea expresa
 * @value: valor a comparar
 *
 * Retorno: nodo encontrado
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *cur = head, *next = NULL;

	if (head == NULL)
		return (NULL);

	while (cur != NULL)
	{
		next = cur->express;
		if (next != NULL)
		{
			print_check(next->index, next->n);
			if (next->n >= value)
			{
				print_found(cur->index, next->index, NULL);
				return (find_each(cur, value));
			}

			if (next->express == NULL)
			{
				print_found(next->index, 0, next);
				return (find_each(next, value));
			}
		}
		cur = cur->express;
	}
	return (NULL);
}