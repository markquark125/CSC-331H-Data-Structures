# Sorted Singular Linked List

Just a template class of a single-link sorted list. The list uses a template node structure.
The node has two members: info (data to hold) and next (pointer to next node).
I will update as need but below is a simple implementation of the class.

## Sorted Linked List

- Linked list initialized with first = NULL and length = 0.
- Insert is sorted.

The code is commented; will update if needed.


### BUG
* With assignment operator, we need to check if the lengths are accurate; the list is destroyed but \
is the length returned to 0 or is it unchanged? 
