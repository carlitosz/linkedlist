#include <iostream>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "SortedSinglyLinkedList.h"
#include "DoublyLinkedList.h"

// ============================================================================
// Main.
// ============================================================================
int main(void) {
    // Create a new sorted singly linked list
    SortedSinglyLinkedList<int> list;

    // Populate the linked list in random order
    list.addList(2);
    list.addList(5);
    list.addList(3);
    list.addList(1);
    list.addList(14);
    list.addList(12);
    list.addList(8);
    list.addList(0);

    // Print list
    list.printList();


    // Create a doubly linked list.
    DoublyLinkedList<char> doublyList;

    // Populate
    doublyList.addList('c');
    doublyList.addList('a');
    doublyList.addList('r');
    doublyList.addList('l');
    doublyList.addList('o');
    doublyList.addList('s');

    // Print
    doublyList.printList();

    return 0;
}
