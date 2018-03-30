#ifndef SORTED_SINGLY_PRIORITY_LINKED_LIST_H
#define SORTED_SINGLY_PRIORITY_LINKED_LIST_H

#include "SortedSinglyLinkedList.h"

template<class T>
class SortedSinglyPriorityLinkedList : public SortedSinglyLinkedList<T> {
    public:
        void prioritize(const T& value) {
            if(!SortedSinglyLinkedList<T>::inList(value)) {
                cout << "Could not find " << value << "in the list." << endl;
                return;
            }

            SortedSinglyLinkedList<T>::moveToFront(value);
        }
};

#endif /* SORTED_SINGLY_PRIORITY_LINKED_LIST_H */
