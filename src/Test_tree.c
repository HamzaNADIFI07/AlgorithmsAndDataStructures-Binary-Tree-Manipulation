#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

#define max(a,b) ((a)>(b)?(a):(b))

#define DEBUT_ARBRE_MYSTERIEUX 12
#define FIN_ARBRE_MYSTERIEUX 24

/* Manipulation d'arbres binaires */

binary_tree_p tree1 (void) {
   
   binary_tree_p tree,left_subtree,right_subtree;

   tree = create_leaf(12) ;

   left_subtree = create_leaf(9) ;
   set_left_subtree(tree, left_subtree);

   right_subtree = create_leaf(8) ;
   set_right_subtree(tree,right_subtree);

   //save_tree_in_file(tree,"tree1");
	
   return tree;
}

binary_tree_p tree2 (void) {

   binary_tree_p tree,left_subtree,left_right_subtree, left_right_left_subtree  ;

   tree = create_leaf(12) ;

   left_subtree = create_leaf(9) ;
   set_left_subtree(tree, left_subtree);

   left_right_subtree = create_leaf(5) ;
   set_right_subtree(left_subtree,left_right_subtree);

	left_right_left_subtree = create_leaf(7) ;
   set_left_subtree(left_right_subtree, left_right_left_subtree);

   //save_tree_in_file(tree,"tree2");

   return tree;
}

binary_tree_p tree3 (void) {

   binary_tree_p tree,left_subtree,right_subtree,left_left_subtree, left_right_subtree, right_right_subtree, right_right_right_subtree, right_right_left_subtree ;

   tree = create_leaf(12) ;

   left_subtree = create_leaf(9) ;
   set_left_subtree(tree, left_subtree);

   right_subtree = create_leaf(8) ;
   set_right_subtree(tree,right_subtree);

   left_left_subtree = create_leaf(1) ;
   set_left_subtree(left_subtree,left_left_subtree);

	left_right_subtree = create_leaf(5) ;
   set_right_subtree(left_subtree,left_right_subtree);

   right_right_subtree = create_leaf(4) ;
   set_right_subtree(right_subtree,right_right_subtree);

   right_right_right_subtree = create_leaf(6) ;
   set_right_subtree(right_right_subtree,right_right_right_subtree);

   right_right_left_subtree = create_leaf(7) ;
   set_left_subtree(right_right_subtree,right_right_left_subtree);

   //save_tree_in_file(tree,"tree3");

   return tree;
}

void print_tree (binary_tree_p a) {
   ;
}

int size (binary_tree_p a) {
   return -1;
}

int height (binary_tree_p a) {
   return -1;
}

int nbLeaves(binary_tree_p a) {
   return -1;
}


/* Comptage d'arbres */

int nbTrees(int n) {
   return 0;
}
    
/* Manipulation d'arbres binaires de recherche */

binary_tree_p bst1 (void) {
   return NULL;
}

binary_tree_p add (value_t v, binary_tree_p a) {
   return NULL;
}

binary_tree_p bst2 (void) {
   return NULL;
}

binary_tree_p bst3 (void) {
   return NULL;
}

int exists (value_t v, binary_tree_p a) {
   return 0;
}

int min_value (binary_tree_p bst) {
   return -1;
}

int max_value (binary_tree_p bst) {
   return -1;
}

/* Entier mysterieux */

binary_tree_p build_tree_mysterious_integer (value_t i, value_t j) {
   return NULL;
}

void play (int i, int j) {
   ;
}

/* Tests sur les arbres binaires */

void binaryTreeProperties(binary_tree_p a) {
   print_tree(a); printf("\n");
   printf("Size     = %d\n",(size(a)));
   printf("Height    = %d\n",(height(a)));
   printf("nbLeaves = %d\n",(nbLeaves(a)));
}

/* Tests sur les arbres binaires de recherche */
void BSTProperties (binary_tree_p a) {
   int i;
   print_tree(a); printf("\n");
   printf("Size     = %d\n",(size(a)));
   printf("Height    = %d\n",(height(a)));
   printf("nbLeaves = %d\n",(nbLeaves(a)));
   printf("Values in the tree : ");
   for (i = 0; i <= 10; i++) {
      if (exists(i,a)) {
         printf("%d ",i);
      }
   }
   printf("\n");
}
  
/* Programme principal */
int main (int argc, char **argv) {

   int i;

   binary_tree_p a1 = tree1();
   binary_tree_p a2 = tree2();
   binary_tree_p a3 = tree3();
   
   binaryTreeProperties(a1);
   binaryTreeProperties(a2);
   binaryTreeProperties(a3);

   destroy_binary_tree(a1);
   destroy_binary_tree(a2);
   destroy_binary_tree(a3);

   for (i = 0; i <= 19; i++) {
      printf("Number of binary trees with %d nodes is %d\n",i,(nbTrees(i)));
   }

   a1 = bst1();
   a2 = bst2();
   a3 = bst3();
   
   BSTProperties(a1);
   BSTProperties(a2);
   BSTProperties(a3);

   destroy_binary_tree(a1);
   destroy_binary_tree(a2);
   destroy_binary_tree(a3);

   printf("Mysterious tree between %d and %d:\n", DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);
   print_tree(build_tree_mysterious_integer(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX));
   printf("\n");
  
   play(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);

   return 0;
   
}
