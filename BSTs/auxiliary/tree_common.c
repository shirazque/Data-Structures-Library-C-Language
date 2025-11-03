/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Implementation for Tree Node and its Data.
    Includes Traversal functions for all types
    of BSTs and utility functions for FOOD
    structs.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include "tree_common.h"
#include "aux_stack_queue.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        Constants
--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

char ORIGINS[19][12] = {"Canadian", "Chinese", "Indian", "Ethiopian", 
    "Mexican", "Greek", "Japanese", "Italian", "American", "Scottish", "New Zealand", "English"};

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            Functions Operating on FOOD Structures 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

FOOD food_init(int calories, const char *food[85], BOOLEAN is_veg, int origin) {
    FOOD new_food = { 0 }; // Create a new FOOD Structure
    
    // Set the members of the newly initialized Food
    new_food.calories = calories; 
    strcpy(new_food.food, food); // Copies data. strcpy(destination, source)
    new_food.is_veg = is_veg; // Copies the boolean value
    strcpy(new_food.origin, ORIGINS[origin]); // Copies the contents of the food origin
    
    return new_food;
}

int food_compare(FOOD *me, FOOD *other) {
    return strcmp(me->food, other->food);
}

void food_array_iter(FOOD *array_foods_bst, int max_length) {
    if (array_foods_bst) {
        // If the array exists
        for (int i = 0; i < max_length; i++) {
            // Iterates through the contents of the Foods Array
            printf("-----------------------------------------------------");
            printf("Food: %s\n", array_foods_bst[i].food);
            printf("Calories: %d\n", array_foods_bst[i].calories);
            printf("Is Vegetarian: %s\n", array_foods_bst[i].is_veg ? "Yes" : "No");
            printf("Food Origin: %s\n", array_foods_bst[i].origin);
            printf("-----------------------------------------------------");
        }
    }
}

void food_free(FOOD *me) {
    free(me);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                BST Traversal Functions
--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------
Auxiliary Function:
    Adds the contents of the Tree to the
    Array in Preorder
Parameters:
    1. Current Tree Node of the BST
    2. Array of Pointers to FOOD structs
    from the Tree
    3. current index of the Array
Returns:
    N/A
-------------------------------------*/
void preorder_aux(TREENODE *node, FOOD *array_preorder, int *i) {
    if (node) {
        // Add the pointer of the food object from the current Tree Node to the Array
        array_preorder[*i] = node->food;
        (*i)++;
        preorder_aux(node->left, array_preorder, i); // Recursively traverse to the left Subtree
        preorder_aux(node->right, array_preorder, i); // Recursively traverse to the right Subtree
    }
}

/*-------------------------------------
Auxiliary Function:
    Adds the contents of the Tree to the
    Array Inorder
Parameters:
    1. Current Tree Node of the BST
    2. Array of Pointers to FOOD structs
    from the Tree
    3. current index of the Array
Returns:
    N/A
-------------------------------------*/
void inorder_aux(TREENODE *node, FOOD *array_inorder, int *i) {
    if (node) {
        inorder_aux(node->left, array_inorder, i); // Recursively traverse to the left Subtree

        // Add the pointer of the food object from the current Tree Node to the Array
        array_inorder[*i] = node->food;
        (*i)++;

        inorder_aux(node->right, array_inorder, i); // Recursively traverse to the right Subtree
    }
}

/*-------------------------------------
Auxiliary Function:
    Adds the contents of the Tree to the
    Array in Postorder
Parameters:
    1. Current Tree Node of the BST
    2. Array of Pointers to FOOD structs
    from the Tree
    3. current index of the Array
Returns:
    N/A
-------------------------------------*/
void postorder_aux(TREENODE *node, FOOD *array_postorder, int *i) {
    if (node) {
        postorder_aux(node->left, array_postorder, i); // Recursively traverse to the left Subtree
        postorder_aux(node->right, array_postorder, i); // Recursively traverse to the right Subtree
        
        // Add the pointer of the food object from the current Tree Node to the Array
        array_postorder[*i] = node->food;
        (*i) = (*i) + 1;
    }
}

void preorder_traversal(TREENODE *root, FOOD *array_preorder) {
    int i = 0;
    preorder_aux(root, array_preorder, &i);
}

void inorder_traversal(TREENODE *root, FOOD *array_inorder) {
    int i = 0;
    inorder_aux(root, array_inorder, &i);
}

void postorder_traversal(TREENODE *root, FOOD *array_postorder) {
    int i = 0;
    postorder_aux(root, array_postorder, &i);
}

void bf_traversal(TREENODE *root, FOOD *array_breadth_first) {
    if (root) {
        // If there exists a Root Node
        int i = 0;
        QUEUE *new_queue = init(); // Initialize a Queue
        queue_enqueue(new_queue, root); // Enqueue the root

        while (queue_length(new_queue) > 0) {
            // While the Queue is not empty
            TREENODE *current = queue_dequeue(new_queue); // Dequeue the Tree Node

            // Add the FOOD data into the Array
            array_breadth_first[i] = current->food;
            i = i + 1;

            if (current->left) {
                // If there is a left child of the Dequeued Tree Node above, enqueue it
                queue_enqueue(new_queue, current->left);
            }

            if (current->right) {
                // If there is a right child of the Dequeued Tree Node above, enqueue it
                queue_enqueue(new_queue, current->right);
            }
        }
    }
}

void df_traversal(TREENODE *root, FOOD *array_depth_first, int max_length) {
    if (root) {
        // If there exists a Root Node
        int i = 0;
        STACK *new_stack = stack_init(max_length); // Initialize a Stack
        stack_push(new_stack, root); // Push the root

        while (stack_length(new_stack) > 0) {
            // While the Stack is not empty
            TREENODE *current = stack_pop(new_stack); // Pop the Tree Node

            // Add the FOOD data into the Array
            array_depth_first[i] = current->food;
            i = i + 1;

            if (current->right) {
                // If there is a right child of the Popped Tree Node above, push it
                stack_push(new_stack, current->right);
            }

            if (current->left) {
                // If there is a left child of the Popped Tree Node above, push it
                stack_push(new_stack, current->left);
            }
        }
    }
}