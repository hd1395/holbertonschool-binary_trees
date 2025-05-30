#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree (number of nodes), or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
