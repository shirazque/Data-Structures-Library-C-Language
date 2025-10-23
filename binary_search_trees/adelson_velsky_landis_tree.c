/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for
Adelson-Velsky-Landis (AVL) Tree
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <adelson_velsky_landis_tree.h>

AVLTREE* avl_init(){
    AVLTREE *avl = malloc(sizeof(AVLTREE)); // Allocate space for new tree and return it as a pointer to that space

    if (avl) {
        // If allocation was successful, set the members of the tree structure
        avl->length = 0;
        avl->root = NULL;
    }

    return avl;
}

AVLTREE* new_node(AVLTREE *avl, char *username, int user_id) {
    AVLNODE *node = malloc(sizeof(AVLNODE)); // Allocate space for new node and return it as a pointer to that space

    if (avl){
        if (node) {
            // If the node was successfully allocated
            strcpy(node->user.name, username); // Copy the contents of the string into the node name
            node->user.id = user_id; // Copy the user id
            node->balance_factor = 0;
            node->height = 0;
            node->left = NULL;
            node->right = NULL;
        }
    }
    
    return node;
}

int avl_insert(AVLTREE *avl, char *username, int user_id) {
    int inserted = 1;
    int already_inserted = 0;

    if (avl) {
        // Passes address of the root pointer (double pointer)
        already_inserted = insert_aux(avl, &(avl->root), username, user_id, &already_inserted);
    }

    if (already_inserted) {
        // If the node was already in the tree, flag inserted as unsuccessful
        inserted = 0;
    } 

    return inserted;
}

/*------------------------------------------------
Auxiliary function: Inserts a new node into AVL
Parameters:
    1. AVLNODE *node: Pointer to an AVL Node
    2. AVLNODE **curr_pointer: Double POinter
    (variable that holds the address of the current
    node pointer)
    2. char *username: Pointer to Character String
    username
    3. int user_id: The ID of the user
    4. int *already_inserted: Checks if BST user 
    ID was already inserted in a node. 
-------------------------------------------------
Returns:
    int check: 1 if already inserted, 0 otherwise.
------------------------------------------------*/
int insert_aux(AVLTREE *avl, AVLNODE **curr_pointer, char *username, int user_id, int *already_inserted) {
    if (!(*already_inserted)) {
        if ((*curr_pointer) == NULL){
            // Special Case: Spot to insert found
            *(curr_pointer) = new_node(avl, username, user_id); // Create new node
            avl->length = avl->length + 1; // Increment the length
        }

        else if (((*curr_pointer)->user).id > user_id) {
            // General Case: Recursively traverse to the left subtree
            insert_aux(avl, &((*curr_pointer)->left), username, user_id, already_inserted);
        }

        else if (((*curr_pointer)->user).id < user_id) {
            // General Case: Recursively traverse to the right subtree
            insert_aux(avl, &((*curr_pointer)->right), username, user_id, already_inserted);
        }

        else {
            // Special Case: Node already inserted
            *already_inserted = 1;
        }

        if (!(*already_inserted)){
            // Update the ancestor heights and tree structure via rotations from leaf to root
            int balance_factor = get_bf_aux(*curr_pointer); // Get the balance factor from newly inserted node to root

            if (balance_factor < -1) {
                // Left Rotation
                int balance_factor_right = get_bf_aux((*curr_pointer)->right); // Gets balance factor of left of curr
                
                if (balance_factor_right == 1) {
                    // Right-Left Case: Perform a right rotation on left child of curr
                    (*curr_pointer)->right = rotate_right_aux((*curr_pointer)->right);
                }

                // Perform a left rotation on curr
                *(curr_pointer) = rotate_left_aux(*curr_pointer);            
            }

            else if (balance_factor > 1) {
                int balance_factor_left = get_bf_aux((*curr_pointer)->left); // Gets balance factor of left of curr
                
                if (balance_factor_left == -1) {
                    // Left-Right Case: Perform a left rotation on left child of curr
                    (*curr_pointer)->left = rotate_left_aux((*curr_pointer)->left);
                }

                // Perform a right rotation on curr
                *(curr_pointer) = rotate_right_aux(*curr_pointer);            
            }
        }
    }

    return *already_inserted;
}

AVLUSER avl_remove(AVLTREE *avl, int user_id); // W.I.P

/*------------------------------------------------
Auxiliary function: Returns the Balance factor of
the node
Parameters:
    1. AVLNODE *node: Pointer to an AVL Node
-------------------------------------------------
Returns:
    Balance factor of the node
------------------------------------------------*/
int get_bf_aux(AVLNODE *node) {
    int left_child_height = 0;
    int right_child_height = 0;

    if (node->left) {
        // If the node has a left child, grab its height
        left_child_height = node_height_aux(node->left);
    }

    if (node->right) {
        // If the node has a right child, grab its height
        right_child_height = node_height_aux(node->right);
    }

    return left_child_height - right_child_height;
}

/*------------------------------------------------
Auxiliary function: Performs a left rotation on the
AVL node via Pointer manipulation
Parameters:
    1. AVLNODE *node: Pointer to an AVL Node
-------------------------------------------------
Returns:
    Node taking place of parameter node
------------------------------------------------*/
AVLNODE *rotate_left_aux(AVLNODE *node) {
    AVLNODE *new_parent = node->right; // Right child of node will be the new parent. The left child of the newly made parent will be 'node'
    AVLNODE  *new_parent_left = new_parent->left; // Right grandchild of the new parent

    new_parent->left = node; // Think of it like the dad becoming the son and the son becoming the dad :)
    node->right = new_parent_left; // The right child of the original node will be of its original grandchild

    // Update the heights of the nodes
    update_height_aux(node);
    update_height_aux(new_parent);

    return new_parent;
}   

/*------------------------------------------------
Auxiliary function: Performs a right rotation on
the AVL node via Pointer manipulation
Parameters:
    1. AVLNODE *node: Pointer to an AVL Node
-------------------------------------------------
Returns:
    Node taking place of parameter node
------------------------------------------------*/
AVLNODE *rotate_right_aux(AVLNODE *node) {
    AVLNODE *new_parent = node->left;
    AVLNODE *new_parent_right = new_parent->right;

    new_parent->right = node;
    node->left = new_parent_right;

    // Update the heights of the nodes
    update_height_aux(node);
    update_height_aux(new_parent);

    return new_parent;
}

void avl_wipe(AVLTREE *avl){
    int wiped = 0;

    if (avl){
        if (avl->root){
            wipe_nodes_aux(avl->root); // Clean all nodes of the Tree
            // Set members of Tree back to 0
            avl->root = NULL;
            avl->length = 0;
        }

        free(avl); // Free the Tree
        wiped = 1; // Flag as successful wipe
    }

    return wiped;
}

/*------------------------------------------------
Auxiliary function: Frees all Tree nodes and all its
contents from memory.
    1. AVLNODE *node: Pointer to an AVL Node
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void wipe_nodes_aux(AVLNODE *node) {
    if (node) {
        wipe_nodes_aux(node->left);
        wipe_nodes_aux(node->right);
        free(node);
    }
}