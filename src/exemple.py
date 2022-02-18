# -*- coding: utf-8 -*-

"""

Note: Author
      [Dpt Informatique - FST - Univ. Lille](http://portail.fil.univ-lille1.fr)
      2016, march

"""

from tree import *
import displayer

if __name__ == "__main__":
  tree = create(1,create(2,empty_tree(),empty_tree()),create(3,empty_tree(),empty_tree()))
  displayer.tree2file(tree,"exemple.gv")

# comandline:
# python3 exemple.py && dot -Tpdf -o exemple.pdf exemple.gv
    
