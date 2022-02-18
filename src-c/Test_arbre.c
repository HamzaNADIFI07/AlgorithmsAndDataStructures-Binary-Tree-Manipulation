#include <stdio.h>
#include <stdlib.h>

#include "ArbreBinaire.h"

#define max(a,b) ((a)>(b)?(a):(b))

#define DEBUT_ARBRE_MYSTERIEUX 12
#define FIN_ARBRE_MYSTERIEUX 24

/* Manipulation d'arbres binaires */

Noeud_t arbre1 (void) {
   return NULL;
}

Noeud_t arbre2 (void) {
   return NULL;
}

Noeud_t arbre3 (void) {
   return NULL;
}

void imprimer (Noeud_t a) {
   ;
}

int taille (Noeud_t a) {
   return -1;
}

int hauteur (Noeud_t a) {
   return -1;
}

int nbFeuilles(Noeud_t a) {
   return -1;
}


/* Comptage d'arbres */

int nbArbres(int n) {
   return 0;
}
    
/* Manipulation d'arbres binaires de recherche */

Noeud_t abr1 (void) {
   return NULL;
}

Noeud_t ajouter (value_t v, Noeud_t a) {
   return NULL;
}

Noeud_t abr2 (void) {
   return NULL;
}

Noeud_t abr3 (void) {
   return NULL;
}

int appartient (value_t v, Noeud_t a) {
   return 0;
}

int valeur_minimale (Noeud_t abr) {
   return -1;
}

int valeur_maximale (Noeud_t abr) {
   return -1;
}

/* Entier mysterieux */

Noeud_t construitArbreEntierMysterieux (value_t i, value_t j) { 
   return NULL;
}

void jouer (int i, int j) {
   ;
}

/* Tests sur les arbres binaires */

void testArbreBinaire(Noeud_t a) {
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
}

/* Tests sur les arbres binaires de recherche */
void testABR (Noeud_t a) {
   int i;
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
   printf("Valeurs présentes dans l'arbre : ");
   for (i = 0; i <= 10; i++) {
      if (appartient(i,a)) {
         printf("%d ",i);
      }
   }
   printf("\n");
}
  
/* Programme principal */
int main (int argc, char **argv) {

   int i;

   Noeud_t a1 = arbre1();
   Noeud_t a2 = arbre2();
   Noeud_t a3 = arbre3();
   
   testArbreBinaire(a1);
   testArbreBinaire(a2);
   testArbreBinaire(a3);

   DetruireArbre(a1);
   DetruireArbre(a2);
   DetruireArbre(a3);

   for (i = 0; i <= 19; i++) {
      printf("Le nombre d'arbres à %d noeuds est %d\n",i,(nbArbres(i)));
   }

   a1 = abr1();
   a2 = abr2();
   a3 = abr3();
   
   testABR(a1);
   testABR(a2);
   testABR(a3);

   DetruireArbre(a1);
   DetruireArbre(a2);
   DetruireArbre(a3);

   printf("Arbre mysterieux entre %d et %d:\n", DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);
   imprimer(construitArbreEntierMysterieux(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX));
   printf("\n");
  
   jouer(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);

   return 0;
   
}
