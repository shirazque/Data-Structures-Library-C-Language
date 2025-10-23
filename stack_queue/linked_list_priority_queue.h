/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for Linked List-based
Priority Queue
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header 
#ifndef LINKED_LIST_PQ
#define LINKED_LIST_PQ

/*------------------------------------------------
Structure: Data
Members:
    1. int value: Value of the node data
-------------------------------------------------*/
typedef struct data {
    int value;
} DATA;

/*------------------------------------------------
Structure: Priority Queue Node
Members:
    1. DATA value: Data of node
    2. PQNODE *next: Pointer to next node
-------------------------------------------------*/
typedef struct pq_node{
    DATA value;
    struct pq_node *next;
} PQNODE;

/*------------------------------------------------
Structure: Priority Queue 
Members:
    1. PQNODE *front: Pointer to front node
    2. PQNODE *rear: Pointer to rear node
    3. int length: length of the Queue
-------------------------------------------------*/
typedef struct priority_queue {
    PQNODE *front;
    PQNODE *rear;
    int length;
} PRIORITYQUEUE;

/*------------------------------------------------
Function: Allocates a new Queue and returns a pointer
to it
Parameters:
    N/A
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to new Priority Queue Data Structure
------------------------------------------------*/
PRIORITYQUEUE *pq_init();

/*------------------------------------------------
Function: Enqueues a new Node
Parameters:
    1. PRIORITYQUEUE *pq: Pointer to Queue
    2. int value: Value to be inserted
Time and Space Complexity: O(n), O(1)
--------------------------------------------------
Returns:
    1 if successfully enqueued, 0 otherwise
------------------------------------------------*/
int pq_enqueue(PRIORITYQUEUE *pq, int value);

/*------------------------------------------------
Function: Enqueues a new Node
Parameters:
    1. PRIORITYQUEUE *pq: Pointer to Queue
    2. int value: Value to be inserted
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    DATA contained in dequeued node. Members are to
    be all zero if dequeue is unsuccessful
------------------------------------------------*/
DATA pq_dequeue(PRIORITYQUEUE *pq);

/*------------------------------------------------
Function: Peeks at front of the Queue
Parameters:
    1. PRIORITYQUEUE *pq: Pointer to Queue
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Peeked value, 0 otherwise
------------------------------------------------*/
int pq_peek(PRIORITYQUEUE *pq);

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
int pq_wipe(PRIORITYQUEUE *pq);

#endif