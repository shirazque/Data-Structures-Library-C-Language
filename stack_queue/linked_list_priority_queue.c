/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Implementation for Linked 
List-based Priority Queue
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header 
#include <linked_list_priority_queue.h> 

PRIORITYQUEUE *pq_init() {
    PRIORITYQUEUE *new_pq = malloc(sizeof(PRIORITYQUEUE));

    if (new_pq) {
        // Set all members
        new_pq->front = NULL;
        new_pq->rear = NULL;
        new_pq->length = 0;
    }

    return new_pq;
}

/*------------------------------------------------
Auxiliary Function: Creates a a new PQ node.
Parameters:
    1. BST *bt: Pointer to Binary Search Tree
    2. int data: 
Time and Space Complexity: O(1), O(1)
-------------------------------------------------
Returns:
    Pointer to node if successfully allocated,
    NULL otherwise
------------------------------------------------*/
PQNODE* new_node(PRIORITYQUEUE *pq, int data) {
    PQNODE *node = malloc(sizeof(PQNODE)); // Allocate space for new node and return it as a pointer to that space

    // If pointer to PQ exists
    if (node) {
        // If the node was successfully allocated
        node->value.value = data; // Copy the data
    }


    return node;
}

int pq_enqueue(PRIORITYQUEUE *pq, int value) {
    PQNODE *node = new_node(pq, value);
    int enqueued = 0;

    if (pq) {
        if (node) {
            if (!pq->front) {
                // Special Case: If queue is empty
                pq->front = pq->rear = node;
            }

            else if (value < pq->front->value.value) {
                // Special Case: node becomes front
                node->next = pq->front;
                pq->front = node;
            }

            else if (value >= pq->rear->value.value) {
                // Special Case: Node becomes rear
                pq->rear->next = node;
                pq->rear = node;
            }

            else {
                // General Case: Traverse queue to find proper insertion place
                PQNODE *previous = NULL;
                PQNODE *curr = pq->front;

                while (value >= curr->value.value) {
                    // Traverse the queue to find proper place of insertion
                    previous = curr;
                    curr = curr->next;
                }

                // Perform pointer manipulation
                node->next = curr;
                previous->next = node;
            }

            enqueued = 1; // Flag insertion as successful
            pq->length = pq->length + 1; // Increment the queue length
        }
    }

    return enqueued;
}

DATA pq_dequeue(PRIORITYQUEUE *pq) {
    DATA dequeued = { 0 };

    if (pq) {
        if (pq->front) {
            // If a pointer to queue exists and if queue is not empty, retrieve front value, free node, & update front pointer
            PQNODE *temp = pq->front;
            dequeued = pq->front->value;
            free(temp);
            pq->front = pq->front->next;
            pq->length = pq->length - 1;
        }
    }

    return dequeued;
}

int pq_peek(PRIORITYQUEUE *pq) {
    int peeked = 0;
    
    if (pq) {
        if (pq->front) {
            // If a pointer to queue exists and if queue is not empty, retrieve front value
            peeked = pq->front->value.value;
        }
    }

    return peeked;
}


int pq_wipe(PRIORITYQUEUE *pq) {
    int wiped = 0;

    if (pq) {
        PQNODE *node = pq->front;

        if (pq->length > 0) {
            while (node) {
                pq->front = pq->front->next;
                free(node);
                node = pq->front;
            }

            pq->front = pq->rear = NULL;
            pq->length = 0;
            wiped = 1;
        }

        free(pq);
    }

    return wiped;
}