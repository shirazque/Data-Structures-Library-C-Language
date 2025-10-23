/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header for Array Stack
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

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
Structure Type: Array-Based Stack
Members:
    1. DATA *values: Pointer to stack array
    2. int top: Index of the top value
    3. int capacity: Maximum capacity of the stack
--------------------------------------------
*/
typedef struct stack {
    DATA *values; 
    int top; 
    int capacity;
} STACK;

/*
--------------------------------------------
Function: Initializes an array-based stack
Parameters: max_length
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: Pointer to stack structure
*/
STACK* stack_init(int max_length);

/*
--------------------------------------------
Function: Pushes an integer onto the stack
Parameters:
    1. Pointer to stack
    2. Value to be pushed
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: 1 if pushed, 0 otherwise
*/
int stack_push(STACK *as, int value);

/*
--------------------------------------------
Function: Pops an integer from the stack
Parameters: Pointer to stack
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: DATA 
*/
DATA stack_pop(STACK *as);

/*
--------------------------------------------
Function: Peeks at the top of the stack
Parameters: Pointer to stack
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: Number if peeked, 0 otherwise
*/
int stack_peek(STACK *as);

/*
--------------------------------------------
Function: Frees the contents of the stack
Parameters: Pointer to stack
Time & Space Complexity: O(1), O(1)
--------------------------------------------
Returns: N/A
*/
void stack_wipe(STACK *as);

#endif
