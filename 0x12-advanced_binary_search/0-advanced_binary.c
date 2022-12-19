#include "search_algos.h"
/**
 * search: busca recursivamente un valor dado en una matriz
 * @array: puntero al primer elemento de la búsqueda de matriz en
 * @value: el valor a buscar
 * @l: índice más a la izquierda utilizado como límite
 * @r: índice más a la derecha utilizado como límite
 *
 * return: El índice donde se ubicó el valor para el primer
 * tiempo, o -1
 */
int search(int *array, int l, int r, int value)
{
	int i, korn;

	korn = l + (r - l) / 2;
	if (l == r)
	{
		if (value < array[l] || value > array[r])
		{
			printf("Searching in array: %d\n", array[korn]);
			return (-1);
		}
		return (l);
	}
	printf("Searching in array:");
	for (i = l; i <= r; i++)
	{
		if (i != r)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (array[korn] < value)
		return (search(array, korn + 1, r, value));
	else
		return (search(array, l, korn, value));
}

/**
 * advanced_binary: busca un valor en una matriz ordenada de enteros.
 * @array: apunta al primer elemento de la matriz para buscar en
 * @size: número de elementos en la matriz
 * @value: el valor a buscar
 *
 * Retorno: El índice donde se ubicó el valor por primera vez, o -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (search(array, 0, size - 1, value));
}