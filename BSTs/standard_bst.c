/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Implementation for standard non-balancing
    Binary Search Tree.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include <standard_bst.h>
#include <auxiliary/tree_common.h>

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

int bst_insert(BST *nbt, int calories, char food[85], BOOLEAN is_veg, int origin) { 
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

FOOD* bst_remove(BST *nbt, char key_food[85]) {
    FOOD *food_data_removed = NULL;

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
                    food_data_removed = &((*current)->food);
                    TREENODE *temp = *current;

                    // Deletion process here
                    if (((*current)->left) && ((*current)->right)) {
                        // Node of deletion has two children
                        TREENODE *replacement_node = find_repl_node(*current); // Find replacement node
                        
                        // Update Pointers
                        replacement_node->left = (*current)->left;
                        replacement_node->right = (*current)->right;

                        // Set Replacement Node
                        (*current) = replacement_node;
                    }

                    else {
                        if ((*current)->left) {
                            // Node of deletion has one left child
                            (*current) = (*current)->left; // Set Replacement Node
                        }

                        else if ((*current)->right) {
                            // Node of deletion has one right child
                            (*current) = (*current)->right; // Set Replacement Node
                        }

                        else {
                            // Node of deletion has no children
                            (*current) = NULL;
                        }
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

    // If the Replacement Node has a Right Child
    if (current->right) {
        parent->left = current->right;
    }

    else {
        node->right = current->right;
    }

    return current;
}