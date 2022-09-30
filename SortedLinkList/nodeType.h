#ifndef NODETYPE_H
#define NODETYPE_H

template <class T>
struct nodeType
{
    T info;
    nodeType<T> *next;
};

#endif