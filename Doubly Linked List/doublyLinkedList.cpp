#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "node.h"

using namespace std;

class doublyLinkedList {// This class will be the interface that manages the list
    private:
        node* head;// "head" is a node pointer to the head of the list
    
    public:
        doublyLinkedList() {
            head = nullptr;
        }
        
        ~doublyLinkedList() {// Destructor
            cout << "Destructor is called." << endl;
            
            node* tmp = head;
            node* previous = nullptr;
            while (tmp->next != nullptr) {
                previous = tmp;
                tmp = tmp->next;
                delete previous;
            }
            
            delete tmp;
        }
        
        doublyLinkedList(const doublyLinkedList& originalDLL) {// Copy constructor
            cout << "Copy constructor called." << endl;
            
            head = new node;
            head->prev = nullptr;
            head->next = nullptr;
            node* tmp = head;
            node* previous = nullptr;
            
            node* tmpOrig = originalDLL.head;
            node* prevOrig = nullptr;
            
            while (tmpOrig->next != nullptr) {
                prevOrig = tmpOrig;
                previous = tmp;
                previous->data = prevOrig->data;
                
                tmpOrig = tmpOrig->next;
                tmp->next = new node;
                tmp = tmp->next;
                previous->next = tmp;
                tmp->prev = previous;
            }
            
            tmp->data = tmpOrig->data;
            tmp->next = nullptr;
        }
        
        doublyLinkedList& operator=(const doublyLinkedList& listToCopy) {
            cout << "Copy assignment override." << endl;
            
            head = new node;
            head->prev = nullptr;
            head->next = nullptr;
            node* tmp = head;
            node* previous = nullptr;
            
            node* tmpOrig = listToCopy.head;
            node* prevOrig = nullptr;
            
            while (tmpOrig->next != nullptr) {
                prevOrig = tmpOrig;
                previous = tmp;
                previous->data = prevOrig->data;
                
                tmpOrig = tmpOrig->next;
                tmp->next = new node;
                tmp = tmp->next;
                previous->next = tmp;
                tmp->prev = previous;
            }
            
            tmp->data = tmpOrig->data;
            tmp->next = nullptr;
            
        }
        
        void push(int newData) {// Appends a new node on the end of the list
            if (head == nullptr) {
                head = new node;// The new operator allocates memory for the given type and returns a pointer to the allocated memory.
                                // If the type is a class, the new operator calls the class's constructor after allocating memory for the class's member variables.
                head->data = newData;
                head->next = nullptr;
                head->prev = nullptr;
            }
            else {
                node* tmp = head;
                while (tmp->next != nullptr) {
                    tmp = tmp->next;// Ex. The node pointer tmp is pointing to node-A. The next pointer of node-A that tmp is pointing to, is pointing to node-B.
                                    //     This equation is setting tmp to point to the node that the next pointer of node-A is pointing to: node-B.
                }
                
                //*****all the verbose comments are to aid in my understanding of what the code is doing*****
                
                // the node pointer tmp has been made to point to the last node in the list whose *next* pointer, points to nullptr
                tmp->next = new node;// this *next* pointer has now been set to point to a new node that has been newly allocated in memory
                (tmp->next)->data = newData;// the data of the new node that *next* is pointing to is made equal to newData 
                (tmp->next)->next = nullptr;// the next pointer of the new node that the *next* pointer is pointing to has been set to point to nullptr
                (tmp->next)->prev = tmp;// the prev pointer of the new node that the *next* pointer is pointing to has been set to point to the previous node
            }
        }
        
        int pop() {// Removes the last element of the list and returns its value
            int ret;
            node* tmp = head;
            node* previous = nullptr;
            while (tmp->next != nullptr) {
                previous = tmp;
                tmp = tmp->next;
            }
            
            ret = tmp->data;
            delete tmp;
            previous->next = nullptr;
            
            return ret;
        }
        
        int size() {// Returns the number of elements in the list
            int ret = 1;
            node* tmp = head;
            while (tmp->next != nullptr) {
                ret = ret + 1;
                tmp = tmp->next;
            }
            
            return ret;
        }
        
        void print() {// Prints all elements in the list to the console
            cout << "list: ";
            node* tmp = head;
            while(tmp->next != nullptr) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << tmp->data << " ";
            cout << endl;
        }
        
        void insert(int newData, unsigned int index) {
            int testIndex = 0;
            node* test = head;
            node* tmp = head;
            node* previous = nullptr;
            
            while (test->next != nullptr) {
                testIndex = testIndex + 1;
                test = test->next;
            }
            
            if (index == 0) {
                head = new node;
                head->data = newData;
                head->prev = nullptr;
                head->next = tmp;
                (head->next)->prev = head;
            }
            else if (index > testIndex) {
                cout << "Selected index is out of bounds." << endl;
            }
            else {
                for (int i = 1; i <= index; i++) {
                    previous = tmp;
                    tmp = tmp->next;
                }
                
                previous->next = new node;
                (previous->next)->data = newData;
                (previous->next)->prev =previous;
                (previous->next)->next = tmp;
            }
 
        }
        
        void removeElement(unsigned int index) {
            int testIndex = 0;
            node* test = head;
            node* backup = nullptr;
            node* tmp = head;
            node* previous = nullptr;
            
            while (test->next != nullptr) {
                testIndex = testIndex + 1;
                backup = test;
                test = test->next;
            }
            
            if (index == 0) {
                head = head->next;
                head->prev = nullptr;
                delete tmp;
            }
            else if (index > testIndex) {
                cout << "Selected index is out of bounds." << endl;
            }
            else if (index == testIndex) {
                backup->next = nullptr;
                delete test;
            }
            else {
                for (int i = 1; i < index; i++) {
                    previous = tmp;
                    tmp = tmp->next;
                }
                
                previous->next = tmp->next;
                (tmp->next)->prev = previous;
                delete tmp;
            }
        }
};

#endif
