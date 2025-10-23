/*
--------------------------------------------
Author: Shiraz Qasmi
Description: Header of Data Structure
Testing
--------------------------------------------
*/

#include <stdio.h> // Includes the Standard Input Output package
#include <stdlib.h> // Includes the Standard Library Header

#include <stack_queue/array_stack.h> // Include Stack Header
#include <stack_queue/array_circular_deque.h> // Include Deque Header
#include <stack_queue/linked_list_priority_queue.h> // Include Priority Queue Header
#include <linked_lists/singly_linked_list.h> // Include Singly Linked List Header
#include <binary_search_trees/binary_search_tree.h> // Include Binary Search Tree Header
#include <binary_search_trees/adelson_velsky_landis_tree.h> // Include AVL Tree Header

#define MAX_LENGTH 10 // Define a Max length for Array-based Structures
#ifndef TEST
#define TEST

// Dataset for Stacks and Queues
int elements[MAX_LENGTH] = {50, 25, 75, 15, 35, 60, 90, 10, 30, 40}; 

// Dataset for Linked Lists and BSTs
int user_ids[MAX_LENGTH] = {1001, 1005, 1002, 1010, 1008, 1015, 1020, 1003, 1007, 1012}; // For Linked Lists and BSTs 
char *usernames[MAX_LENGTH] = {
    "charlie_a",      // 1001
    "courtney_b",     // 1005  
    "alex_c",         // 1002
    "ashley_z",       // 1010
    "david_m",        // 1008
    "daniella_k",     // 1015
    "bryan_t",        // 1020
    "britney_g",      // 1003
    "ethan_r",        // 1007
    "emily_g"         // 1012
};

void test_array_stack();

void test_array_deque();

void test_linked_list_priority_queue();

void test_singly_linked_list();

void test_bst();

void test_avl();

#endif