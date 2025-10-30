/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Header for Stack and Queue. The purpose 
    is to implement Breadth-First Search
    and Depth-First Search algorithms for
    Binary Search Trees.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include "tree_common.h"
                        /*    ----------    Array-based Stack    ----------    */

/*-------------------------------------
Structure: Stack
Members:
    1. Index of the Top Tree Node
    2. Array of Pointers to Tree Nodes
    3. Length of the Stack
-------------------------------------*/
typedef struct stack {
    int top;
    TREENODE **values; // Pointer to an Array of Tree Node Pointers
    int length;
    int max_length;
} STACK;

/*-------------------------------------
Function:
    Initializes and returns a
    pointer to a newly allocated Stack
Parameters:
    1. The maximum size of the Stack
Returns:
    Pointer to the new Stack
-------------------------------------*/
STACK* stack_init(int max_size);

/*-------------------------------------
Function:
    Pushes a Tree Node onto the Stack
Parameters:
    1. Pointer to the Stack
    2. Pointer to the Tree Node
Returns:
    1 if pushed, 0 otherwise
-------------------------------------*/
int stack_push(STACK *as, TREENODE *node);

/*-------------------------------------
Function:
    Pops a Tree Node from the Stack
Parameters:
    1. Pointer to the Stack
Returns:
    Pointer to the Tree Node, NULL otherwise
-------------------------------------*/
TREENODE* stack_pop(STACK *as);

/*-------------------------------------
Function:
    Returns the length of the Stack
Parameters:
    1. Pointer to the Stack
Returns:
    Length of the Stack
-------------------------------------*/
int stack_length(STACK *as);

/*-------------------------------------
Function:
    Cleans the Stack and all its
    contents
Parameters:
    1. Pointer to the Stack
Returns:
    1 if wiped, 0 otherwise
-------------------------------------*/
int wipe_stack(STACK *as);

                        /*    ----------    Linked List-based Queue    ----------    */

/*-------------------------------------
Structure: Common Queue Node designed
to hold a Tree Node
Members:
    1. Pointer to the Tree Node
    2. Pointer to the next Queue Node
-------------------------------------*/
typedef struct commonnode {
    TREENODE *treedata;
    struct commonnode *next;
} COMMONNODE;

/*-------------------------------------
Structure: Queue
Members:
    1. Pointer to the Front Node
    2. Pointer to the Rear Node
    3. Length of the Queue
-------------------------------------*/
typedef struct queue {
    COMMONNODE *front;
    COMMONNODE *rear;
    int length;
} QUEUE;

/*-------------------------------------
Function:
    Initializes and returns a
    pointer to a newly allocated Queue
Parameters:
    N/A
Returns:
    Pointer to the new Queue
-------------------------------------*/
QUEUE* queue_init();

/*-------------------------------------
Function:
    Enqueues a Tree Node onto the Queue
Parameters:
    1. Pointer to the Queue
    2. Tree Node to enqueue
Returns:
    1 if enqueued, 0 otherwise
-------------------------------------*/
int queue_enqueue(QUEUE *lq, TREENODE *node);

/*-------------------------------------
Function:
    Dequeues a Tree Node from the Queue
Parameters:
    1. Pointer to the Queue
Returns:
    Pointer to the Tree Node, NULL otherwise
-------------------------------------*/
TREENODE* queue_dequeue(QUEUE *lq);

/*-------------------------------------
Function:
    Returns the length of the Queue
Parameters:
    1. Pointer to the Queue
Returns:
    Length of the Queue
-------------------------------------*/
int queue_length(QUEUE *lq);

/*-------------------------------------
Function:
    Cleans the Queue and all its
    contents
Parameters:
    1. Pointer to the Queue
Returns:
    1 if wiped, 0 otherwise
-------------------------------------*/
int wipe_queue(QUEUE *lq);