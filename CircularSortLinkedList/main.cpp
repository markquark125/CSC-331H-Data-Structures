#include <iostream>
#include "circleLinkList.cpp"
using namespace std;

int main()
{
    circleLinkList<int> list;
    cout << "\nLength: " << list.getLength() << endl;

    list.insertItem(1);
    list.insertItem(2);
    list.printList();

    list.deleteItem(2);

    cout << "\nLength: " << list.getLength() << endl;
    list.printList();

    circleLinkList<int> list2;
    cout << "\nLength: " << list2.getLength() << endl;
}