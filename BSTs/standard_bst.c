/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Implementation for standard non-balancing
    Binary Search Tree.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include "standard_bst.h"
#include "auxiliary/tree_common.h"

BST* bst_init() {
    BST *new_tree = malloc(sizeof(BST));

    if (new_tree) {
        // If tree was successfully allocated
        new_tree->root = NULL;
        new_tree->length = 0;
    }

    return new_tree;
}

TREENODE* bstnode_init(FOOD food) {
    TREENODE *new_node = malloc(sizeof(TREENODE)); // Return a pointer to a newly allocated BST

    if (new_node) {
        // If node was successfully allocated, set the members
        new_node->food = food;
        new_node->color = NON_RBT; // Since this is a non-balancing Binary Search Tree 
        new_node->height = -1;     // Since this is a non-balancing Binary Search Tree
        new_node->left = NULL;
        new_node->height = NULL;
    }

    return new_node;
}

int bst_insert(BST *nbt, int calories, const char *food, BOOLEAN is_veg, int origin) { 
    int inserted = 0;

    if (nbt) {
        // If Tree exists
        FOOD new_food = food_init(calories, food, is_veg, origin); // Initialize a Food Structure
        TREENODE *new_node = bstnode_init(new_food); // Initialize a new BST Node

        if (new_node) {
            // If BST node was successfully allocated
            if (nbt->root) {
                // If there already exists a Root in the Tree
                TREENODE **current = &(nbt->root); // Double Pointer - Stores address of Root Pointer
                int already_in_tree = 0;

                while (*current && !already_in_tree) {
                    // Traverse the BST to find the proper place of insertion
                    int compare_foods = food_compare(&new_food, &((*current)->food)); // Compares Food Type Names

                    if (compare_foods) {
                        // If the data is not yet present in the BST
                        if (compare_foods < 0) {
                            // If the new node is lexicographically smaller than the current node
                            current = &((*current)->left); // Iteratively traverse to the left subtree
                        }

                        else {
                            // If the new node is lexicographically greater than the current node 
                            current = &((*current)->right); // Iteratively traverse to the right subtree
                        }
                    }

                    else {
                        // Data is already in the BST - Stop loop
                        already_in_tree = 1;
                        free(new_node); // Free the node. 
                        food_free(&new_food);
                    }
                }

                // Insertion place found
                if (!already_in_tree) {
                    (*current) = new_node; // Node goes in place of the current address, which WAS holding a NULL memory cell.
                                        // Memory cell holds Node
                }
            }

            else {
                // Tree is empty - Newly allocated node becomes the Root
                nbt->root = new_node;
            }

            nbt->length = nbt->length + 1;
            inserted = 1;
        }
    }

    return inserted;
}

FOOD bst_remove(BST *nbt, char key_food[85]) {
    FOOD food_data_removed = { 0 }; // Newly initialized food struct. Returns as all members 0 if removal was unsuccessful

    if (nbt) {
        // If the tree exists
        if (nbt->root) {
            TREENODE **current = &(nbt->root); // Double Pointer - Stores address of Root Pointer
            int found = 0;

            while (*current && !found) {
                int compare_foods = strcmp(key_food, ((*current)->food.food)); // Compares Food Type Names

                if (compare_foods < 0) {
                    // If the new node is lexicographically smaller than the current node
                    current = &((*current)->left); // Iteratively traverse to the left subtree
                }

                else if (compare_foods > 0) {
                    // If the new node is lexicographically greater than the current node 
                    current = &((*current)->right); // Iteratively traverse to the right subtree
                }

                else {
                    // Found the Node of deletion
                    found = 1; // Set found to 1 in order to stop the loop
                    TREENODE *temp = *current;
                    food_data_removed = ((*current)->food); // Copy the contents on the newly initialized food struct above
                    
                    if (!((*current)->left) && !((*current)->right)) {
                        // Case #1: Node has no children
                        (*current) = NULL; 
                    }

                    else if ((*current)->left && !((*current)->right)) {
                        // Case #2: Node has only one left child
                        (*current) = (*current)->left; // Left child is the Replacement Node
                    }

                    else if (!(*current)->left && ((*current)->right)) {
                        // Case #3: Node has only one left child
                        (*current) = (*current)->right; // Right child is the Replacement Node
                    }

                    else {
                        // Case #4: Node has two children
                        TREENODE *replacement = find_repl_node(*current); // Retrieve Replacement Node (Smallest Node in the Right Subtree)

                        // Pointer Manipulation
                        replacement->left = (*current)->left;
                        replacement->right = (*current)->right;
                        (*current) = replacement;
                        
                    }

                    free(temp); // Free the Node we're deleting
                    nbt->length = nbt->length - 1; // Decrement Count
                }
            }            
        }
    }

    return food_data_removed;
}

/*-------------------------------------
Auxiliary Function:
    Finds the smallest Node in the Right
    Subtree as a replacement Tree Node.
    Takes care of the case for if the
    replacement Tree Node contains a
    Right Child Node
Parameters:
    1. Node being deleted
Returns:
    Replacement Node
-------------------------------------*/
TREENODE* find_repl_node(TREENODE *node) {
    TREENODE *parent = NULL;
    TREENODE *current = node->right;

    while (current->left) {
        // Find the left most node
        parent = current;
        current = current->left;
    }

    // Pointer Manipulation if Replacement Node has a right child
    if (parent) {
        // If replacement node has right child
        parent->left = current->right;        
    } else {
        // If the replacement node is directly to the right of deletion node (while loop didn't run)
        node->right = current->right;
    }

    current->right = NULL;
    
    return current;
}

int bst_length(BST *nbt) {
    int length = 0;

    if (nbt) {
        length = nbt->length;
    }

    return length;
}

int wipe_bst(BST *nbt) {
    int wiped = 0;

    if (nbt) {
        if (nbt->root) {
            wipe_bst_aux(nbt->root);
        }

        free(nbt);
        wiped = 1;
    }

    return wiped;
}

/*-------------------------------------
Auxiliary Function:
    Frees all BST nodes in Postorder
Parameters:
    1. Pointer to current Tree Node
Returns:
    1 if Wipped, 0 otherwise
-------------------------------------*/
void wipe_bst_aux(TREENODE *node) {
    if (node) {
        wipe_bst_aux(node->left);
        wipe_bst_aux(node->right);
        free(node);
    }
}