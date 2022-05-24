#include "binary_trees.h"

/**
* is_leaf - verify if a node is a leaf
* @node: node to check
*
* Return: 1 if is a leaf, otherwise 0
*/
int is_leaf(heap_t *node)
{
	if (!node->left && !node->right)
		return (1);
	return (0);
}

/**
* tree_depth - get the depth of a node
* @tree: node to check
*
* Return: depth
*/
int tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root:  is a double pointer to the root node of the Heap
* @value:  is the value to store in the node to be inserted
*
* Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	int height = 0, level, tmp_value;
	heap_t *new_node = NULL;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	height = tree_height(*root);
	for (level = 0; level <= height; level++)
	{
		new_node = add_node(*root, level, value);
		if (new_node)
			break;
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp_value = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = tmp_value;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
* tree_height - function to know the height of a binary sub-tree
* @tree: first node of the tree
*
* Return: height of the sub-tree
*/
int tree_height(heap_t *tree)
{
	int l_height, r_height;

	if (!tree || is_leaf(tree) == 1)
		return (0);

	l_height = tree_height(tree->left) + 1;
	r_height = tree_height(tree->right) + 1;

	if (l_height >= r_height)
		return (l_height);
	return (r_height);
}

/**
* add_node - add a node
* @tree: pointer to tree
* @level: level of insertion
* @value: value of the new node
*
* Return: new node
*/
binary_tree_t *add_node(binary_tree_t *tree, int level, int value)
{
	binary_tree_t *left_node, *right_node;

	if (!tree)
		return (NULL);
	if (tree_depth(tree) == level)
	{
		if (is_leaf(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left && !tree->right)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left_node = add_node(tree->left, level, value);
	if (!left_node)
		right_node = add_node(tree->right, level, value);
	else
		return (left_node);
	return (right_node);
}