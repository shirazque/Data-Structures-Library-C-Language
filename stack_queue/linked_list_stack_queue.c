/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Auxiliary Stack and Queue Data
Structure implementation for BST Breadth/Depth
First Search
--------------------------------------------
*/

#include <linked_list_stack_queue.h>

                                            /* ------------ STACK ------------ */

STACK *init_stack(){
    STACK *ls = malloc(sizeof(STACK));

    if (ls){
        ls->length = 0;
        ls->top = NULL;
    }

    return ls;
}

/*------------------------------------------------
Auxiliary Function: Creates a Node for the Stack
Parameters:
    1. STACK *ls: Pointer to Stack Data Structure
    2. TREENODE *treenode: The data of the node,
    i.e., the Tree node
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to a new Node
------------------------------------------------*/
NODE *create_stack_node(STACK *ls, TREENODE *treenode){
    NODE *new_node = malloc(sizeof(NODE));

    if (new_node){
        new_node->treenode = treenode;
        new_node->next = NULL;
    }

    return new_node;
}

int length_stack(STACK *ls){
    return ls->length;
}

int push(STACK *ls, TREENODE *treenode){
    NODE *new_node = create_stack_node(ls, treenode);
    int pushed = 0;

    if (new_node){
        new_node->next = ls->top;
        ls->top = new_node;

        ls->length = ls->length + 1;
        pushed = 1;
    }
    return pushed;
}   

TREENODE *pop(STACK *ls){
    TREENODE *removed = NULL;
    NODE *node = ls->top;

    if (ls->top){
        removed = ls->top->treenode;
        ls->top = ls->top->next;
        
        free(node);
        ls->length = ls->length - 1;
    }

    return removed;
}

int wipe_stack(STACK *ls) {
    int wiped = 0;

    if (ls) {
        NODE *node = ls->top;
        NODE *curr = NULL;

        if (ls->length > 0) {
            while (node){
                curr = node;
                node = node->next;
                ls->top = node;
                free(curr);
            }

            ls->top = NULL;
            ls->length = 0;
            wiped = 1;
        }
        free(ls);
    }

    return wiped;
}

                                            /* ------------ QUEUE ------------ */

QUEUE *init_queue(){
    QUEUE *lq = malloc(sizeof(QUEUE));

    if (lq){
        lq->length = 0;
        lq->front = NULL;
        lq->rear = NULL;
    }

    return lq;
}

/*------------------------------------------------
Auxiliary Function: Creates a Node for the Queue
Parameters:
    1. QUEUE *lq: Pointer to Queue Data Structure
    2. TREENODE *treenode: The data of the node,
    i.e., the Tree node
Time and Space Complexity: O(1), O(1)
--------------------------------------------------
Returns:
    Pointer to a new Node
------------------------------------------------*/
NODE *create_queue_node(QUEUE *lq, TREENODE *treenode){
    NODE *new_node = malloc(sizeof(NODE));
    
    if (new_node){
        new_node->treenode = treenode;
        new_node->next = NULL;
    }

    return new_node;
}

int length_queue(QUEUE *lq){
    return lq->length;
}

int enqueue(QUEUE *lq, TREENODE *treenode){
    NODE *new_node = create_queue_node(lq, treenode);
    int enqueued = 0;

    if (new_node){
        if (lq->front == NULL) {
            lq->front = lq->rear = new_node;
        }
        
        else {
            lq->rear->next = new_node;
            lq->rear = new_node;
        }

        enqueued = 1;
        lq->length = lq->length + 1;
    }

    return enqueued;
}

TREENODE *dequeue(QUEUE *lq){
    TREENODE *dequeued = NULL;
    NODE *node = lq->front;

    if (lq->front){
        dequeued = lq->front->treenode;
        
        if (lq->front == lq->rear){
            lq->front = lq->rear = NULL;
        }

        else{
            lq->front = lq->front->next;
        }

        free(node);
        lq->length = lq->length - 1;
    }

    return dequeued;
}

int wipe_queue(QUEUE *lq) {
    int wiped = 0;

    if (lq) {
        NODE *node = lq->front;

        if (lq->length > 0) {
            while (node) {
                lq->front = lq->front->next;
                free(node);
                node = lq->front;
            }

            lq->front = lq->rear = NULL;
            lq->length = 0;
            wiped = 1;
        }

        free(lq);
    }

    return wiped;
}
