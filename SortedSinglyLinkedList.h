#ifndef SORTED_SINGLY_LINKED_LIST_H
#define SORTED_SINGLY_LINKED_LIST_H

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
        void printList();               // Prints list to output stream
        void addList(const T& data);    // Adds link to the correct place
        int getTotal();                 // Returns total number of links
        bool inList(const T& data);     // True if the value exists in the list
        void moveToFront(const T& data);// Moves this link to the front.

        ~SortedSinglyLinkedList() {
            Link *ptr = head;
            while (ptr != NULL) {
                delete ptr;
                ptr = ptr->next;
            }
        }
};

// ============================================================================
// moveToFront.
//
// Input -> the value to move.
// Output -> nothing.
// ============================================================================
template<class T>
void SortedSinglyLinkedList<T>::moveToFront(const T& data) {
    if (data == head->data) {
        cout << "Priority for value " << data << " is already set." << endl;
        return;
    }

    // Find the target link
    Link *tmp = head;
    Link *prev = head;
    Link *after = head->next;
    while (after != NULL) {
        if (after->data == data) {
            break;            
        }

        after = after->next;
        prev = prev->next;
    }

    // Set the new links.
    if (after->next == NULL) {
        prev->next = NULL;
        after->next = head;
        head = after;

        return;
    }

    prev->next = after->next;
    head = after;
    after->next = tmp;
}

// ============================================================================
// inList.
//
// Input -> the value to find.
// Output -> true if found, false if not.
// ============================================================================
template<class T>
bool SortedSinglyLinkedList<T>::inList(const T& data) {
    Link *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

// ============================================================================
// printList.
// 
// Input -> nothing.
// Output -> the list.
// ============================================================================
template<class T>
void SortedSinglyLinkedList<T>::printList() {
    cout << "\n\nPrinting sorted singly linked list.\n";

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

#endif /* SORTED_SINGLY_LINKED_LIST_H */
