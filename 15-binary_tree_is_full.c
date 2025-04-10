#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_is_full- checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (!tree)
return (1);
if (tree->left == NULL && tree->right == NULL)
return (1);

if ((tree->left) && (tree->right))
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
return (0);

}
