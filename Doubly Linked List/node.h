#ifndef NODE_H
#define NODE_H

using namespace std;

struct node {// This is the structure of an individual node
    int data;// The data stored within an individual node
    node* next;// "next" is a node pointer to the next node in the list
    node* prev;// "prev" is a node pointer to the previous node in the list
    
};

#endif
