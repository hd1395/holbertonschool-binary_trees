#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_sibling- finds the sibling of a node
 * @node: pointer to the node to find its sibling
 * Return: the sibling of the node, NULL otherwise
 */
int binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);

if (node->parent->left == node)
return (node->parent->right);
return (node->parent->left);
}
