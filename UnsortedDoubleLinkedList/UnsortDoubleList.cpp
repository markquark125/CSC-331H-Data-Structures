#include "UnsortDoubleList.h"

template <class T>
UnsortDoubleList<T>::UnsortDoubleList()
{
    first = NULL;
    last = NULL;
    length = 0;
}
template <class T>
UnsortDoubleList<T>::UnsortDoubleList(const UnsortDoubleList<T> &)
{
}

template <class T>
UnsortDoubleList<T>::~UnsortDoubleList()
{
}

template <class T>
void UnsortDoubleList<T>::copyList(const UnsortDoubleList<T> &)
{
}

template <class T>
const UnsortDoubleList<T> &UnsortDoubleList<T>::operator=(const UnsortDoubleList<T> &otherList)
{
}

template <class T>
bool UnsortDoubleList<T>::isEmpty()
{
    return length == NULL;
}

template <class T>
bool UnsortDoubleList<T>::searchItem(T item)
{
}
template <class T>
int UnsortDoubleList<T>::getLength() const
{

} // get length
template <class T>
void UnsortDoubleList<T>::printList()
{

} // print list

template <class T>
void UnsortDoubleList<T>::destroy()
{

} // Deallocate list
template <class T>
void UnsortDoubleList<T>::insertItemFront(T item)
{
    newNode = new nodetype<T>;
    newNode->info = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (first == NULL)
    {
        first = newNode;
        last = newNode;
    }
}

template <class T>
void UnsortDoubleList<T>::insertItemBack(T item)
{
}

template <class T>
void UnsortDoubleList<T>::deleteItem(T item)
{

} // delete item