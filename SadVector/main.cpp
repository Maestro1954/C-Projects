#include <iostream>
#include "sad_vector.h"

using namespace std;// Last edited during lecture 13

void func() {
    SadVector<int> sv(10);// two instances of sadvector are the reason the destructor is called twice
                     // the first destructor is for sv2, because it is on top of sv in the stack
    sv.push_back(5);
    sv.push_back(7);
    sv.push_back(-4);
    
    sv.print();
    
    /*
    SadVector sv2;
    sv2 = sv;
    sv2.push_back(10);
    sv.print() <- sv would have that 10, because the new sv2 pointer still points to sv
    */
    
    SadVector<int> sv2 = sv; // copy constructor
    
    //sv2 = sv;// ****
    
    sv2.push_back(10);
    
    sv2.print();
    sv.print();
}

int main() {
    
    func();
    
    
    return 0;
}
