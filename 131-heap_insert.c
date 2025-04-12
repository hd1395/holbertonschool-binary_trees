#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_at_index - Gets the parent node for the next insertion
 * using index in level-order fashion
 * @tree: Pointer to the root node
 * @index: Index of the parent node
 * Return: Pointer to the parent node
 */
heap_t *get_node_at_index(heap_t *tree, size_t index)
{
	size_t path[64];
	size_t depth = 0, i;
	heap_t *current = tree;

	if (!tree)
		return (NULL);

	/* Convert index to binary path */
	while (index)
	{
		path[depth++] = index % 2;
		index /= 2;
	}

	/* Traverse using path (skip last bit to get parent) */
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
 * bubble_up - Moves the inserted node up to maintain Max Heap
 * @node: Pointer to the inserted node
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
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the created node or NULL on failure
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
