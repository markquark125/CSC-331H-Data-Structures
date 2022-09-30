#include "nodeType.h"
#include <iostream>
using namespace std;

#ifndef CIRCLE_LIST
#define CIRCLE_LIST

/****************************************************************
 * A sorted circular linked list. *first always points to the
 * last node in the list; can be used to access both first
 * and last node in the list.
 ****************************************************************/

template <class T>
class circleLinkList
{
private:
    int length;
    nodeType<T> *first;

public:
    // Constructors, copy constructs, destructor
    circleLinkList();
    circleLinkList(const circleLinkList<T> &);
    ~circleLinkList();

    // Overload assignment operator
    const circleLinkList<T> &operator=(const circleLinkList<T> &);

    // Getters
    int getLength();  // Get lenzgth of list.
    bool isEmpty();   // Check if list is empty
    void printList(); // Print all items in the list.

    // Setters
    // void initializeList();
    void destroy();
    void copy(const circleLinkList<T> &); // Copy list
    void insertItem(T);                   // Insert an item into the list
    void deleteItem(T);                   // Delete an item from the list
    bool searchItem(T);                   // Search for an item, return true if found.
};

#endif //