#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BinaryTree.h"
#include "Display.h"

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

   save_tree_in_file(tree,"tree1");

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

   save_tree_in_file(tree,"tree2");

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

   save_tree_in_file(tree,"tree3");

   return tree;
}

int print_tree (binary_tree_p a) {
   if (a != NULL) {

      print_tree(a->left);

      printf("%ld ", a->val);

      print_tree(a->right); 

   }
   return 0;
}
int size (binary_tree_p a) {
   if (a == NULL){
      return 0;
   }
   return 1 + size(a->left) + size(a->right);
}

int height (binary_tree_p a) {
   if (a == NULL){
      return -1;
   }
   return 1 + max(height(a->left), height(a->right));
}

int nbLeaves(binary_tree_p a) {
   if (a == NULL){
      return 0;
   }

   if (a->left == NULL && a->right == NULL){
      return 1;
   }

   return nbLeaves(a->left) + nbLeaves(a->right);

}


/* Comptage d'arbres */

int nbTrees(int n) {
   if (n == 0) {
      return 1;
   } 
   else {
      int total = 0;
      int k;
      for ( k = 0; k <= n - 1; k++) {
         total += nbTrees(k) * nbTrees(n - k - 1);
      }
      return total;
   }
}
int nbTreesEfficient(int n) {
   int i, k;

   int *C = malloc((n + 1) * sizeof(int));
    
   if (C == NULL) {
      printf("Erreur d'allocation mémoire.\n");
      exit(EXIT_FAILURE);
   }

   C[0] = 1;
   for ( i = 1; i <= n; i++) {
      C[i] = 0;
      for ( k = 0; k < i; k++) {
         C[i] += C[k] * C[i - 1 - k];
      }
   }
   int result = C[n];
   free(C);
   return result;
}
    
/* Manipulation d'arbres binaires de recherche */

binary_tree_p bst1 (void) {
   binary_tree_p tree,left_subtree,right_subtree, left_right_subtree,left_left_subtree, left_left_left_subtree  ;

   tree = create_leaf(6) ;

   left_subtree = create_leaf(4) ;
   set_left_subtree(tree, left_subtree);

   left_left_subtree = create_leaf(2) ;
   set_left_subtree(left_subtree, left_left_subtree);

   right_subtree = create_leaf(7) ;
   set_right_subtree(tree, right_subtree);

   left_right_subtree = create_leaf(5) ;
   set_right_subtree(left_subtree,left_right_subtree);

	left_left_left_subtree = create_leaf(1) ;
   set_left_subtree(left_left_subtree, left_left_left_subtree);

   save_tree_in_file(tree,"treerech");

   return tree;
}

binary_tree_p add(value_t v, binary_tree_p a) {
   
   if (is_empty_binary_tree(a)) {
      return create_leaf(v);
   }

   if (v <= get_value(a)) {
      binary_tree_p left = left_subtree(a);
      if (is_empty_binary_tree(left)) {
         set_left_subtree(a, create_leaf(v));
      } else {
         add(v, left);
      }
   } else {
      binary_tree_p right = right_subtree(a);
      if (is_empty_binary_tree(right)) {
         set_right_subtree(a, create_leaf(v));
      } else {
         add(v, right);
      }
   }

   return a;
}



binary_tree_p bst2 (void) {
   binary_tree_p arbre;
   arbre = create_leaf(5);

   add( 4 , arbre );
   add( 2 , arbre );
   add( 7 , arbre );
   add( 6 , arbre );
   add( 1 , arbre );
   save_tree_in_file(arbre,"treerech2");
   return arbre;
}

binary_tree_p bst3 (void) {
   binary_tree_p arbre;
   arbre = create_leaf(7);

   add( 1 , arbre );
   add( 4 , arbre );
   add( 5 , arbre );
   add( 6 , arbre );
   add( 2 , arbre );
   save_tree_in_file(arbre,"treerech3");
   return arbre;
}


int exists(value_t v, binary_tree_p a) {
   int nbComparaison = 0;
   while (!is_empty_binary_tree(a)) {
      nbComparaison++;
      value_t valeur = get_value(a);
      if (v == valeur) {
         printf("Nombre de comparaisons : %d\n", nbComparaison);
         return 1;
      } else if (v < valeur) {
         a = left_subtree(a);
      } else {
         a = right_subtree(a);
      }
   }
   printf("Nombre de comparaisons : %d\n", nbComparaison);
   return 0;
}

int min_value (binary_tree_p bst) {
   if (is_empty_binary_tree(bst)) {
      return -1;
   }

   while (!is_empty_binary_tree(left_subtree(bst))) {
      bst = left_subtree(bst);
   }

   return get_value(bst);
}

int max_value (binary_tree_p bst) {
   if (is_empty_binary_tree(bst)) {
      return -1;
   }

   while (!is_empty_binary_tree(right_subtree(bst))) {
      bst = right_subtree(bst);
   }

   return get_value(bst);
}

/* Entier mysterieux */

binary_tree_p build_tree_mysterious_integer (value_t i, value_t j) {
   if (i > j) {
      return create_empty_binary_tree();
   }

   value_t milieu = (i + j) / 2;
   binary_tree_p leaf = create_leaf(milieu);

   binary_tree_p left = build_tree_mysterious_integer(i, milieu - 1);
   binary_tree_p right = build_tree_mysterious_integer(milieu + 1, j);

   if (!is_empty_binary_tree(left)) {
      set_left_subtree(leaf, left);
   }

   if (!is_empty_binary_tree(right)) {
      set_right_subtree(leaf, right);
   }

   return leaf;
}

void play (int i, int j) {
   binary_tree_p arbreMyst = build_tree_mysterious_integer(i,j);
   printf("choisir un nombre entre %d et %d ? :\n", i, j);
   int x;
   scanf("%d", &x);
   value_t noeud = get_value(arbreMyst);
   printf("\n Est-ce %d ? \n",noeud);
   while (noeud != x){
      if (x < noeud){
         printf("\n Trop grand \n");
         arbreMyst = left_subtree(arbreMyst);
      }
      else{
         printf("\n Trop petit \n");
         arbreMyst = right_subtree(arbreMyst);
      }
      noeud = get_value(arbreMyst);
      printf("\n Est-ce %d \n ",noeud);
   }
   printf("\n C'est gagné !\n");

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

   struct timespec debut, fin;
   double temps_execution;

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

   clock_gettime(CLOCK_MONOTONIC, &debut);
   for (i = 0; i <= 19; i++) {
      printf("Number of binary trees with %d nodes is %d\n",i,(nbTreesEfficient(i)));
   }
   clock_gettime(CLOCK_MONOTONIC, &fin);
   temps_execution = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
   printf("Temps d'exécution : %.9f secondes\n", temps_execution);

   a1 = bst1();
   a2 = bst2();
   a3 = bst3();
   
   BSTProperties(a1);
   BSTProperties(a2);
   BSTProperties(a3);

   exists(0, a1);
   exists(0, a2);
   exists(0, a3);

   destroy_binary_tree(a1);
   destroy_binary_tree(a2);
   destroy_binary_tree(a3);

   printf("Mysterious tree between %d and %d:\n", DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);
   print_tree(build_tree_mysterious_integer(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX));
   printf("\n");
  
   play(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);


   return 0;
   
}
