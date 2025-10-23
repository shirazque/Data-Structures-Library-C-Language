/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Implementation for Binary
Search Tree
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <binary_search_tree.h> // Includes Binary Search Tree Header
#include <linked_list_stack_queue.h> // Includes the Auxiliary Stack and Queue Data Structure

BST* bst_init() {
    BST *bt = malloc(sizeof(BST)); // Allocate space for new tree and return it as a pointer to that space

    if (bt) {
        // If allocation was successful, set the members of the tree structure
        bt->length = 0;
        bt->root = NULL;
    }

    return bt;
}

/*------------------------------------------------
Auxiliary Function: Creates a a new BST node.
Compare type: user ID
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. char *username: Pointer to Character String
    username
    3. int user_id: The ID of the user
Time and Space Complexity: O(h), O(1)
-------------------------------------------------
Returns:
    Pointer to node if successfully allocated,
    NULL otherwise
------------------------------------------------*/
TREENODE* new_node(BST *bt, char *username, int user_id) {
    TREENODE *node = malloc(sizeof(TREENODE)); // Allocate space for new node and return it as a pointer to that space

    if (bt){
        // If pointer to BST exists
        if (node) {
            // If the node was successfully allocated
            strcpy(node->user.name, username); // Copy the contents of the string into the node name
            node->user.id = user_id; // Copy the user id
            node->left = NULL;
            node->right = NULL;
        }
    }

    return node;
}

int bst_insert(BST *bt, char *username, int user_id) {
    int inserted = 0;

    if (bt) {
        // If pointer to BST exists
        TREENODE **curr_pointer = &(bt->root); // Pointer storing address of the pointer of root, i.e., current node we are accessing
        int already_in_tree = 0;
        
        while (*curr_pointer && !already_in_tree) {
            // Dereference pointer pointing to current node and access its content. Compare our user_id to the node user_id
            if ((*curr_pointer)->user.id > user_id) {
                // Traverse to the left
                curr_pointer = &((*curr_pointer)->left); // Pass the address of the left node to curr_pointer
            }

            else if ((*curr_pointer)->user.id < user_id) {
                // Traverse to the right
                curr_pointer = &((*curr_pointer)->right); // Pass the address of the right node to curr_pointer

            }

            else {
                // Node is already in the tree
                already_in_tree = 1;
            }
        }

        if (already_in_tree == 0) {
            // Insert node into tree
            TREENODE *node = new_node(bt, username, user_id); // Pointer to new BST node

            if (node) {
                // If above node allocation was successful
                *curr_pointer = node; // curr pointer holds the address containing NULL, as there is no node containing user ID we are inserting. 
                                    // Dereference it to contain new node in that address.
                inserted = 1; // Flag insertion as successful
                bt->length = bt->length + 1; // Increment the number of nodes
            }
        }
    }

    return inserted;
}

BSTUSER bst_remove(BST *bt, int user_id) {
    int removed = 0;
    BSTUSER removed_user = { 0 }; // New structure that holds the contents of the removed node. If node is not found, empty struct will be returned

    if (bt) {
        TREENODE **curr_pointer = &(bt->root);  // Pointer storing address of the pointer of root, i.e., current node we are accessing
        int node_found = 0; // Integer to stop the loop - to flag that node to remove has been found

        if (*curr_pointer) {
            // If root node exists
            while (*curr_pointer && !node_found) {
                if ((*curr_pointer)->user.id > user_id) {
                    // Traverse to the left
                    curr_pointer = &((*curr_pointer)->left);
                }

                else if ((*curr_pointer)->user.id < user_id) {
                    // Traverse to the right
                    curr_pointer = &((*curr_pointer)->right);
                }

                else {
                    // Node has been found - stop loop
                    node_found = 1;
                }
            }

            if (node_found) {
                // Copy contents to USER
                removed_user.id = (*curr_pointer)->user.id;
                strcpy(removed_user.name, (*curr_pointer)->user.name);
                TREENODE *replacement = NULL;

                if ((*curr_pointer)->left && (*curr_pointer)->right) {
                    // Case #1: Node of removal has two children
                    replacement = repl_and_patch(*curr_pointer);
                    replacement->left = (*curr_pointer)->left;
                    replacement->right = (*curr_pointer)->right;
                }

                else if ((*curr_pointer)->left && !((*curr_pointer)->right)) {
                    // Case #2: Node of removal has one left child
                    replacement = (*curr_pointer)->left;
                }

                else if (!((*curr_pointer)->left) && (*curr_pointer)->right) {
                    // Case #3: Node of removal has one right child
                    replacement = (*curr_pointer)->right;
                }

                // The following automatically handles for case #4 (Node of removal has no children):
                free(*curr_pointer); // Free the node and all its contents
                *curr_pointer = replacement; // Replaces node with replacement, even if replacement pointer is NULL.
                
                bt->length = bt->length - 1; // Decrement the number of nodes 
            }
        }
    }

    return removed_user;
} 

/*------------------------------------------------
Auxiliary Function: Finds a replacement node, i.e.,
the smallest node in the RIGHT subtree of the node
we are trying to remove. If the replacement node
has a right child, the right child will take the
initial position of the replacement node.
Compare type: user ID
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. char *username: Pointer to Character String
    username
    3. int user_id: The ID of the user
-------------------------------------------------
Returns:
    Pointer to node if successfully allocated, NULL
    otherwise
------------------------------------------------*/
TREENODE *repl_and_patch(TREENODE *to_remove) {
    TREENODE *parent = NULL; // Keep track of parent node
    TREENODE *replacement_node = to_remove->right; // Go to the right subtree of the node we're removing 

    while (replacement_node->left) {
        parent = replacement_node; // Update the parent node
        replacement_node = replacement_node->left; // Traverse all the way to the left until there is no longer a left child 
    }

    if (replacement_node->right) {
        // Handles for case if the replacement node has a right child
        parent->left = replacement_node->right;
    }

    replacement_node->right = NULL; // Isolate the replacement node from its current child

    return replacement_node;
}

