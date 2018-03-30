#include <iostream>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "SortedSinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "SortedDoublyLinkedList.h"
#include "SortedSinglyPriorityLinkedList.h"
#include "SortedDoublyPriorityLinkedList.h"

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

    // ========================================================================

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

    // ========================================================================

    // Create a sorted doubly linked list.
    SortedDoublyLinkedList<float> sortedDoublyList;

    // Populate
    sortedDoublyList.addList(1.00);
    sortedDoublyList.addList(5.00);
    sortedDoublyList.addList(0.60);
    sortedDoublyList.addList(0.50);
    sortedDoublyList.addList(6.00);
    sortedDoublyList.addList(6.00);
    sortedDoublyList.addList(10.50);
    sortedDoublyList.addList(3.50);
    sortedDoublyList.addList(1.25);

    // Print
    sortedDoublyList.printList();

    // ========================================================================

    // Create a singly priority list.
    SortedSinglyPriorityLinkedList<int> sortedPriorityList;

    // Populate
    sortedPriorityList.addList(1);
    sortedPriorityList.addList(12);
    sortedPriorityList.addList(11);
    sortedPriorityList.addList(3);
    sortedPriorityList.addList(5);
    sortedPriorityList.addList(2);
    sortedPriorityList.addList(55);
    sortedPriorityList.addList(8);
    sortedPriorityList.addList(22);

    // Print
    sortedPriorityList.printList();

    // Prioritize the last link
    sortedPriorityList.prioritize(55);
    cout << "\n\n********** Prioritizing 55 **********";
    sortedPriorityList.printList();

    // Prioritize middle link
    sortedPriorityList.prioritize(5);
    cout << "\n\n********** Prioritizing 5 **********";
    sortedPriorityList.printList();

    // Prioritize the first
    sortedPriorityList.prioritize(1);
    cout << "\n\n********** Prioritizing 1 **********";
    sortedPriorityList.printList();

    // ========================================================================

    // Create a doubly priority list.
    SortedDoublyPriorityLinkedList<float> sortedDoublyPriorityList;

    // Populate
    sortedDoublyPriorityList.addList(4.5);
    sortedDoublyPriorityList.addList(67.5);
    sortedDoublyPriorityList.addList(45.5);
    sortedDoublyPriorityList.addList(3.25);
    sortedDoublyPriorityList.addList(78.34);
    sortedDoublyPriorityList.addList(23.5);
    sortedDoublyPriorityList.addList(1.10);
    sortedDoublyPriorityList.addList(44.56);
    sortedDoublyPriorityList.addList(6.23);
    sortedDoublyPriorityList.addList(65.75);
    sortedDoublyPriorityList.addList(21.54);
    sortedDoublyPriorityList.addList(436.64);
    sortedDoublyPriorityList.addList(87.74);
    sortedDoublyPriorityList.addList(45.43);

    // Print
    sortedDoublyPriorityList.printList();

    // Prioritize a middle link
    cout << "\n\n********** Prioritizing 78.34 **********";
    sortedDoublyPriorityList.prioritize(78.34);
    sortedDoublyPriorityList.printList();

    // Prioritize the end
    cout << "\n\n********** Prioritizing 45.43 **********";
    sortedDoublyPriorityList.prioritize(45.43);
    sortedDoublyPriorityList.printList();

        // Prioritize the first
    cout << "\n\n********** Prioritizing 4.5 **********";
    sortedDoublyPriorityList.prioritize(4.5);
    sortedDoublyPriorityList.printList();

    return 0;
}
