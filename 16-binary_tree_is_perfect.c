#include "binary_trees.h"
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
return (1);

return (1 + max(
binary_tree_height(tree->left),
binary_tree_height(tree->right)
));

}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (!tree)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);

if ((tree->left) && (tree->right))
return ((binary_tree_height(tree->left) == binary_tree_height(tree->right))
&& (binary_tree_is_perfect(tree->left)
&& binary_tree_is_perfect(tree->right)));
return (0);

}


