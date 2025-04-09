#include "binary_trees.h"
#include <stdlib.h>
/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent: a pointer to the node to insert the left-child in
 *@value: the value to store in the new node
 *
 * Return: a pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *new_node;

	if (!parent)
		return (NULL);
	new_node = (binary_tree_node(parent, value));
	if (!parent->left)
		parent->left = new_node;
	else
	{
		tmp = parent->left;
		parent->left = new_node;
		new_node->left = tmp;
		tmp->parent = new_node;
	}
	return (new_node);
}
