
#include "circleLinkList.h"

template <class T>
circleLinkList<T>::circleLinkList()
{
    int length = 0;
    first = NULL;
}

template <class T>
circleLinkList<T>::circleLinkList(const circleLinkList<T> &otherList)
{
    copy(otherList);
}

template <class T>
circleLinkList<T>::~circleLinkList()
{
    destroy();
}

// Overload assignment operator
template <class T>
const circleLinkList<T> &circleLinkList<T>::operator=(const circleLinkList<T> &otherList)
{
    if (this != otherList)
    {
        destroy();
        copy(otherList);
    }
}

template <class T>
int circleLinkList<T>::getLength()
{
    return length;
}

template <class T>
bool circleLinkList<T>::isEmpty()
{
    return (length == 0);
} // Check if list is empty

template <class T>
void circleLinkList<T>::printList()
{
    if (first == NULL)
        cout << "\nLIST IS EMPTY";
    else
    {
        nodeType<T> *ptr = first->next;

        while (ptr != first)
        {
            cout << ptr->info << " ";
            ptr = ptr->next;
        }

        cout << ptr->info;
    }
}

// Setters
template <class T>
void circleLinkList<T>::destroy()
{
    // Check if anything to delete.
    if (first != NULL)
    {
        nodeType<T> *ptr = first->next; // *ptr to first node in list.

        // ptr not at *first...
        while (ptr != first)
        {
            // Reassign first to link to ptr->next, delete ptr, move ptr to link.
            first->next = ptr->next;
            delete ptr;
            ptr = first->next;
        }

        delete ptr; // ptr should point to first, then delete.

        first = NULL; // Make sure first is NULL
    }
}

template <class T>
void circleLinkList<T>::copy(const circleLinkList<T> &otherList)
{
    // List is empty.
    if (otherList.first == NULL)
        first = NULL;
    // List is not empty
    else
    {
        // Copy otherList's first node
        first = new nodeType<T>;
        first->info = otherList.first->info;

        // Two pointers to travsere otherList and ourList.
        nodeType<T> *p = otherList.first->next;
        nodeType<T> *q = first;

        // If otherList has one node, p will be at otherList.first already
        // and will not enter loop. Else, if two or more...
        while (p != otherList.first) // Loop through otherList.
        {
            q->next = new nodeType<T>; // Create a new node.
            q->next->info = p->info;   // Store the info.
            q = q->next;               // Move to the next node.
            p = p->next;               // Move ptr to otherList forward.
        }

        q->next = first; // (For our list) link lastNode->next to first, circular.
    }
}

template <class T>
void circleLinkList<T>::insertItem(T item)
{
    nodeType<T> *newNode = new nodeType<T>; // Create new node
    newNode->info = item;                   // Store item in it.

    // CASE 1: The list is empty. Make one node and close the circle.
    if (first == NULL)
    {
        first = newNode;
        first->next = first;
    }
    // CASE 2: Item is larger than lastNode, so append and update first.
    else if (first->info <= item)
    {
        newNode->next = first->next;
        first->next = newNode;
        first = first->next;
    }
    else
    {
        // One pointer to lead, another to follow.
        nodeType<T> *trailPtr = first;
        nodeType<T> *ptr = first->next;

        while (item > ptr->info)
        {
            trailPtr = ptr;
            ptr = ptr->next;
        }

        newNode->next = trailPtr->next;
        trailPtr->next = newNode;
    }

    length++;
}

template <class T>
void circleLinkList<T>::deleteItem(T item)
{
    // CASE 1: The list is empty or is greater than list's greatest value.
    if (first == NULL || first->info < item)
        cout << "\nITEM NOT IN LIST";
    // Case 2: Item to be delete is first and only node in the list.
    else if ((first->info == item) && (first->next == first))
    {
        delete first;
        first = NULL;
        length--;
    }
    // Case 3: In list of two or more nodes, item may be within the list.
    else
    {
        nodeType<T> *trailPtr = first;
        nodeType<T> *ptr = first->next;

        while (ptr->info < item)
        {
            trailPtr = ptr;
            ptr = ptr->next;
        }

        if (ptr->info == item)
        {
            if (ptr == first) // In case lastNode is to be deleted, move first backwards.
                first = trailPtr;

            trailPtr->next = ptr->next;
            delete ptr;
            length--;
        }
        else
            cout << "/nITEM NOT IN LIST";
    }
}

template <class T>
bool circleLinkList<T>::searchItem(T item)
{
    bool found = false;

    // CASE 1: The list is empty or item not in range of list.
    if (first == NULL || (first->info < item) || (first->next->info > item))
        return found;
    // CASE 2: Check the last node of the list.
    else if (item == first->info)
        found = true;
    // Case 3: May be within the list.
    else
    {
        nodeType<T> *ptr = first->next; // Start at first node

        // Iterate 'til item is found or one full loop.
        while (!found && (item < ptr->info))
        {
            if (ptr->info == item)
                found = true;
            else
                ptr = ptr->next;
        }
    }

    return found;
}