/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Implementation for Array-based 
             Circular Deque
             - Input Restricted.
--------------------------------------------
*/

#include <stdio.h> // Includes the standard input/output package
#include <stdlib.h> // Includes the standard library header
#include <array_circular_deque.h>

DEQUE* deque_init(int capacity){
    DEQUE *new_queue = malloc(sizeof(DEQUE)); // Allocates space for the deque structure and returns a pointer to it
    
    if (new_queue) {
        // Creates new queue
        new_queue->front = -1; 
        new_queue->rear = 0;
        new_queue->capacity = capacity;
        new_queue->length = 0;
        new_queue->values = calloc(capacity, sizeof(DATA)); // Makes room for capacity# Data zeros in the Array
    }

    return new_queue;
}

int deque_insert_rear(DEQUE *adq, int value) {
    int inserted = 0;
    int to_insert = 0;

    if (adq->length != adq->capacity) {
        // If the circular deque is not full
        to_insert = value;

        if (adq->front == -1){
            // If circular queue is empty
            adq->front = 0;
        }

        adq->values[adq->rear].value = to_insert; // Add data to the deque
        adq->rear = (adq->rear + 1) % adq->capacity; // INcrement the rear
        adq->length += 1; // Update the length of the deque
        inserted = 1; // Insertion worked
    }
    return inserted;
}

DATA deque_remove_front(DEQUE *adq) {
    DATA removed = { 0 };
    
    if (adq->front != -1){
        // If the circular deque is not empty
        removed = adq->values[adq->front]; // Grab the data
        adq->values[adq->front].value = 0; // Reset the value at index front
        adq->length -= 1;

        if (adq->length == 0){
            // Reset the deque
            adq->front = -1;
            adq->rear = 0;
            
        } else{
            // Update front index
            adq->front = (adq->front + 1) % adq->capacity;
        }
    }

    return removed;
}

DATA deque_remove_rear(DEQUE *adq) {
    DATA removed = { 0 };

    if (adq->front != -1){
        int rear_updated = (adq->rear - 1 + adq->capacity) % adq->capacity;
        removed = adq->values[rear_updated]; // Grab the data
        adq->values[rear_updated].value = 0; // Reset the value at index rear
        adq->length -= 1;

        if (adq->length == 0){
            // Reset the deque
            adq->front = -1;
            adq->rear = 0;
        }

        else{
            // Update rear index
            adq->rear = rear_updated;
        }
    }

    return removed;
}

int deque_peek_front(DEQUE *adq) {
    int peeked = 0;

    if (adq->front > -1){
        // If the deque isn't empty
        peeked = adq->values[adq->front].value; // Copy value
    }

    return peeked;
}

int deque_peek_rear(DEQUE *adq) {
    int peeked = 0;

    if (adq->front > -1){
        // If the deque isn't empty
        int rear_updated = (adq->rear - 1 + adq->capacity) % adq->capacity;
        peeked = adq->values[rear_updated].value; // Copy value
    }

    return peeked;
}

int deque_wipe(DEQUE *adq) {
    int wiped = 0;

    if (adq) {
        free(adq->values); // Frees the contents of the deque
        adq->values = NULL; // Sets the pointer of the array to NULL
        adq->front = 0;
        adq->rear = 0;
        wiped = 1;
    
    free(adq);
    }

    return wiped;
}