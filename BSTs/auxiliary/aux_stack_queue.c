/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Implementation of Stack and Queue. 
    The purpose is to implement Breadth-First
    Search and Depth-First Search algorithms
    for Binary Search Trees.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include <auxiliary/aux_stack_queue.h> 
#include <auxiliary/tree_common.h>

                        /*    ----------    Array-based Stack    ----------    */

STACK* stack_init(int max_size) {
    STACK *new_stack = malloc(sizeof(STACK));

    if (new_stack) {
        // If the stack was successfully allocated
        new_stack->length = 0;
        new_stack->values = calloc(max_size, sizeof(TREENODE *));
        new_stack->top = -1;
        new_stack->max_length = max_size;
    }

    return new_stack;
}

int stack_push(STACK *as, TREENODE *node) {
    int inserted = 0;

    if (as) {
        // if Stack exists
        if (node && as->length < as->max_length) {
            // If node exists
            as->top = as->top + 1; 
            as->values[as->top] = node;
            inserted = 1;
            as->length = as->length + 1;
        }
    }
    return inserted;
}

TREENODE* stack_pop(STACK *as) {
    TREENODE *popped = NULL;

    if (as) {
        // If Stack exists
        if (as->length) {
            // If length of stack is greater than 0
            popped = as->values[as->top];
            as->values[as->top] = NULL;
            as->top = as->top - 1;
            as->length = as->length - 1;
        }
    }
    return popped;
}

int stack_length(STACK *as) {
    int length = 0;

    if (as) {
        length = as->length;
    }
    
    return length;
}

int wipe_stack(STACK *as) {
    int wiped = 0; 

    if (as) {
        // Frees Stack and all its contents
        free(as->values);
        free(as);
        wiped = 1;
    }

    return wiped;
}

                    /*    ----------    Linked List-based Queue    ----------    */

QUEUE* queue_init() {
    QUEUE *new_queue = malloc(sizeof(QUEUE));

    if (new_queue) {
        new_queue->front = NULL;
        new_queue->rear = NULL;
        new_queue->length = 0;
    }

    return new_queue;
}

/*-------------------------------------
Auxiliary Function:
    Initializes and returns a
    pointer to a newly allocated Node
Parameters:
    1. Tree Node
Returns:
    Pointer to newly initialized Node
-------------------------------------*/
COMMONNODE* node_init(TREENODE *node) {
    COMMONNODE *new_node = malloc(sizeof(COMMONNODE));

    if (new_node) {
        // If newly allocated node exists
        new_node->treedata = node;
        new_node->next = NULL;
    }

    return new_node;
}

int queue_enqueue(QUEUE *lq, TREENODE *node) {
    int enqueued = 0;

    if (lq) {
        if (node) {
            COMMONNODE *new_node = node_init(node);

            if (new_node) {
                if (lq->length) {
                    // If the queue is not empty
                    lq->rear->next = new_node;
                    lq->rear = new_node;
                } else {
                    // If the queue is empty
                    lq->front = lq->rear = new_node;
                }

                enqueued = 1;
                lq->length = lq->length + 1;
            }
        }
    }

    return enqueued;
}

TREENODE* queue_dequeue(QUEUE *lq) {
    TREENODE *dequeued = NULL;

    if (lq) {
        if (lq->length) {
            dequeued = lq->front->treedata;
            COMMONNODE *old_front = lq->front;

            if (lq->length > 1) {
                lq->front = lq->front->next;
            }

            else {
                lq->front = lq->rear = NULL;
            }

            free(old_front);
            lq->length = lq->length - 1;
        }
    }

    return dequeued;
}

int queue_length(QUEUE *lq) {
    int length = 0;

    if (lq) {
        length = lq->length;
    }
    
    return length;
}

int wipe_queue(QUEUE *lq) {
    int wiped = 0;
    
    if (lq) {
        if (lq->length) {
            COMMONNODE *temp = lq->front;
            lq->front = lq->front->next;
            free(temp);
        }

        free(lq);
        wiped = 1;
        
    }

    return wiped;
}