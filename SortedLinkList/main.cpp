#include "sortedList.cpp"

int main()
{
    int number;
    sortList<int> list1; // created list object

    // fill list with values 1 to 10
    for (int i = 0; i < 10; i++)
        list1.insertItem(i + 1);

    cout << "\nTest length() and printList():\n";
    cout << "Length: " << list1.getLength() << endl;
    cout << "LIST: ";
    list1.printList();

    cout << "\n\nAfter deletion with 2, 3, 4 on previous list:\n";
    list1.deleteItem(2);
    list1.deleteItem(3);
    list1.deleteItem(4);
    cout << "Length: " << list1.getLength() << endl;
    cout << "LIST: ";
    list1.printList();

    cout << "\n\nCopy constructor test:\n";
    sortList<int> list3(list1);
    cout << "Length: " << list1.getLength() << endl;
    cout << "LIST: ";
    list1.printList();
    cout << endl;

    cout << "\nCheck searchList() and isEmpty():\n";
    cout << "list3 length: " << list3.getLength() << endl;
    cout << "Search list3 for 5: " << list3.searchItem(5) << endl;
    cout << "Search list3 for 3: " << list3.searchItem(3) << endl;
    cout << "\nEmpty: " << list3.isEmpty() << endl;
    sortList<int> emptyList;
    cout << "emptyList, empty: " << emptyList.isEmpty() << endl;

    sortList<int> list4;
    sortList<int> list5(list4);

    cout << "list4 length: " << list5.getLength() << endl;
    cout << "list5 length: " << list5.getLength() << endl;
}