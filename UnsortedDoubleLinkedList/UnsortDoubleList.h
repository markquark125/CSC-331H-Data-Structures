// Createing the unsorted doubly linked list class. Included is a node template class
// By Marcos Ortega

#ifndef UDLL_H
#define UDLL_H

#include <iostream>
using namespace std;

template <class T>
struct nodeType
{
    T info;
    nodeType<T> *next;
    nodeType<T> *prev;
};

template <class T>
class UnsortDoubleList
{
private:
    int length;

    // nodeType<T> *next;
    // nodeType<T> *prev;

    nodeType<T> *first;
    nodeType<T> *last;
    nodeType<T> *current;

    // Private func since overloaded operator= calls copyList function.
    // to be used in copy constructor, too.
    void copyList(const UnsortDoubleList<T> &); // function just to copy

public:
    UnsortDoubleList();
    UnsortDoubleList(const UnsortDoubleList<T> &);
    ~UnsortDoubleList();
    // overload assignment operator
    const UnsortDoubleList<T> &operator=(const UnsortDoubleList<T> &);

    bool isEmpty();
    bool searchItem(T item);
    int getLength() const; // get length
    void printList();      // print list

    void destroy();          // Deallocate list
    void insertItem(T item); // sorted insert item
    void deleteItem(T item); // delete item
};

#endif