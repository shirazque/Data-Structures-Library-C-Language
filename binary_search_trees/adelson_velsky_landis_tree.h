/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for
Adelson-Velsky-Landis (AVL) Tree
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#ifndef ADELSON_VELSKY_LANDIS_TREE
#define ADELSON_VELSKY_LANDIS_TREE

/*------------------------------------------------
Structure: Tester/User of a prototype AI app
Members:
    1. int id: Holds the user id
    2. char name[25]: Holds the username of the user
-------------------------------------------------*/
typedef struct user {
    int id;
    char name[25];
} USER;

/*------------------------------------------------
Structure: AVL Tree Node
Members:
    1. USER user: data of a user
    2. int height: height of the AVL node
    3. int balance_factor: balance factor of the node
        * balance_factor = avl_node->left.height - avl_node->right.height
    4. AVLNODE *left: Pointer to left child node
    5. AVLNODE *right: Pointer to right child node
-------------------------------------------------*/
typedef struct avl_node {
    USER user;
    int height;
    int balance_factor;
    struct avl_node *left;
    struct avl_node *right;
} AVLNODE;

/*------------------------------------------------
Structure: Adelson-Velsky-Landis Tree
Members:
    1. AVLNODE *root: Pointer to root node
    2. int length: The number of nodes in the AVL
-------------------------------------------------*/
typedef struct avl_tree {
    AVLNODE *root;
    int length;
} AVLTREE;

/*------------------------------------------------
Function: Initializes a new AVL
Parameters:
    N/A
Time and Space Complexity: O(1), O(1)
-------------------------------------------------
Returns:
    Pointer to an allocated AVL Tree
------------------------------------------------*/
AVLTREE* init();

/*------------------------------------------------
Function: Inserts new User struct into an AVL.
Compare type: user ID
Parameters:
    1. AVLTREE *avl: Pointer to an AVL Tree
    2. char *username: Pointer to Character String
    username
    3. int user_id: The ID of the user
Time and Space Complexity: O(log(n)), O(1)
Traversal type: Recursive
-------------------------------------------------
Returns:
    1 if inserted, 0 otherwise
------------------------------------------------*/
int insert(AVLTREE *avl, char *username, int user_id);

/*------------------------------------------------
Function: Removes a User from an AVL.
Compare type: user ID
Parameters:
    1. AVLTREE *avl: Pointer to an AVL Tree
    2. int user_id: The ID of the user (key)
Time and Space Complexity: O(log(n)), O(log(n))
Traversal type: Recursive
-------------------------------------------------
Returns:
    New user struct with either return:
        a. Members being assigned as the contents
        of the removed node. Indicates successful
        removal.
        b. Members being assigned 0. Indicates
        unsuccessful removal. 
------------------------------------------------*/
USER remove(AVLTREE *avl, int user_id); 

/*------------------------------------------------
Function: Frees the AVL Tree and all its
contents from memory.
Parameters:
    1. AVLTREE *avl: Pointer to an AVL Tree
Time and Space Complexity: O(n), O(1)
-------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void wipe_avl(AVLTREE *avl);

#endif