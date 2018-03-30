#ifndef SORTED_DOUBLY_PRIORITY_LINKED_LIST_H
#define SORTED_DOUBLY_PRIORITY_LINKED_LIST_H

#include "SortedDoublyLinkedList.h"

template<class T>
class SortedDoublyPriorityLinkedList : public SortedDoublyLinkedList<T> {
    public:
        void prioritize(const T& value) {
            if(!SortedDoublyLinkedList<T>::inList(value)) {
                cout << "Could not find " << value << "in the list." << endl;
                return;
            }

            SortedDoublyLinkedList<T>::moveToFront(value);
        }
};

#endif /* SORTED_DOUBLY_PRIORITY_LINKED_LIST_H */
