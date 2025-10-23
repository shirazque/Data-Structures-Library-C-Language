
#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <stack_queue/array_stack.h> // Include Stack Header
#include <stack_queue/array_circular_deque.h> // Include Deque Header
#include <stack_queue/linked_list_priority_queue.h> // Include Priority Queue Header
#define MAX_LENGTH 10 // Define a Max length for Array-based Structures

// Dataset for Stacks and Queues
int elements[MAX_LENGTH] = {50, 25, 75, 15, 35, 60, 90, 10, 30, 40}; 

// Dataset for Linked Lists and BSTs
int user_ids[MAX_LENGTH] = {1001, 1005, 1002, 1010, 1008, 1015, 1020, 1003, 1007, 1012}; // For Linked Lists and BSTs 
char *usernames[MAX_LENGTH] = {
    "charlie_a",      // 1001
    "courtney_b",    // 1005  
    "alex_c",    // 1002
    "ashley_z",        // 1010
    "david_m",      // 1008
    "daniella_k",      // 1015
    "bryan_t",       // 1020
    "britney_g",    // 1003
    "ethan_r",      // 1007
    "emily_g"     // 1012
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

    PRIORITYQUEUE *new_pq = pq_init(MAX_LENGTH);  // Initialize pointer to new Deque    

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

}

// W.I.P
void test_singly_linked_list();

// W.I.P
void test_bst();

// W.I.P
void test_avl();