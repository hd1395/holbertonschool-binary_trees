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
 * get_node_at_index - Gets the node where we should insert next
 * @tree: Pointer to the root node
 * @index: Index to find (as if tree is in array)
 * Return: Pointer to node at that position
 */
heap_t *get_node_at_index(heap_t *tree, size_t index)
{
	heap_t *parent;
	size_t path[64], i = 0, depth = 0;

	if (!tree)
		return (NULL);

	while (index)
	{
		path[depth++] = index % 2;
		index /= 2;
	}

	parent = tree;
	for (i = depth - 1; i > 0; i--)
	{
		if (path[i] == 0)
			parent = parent->left;
		else
			parent = parent->right;
	}
	return (parent);
}

/**
 * bubble_up - Fixes the Max Heap by moving the node up
 * @node: The node to bubble up
 */
void bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent = get_node_at_index(*root, (size - 1) / 2);

	if (parent->left == NULL)
	{
		parent->left = binary_tree_node(parent, value);
		new_node = parent->left;
	}
	else
	{
		parent->right = binary_tree_node(parent, value);
		new_node = parent->right;
	}

	bubble_up(new_node);
	return (new_node);
}
