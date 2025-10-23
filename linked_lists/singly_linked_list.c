/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Implementation of Linked List
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#include <singly_linked_list.h>


LINKEDLIST* list_init() {
    LINKEDLIST *new_list = malloc(sizeof(LINKEDLIST));

    if (new_list) {
        new_list->head = NULL;
        new_list->tail = NULL;
        new_list->length = 0;
    }

    return new_list;
}

int list_length(LINKEDLIST *ll) {
    int size = 0;

    if (ll) {
        size = ll->length;
    }

    return size;
}


LINKEDLIST* new_node(LINKEDLIST *ll, char *username, int user_id) {
    NODE *node = malloc(sizeof(NODE)); // Allocate space for new node and return it as a pointer to that space

    if (ll){
        // If pointer to list exists
        if (node) {
            // If the node was successfully allocated
            strcpy(node->data.name, username); // Copy the contents of the string into the node name
            node->data.id = user_id; // Copy the user id
            node->next = NULL;
        }
    }

    return node;
}

int list_insert(LINKEDLIST *ll, int index, int user_id, char *username) {
    int inserted = 0;

    if (ll) {
        if (ll->head) {
            NODE *node = new_node(ll, username, user_id);

            if (index <= 0) {
                // Node goes to the front
                node->next = ll->head;
                ll->head = node;
            }

            else if (index >= ll->length - 1) {
                // Node goes to the rear
                ll->tail->next = node;
                ll->tail = node;
            }

            else {
                // Node goes elsewhere
                NODE *previous = NULL;
                NODE *curr = ll->head;
                int i = 0;

                while (i < index) {
                    // Traverse the list until we find the right place of insertion
                    previous = curr;
                    curr = curr->next;
                    i = i + 1;
                }

                // Insert node via pointer manipulation
                node->next = curr;
                previous->next = node;
            }

            inserted = 1; // Flag insertion as successful 
            ll->length = ll->length + 1; // Increment the length of the list
        }

        else {
            // List is empty - prepend
            inserted = prepend(ll, user_id, username);
        }
    }

    return inserted;
}

int list_prepend(LINKEDLIST *ll, int user_id, char *username) {
    int prepended = 0;

    if (ll) {
        NODE *node = new_node(ll, username, user_id);

        if (!ll->head) {
            // List is empty
            ll->head = ll->tail = node;
        }

        else {
            // List is not empty
            node->next = ll->head;
            ll->head = node;
        }

        prepended = 1;
        ll->length = ll->length + 1;
    }

    return prepended;
}

int list_append(LINKEDLIST *ll, int user_id, char *username) {
    int appended = 0;

    if (ll) {
        NODE *node = new_node(ll, username, user_id);

        if (!ll->head) {
            // List is empty
            ll->head = ll->tail = node;
        }

        else {
            // List is not empty
            ll->tail->next = node;
            ll->tail = node;
        }

        appended = 1;
        ll->length = ll->length + 1;
    }

    return appended;
}

LLUSER list_remove_by_key(LINKEDLIST *ll, int user_id_key) {
    LLUSER removed = { 0 }; 

    if (ll) {
        if (ll->head) {
            NODE *previous = linear_search(ll, user_id_key); // Perform a linear search
            NODE *temp = NULL; // Storing node containing id key to free from memory

            if (!previous) {
                // If there is no previous node, node containing key ID is at the head of the List
                removed = ll->head->data; // Grab the head data
                temp = ll->head; // Store head temporarily
                ll->head = ll->head->next; // Update the head to point to next node
                free(temp); // Free the previous head
                temp = NULL;
            }

            else if (previous->next->data.id == user_id_key) {
                temp = previous->next; // Store node of deletion in temp
                previous->next = temp->next; // Pointer manipulation to remove any connections to temp
                free(temp); // Free the node of deletion

            }
        }
    }

    return removed;
}

/*
--------------------------------------------
* Auxiliary function: Performs a linear search
by finding the first occurence of a node containing
key ID
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int key: Key ID
* Time & Space Complexity: O(n), O(1)
--------------------------------------------
* Returns: previousious node of the node containing
key
    a. If previous is NULL, node containing key ID 
    is at the head of the List
    b. If the next node of previous is NULL,
    node containing key ID doesn't exist
    c. If the next node of previous is not NULL, 
    node containing key ID is in between index 1
    and length - 1
*/
NODE *linear_search(LINKEDLIST *ll, int key) {
    NODE *previous = NULL;
    NODE *curr = ll->head;
    int found = 0;

    while (curr && !found) {
        // Traverse the list
        if (curr->data.id == key) {
            // Node found: Stop the loop
            found = 1;
        }

        else {
            // Node not found (yet): Continue traversal
            previous = curr;
            curr = curr->next;
        }
    }

    if (!found) {
        curr = NULL;
    }

    return previous;
}

int list_reverse(LINKEDLIST *ll) {
    int reversed = 0;

    if (ll) {
        if (ll->head) {
            if (ll->head != ll->tail) {
                NODE *previous = NULL;
                NODE *curr = ll->head;
                NODE *next = NULL;

                while (curr) {
                    next = curr->next; // Update next to be next node of curr
                    curr->next = previous; // Update curr->next to be the previous node

                    previous = curr; // Make previous be the initial curr
                    curr = next; // Update curr to be the next node of the initial curr
                }  

                reversed = 1;
                
                // Swap head and tail
                NODE *temp = ll->head;
                ll->head = ll->tail;
                ll->tail = temp;
            }
        }
    }

    return reversed;
}

void list_iterate(LINKEDLIST *ll) {
    if (ll) {
        if (ll->head) {
            printf("Database of users: ");
            printf("-------------------");
            NODE *curr = ll->head;

            while (curr) {
                printf("user: %d, %s", curr->data.id, curr->data.name);
                printf("");
            }
        }

        else {
            printf("List is empty");
            printf("");
        }
    }
}

int list_wipe(LINKEDLIST *ll) {
    NODE *node = ll->head;
    int wiped = 0;

    if (ll->length > 0) {
        while (node) {
            ll->head = ll->head->next;
            free(node);
            node = ll->head;
        }

        ll->head = ll->tail = NULL;
        ll->length = 0;
        wiped = 1;
    }

    return wiped;
}