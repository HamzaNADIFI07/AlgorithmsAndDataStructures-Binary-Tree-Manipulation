# -*- coding: utf-8 -*-

"""
Note: Author
      [Dpt Informatique - FST - Univ. Lille](http://portail.fil.univ-lille1.fr)
      2016, march
"""

def is_empty (tree):
    """
    Predicates that tests whether `tree` is an empty tree.

    Args:
      tree (dict): The tree to be tested

    Returns:
      bool: True if `tree` is empty, False otherwise
    """
    return tree is None
    
def empty_tree ():
    """
    Returns:
      dict: an empty Tree
    """
    return None

def create (value, left, right):
    """
    Args:
      value (any): The label of the node
      left (dict): The left subtree
      right (dict): The right subtree

    Returns: 
      dict: a tree, whose root has `value` as a label and whose left and right subtrees are `left` and `right`, respectively
    """
    return { "value" : value, "left" : left, "right" : right }

def change_left (tree, new):
    """
    Args:
      tree (dict): The tree for which the subtree son will be changed
      new (dict): The new left subtree

    Warning: Pre-condition
             `tree` cannot be empty
    """
    assert(tree is not None)
    tree["left"] = new

def change_right (tree, new):
    """
    Args:
      tree (dict): The tree for which the right subtree will be changed
      new (dict): The new right subtree

    Warning: Pre-condition
             `tree` cannot be empty
    """
    assert(tree is not None)
    tree["right"] = new

def get_root_value (tree):
    """
    Args:
      tree (dict): A tree 

    Returns:
      dict: The value of the root

    Warning: Pre-condition
             `tree` cannot be empty
    """
    assert(tree is not None)
    return tree["value"]

def get_left_son (tree):
    """
    Args:
      tree (dict): A tree 

    Returns:
      dict: The left subtree of the root

    Warning: Pre-condition
             `tree` cannot be empty
    """
    assert(tree is not None)
    return tree["left"]

def get_right_son (tree):
    """
    Args:
      tree (dict): A tree 

    Returns:
      dict: The right subtree of the root

    Warning: Pre-condition
             `tree` cannot be empty
    """
    assert(tree is not None)
    return tree["right"]

def is_a_leaf (tree):
    """
    Args:
      tree (dict): A tree 

    Returns:
      bool: True if and only if `tree` is a leaf
    """
    return is_empty(get_right_son(tree)) and is_empty(get_left_son(tree))

      

    
    
