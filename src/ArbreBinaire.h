#define ARBREBINAIRE

#define SOUS_ARBRE_EXISTANT 1 
#define BADARGUMENT 2
#define ARBREVIDE 3

typedef signed long int value_t ;
typedef struct NoeudBinaire_m * Noeud_t ;


/**
 * Structure interne de l'arbre binaire.
 * Cette structure ne doit pas être utilisée directement. 
 * Il **faut** passer par les fonctions de ArbreBinaire.h
 */
struct NoeudBinaire_m 
{
	value_t  val ;
	Noeud_t  gauche ;
	Noeud_t  droite ;
} ;


/**
 * @return un arbre vide
 */
Noeud_t CreerArbreVide(void) ;

/**
 * Crée une feuille avec la valeur passée en paramètre
 *
 * @param la valeur de la feuille
 * @return un arbre d'une seule feuille dont la valeur est celle passée en paramètre
 */
Noeud_t CreerNoeud(value_t) ;

/**
 * Détruit l'arbre passé en paramètre.
 * La mémoire occupée par l'arbre est libérée et l'arbre ne doit donc plus être utilisé.
 */
void DetruireArbre(Noeud_t);

/**
 * @return une valeur évaluée à vraie si l'arbre passé en paramètre est vide.
 */
int EstVide (Noeud_t);

/**
 * Teste si un arbre est restreit à une feuille.
 * @pre L'arbre passé en paramètre ne doit pas être vide.
 * @return une valeur évaluée à vrai si et seulement si l'arbre est restreint à une feuille
 */
int EstFeuille (Noeud_t);

/**
 * @pre L'arbre passé en paramètre ne doit pas être vide.
 * @return La valeur associée au nœud passé en paramètre
 */
value_t ValeurDuNoeud(Noeud_t) ;

/**
 * Ajoute en sous-arbre gauche du premier paramètre l'arbre passé en second paramètre.
 * @pre L'arbre passé en premier paramètre ne doit pas être vide mais son 
 * sous-arbre gauche doit être vide
 */
void AjouterGauche(Noeud_t,Noeud_t) ;

/**
 * Ajoute en sous-arbre droit du premier paramètre l'arbre passé en second paramètre.
 * @pre L'arbre passé en premier paramètre ne doit pas être vide mais son 
 * sous-arbre droit doit être vide
 */
void AjouterDroite(Noeud_t,Noeud_t) ;

/**
 * Remplace le sous-arbre gauche du noeud en premier argument par le noeud
 * second argument.
 * @pre Le premier argument ne doit pas être un arbre vide.
 */
void RemplacerGauche(Noeud_t,Noeud_t) ;

/**
 * Remplace le sous-arbre droit du noeud en premier argument par le noeud
 * second argument.
 * @pre Le premier argument ne doit pas être un arbre vide.
 */
void RemplacerDroite(Noeud_t,Noeud_t) ;

/**
 * @return Le sous-arbre gauche de l'arbre passé en paramètre
 * @pre L'arbre ne doit pas être vide.
 */
Noeud_t Gauche(Noeud_t);

/**
 * @return Le sous-arbre droit de l'arbre passé en paramètre
 * @pre L'arbre ne doit pas être vide.
 */
Noeud_t Droite(Noeud_t);


