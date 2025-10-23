/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Implementation for Array Stack
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <array_stack.h>

STACK* stack_init(int capacity) {
    STACK *new_stack = malloc(sizeof(STACK)); // Allocates space for the stack structure and returns a pointer to it
    
    if (new_stack != NULL) {
        new_stack->values = calloc(capacity, sizeof(DATA)); // Makes room for capacity# Data zeros in the Array
        
        if (new_stack->values != NULL) {
            new_stack->top = -1; // -1 indicates the stack is empty
            new_stack->capacity = capacity; // Sets the maximum length of the stack
        } else {
            // Allocation of values array failed, free the stack structure 
            free(new_stack);
        }
    }

    return new_stack;
}

int stack_push(STACK *as, int value) {
    int pushed = 0; // Initially false, remains unchanged if the stack is full

    if (as->top < as->capacity - 1) {
        // As long as the stack is not full
        as->top += 1; // Increments the top
        as->values[as->top].value = value; // Sets the top index as the value
        pushed = 1; // Sets pushed to true

    }

    return pushed;
}

DATA stack_pop(STACK *as) {
    DATA value = { 0 }; // 0 means the pop is unsuccessful and will not change unless the stack is not empty

    if (as->top > -1) {
        // As long as the stack is not empty
        value = as->values[as->top]; // Stores the top value
        as->top -= 1; // Decrements the top
    }

    return value;
}

int stack_peek(STACK *as) {
    int value = 0;

    if (as->top > -1) {
        // As long as the stack is not empty
        value = as->values[as->top].value;
    }

    return value;
}

void stack_wipe(STACK *as) {
    if (as) {
        free(as->values); // Frees the contents of the stack
        as->values = NULL; // Sets the pointer of the array to NULL
        as->top = -1; // Sets the top to -1 to indicate the stack is empty
        free(as);
    }
}


