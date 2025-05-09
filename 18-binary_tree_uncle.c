#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_uncle- finds the uncle of a node
 * @node: pointer to the node to find its uncle
 * Return: the sibling of the node, NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);
if (node->parent->parent == NULL)
return (NULL);
if (node->parent->parent->left == NULL || node->parent->parent->right == NULL)
return (NULL);
if (node->parent->parent->left == node->parent)
return (node->parent->parent->right);
return (node->parent->parent->left);
}

