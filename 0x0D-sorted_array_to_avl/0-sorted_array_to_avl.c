#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the array to convert
 * @size: number of elements in the array
 * Return: a pointer to the new AVL tree or Null if it fails
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	avl_t *root = NULL;

	if (!array || !size)
		return (NULL);

	root = construct_avl(&root, array, 0, size - 1);

	return (root);
}

/**
 * construct_avl - builds an AVL tree from an array with recursion
 * @root: double pointer to the root
 * @array: pointer to the array to convert
 * @start: start of the tree
 * @end: end of the tree
 * Return: a pointer to the new AVL tree or Null if it fails
 */
avl_t *construct_avl(avl_t **root, int *array, int start, int end)
{
	int mid;
	avl_t *head = NULL;

	if (start > end)
	{
		return (NULL);
	}

	mid = (start + end) / 2;
	head = binary_tree_node(array[mid], *root);

	if (mid != start)
	{
		head->left = construct_avl(&head, array, start, mid - 1);
	}
	if (mid != end)
	{
		head->right = construct_avl(&head, array, mid + 1, end);
	}

	return (head);
}

/**
 * binary_tree_node - create new node
 * @value: value to enter in the node
 * @parent: pointer to the parent node
 * Return: new node of NULL if it fails
 */
avl_t *binary_tree_node(int value, avl_t *parent)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->parent = parent;
	new_node->right = NULL;

	return (new_node);
}