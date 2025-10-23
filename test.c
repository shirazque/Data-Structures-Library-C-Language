#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header

#include <stack_queue/array_stack.h> // Include Stack Header
#include <stack_queue/array_circular_deque.h> // Include Deque Header
#include <stack_queue/linked_list_priority_queue.h> // Include Priority Queue Header
#include <linked_lists/singly_linked_list.h> // Include Singly Linked List Header
#include <binary_search_trees/binary_search_tree.h> // Include Binary Search Tree Header
#include <binary_search_trees/adelson_velsky_landis_tree.h> // Include AVL Tree Header

#define MAX_LENGTH 10 // Define a Max length for Array-based Structures

// Dataset for Stacks and Queues
int elements[MAX_LENGTH] = {50, 25, 75, 15, 35, 60, 90, 10, 30, 40}; 

// Dataset for Linked Lists and BSTs
int user_ids[MAX_LENGTH] = {1001, 1005, 1002, 1010, 1008, 1015, 1020, 1003, 1007, 1012}; // For Linked Lists and BSTs 
char *usernames[MAX_LENGTH] = {
    "charlie_a",      // 1001
    "courtney_b",     // 1005  
    "alex_c",         // 1002
    "ashley_z",       // 1010
    "david_m",        // 1008
    "daniella_k",     // 1015
    "bryan_t",        // 1020
    "britney_g",      // 1003
    "ethan_r",        // 1007
    "emily_g"         // 1012
};


void test_array_stack() {
    printf("--------------------- Testing for Array-based Stack ---------------------");

    STACK *new_stack = stack_init(MAX_LENGTH); // Initialize pointer to new Stack
    
    for (int i = 0; i < MAX_LENGTH; i++) {
        // Push elements into Stack
        int pushed = stack_push(new_stack, elements[i]);
        
        if (pushed) {
            printf("Pushed: %d", elements[i]);
            printf("");
        }
    }

    // Peek top
    printf("Peeked: %d", stack_peek(new_stack));
    printf("");

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Pop elements from Stack
        printf("Popped: %d", stack_pop(new_stack).value);
        printf("");
    }

    // Destroy the Stack
    stack_wipe(new_stack);
}

void test_array_deque() {
    printf("--------------------- Testing for Array-based Deque ---------------------");

    DEQUE *new_deque = deque_init(MAX_LENGTH);  // Initialize pointer to new Deque

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Insert elements into Deque
        int inserted = deque_insert_rear(new_deque, elements[i]);

        if (inserted) {
            printf("Inserted in Rear: %d", elements[i]);
            printf("");
        }
    }

    // Peek front
    printf("Peeked at front: %d", deque_peek_front(new_deque));
    printf("");

    // Peek rear
    printf("Peeked at rear: %d", deque_peek_rear(new_deque));
    printf("");

    for (int i = 0; i < MAX_LENGTH/2; i++) {
        // Removed at front from Deque
        printf("Removed at front: %d", deque_remove_front(new_deque).value);
        printf("");
    }

    for (int i = 0; i < MAX_LENGTH/2; i++) {
        // Removed at rear from Deque
        printf("Removed at rear: %d", deque_remove_rear(new_deque).value);
        printf("");
    }

    // Destroy the Deque
    deque_wipe(new_deque);
}

void test_linked_list_priority_queue() {
    printf("--------------------- Testing for Linked List-based Priority Queue ---------------------");

    PRIORITYQUEUE *new_pq = pq_init(MAX_LENGTH);  // Initialize pointer to new PQ    

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Insert elements into Queue
        int inserted = pq_enqueue(new_pq, elements[i]);

        if (inserted) {
            printf("Enqueued: %d", elements[i]);
            printf("");
        }
    }   

    // Peek front
    printf("Peeked at front: %d", pq_peek(new_pq));
    printf("");

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Dequeue elements from Priority Queue
        printf("Dequeued: %d", pq_dequeue(new_pq).value);
        printf("");
    }

    // Destroy the Queue
    pq_wipe(new_pq);

}

