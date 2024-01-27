/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  cout << "Hello: ";
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));


    Node* odds = nullptr;
    Node* evens = nullptr;
    split(head, odds, evens);


    cout << "Odd values: ";
    for (Node* curr = odds; curr != nullptr; curr = curr->next) {
        cout << curr->value << " ";
    }
    cout << endl;


    cout << "Even values: ";
    for (Node* curr = evens; curr != nullptr; curr = curr->next) {
        cout << curr->value << " ";
    }
    cout << endl;


    delete head;
    delete odds;
    delete evens;

    return 0;
}
