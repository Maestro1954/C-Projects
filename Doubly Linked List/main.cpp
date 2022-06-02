#include <iostream>
#include "doublyLinkedList.h"
#include "node.h"

using namespace std;

int main() {
    doublyLinkedList* list;
    list = new doublyLinkedList();

    list->push(5);
    list->push(7);
    list->push(3);
    list->push(8);
    list->push(1);
    list->push(9);
    
    cout << "\n*********************************" << endl;
    list->print();
    cout << "Size: " << list->size() << endl;
    cout << "Pop: " << list->pop() << endl;
    list->print();
    cout << "Size: " << list->size() << endl;
    
    cout << "\n*********************************" << endl;
    list->print();
    cout << "insert 2 at index 1" << endl;
    list->insert(2, 1);// case in which selected index is between the first and last index of the list
    list->print();
    cout << "insert 6 at index 0" << endl;
    list->insert(6, 0);// case in which selected index is zero
    list->print();
    cout << "insert 3 at index 8" << endl;
    list->insert(3, 8);// case in which selected index is out of bounds
    list->print();
    cout << "insert 3 at index 6" << endl;
    list->insert(3, 6);// case in which selected index is the very last index of the list
    list->print();
    
    cout << "\n*********************************" << endl;
    list->print();
    cout << "remove element at index 0" << endl;
    list->removeElement(0);// case in which selected index is zero
    list->print();
    cout << "remove element at index 3" << endl;
    list->removeElement(3);// case in which selected index is between the first and last index of the list
    list->print();
    cout << "remove element at index 10" << endl;
    list->removeElement(10);// case in which selected index is out of bounds
    list->print();
    cout << "remove element at index 5" << endl;
    list->removeElement(5);// case in which selected index is the very last index of the list
    list->print();
    
    cout << "\n*********************************" << endl;
    cout << "Rule of Three." << endl;
    list->print();
    delete list;
    cout << endl;
    
    doublyLinkedList list2;
    list2.push(70);
    list2.push(80);
    list2.push(90);
    list2.push(100);
    cout << "Second ";
    list2.print();
    
    doublyLinkedList list3 = list2;
    cout << "Third ";
    list3.print();
    cout << "\nList three push 110." << endl;
    list3.push(110);
    cout << "Third ";
    list3.print();
    
    doublyLinkedList list4;
    list4 = list3;
    cout << "Fourth ";
    list4.print();
    
    return 0;
}