void test_singly_linked_list() {
    printf("--------------------- Testing for Linked List ---------------------");

    LINKEDLIST *new_list = list_init(); // Initialize pointer to new List

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Add into the list
        if (i < 3) {
            // Prepend if "i" is 0, 1, 2
            int prepended = list_prepend(new_list, user_ids[i], usernames[i]);

            if (prepended) {
                printf("Prepended user: %d, %s", user_ids[i], usernames[i]);
                printf("");
            }
        }

        else if (i >= 3 && i < 7) {  
            // Insert at index "i" if "i" is 3, 4, 5, 6
            int inserted = list_insert(new_list, i, user_ids[i], usernames[i]);

            if (inserted) {
                printf("Inserted user into index %d: %d, %s", i, user_ids[i], usernames[i]);
                printf("");
            }        
        }

        else {
            // Append if "i" is 7, 8, 9
            int appended = list_append(new_list, user_ids[i], usernames[i]);

            if (appended) {
                printf("Appended user: %d, %s", user_ids[i], usernames[i]);
                printf("");
            }        
        }
    }

    // Reversing the list
    list_reverse(new_list);
    printf("List has now been reversed");
    printf("");

    // Iterate through the List
    list_iterate(new_list);

    // Removing by key
    LLUSER removed;

    removed = list_remove_by_key(new_list, user_ids[0]);
    printf("Removed user: %d, %s", removed.id, removed.name);
    printf("");

    removed = list_remove_by_key(new_list, user_ids[9]);
    printf("Removed user: %d, %s", removed.id, removed.name);
    printf("");

    removed = list_remove_by_key(new_list, user_ids[5]);
    printf("Removed user: %d, %s", removed.id, removed.name);
    printf("");

    // Destroy the List
    list_wipe(new_list);
}

void test_bst() {
    printf("--------------------- Testing for Standard Binary Search Tree ---------------------");

    BST *new_bst = bst_init(); // Initialize pointer to new BST
    BSTUSER users_preorder[MAX_LENGTH] = {};
    BSTUSER users_inorder[MAX_LENGTH] = {};
    BSTUSER users_postorder[MAX_LENGTH] = {};


    for (int i = 0; i < MAX_LENGTH; i++) {
        // Inserting contents into BST
        int inserted = bst_insert(new_bst, usernames[i], user_ids[i]);
    
        if (inserted) {
            printf("Inserted user: %d, %s", user_ids[i], usernames[i]); 
            printf("");
        }
    }

    // BSTs stored in preorder, inorder, and postorder into Arrays
    bst_preorder(new_bst, users_preorder);
    bst_inorder(new_bst, users_inorder);
    bst_postorder(new_bst, users_postorder);

    // BST contents in Preorder
    printf("Preorder Traversal:");
    printf("");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("User: %d, %s", users_preorder[i].id, users_preorder[i].name);
    }

    printf("");

    // BST contents Inorder
    printf("Inorder Traversal:");
    printf("");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("User: %d, %s", users_inorder[i].id, users_inorder[i].name);
    }

    printf("");

    // BST contents Postorder
    printf("Postorder Traversal:");
    printf("");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("User: %d, %s", users_postorder[i].id, users_postorder[i].name);
    }

    printf("");

    printf("Finding User with ID %d using Breadth First Search", user_ids[5]);
    BSTUSER retrieved_using_bfs = bst_bfs(new_bst, user_ids[5]);
    printf("Username of user with ID %d, %s", retrieved_using_bfs.id, retrieved_using_bfs.name);
    printf("");

    printf("Finding User with ID %d using Depth First Search", user_ids[5]);
    BSTUSER retrieved_using_dfs = bst_dfs(new_bst, user_ids[5]);
    printf("Username of user with ID %d, %s", retrieved_using_dfs.id, retrieved_using_dfs.name);  
    printf("");

    // Destroy BST
    bst_wipe(new_bst);
}

void test_avl() {
    printf("--------------------- Testing for AVL Tree ---------------------");

    AVLTREE *new_avl = avl_init();

    for (int i = 0; i < MAX_LENGTH; i++) {
        // Inserting contents into BST
        int inserted = avl_insert(new_avl, usernames[i], user_ids[i]);
    
        if (inserted) {
            printf("Inserted user: %d, %s", user_ids[i], usernames[i]); 
            printf("");
        }
    }

    avl_wipe(new_avl);

}