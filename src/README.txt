
Le module BinaryTree permet de manipuler des arbres binaires. Afin
de vérifier que les arbres produits sont ceux auxquels vous vous
attendez, nous fournissons également une primitive qui prend un arbre,
le transforme en un fichier au format "gv" qui permet la visualisation
de l'arbre grâce au programme "dot".

Vous observerez attentivement la documentation dans BinaryTree.h
pour comprendre le fonctionnement des primitives.

Par exemple, le fichier example1_tree.c contient la construction d'un
arbre puis produit le fichier "gv" de cet arbre. Pour construire cet
arbre et le visualiser, il suffit d'exécuter les commandes suivantes :

make example1_tree
./example1_tree # produit example1.gv
make example1.pdf # produit example1.pdf si example1.gv existe

Vous pouvez alors visualiser le pdf produit avec l’outil de votre choix.

Pour compiler le programme de test Test_tree.c il suffira d'exécuter
make Test_tree

et on pourra lancer ce programme grâce à
./Test_tree
