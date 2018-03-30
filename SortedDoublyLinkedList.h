#ifndef SORTED_DOUBLY_LINKED_LIST_H
#define SORTED_DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template<class T>
class SortedDoublyLinkedList {
    private:
        struct Link {
            T data;
            Link *next;         // Points to next
            Link *prev;         // Points to previous
        };

        Link *head;
    public:
        SortedDoublyLinkedList() { head = NULL; }
        ~SortedDoublyLinkedList() {};
        void printList();
        void addList(const T& data);
        int getTotal();
        void moveToFront(const T& data);
        bool inList(const T& data);
};

// ============================================================================
// inList.
//
// Input -> The value to find.
// Output -> True if found, else false.
// ============================================================================
template<class T>
bool SortedDoublyLinkedList<T>::inList(const T& data) {
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
// moveToFront.
//
// Input -> nothing.
// Output -> nothing.
// ============================================================================
template<class T>
void SortedDoublyLinkedList<T>::moveToFront(const T& data) {
    if (data == head->data) {
        cout << "Priority for value " << data << " is already set." << endl;
    }

    // Find the target link.
    Link *ptr = head;
    Link *tmp = head;
    while (ptr != NULL) {
        if (ptr->data == data) {
            break;
        }

        ptr = ptr->next;
    }

    // Set the new null
    if (ptr->next == NULL) {
        ptr->prev->next = NULL;

        return;
    }

    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    head = ptr;
    ptr->prev = NULL;
    ptr->next = tmp;
}

// ============================================================================
// printList.
//
// Input -> nothing.
// Output -> prints the list.
// ============================================================================
template<class T>
void SortedDoublyLinkedList<T>::printList() {
    cout << "\n\nPrinting SortedDoublyLinkedList.\n";
    cout << "NULL ";

    Link *ptr = head;
    while (ptr != NULL) {
        cout << " <- " << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

// ============================================================================
// addList
//
// Input -> The value to add.
// Output -> nothing.
// ============================================================================
template<class T>
void SortedDoublyLinkedList<T>::addList(const T& data) {
    // Add to empty list
    if (head == NULL) {
        Link *temp = new Link;
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = data;
        head = temp;

        return;
    }

    // Add to front
    Link *ptr = head;
    if (head->data > data) {
        Link *temp = new Link;
        temp->data = data;
        temp->prev = NULL;
        temp->next = ptr;
        head = temp;

        return;
    }

    // Add to single link
    ptr = head;
    if (getTotal() < 2) {
        if (data <= head->data) {
            Link *temp = new Link;
            temp->data = data;
            temp->prev = NULL;
            temp->next = ptr;
            ptr->prev = temp;
            head = temp;

            return;                
        }

        if (data > head->data) {
            Link *temp = new Link;
            temp->data = data;
            temp->prev = ptr;
            temp->next = NULL;
            ptr->next = temp;

            return;
        }
    }

    // Find position of next link.
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

    // Insert
    Link *temp = new Link;
    temp->data = data;
    temp->next = after;
    temp->prev = prev;
    prev->next = temp;

}


// ============================================================================
// getTotal.
//
// Input -> nothing.
// Output -> total number of links in the list.
// ============================================================================
template<class T>
int SortedDoublyLinkedList<T>::getTotal() {
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

#endif /* SORTED_DOUBLY_LINKED_LIST_H */
