#include "search_algos.h"
/**
 * advanced_binary - searches a value in an array of integers
 * @array: pointer to the first element
 * @size: number of elements in array
 * @value: the value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index = 0;

	if (array == NULL || size == 0)
		return (-1);

	index = binary_search(array, 0, size - 1, value);
	return (index);
}

/**
 * binary_search - recursive search
 * @array: pointer to the first element
 * @left: first element
 * @right: last element
 * @value: the value to search for
 * Return: index
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	mid = (left + right) / 2;

	if (value == array[mid])
	{
		print_binary(array, left, right);
		return (mid);
	}
	else if (value < array[mid])
	{
		print_binary(array, left, right);
		return (binary_search(array, left, mid - 1, value));
	}
	else
	{
		print_binary(array, left, right);
		return (binary_search(array, mid + 1, right, value));
	}
}

/**
 * print_binary - print array searched
 * @array: pointer to the first element
 * @left: first element
 * @right: last element
 */
void print_binary(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
}