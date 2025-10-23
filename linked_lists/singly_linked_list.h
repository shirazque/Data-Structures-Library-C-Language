/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header of Linked List
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library header
#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

/*------------------------------------------------
Structure: Tester/User of a prototype AI app
Members:
    1. int id: Holds the user id
    2. char name[25]: Holds the username of the user
-------------------------------------------------*/
typedef struct user {
    int id;
    char name[25];
} USER;

/*
--------------------------------------------
* Structure Type: Node for List
* Members:
    1. int value: Value contained in the node
    2. NODE *next: Pointer to the next node
* Size: 4 bytes
--------------------------------------------
*/
typedef struct node {
    USER data;
    NODE *next;
} NODE;

/*
--------------------------------------------
* Structure Type: Linked list
* Members:
    1. NODE *head: Pointer to the head node of the list
    2. NODE *TAIL: Pointer to the tail node of the list
    3. int length: Size of the list
* Size: 4 bytes
--------------------------------------------
*/
typedef struct linked_list {
    NODE *head; 
    NODE *tail; 
    int length;
} LINKEDLIST;

/*
--------------------------------------------
* Function: Initializes a linked list
* Parameters: N/A
* Time & Space Complexity: O(1), O(1)
--------------------------------------------
* Returns: Pointer to Linked List
*/
LINKEDLIST* list_init();

/*
--------------------------------------------
* Function: Gets the length of the List
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
* Time & Space Complexity: O(1), O(1)
--------------------------------------------
* Returns: Size of the List
*/
int list_length(LINKEDLIST *ll);

/*
--------------------------------------------
* Function: Inserts into the list
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int index: Index of where we want to insert
    3. int user_id: User ID of the user
    4. char *username: String, i.e., name of user
* Time & Space Complexity: O(n), O(1)
--------------------------------------------
* Returns: 1 if inserted, 0 otherwise
*/
int list_insert(LINKEDLIST *ll, int index, int user_id, char *username);

/*
--------------------------------------------
* Function: Prepends into List
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int user_id: User ID of the user
    3. char *username: String, i.e., name of user
* Time & Space Complexity: O(1), O(1)
--------------------------------------------
* Returns: 1 if prepended, 0 otherwise
*/
int list_prepend(LINKEDLIST *ll, int user_id, char *username);

/*
--------------------------------------------
* Function: Appends into List
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int user_id: User ID of the user
    3. char *username: String, i.e., name of user
* Time & Space Complexity: O(1), O(1)
--------------------------------------------
* Returns: 1 if appended, 0 otherwise
*/
int list_append(LINKEDLIST *ll, int user_id, char *username);

/*
--------------------------------------------
* Function: Removes user by Key. Removes
first occurence
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int user_id_key: User ID
* Time & Space Complexity: O(n), O(1)
--------------------------------------------
* Returns: Copied contents of Node data in
copied USER struct
*/
USER list_remove_by_key(LINKEDLIST *ll, int user_id_key);

/*
--------------------------------------------
* Function: Removes user by Index
* Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
    2. int user_id_key: User ID
* Time & Space Complexity: O(n), O(1)
--------------------------------------------
* Returns: 1 if reversed, 0 otherwise
*/
int list_reverse(LINKEDLIST *ll);

/*------------------------------------------------
Function: Frees the List and all its
contents from memory.
Parameters:
    1. LINKEDLIST *ll: Pointer to Linked List
Time and Space Complexity: O(n), O(1)
Traversal type: Recursive
-------------------------------------------------
Returns:
    N/A
------------------------------------------------*/

int list_wipe(LINKEDLIST *ll);

#endif