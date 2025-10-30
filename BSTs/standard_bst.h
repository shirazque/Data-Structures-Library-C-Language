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

BST* bst_init();

int bst_insert(int calories, char food[85], BOOLEAN is_veg, int origin);

FOOD* bst_remove(char key_food[85]);

int wipe_bst();

#endif