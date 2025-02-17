#define ARBREBINAIRE

#define SOUS_ARBRE_EXISTANT 1 
#define BADARGUMENT 2
#define ARBREVIDE 3

typedef signed long int value_t ;
typedef struct binary_tree_s *binary_tree_p;


/**
 * Structure interne de l'arbre binaire.
 * Cette structure ne doit pas être utilisée directement. 
 * Il **faut** passer par les fonctions de ArbreBinaire.h
 */
struct binary_tree_s
{
	/** The value stored in the node. */
	value_t  val ;
	/** `left` and `right` are respectively the left and right subtrees of the tree. */
	binary_tree_p left, right;
} ;


/**
 * @return an empty binary tree
 */
binary_tree_p create_empty_binary_tree(void) ;

/**
 * Create a leaf with the value passed in parameter
 *
 * @param the value of the leaf
 * @return a binary tree consisting of a leaf whose value is passed in parameter
 */
binary_tree_p create_leaf(value_t) ;

/**
 * Destroy the tree passed in parameterDétruit l'arbre passé en paramètre.
 * The memory used by the binary tree is freed, thus the tree must not be used anymore.
 */
void destroy_binary_tree(binary_tree_p);

/**
 * @return a value evaluated as true if the binary tree is empty
 */
int is_empty_binary_tree(binary_tree_p);

/**
 * Assesses whether the binary tree consists of a single leaf.
 * @pre The binary tree must not be empty.
 * @return a value evaluated as true if the binary tree consists of a single leaf.
 */
int is_leaf (binary_tree_p);

/**
 * @pre The binary tree must not be empty.
 * @return the value associated to the root of the binary tree passed in parameter
 */
value_t get_value(binary_tree_p) ;

/**
 * Adds to the left subtree of the first parameter the tree given in the second parameter.
 * @pre The binary tree in the parameter must not be empty but its left subtree must be empty.
 */
void set_left_subtree(binary_tree_p,binary_tree_p) ;

/**
 * Adds to the right subtree of the first parameter the tree given in the second parameter.
 * @pre The binary tree in the parameter must not be empty but its right subtree must be empty.
 */
void set_right_subtree(binary_tree_p,binary_tree_p) ;

/**
 * Replaces the left subtree of the binary tree passed as the first argument by the binary
 * tree in the second argument.
 * @pre The first argument must not be an empty binary tree.
 */
void replace_left_subtree(binary_tree_p,binary_tree_p) ;

/**
 * Replaces the right subtree of the binary tree passed as the first argument by the binary
 * tree in the second argument.
 * @pre The first argument must not be an empty binary tree.
 */
void replace_right_subtree(binary_tree_p,binary_tree_p) ;

/**
 * @return The left subtree of the binary tree passed in parameter
 * @pre The binary tree must not be empty
 */
binary_tree_p left_subtree(binary_tree_p);

/**
 * @return The right subtree of the binary tree passed in parameter
 * @pre The binary tree must not be empty
 */
binary_tree_p right_subtree(binary_tree_p);
