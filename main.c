#include <stdio.h>
#include <testing/test.h>

int main() {

    printf("Data Elements for Stacks and Queues: ");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%d", elements[i]);
    }
    printf("");

    printf("Data Elements for Linked Lists and BSTs: ");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%d", elements[i]);
    }
    printf("");

    test_array_stack();
    test_array_deque();
    test_linked_list_priority_queue();
    test_singly_linked_list();
    test_bst();
    test_avl();

    return 0;
}