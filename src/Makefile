CC=gcc
OPT=-Wall -ansi -pedantic -g

all:Test_tree

%_tree: %_tree.c Display.o BinaryTree.o
	$(CC) $(OPT) -o $@  $^

%.pdf: %.gv
	dot -Tpdf -o $@ $^

Display.o : Display.c
	$(CC) $(OPT) -c $<

BinaryTree.o: BinaryTree.c BinaryTree.h
	$(CC) $(OPT) -c $<

clean:
	rm -f *.gv *.pdf *.o *_arbre
