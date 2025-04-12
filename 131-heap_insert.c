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
 * bubble_up - Moves the inserted node up to maintain Max Heap
 * @node: Pointer to the inserted node
 * Return: Pointer to the final node after bubbling
 */
heap_t *bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;
	heap_t **queue;
	size_t front = 0, rear = 0, size = 1024;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = *root;

	while (front < rear)
	{
		current = queue[front++];

		if (!current->left)
		{
			current->left = binary_tree_node(current, value);
			if (!current->left)
			{
				free(queue);
				return (NULL);
			}
			new_node = current->left;
			free(queue);
			return (bubble_up(new_node));
		}
		else
		{
			if (rear < size)
				queue[rear++] = current->left;
		}

		if (!current->right)
		{
			current->right = binary_tree_node(current, value);
			if (!current->right)
			{
				free(queue);
				return (NULL);
			}
			new_node = current->right;
			free(queue);
			return (bubble_up(new_node));
		}
		else
		{
			if (rear < size)
				queue[rear++] = current->right;
		}
	}

	free(queue);
	return (NULL);
}
