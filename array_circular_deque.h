/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for Array-based Circular
             Deque
             - Input Restricted.
--------------------------------------------
*/

#include <stdio.h> // Includes the standard input/output package
#include <stdlib.h> // Includes the standard library header
#ifndef ARRAY_CIRCULAR_DEQUE_H
#define ARRAY_CIRCULAR_DEQUE_H

/*------------------------------------------------
Structure: Data
Members:
    1. int value: Value of the node data
-------------------------------------------------*/
typedef struct data {
    int value;
} DATA;

/*
--------------------------------------------
Structure Type: Array-Based Circular Deque
Members:
    1. DATA *values: Pointer to the deque array
    2. int front: Index of the front value
    3. int rear: Index of the rear value
    4. int max_length: Maximum size of the deque
--------------------------------------------
*/
typedef struct deque {
    DATA *values; 
    int front; 
    int rear;
    int capacity;
    int length;
} DEQUE;

/*
--------------------------------------------
Function: Initializes an array-based circular deque
Parameters:
    N/A
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: Pointer to the deque structure
*/
DEQUE* deque_init(int capacity);

/*
--------------------------------------------
Function: Inserts at the rear of the deque 
based on priority
Parameters:
    1. Pointer to deque
    2. Value to be inserted
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: 1 if inserted, 0 otherwise
*/
int deque_insert_rear(DEQUE *adq, int value);

/*
--------------------------------------------
Function: Removes from the front of the deque
Parameters:
    1. Pointer to deque
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: DATA being removed, 0 otherwise
*/
DATA deque_remove_front(DEQUE *adq);

/*
--------------------------------------------
Function: Removes from the rear of the deque
Parameters:
    1. Pointer to deque
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: DATA being removed, 0 otherwise
*/
DATA deque_remove_rear(DEQUE *adq);

/*
--------------------------------------------
Function: Peeks at the front of the deque
Parameters: 
    1. Pointer to deque
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: Value being peeked, 0 otherwise
*/
int deque_peek_front(DEQUE *adq);

/*
--------------------------------------------
Function: Peeks at the rear of the deque
Parameters:
    1. Pointer to deque
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: Value being peeked, 0 otherwise
*/
int deque_peek_rear(DEQUE *adq);

/*
--------------------------------------------
Function: Frees the contents of the deque
Parameters:
    1. Pointer to deque
Time & Space Complexity: O(n), O(1)
--------------------------------------------
Returns: 1 if wiped, 0 otherwise
*/
int deque_wipe(DEQUE *adq);

#endif
