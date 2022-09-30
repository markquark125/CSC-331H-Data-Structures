#include "sortedLish.h"

template <class T>
sortList<T>::sortList()
{
    length = 0; // Initialize the list.
    first = NULL;
}

template <class T>
sortList<T>::sortList(const sortList<T> &otherList)
{
    copyList(otherList); // copy constructor
}

template <class T>
sortList<T>::~sortList()
{
    destroy(); // Deallocate the list
}

template <class T>
bool sortList<T>::isEmpty()
{
    return (first == NULL); // return true if empty, else false.
}

template <class T>
bool sortList<T>::searchItem(T item)
{
    nodeType<T> *p = first; // start search at first.
    bool found = false;     // start with false

    while (p != NULL && !found) // iterate through the list
    {
        if (p->info == item) // check equality, if found
            found = true;    // set to true, break out of loop.

        p = p->next;
    }

    return found; // if found, is true. Else, false.
}

template <class T>
int sortList<T>::getLength() const
{
    return length;
}

template <class T>
void sortList<T>::insertItem(T item)
{
    nodeType<T> *newNode = new nodeType<T>; // create new node
    newNode->info = item;                   // store item in it

    // CASE 1: item is firstNode or less than firstNode.
    if (first == NULL || item < first->info)
    {
        newNode->next = first;
        first = newNode;
    }
    // CASE 2: Insert after firstNode.
    else
    {
        nodeType<T> *q = first;       // trailing ptr
        nodeType<T> *p = first->next; // leading ptr

        // Either item > lastItem or item >= middleItem
        while (p != NULL && item > p->info)
        {
            q = p;
            p = p->next;
        }

        q->next = newNode; // trailPtr->next connects to newNode
        newNode->next = p; // newNode connects to where trailPtr
    }                      // pointed to (nextNode or NULL).

    length++;
}

template <class T>
void sortList<T>::deleteItem(T item)
{
    // Case 1: Empty list or item is less than firstNode info.
    if (first == NULL || item < first->info)
        cout << "\nITEM IS NOT IN LIST";
    else
    {
        nodeType<T> *p = first;

        // Case 2: firstNode to be deleted. Could be a single node list or not.
        if (item == first->info)
        {
            first = first->next; // first = NULL or nextNode in thisList
            delete p;
            length--;
        }
        // Case 3: Item to be deleted is in the list.
        else
        {
            nodeType<T> *q = NULL; // pointer to follow p

            // move p and q along thisList till either at end (p = NULL)
            // or item > nodeItem is false, (i.e. notNull && 3 > 3)
            while (p != NULL && item > p->info)
            {
                q = p;
                p = p->next;
            }

            // Either at end of list or item not equal to p->info
            // (i.e. item is 3, then p != NULL || 3 < 3)
            if (p == NULL || item < p->info)
                cout << "\nITEM NOT IN LIST";

            // item == nodeItem
            else
            {
                q->next = p->next; // trailPtr->next = leadPtr->next
                delete p;          // deallocate the trailptr AKA deleteNode
                length--;
            }
        }
    }
}

template <class T>
void sortList<T>::copyList(const sortList<T> &otherList)
{
    // Precondition: List exists.
    // Remember length; increment for every copyItem. Forgot this first time.

    // Case 1: otherList is empty
    if (otherList.first == NULL)
    {
        first = NULL; // need both, else you get garbage.
        length = 0;
    }
    // Case 2: otherList is nonempty
    else
    {
        // Create first node for thisList, copy first value of
        // otherList into thisList
        first = new nodeType<T>;
        first->info = otherList.first->info;
        length++;

        // Create two pointers; one to traverse otherList and other
        // to insert otherList value into thisList.
        nodeType<T> *p = otherList.first->next;
        nodeType<T> *q = first;

        while (p != NULL)
        {
            q->next = new nodeType<T>; // Link q to a new node
            q->next->info = p->info;   // Store p->info into new node.
            length++;
            p = p->next; // move p along otherList.
            q = q->next; // move q to next node
        }

        q->next = NULL; // p should be at null at this point.
    }
}

template <class T>
void sortList<T>::printList()
{
    // Case 1: List is empty
    if (first == NULL)
        cout << "\nLIST IS EMPTY";
    // Case 2: List is nonempty.
    else
    {
        nodeType<T> *p; // Pointer to traverse thisList.
        p = first;      // assign to thisList firstNode

        while (p != NULL) // iterate till end, printing each value.
        {
            cout << p->info << " ";
            p = p->next;
        }
    }
}

template <class T>
void sortList<T>::destroy()
{
    nodeType<T> *p; // p to traverse thisList

    while (first != NULL) // if nonempty, assign p to first,
    {                     // first moves to next node, and
        p = first;        // delete p/node. repeat till NULL.
        first = first->next;
        delete p;
    } // at end, first = NULL
}

template <class T>
const sortList<T> &sortList<T>::operator=(const sortList<T> &otherList)
{
    if (this != &otherList) // Avoid self copying
    {
        destroy();           // destroy thisList
        copyList(otherList); // copy otherList
    }
}