#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root,
 * Otherwise - returns 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->parent)
		return (0);
	return (1);
}
