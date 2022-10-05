#include <bits/stdc++.h>
using namespace std;

template <class T>
struct node
{
    node<T> *next;
    node<T> *prev;
    T data;
};

template <class T>
class DDL
{
private:
    node<T> *next;
    node<T> *prev;
    node<T> *first;
    node<T> *last;
    node<T> *current;
    int size = 0;

public:
    DDL<T>()
    {
        next = NULL;
        prev = NULL;
        first = NULL;
        last = NULL;
        current = NULL;
    }
    DDL<T>(const DDL<T> &D)
    {
        first = D.first;
        last = D.last;
        next = D.next;
        prev = D.prev;
        current = D.current;
        size = D.size;
    }
    void push_back(T d)
    {
        size++;
        if (!first)
        {
            // The list is empty
            first = new node<T>;
            first->data = d;
            first->next = NULL;
            first->prev = NULL;
            last = first;
            current = first;
        }
        else
        {
            // The list isn't empty
            if (last == first)
            {
                // The list has one element
                last = new node<T>;
                last->data = d;
                last->next = NULL;
                last->prev = first;
                first->next = last;
                current = last;
            }
            else
            {
                // The list has more than one element
                node<T> *insdata = new node<T>;
                insdata->data = d;
                insdata->next = NULL;
                last->next = insdata;
                insdata->prev = last;
                last = insdata;
                current = last;
            }
        }
    }

    void push_front(T d)
    {
        size++;
        if (!last)
        {
            // The list is empty
            last = new node<T>;
            last->data = d;
            last->next = NULL;
            last->prev = NULL;
            first = last;
            current = first;
        }
        else
        {
            // The list isn't empty
            if (last == first)
            {
                // The list has one element
                first = new node<T>;
                first->data = d;
                first->prev = NULL;
                first->next = last;
                first->prev = first;
                current = first;
            }
            else
            {
                // The list has more than one element
                node<T> *insdata = new node<T>;
                insdata->data = d;
                insdata->prev = NULL;
                last->next = insdata;
                insdata->next = first;
                first = insdata;
                current = first;
            }
        }
    }

    T get()
    {
        return this->current.data;
    }

    T get(int index)
    {
        if (index == 0)
        {
            // Get the first element
            return this->first->data;
        }
        else
        {
            // Get the index'th element
            node<T> *curr = this->first;
            for (int i = 0; i < index; ++i)
            {
                curr = curr->next;
            }
            return curr->data;
        }
    }

    int length()
    {
        return size;
    }

    T operator[](int index)
    {
        return get(index);
    }
    ~DDL() {}
};

int main()
{
    DDL<int> p;
    for (int i = 0; i < 10; i++)
        p.push_front(i + 1);
    DDL<int> head = p;
    for (int i = 0; i < head.length(); i++)
        cout << head[i] << endl;
    return 0;
}