/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Header for Tree Node and its Data, and all
    traversals for all Binary Search Trees
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#ifndef TREE_COMMON_H
#define TREE_COMMON_H

typedef enum {True = 1, False = 0} BOOLEAN; // Enumerator defining True/False Boolean
typedef enum {RED, BLACK, NON_RBT} RBT_NODE_TYPE; // Enumerator defining Red-Black Tree Node Type Options

                        /*    ----------    Food Structure    ----------    */
extern char ORIGINS[19][12];

/*-------------------------------------
Structure: Food
Members:
    1. Food Name (85 characters as that
       is the longest food name)
    2. Origin of the Food
    3. Boolean indicating if the food is vegetarian
    4. Calories of the Food 
-------------------------------------*/
typedef struct food {
    char food[85];
    char origin[19];
    BOOLEAN is_veg;
    int calories;
} FOOD;

/*-------------------------------------
Function:
    Returns a Structure of Food
Parameters:
    1. Food Name (85 characters as that
       is the longest food name)
    2. Origin of the Food
    3. Boolean indicating if the food is vegetarian
    4. Calories of the Food 
Returns:
    New Food Structure
-------------------------------------*/
FOOD food_init(int calories, char food[85], BOOLEAN is_veg, int origin);

/*-------------------------------------
Function:
    Compares two Food objects by the name
    of the Dish.
Parameters:
    1. Pointer of first food structure
    being compared
    2. Pointer of second food structure
    being compared
Returns:
    a. 1 if "me" is lexicographically greater
    b. 0 if "me" is lexicographically equal
    c. -1 if "me" is lexicographically smaller
    -------------------------------------*/
int food_compare(FOOD *me, FOOD *other);

/*-------------------------------------
Function:
    Traverses and prints the contents of
    an Array with Pointers to FOOD from
    the BST
Parameters:
    1. Pointer to array of FOOD structures
    2. Maximum size of Array
    from a BST
Returns:
    N/A
-------------------------------------*/
void food_array_iter(FOOD *array_foods_bst, int max_length);

                /*    ----------    Tree Node & BST Traversal Functions    ----------    */

/*-------------------------------------
Structure: Tree Node for BSTs
Members:
    1. Pointer to the left Tree Node
    2. Pointer to the right Tree Node
    3. Food Structure
    4. Color of the Node (only applies
       if the Tree is an RBT)
    5. Height of the Node (only applies
       if the Tree is an AVL or RBT)
-------------------------------------*/
typedef struct treenode {
    struct treenode *left;
    struct treenode *right;
    RBT_NODE_TYPE color;                      // Only if the Tree is an RBT 
    int height;                               // Only if the Tree is an RBT or an AVL Tree
    FOOD food;
} TREENODE;

/*-------------------------------------
Function:
    Adds the contents of the Tree to the
    array in Preorder
Parameters:
    1. The root of the BST
    2. Array of FOOD structs from the Tree
Returns:
    N/A
-------------------------------------*/
void preorder_traversal(TREENODE *root, FOOD *array_preorder);

/*-------------------------------------
Function:
    Adds the contents of the Tree to the
    array Inorder
Parameters:
    1. The root of the BST
    2. Array of FOOD structs from the Tree
Returns:
    N/A
-------------------------------------*/
void inorder_traversal(TREENODE *root, FOOD *array_inorder);

/*-------------------------------------
Function:
    Adds the contents of the Tree to the
    array in Postorder
Parameters:
    1. The root of the BST
    2. Array of FOOD structs from the Tree
Returns:
    N/A
-------------------------------------*/
void postorder_traversal(TREENODE *root, FOOD *array_postorder);

/*-------------------------------------
Function:
    Adds the contents of the Tree to the
    array level by level
Parameters:
    1. The root of the BST
    2. Array of FOOD structs from the Tree
Returns:
    N/A
-------------------------------------*/
void bf_traversal(TREENODE *root, FOOD *array_breadth_first);

/*-------------------------------------
Function:
    Adds the contents of the Tree to the
    array depth-first (Deep followed by
    wide)
Parameters:
    1. The root of the BST
    2. Array of FOOD structs from the Tree
    3. Maximum length of the Stack
Returns:
    N/A
-------------------------------------*/
void df_traversal(TREENODE *root, FOOD *array_depth_first, int max_length);

#endif