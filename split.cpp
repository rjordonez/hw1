/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
void insertAtFront(Node*& head, Node* node) {
    node->next = head;
    head = node;
}
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
if (in == NULL) {
        return;
    }

    // Extract the first node from the input list
    Node* currentNode = in;
    in = in->next;

    // Decide whether the node is odd or even and insert it to the appropriate list
    if (currentNode->value % 2 == 0) {
        insertAtFront(evens, currentNode);
    } else {
        insertAtFront(odds, currentNode);
    }

    // Recursive call
    split(in, odds, evens);
}

/* If you needed a helper function, write it here */
