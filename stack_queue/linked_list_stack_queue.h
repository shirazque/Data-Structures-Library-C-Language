/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Auxiliary Stack and Queue Data
Structure Header for BST bfs/dfs
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <binary_search_tree.h> 
#ifndef AUX_LINKED_STACK_QUEUE
#define AUX_LINKED_STACK_QUEUE

                                           /* ------------ Common Node ------------ */

/*------------------------------------------------
Structure: Common Stack and Queue Node
Members:
    1. TREENODE *treenode: Holds the node of a BST
    for Breadth/Depth First Search
    2. NODE *next: Pointer to next node
-------------------------------------------------*/
typedef struct node {
    TREENODE *treenode;
    NODE *next;
} NODE;

                                            /* ------------ STACK ------------ */

/*------------------------------------------------
Structure: Stack
Members:
    1. NODE *top: Pointer to the top node
    2. int length: length of the Stack
-------------------------------------------------*/
typedef struct stack {
    NODE *top;
    int length;
} STACK;

/*------------------------------------------------
Function: Allocates a new Stack and returns a pointer
to it
Parameters:
    N/A
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to Stack Data Structure
------------------------------------------------*/
STACK *init_stack();

/*------------------------------------------------
Function: Returns the length of the Stack
Parameters:
    1. STACK *ls: Stack Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Length of the Stack
------------------------------------------------*/
int length_stack(STACK *ls);

/*------------------------------------------------
Function: Creates a new Node, stores the Tree node
into that new node, and pushes it onto the Stack
Parameters:
    1. STACK *ls: Pointer to Stack Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    1 if pushed, 0 otherwise
------------------------------------------------*/
int push(STACK *ls, TREENODE *treenode);

/*------------------------------------------------
Function: Pops the node and frees it from memory.
Returns the Tree node stored in that node
Parameters:
    1. STACK *ls: Pointer to Stack Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to the Tree node from the popped node
------------------------------------------------*/
TREENODE *pop(STACK *ls);

/*------------------------------------------------
Function: Frees the Stack and all its contents 
from memory.
Parameters:
    1. STACK *ls: Pointer to Stack
Time and Space Complexity: O(n), O(1)
-------------------------------------------------
Returns:
    1 if wipped, 0 otherwise
------------------------------------------------*/
int wipe_stack(STACK *ls);

                                            /* ------------ QUEUE ------------ */

/*------------------------------------------------
Structure: Queue
Members:
    1. NODE *front: Pointer to the front node
    2. NODE *rear: Pointer to the rear node
    2. int length: length of the Queue
-------------------------------------------------*/
typedef struct queue {
    NODE *front; 
    NODE *rear; 
    int length;
} QUEUE;

/*------------------------------------------------
Function: Allocates a new Queue and returns a pointer
to it
Parameters:
    N/A
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to new Queue Data Structure
------------------------------------------------*/
QUEUE *init_queue();

/*------------------------------------------------
Function: Returns the length of the Queue
Parameters:
    1. QUEUE *lq: Pointer to Queue Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Length of the Queue
------------------------------------------------*/
int length_queue(QUEUE *lq);

/*------------------------------------------------
Function: Creates a new Node, stores the Tree node
into that new node, and enqueues it onto the Queue
Parameters:
    1. QUEUE *lq: Pointer to Queue Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    1 if enqueued, 0 otherwise
------------------------------------------------*/
int enqueue(QUEUE *lq, TREENODE *treenode);

/*------------------------------------------------
Function: Dequeues the node and frees it from memory.
Returns the Tree node stored in that node
Parameters:
    1. QUEUE *lq: Pointer to Queue Data Structure
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to the Tree node from the dequeued node
------------------------------------------------*/
TREENODE *dequeue(QUEUE *lq);

/*------------------------------------------------
Function: Frees the Queue and all its contents 
from memory.
Parameters:
    1. QUEUE *lq: Pointer to Queue Data Structure
Time and Space Complexity: O(n), O(1)
-------------------------------------------------
Returns:
    1 if wipped, 0 otherwise
------------------------------------------------*/
int wipe_queue(QUEUE *lq);

#endif