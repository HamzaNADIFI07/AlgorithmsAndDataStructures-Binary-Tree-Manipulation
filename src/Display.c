#ifndef ARBREBINAIRE
#include "BinaryTree.h"
#endif
#include <stdio.h>
#include <stdlib.h>

static
unsigned int
RecursiveTraversal
(binary_tree_p tree, FILE *mfile)
{
  static unsigned int nodenumber ;
  unsigned int fg,fd,node ;

  node = ++nodenumber ;

  if (is_empty_binary_tree(tree)) {
    fprintf(mfile,"N%d [style=invis]\n",nodenumber);
    return nodenumber ;
  }
  
  fprintf(mfile,"N%d [label=\"%d\"]\n",nodenumber,(int) get_value(tree));
  fg = RecursiveTraversal(left_subtree(tree),mfile) ;
  fd = RecursiveTraversal(right_subtree(tree),mfile) ;
  if (!is_empty_binary_tree(left_subtree(tree)))
    fprintf(mfile,"N%d -> N%d\n",node,fg) ;
  else
    fprintf(mfile,"N%d -> N%d [style=invis]\n",node,fg) ;
     
  if (!is_empty_binary_tree(right_subtree(tree)))
    fprintf(mfile,"N%d -> N%d\n",node,fd) ;
  else
    fprintf(mfile,"N%d -> N%d [style=invis]\n",node,fd) ;

	
  return node;
}

void
save_tree_in_file
(binary_tree_p tree,char *file)
{
  char tmp[100] = "";
  FILE *mfile ;
  sprintf(tmp,"%s.gv",file);	
  mfile = fopen(tmp,"w");	
  fprintf(mfile,"digraph G{\n") ;
  RecursiveTraversal(tree,mfile) ;
  fprintf(mfile,"}\n") ;
  fclose(mfile) ;
  return ;
}
