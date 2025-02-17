#ifndef ARBREBINAIRE
#include "BinaryTree.h"
#endif
#include <stdio.h>
#include <stdlib.h>

static 
binary_tree_p
allocate_binary_tree
(value_t val)
{
	binary_tree_p node ;
	node = malloc(sizeof(struct binary_tree_s)) ;
	node -> left = NULL ;
	node -> right  = NULL ;
	node -> val = val ;
	return node ;
}

binary_tree_p
create_empty_binary_tree
(void)
{
   return NULL;
}

binary_tree_p
create_leaf
(value_t val )
{
       return allocate_binary_tree(val) ;
}

void
destroy_binary_tree
(binary_tree_p root)
{
  if (! is_empty_binary_tree(root)) {
    destroy_binary_tree(left_subtree(root));
    destroy_binary_tree(right_subtree(root));
    free(root);
  }
}

int
is_empty_binary_tree
(binary_tree_p n)
{
	return n == NULL ;
}

int
is_leaf
(binary_tree_p a)
{
   if (is_empty_binary_tree(a))
      {
         fprintf(stderr, "Error: The tree is empty\n");
         exit(ARBREVIDE) ;
      }
   return (is_empty_binary_tree(left_subtree(a)) && is_empty_binary_tree(right_subtree(a)));
}


value_t 
get_value
(binary_tree_p n)
{
	return n->val ;
}

void
set_left_subtree
(binary_tree_p root,binary_tree_p node) {
   if (!is_empty_binary_tree(root->left))
      {
         fprintf(stderr, "Error: There is already a left subtree.\n");
         exit(SOUS_ARBRE_EXISTANT) ;
      }
   replace_left_subtree(root, node);
}

void
set_right_subtree
(binary_tree_p root,binary_tree_p node) {
   if (!is_empty_binary_tree(root->right))
      {
         fprintf(stderr, "Error: There is already a right subtree.\n");
         exit(SOUS_ARBRE_EXISTANT) ;
      }
   replace_right_subtree(root, node);
}

void
replace_left_subtree
(binary_tree_p root, binary_tree_p node) {
  if (is_empty_binary_tree(root))
    { 
      fprintf(stderr, "Error: The binary tree is empty\n");
      exit(ARBREVIDE) ;
    }
  root->left = node;
}

void
replace_right_subtree
(binary_tree_p root, binary_tree_p node) {
  if (is_empty_binary_tree(root))
    { 
      fprintf(stderr, "Error: The binary tree is empty\n");
      exit(ARBREVIDE) ;
    }
  root->right = node;
}

binary_tree_p
left_subtree(binary_tree_p n)
{
  if (is_empty_binary_tree(n))
    { 
      fprintf(stderr, "Error: The binary tree is empty\n");
      exit(ARBREVIDE) ;
    }
  return n->left;
}

binary_tree_p
right_subtree(binary_tree_p n)
{
  if (is_empty_binary_tree(n))
    { 
      fprintf(stderr, "Error: The binary tree is empty\n");
      exit(ARBREVIDE) ;
    }
  return n->right;
}
