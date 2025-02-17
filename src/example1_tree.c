#include "BinaryTree.h"
#include "Display.h"

int
main
(void)
{
  binary_tree_p tree,left_subtree,right_subtree, right_right_subtree  ;

  tree = create_leaf(1) ;
  left_subtree = create_leaf(2) ;
  set_left_subtree(tree, left_subtree);
  right_subtree = create_leaf(3) ;
  set_right_subtree(tree,right_subtree);
  right_right_subtree = create_leaf(4) ;
  set_right_subtree(right_subtree,right_right_subtree);
	
  save_tree_in_file(tree,"example1");

  destroy_binary_tree(tree);
        
  return 0 ;
}
