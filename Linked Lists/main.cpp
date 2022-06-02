#include <iostream> //Single linked lists

using namespace std;

// This is the structure that will hold the individual nodes
struct node {//struct is the same as a class with default member variables being public instead
    int data;
    node* next;//node pointer
};
// This class will be the interface to manage all of the nodes
class SingleLinkedList {//class to manage this list
    private:
    node* head;//pointer that always points to the beginning of the list
      
    public:
    SingleLinkedList() {
        head = nullptr;
    }
      
    void print() {//Prints the list's contents
        node* tmp = head;//Loop until we find the end of the list
        while(tmp->next != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << tmp->data << " ";
        cout << endl;
    }
      
    void push(int newData) {//Adds a new node to the end of the list
        if (head == nullptr) {
            head = new node;/*head now points to a new node that we are goint to
                              allocate in "the heap"*/
    
            head->data = newData;//fill the node with data
            head->next = nullptr;//next pointer points to nothing
        }
        else {
            node* tmp = head;
            while(tmp->next != nullptr) {//Loop until we find the end of the list
                tmp = tmp->next;
            }
            
            //Add new node to end of list
            tmp->next = new node;//we create more space for another node
            (tmp->next)->data = newData;//next will now point to the element of the new node
            (tmp->next)->next = nullptr;/*the new node's next pointer points to nothing
                                          it is now the new end of the list*/
        }
    }
      
    int pop() {//Removes the last node in the list and returns its data
        int ret;
        node* tmp = head;//tmp is a pointer to the node's location
        node* prev = nullptr;
        while(tmp->next != nullptr) {
            prev = tmp;
            tmp = tmp->next;
        }
        //save return value
        ret = tmp->data;
        
        //Pop last node off of list and clean up data
        delete tmp;// cleans up space in "the heap" from tmp and deletes data
        prev->next = nullptr;//the element that preceded tmp "next" points to null pointer
        
        return ret;
        
        // head->data = some integer because data is an int type that we are writing to
        // head->next = next is another node pointer. if this equals nullptr, then we only have one node in the list
        // head == nullptr this means that there is nothing in the list
    }
    
    // 5 8 12 14 3
    // data: 4 index: 2
    // we want this pointer: 5 8->12 14 3
    // 5 8 4 12 14 3
    
    //insert data in the middle of the list
    void insert(int dataToInsert, unsigned int index) {//its an index, we dont want it to be negative
        
        if (index == 0) {//special cace for zero'th element
            node* backup = head;//its like a copy of the arrow pointer we are about to change
            head = new node;
            head->data = dataToInsert;
            head->next = backup;
        }
    
        node* tmp = head; //temporary pointer starting at the head
        
        // loop up to index's position
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;// following the chain
        }
        
        node* backup = tmp->next;//its like a copy of the arrow pointer we are about to change
        tmp->next = new node;
        tmp->next->data = dataToInsert;
        tmp->next->next = backup;//address of the old nth element
        // deleting backup would delete 12, which points to 14, so it would also delete everything after 12
        // because we didnt call anything new, we dont have to delete it
        
    }
};

int main() {
    SingleLinkedList list;/*Creates a class which is an automatic variable all 
                            the way at the bottom of memory called "the stack"
                            part of that class is the head pointer which points
                            to the first element using "new" all the way at the
                            top of memory called "the heap"*/

    list.push(5);// the arrow (->) is the same as a dot (.), but only for pointers
    list.push(4);
    list.push(7);
    list.push(8);
    
    list.print();
    
    cout << "Pop: " << list.pop() << endl;
    
    list.print();
    
    return 0;
}
