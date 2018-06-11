#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * binary_tree_is_full - check if a binary tree is full
 *
 * @tree: a binary tree
 *
 * Return 0 if fail, 1 if successful
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
  int is_full = 0;

  if (tree == NULL)
    return (0);

  if (tree->left == NULL && tree->right == NULL)
    is_full = 1;
  else if (tree->left != NULL && tree->right != NULL)
  {
    is_full = binary_tree_is_full(tree->left);
    if (is_full == 0)
      return (0);
    is_full = binary_tree_is_full(tree->right);
  }
  else
    is_full = 0;

  return (is_full);
}
