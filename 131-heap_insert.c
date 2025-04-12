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
 * heap_insert_into_node - Attempts to insert value into a node
 * @current: Node to insert into
 * @value: Value to insert
 * Return: Pointer to new node or NULL
 */
heap_t *heap_insert_into_node(heap_t *current, int value)
{
	if (!current->left)
	{
		current->left = binary_tree_node(current, value);
		if (!current->left)
			return (NULL);
		return (current->left);
	}
	if (!current->right)
	{
		current->right = binary_tree_node(current, value);
		if (!current->right)
			return (NULL);
		return (current->right);
	}
	return (NULL);
}

/**
 * heap_insert_levelorder - Inserts a node using level-order traversal
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the created node or NULL
 */
heap_t *heap_insert_levelorder(heap_t *root, int value)
{
	heap_t *new_node, *current;
	heap_t **queue;
	size_t front = 0, rear = 0, size = 1024;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];

		new_node = heap_insert_into_node(current, value);
		if (new_node)
		{
			free(queue);
			return (bubble_up(new_node));
		}

		if (rear < size)
			queue[rear++] = current->left;
		if (rear < size)
			queue[rear++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	return (heap_insert_levelorder(*root, value));
}