void bst_preorder(BST *bt, BSTUSER user_list[]) {
    if (bt){
        int i = 0;
        preorder_aux(bt->root, user_list, &i);        
    }
}

/*------------------------------------------------
Auxiliary Function: Returns an array of all usernames
of each user in preorder
Parameters:
    1. TREENODE *node: Pointer to the current node
    2. USER user_list: Array where all usernames will
    be stored in preorder
    3. int *current_index: Pointer to the current
    index of array 
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void preorder_aux(TREENODE *node, BSTUSER user_list[], int *current_index){
    if (node) {
        // Store the username in an array, increment the index by 1
        user_list[*current_index] = node->user;
        (*current_index) = (*current_index) + 1;

        // Recursively traverse to the left and right subtrees
        preorder_aux(node->left, user_list, current_index);
        preorder_aux(node->right, user_list, current_index);
    }
}

void bst_inorder(BST *bt, BSTUSER user_list[]){
    if (bt){
        int i = 0;
        inorder_aux(bt->root, user_list, &i);    
    }}

/*------------------------------------------------
Auxiliary Function: Returns an array of all usernames
of each user inorder
Parameters:
    1. TREENODE *node: Pointer to the current node
    2. USER user_list: Array where all usernames will
    be stored inorder
    3. int *current_index: Pointer to the current
    index of array 
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void inorder_aux(TREENODE *node, BSTUSER user_list[], int *current_index){
    if (node) {
        // Recursively traverse to the left subtree
        inorder_aux(node->left, user_list, current_index);

        // Store the username in an array, increment the index by 1
        user_list[*current_index] = node->user;
        (*current_index) = (*current_index) + 1;

        // Recursively traverse to the right subtree
        inorder_aux(node->right, user_list, current_index);
    }
}

void bst_postorder(BST *bt, BSTUSER user_list[]){
    if (bt){
        int i = 0;
        postorder_aux(bt->root, user_list, &i);    
    }
}

/*------------------------------------------------
Auxiliary Function: Returns an array of all usernames
of each user in postorder
Parameters:
    1. TREENODE *node: Pointer to the current node
    2. USER user_list: Array where all usernames will
    be stored in postorder
    3. int *current_index: Pointer to the current
    index of array 
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void postorder_aux(TREENODE *node, BSTUSER user_list[], int *current_index){
    if (node) {
        // Recursively traverse to the left and right subtrees
        postorder_aux(node->left, user_list, current_index);
        postorder_aux(node->right, user_list, current_index);
    
        // Store the username in an array, increment the index by 1
        user_list[*current_index] = node->user;
        (*current_index) = (*current_index) + 1;

    }
}

BSTUSER bst_bfs(BST *bt, int user_id) {
    BSTUSER user = { 0 }; // Define a struct to copy user contents once found
    
    if (bt) {
        QUEUE *queue = init_queue(); // Pointer to a newly allocated Queue
        TREENODE *curr = bt->root; // Store the root 
        enqueue(queue, curr); // Enqueue the root
        int found = 0;


        while (length_queue(queue) && !found) {
            curr = dequeue(queue); // Dequeue from the queue

            if (curr->user.id == user_id) {
                // User ID's match. Copy contents and disable the loop
                user = curr->user;
                found = 1;
            }

            else {
                // Keep searching
                if (curr->left) {
                    // Enqueue the left child of curr
                    enqueue(queue, curr->left);
                }

                if (curr->right) {
                    // Enqueue the right child of curr
                    enqueue(queue, curr->right);
                }
            }
        }

        wipe_queue(queue); // Wipe the Auxiliary USER Structure
    }

    return user;
}

BSTUSER bst_dfs(BST *bt, int user_id) {
    BSTUSER user = { 0 }; // Define a struct to copy user contents once found
    
    if (bt) {
        STACK *stack = init_stack(); // Pointer to a newly allocated Stack 
        TREENODE *curr = bt->root; // Store the root 
        push(stack, curr); // Push the root
        int found = 0;
    
    
        while (length_stack(stack) && !found) {
            curr = pop(stack); // Pop from the stack
    
            if (curr->user.id == user_id) {
                // User ID's match. Copy contents and disable the loop
                user = curr->user;
                found = 1;
            }
    
            else {
                // Keep searching
                if (curr->right) {
                    // Push the right child of curr
                    push(stack, curr->right);
                }
    
                if (curr->left) {
                    // Push the left child of curr
                    push(stack, curr->left);
                }
            }
        }
        wipe_stack(stack); // Wipe the Auxiliary USER Structure    
    }

    return user;
}

int bst_wipe(BST *bt) {
    int wiped = 0;

    if (bt){
        if (bt->root){
            wipe_nodes_aux(bt->root); // Clean all nodes of the Tree
            // Set members of Tree back to 0
            bt->root = NULL;
            bt->length = 0;
        }

        free(bt); // Free the Tree
        wiped = 1; // Flag as successful wipe
    }

    return wiped;
}

/*------------------------------------------------
Auxiliary function: Frees all Tree nodes and all its
contents from memory.
    1. TREENODE *node: Pointer to the current node 
--------------------------------------------------
Returns:
    N/A
------------------------------------------------*/
void wipe_nodes_aux(TREENODE *node) {
    if (node) {
        wipe_nodes_aux(node->left);
        wipe_nodes_aux(node->right);
        free(node);
    }
}