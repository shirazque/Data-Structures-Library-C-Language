/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for Binary Search Tree
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

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
Structure: Binary Search Tree Node
Members:
    1. USER user: Holds the data of a user
    2. TREENODE *left: Pointer to left child node
    3. TREENODE *right: Pointer to right child node
-------------------------------------------------*/
typedef struct tree_node {
    USER user;
    TREENODE *left;
    TREENODE *right;
} TREENODE;

/*------------------------------------------------
Structure: Binary Search Tree
Members:
    1. TREENODE *root: Pointer to root node
    2. int length: The number of nodes in the BST
-------------------------------------------------*/
typedef struct bst {
    TREENODE *root;
    int length;
} BST;

/*------------------------------------------------
Function: Initializes a new BST
Parameters:
    N/A
Time and Space Complexity: O(1), O(1)
-------------------------------------------------
Returns:
    Pointer to an allocated BST
------------------------------------------------*/
BST* bst_init();

/*------------------------------------------------
Function: Inserts new User struct into a BST.
Compare type: user ID
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. char *username: Pointer to Sharacter String
    username
    3. int user_id: The ID of the user
Time and Space Complexity: O(h), O(1)
Traversal type: Iterative
-------------------------------------------------
Returns:
    1 if inserted, 0 otherwise
------------------------------------------------*/
int bst_insert(BST *bt, char *username, int user_id);

/*------------------------------------------------
Function: Removes a User from a BST.
Compare type: user ID
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    3. int user_id: The ID of the user (key)
Time and Space Complexity: O(h), O(1)
Traversal type: Iterative
-------------------------------------------------
Returns:
    New user struct with either:
        a. Members being assigned as the contents
        of the removed node. Indicates successful
        removal.
        
        b. Members being assigned 0. Indicates
        unsuccessful removal. 
------------------------------------------------*/
USER bst_remove(BST *bt, int user_id); 

/*------------------------------------------------
Function: Returns an array of all usernames in preorder
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. USER user_list: Array where all usernames will
    be stored in preorder
Time and Space Complexity: O(n), O(n)
Traversal type: Recursive
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void bst_preorder(BST *bt, USER user_list[]);

/*------------------------------------------------
Function: Returns an array of all usernames inorder
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. USER user_list: Array where all usernames will
    be stored inorder
Time and Space Complexity: O(n), O(n)
Traversal type: Recursive
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void bst_inorder(BST *bt, USER user_list[]);

/*------------------------------------------------
Function: Returns an array of all usernames in postorder
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. USER user_list: Array where all usernames will
    be stored in postorder
Time and Space Complexity: O(n), O(n)
Traversal type: Recursive
-------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void bst_postorder(BST *bt, USER user_list[]);

/*------------------------------------------------
Function: Performs a level by level traversal to
search for a node containing parameter key.
Auxiliary Data Structure: Queue
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. int user_id: Key for search
Time and Space Complexity: O(n), O(n)
Traversal type: Iterative
-------------------------------------------------
Returns:
    New user struct with either:
        a. Members being assigned as the contents
        of the node with matching id. Indicates
        successful search.
        b. Members being assigned 0. Indicates
        unsuccessful search. 
------------------------------------------------*/
USER bst_bfs(BST *bt, int user_id);

/*------------------------------------------------
Function: Performs a deep-subsequently-wide traversal 
to search for a node containing parameter key.
Auxiliary Data Structure: Stack
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. int user_id: Key for search
Time and Space Complexity: O(n), O(n)
Traversal type: Iterative. 
                Simulated Recursive Traversal.
-------------------------------------------------
Returns:
    New user struct with either:
        a. Members being assigned as the contents
        of the node with matching id. Indicates
        successful search.
        b. Members being assigned 0. Indicates
        unsuccessful search. 
------------------------------------------------*/
USER bst_dfs(BST *bt, int user_id);

/*------------------------------------------------
Function: Frees the Binary Search Tree and all its
contents from memory.
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
Time and Space Complexity: O(n), O(1)
Traversal type: Recursive
-------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void bst_wipe(BST *bt);

#endif