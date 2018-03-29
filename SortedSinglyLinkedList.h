#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class SortedSinglyLinkedList {
    private:
        struct Link {
            T data;                     // Stores data
            Link *next;                 // Pointer to the next link
        };

        Link *head;                     // Points to the first link
        void insert(T, Link*, Link*);
    public:
        // Default constructor
        SortedSinglyLinkedList() { head = NULL; }
        ~SortedSinglyLinkedList() {};   // Destructor
        void printList();               // Prints list to output stream
        void addList(const T& data);    // Adds link to the correct place
        int getIndexOf(const T& data);  // Finds index position of the link
        int getTotal();                 // Returns total number of links
};

#endif /* LINKEDLIST_H */


// ============================================================================
// printList.
// 
// Input -> nothing.
// Output -> the list.
// ============================================================================
template<class T>
void SortedSinglyLinkedList<T>::printList() {
    cout << "\nPrinting sorted singly linked list.\n\n";

    Link *ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

// ============================================================================
// addList.
//
// Input -> the data for the new link.
// Output -> nothing.
// ============================================================================
template<class T>
void SortedSinglyLinkedList<T>::addList(const T& data) {
    // Add to empty list
    if (head == NULL) {
        Link *temp = new Link;
        temp->data = data;
        temp->next = NULL;
        head = temp;

        return;
    }

    // Add in front
    Link *ptr = head;
    if (data < ptr->data) {
        Link *temp = new Link;
        temp->data = data;
        temp->next = ptr;
        head = temp;

        return;
    }

    // Add before single link.
    ptr = head;
    if (getTotal() < 2) {
        if (data <= head->data) {
            Link *temp = new Link;
            temp->next = head;
            temp->data = data;
            ptr->next = NULL;
            head = temp;

            return;
        }

        if (data > head->data) {
            insert(data, ptr, NULL);

            return;
        }
    }

    // Get prev/after links.
    Link *prev = head;
    Link *after = head->next;
    while (data > prev->data) {
        if (data < after->data) {
            break;
        }

        prev = prev->next;
        after = after->next;

        if (after == NULL) break;
    }

    insert(data, prev, after);
}

// ============================================================================
// Insert.
//
// ============================================================================
template<class T>
void SortedSinglyLinkedList<T>::insert(T data, Link *prev, Link *after) {
    Link *temp = new Link;
    temp->data = data;
    temp->next = after;
    prev->next = temp;
}

// ============================================================================
// getIndexOf.
//
// Input -> the value of some link.
// Output -> the index position of the link.
// ============================================================================
template<class T>
int SortedSinglyLinkedList<T>::getIndexOf(const T& data) {
    Link *ptr = head;
    for (int i = 0; ptr != NULL; ++i, ptr = ptr->next) {
        if (ptr->data == data) {
            return i;
        }
    }
}

// ============================================================================
// getTotal.
//
// Input -> nothing.
// Output -> total number of links in the list.
// ============================================================================
template<class T>
int SortedSinglyLinkedList<T>::getTotal() {
    if (head == NULL) {
        return 0;
    }

    int i = 0;
    Link *ptr = head;
    while (ptr != NULL) {
        i++;
        ptr = ptr->next;
    }

    return i;
}