#ifndef SORTLIST_H
#define SORTLIST_H

#include <iostream>
#include "nodeType.h"
using namespace std;

template <class T>
class sortList
{
private:
    int length;
    nodeType<T> *first;

    // Private func since overloaded operator= calls copyList function.
    // to be used in copy constructor, too.
    void copyList(const sortList<T> &); // function just to copy

public:
    sortList();
    sortList(const sortList<T> &);
    ~sortList();
    // overload assignment operator
    const sortList<T> &operator=(const sortList<T> &);

    bool isEmpty();
    bool searchItem(T item);
    int getLength() const; // get length
    void printList();      // print list

    void destroy();          // Deallocate list
    void insertItem(T item); // sorted insert item
    void deleteItem(T item); // delete item
};

#endif