/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Header for standard non-balancing Binary
    Search Tree.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include <auxiliary/tree_common.h>
#ifndef STANDARD_BST_H
#define STANDARD_BST_H

/*-------------------------------------
Structure: BST
Members:
    1. Pointer to the root Tree Node
    2. Length of the BST
-------------------------------------*/
typedef struct bst {
    TREENODE *root;
    int length;
} BST;

/*-------------------------------------
Function:
    Initializes a new BST and returns
    a pointer to it
Parameters:
    N/A
Returns:
    Pointer to BST
-------------------------------------*/
BST* bst_init();

/*-------------------------------------
Function:
    Inserts a new Food Instance into a
    BST
Parameters:
    1. Node being deleted
Returns:
    Replacement Node
-------------------------------------*/
int bst_insert(BST *nbt, int calories, char food[85], BOOLEAN is_veg, int origin);

/*-------------------------------------
Function:
    Removes a Node containing Food
    Instance with name matching Key
    from a BST
Parameters:
    1. Pointer to BST
    2. Key (Food Name)
Returns:
    Pointer to Food Instance with
    food name matching key, NULL
    otherwise
-------------------------------------*/
FOOD* bst_remove(BST *nbt, char key_food[85]);

/*-------------------------------------
Function:
    Frees and Destroys a BST
Parameters:
    1. Pointer to BST
Returns:
    1 if Wipped, 0 otherwise
-------------------------------------*/
int wipe_bst();

#endif