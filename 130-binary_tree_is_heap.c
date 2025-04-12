#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 * @index: Current index
 * @size: Total number of nodes
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * is_max_heap - Checks if tree respects Max Heap property
 * @tree: Pointer to the root node
 * Return: 1 if valid, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		if (!is_max_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		if (!is_max_heap(tree->right))
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node
 * Return: 1 if valid Max Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	if (!is_complete(tree, 0, size))
		return (0);

	return (is_max_heap(tree));
}
