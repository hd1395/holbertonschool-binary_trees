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
 * get_node_at_index - Gets the node at a given index (level-order traversal)
 * @tree: Pointer to the root node
 * @index: Index to search for
 * Return: Pointer to the node or NULL
 */
heap_t *get_node_at_index(heap_t *tree, size_t index)
{
	size_t path[64], i = 0, depth = 0;
	heap_t *current = tree;

	if (!tree)
		return (NULL);

	while (index)
	{
		path[depth++] = index % 2;
		index /= 2;
	}

	for (i = depth; i > 1; i--)
	{
		if (path[i - 1] == 0)
			current = current->left;
		else
			current = current->right;
		if (!current)
			return (NULL);
	}

	return (current);
}

/**
 * bubble_up - Moves a node up to maintain Max Heap property
 * @node: Pointer to the node to adjust
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
 * Return: Pointer to the created node or NULL
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

	if (!parent)
		return (NULL);

	if (!parent->left)
	{
		parent->left = binary_tree_node(parent, value);
		if (!parent->left)
			return (NULL);
		new_node = parent->left;
	}
	else
	{
		parent->right = binary_tree_node(parent, value);
		if (!parent->right)
			return (NULL);
		new_node = parent->right;
	}

	bubble_up(new_node);
	return (new_node);
}
