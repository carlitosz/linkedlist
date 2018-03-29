#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList {
    private:
        struct Link {
            T data;
            Link *next;     // Points to next link
            Link *prev;     // Points to previous link
        };

        Link *head;         // Points to first link
    public:
        DoublyLinkedList() { head = NULL; }
        ~DoublyLinkedList() {};
        void printList();
        void printBackward();
        void addList(const T& data);
};

#endif /* DOUBLY_LINKED_LIST_H */


// ============================================================================
// printList.
//
// Input -> nothing.
// Output -> Prints the list.
// ============================================================================
template<class T>
void DoublyLinkedList<T>::printList() {
    cout << "\nPrinting doubly linked list.\n\n";
    cout << "NULL ";

    Link *ptr = head;
    while (ptr != NULL) {
        cout << " <- " << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL";
}

// ============================================================================
// addList
//
// Input -> The value to add.
// Output -> nothing.
// ============================================================================
template<class T>
void DoublyLinkedList<T>::addList(const T& data) {
    // Add to empty list
    if (head == NULL) {
        Link *temp = new Link;
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        head = temp;

        return;
    }

    // Append to end of list
    Link *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    Link *temp = new Link;
    temp->prev = ptr;
    temp->next = NULL;
    temp->data = data;
    ptr->next = temp;
}
