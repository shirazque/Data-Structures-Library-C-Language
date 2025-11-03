/*--------------------------------------------
Author: Shiraz Qasmi
Date: 2025-10-29
Description:
    Main Class.
--------------------------------------------*/

#include <stdio.h>  // Includes Standard Input/Output Header
#include <stdlib.h> // Includes Standard Library Header
#include "BSTs/standard_bst.h"
#include "BSTs/auxiliary/tree_common.h"


void test_bst() {
    BST *new_tree = bst_init(); // Initialize a new BST

    // Inserts new foods into BST
    bst_insert(new_tree, 650, "Poutine", FALSE, 0);                // Canadian
    bst_insert(new_tree, 450, "Sweet and Sour Chicken", FALSE, 1); // Chinese
    bst_insert(new_tree, 300, "Vegetable Stir Fry", TRUE, 1);      // Chinese
    bst_insert(new_tree, 700, "Butter Chicken", FALSE, 2);         // Indian
    bst_insert(new_tree, 250, "Chana Masala", TRUE, 2);            // Indian
    bst_insert(new_tree, 600, "Doro Wat", FALSE, 3);               // Ethiopian
    bst_insert(new_tree, 220, "Injera with Lentils", TRUE, 3);     // Ethiopian
    bst_insert(new_tree, 550, "Tacos al Pastor", FALSE, 4);        // Mexican
    bst_insert(new_tree, 380, "Vegetarian Burrito", TRUE, 4);      // Mexican
    bst_insert(new_tree, 480, "Greek Salad", TRUE, 5);             // Greek
    bst_insert(new_tree, 700, "Moussaka", FALSE, 5);               // Greek
    bst_insert(new_tree, 320, "Sushi Roll", FALSE, 6);             // Japanese
    bst_insert(new_tree, 290, "Vegetable Tempura", TRUE, 6);       // Japanese
    bst_insert(new_tree, 640, "Spaghetti Carbonara", FALSE, 7);    // Italian
    bst_insert(new_tree, 520, "Margherita Pizza", TRUE, 7);        // Italian
    bst_insert(new_tree, 800, "Cheeseburger", FALSE, 8);           // American
    bst_insert(new_tree, 400, "Mac and Cheese", TRUE, 8);          // American
    bst_insert(new_tree, 550, "Haggis", FALSE, 9);                 // Scottish
    bst_insert(new_tree, 350, "Oat Porridge", TRUE, 9);            // Scottish
    bst_insert(new_tree, 600, "Lamb Roast", FALSE, 10);            // New Zealand
    bst_insert(new_tree, 260, "Kumara Salad", TRUE, 10);           // New Zealand
    bst_insert(new_tree, 720, "Fish and Chips", FALSE, 11);        // English
    bst_insert(new_tree, 200, "Cucumber Sandwich", TRUE, 11);      // English

    

}

int main() {
    return 0;
}