#include <stdlib.h>

/**
 * max - returns the maximum of two integers
 * @x: first integer
 * @y: second integer
 * Return: the greater of x and y
 */
int max(int x, int y)
{
	return (x > y ? x : y);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + max(
		binary_tree_height(tree->left),
		binary_tree_height(tree->right)
	));
}
