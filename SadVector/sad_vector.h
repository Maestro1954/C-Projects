#ifndef SAD_VECTOR
#define SAD_VECTOR

#include <iostream>
#include <cstring>

using namespace std;

// Vector class, push_back, pop_back, size, print, at
template<typename T>
class SadVector {
    public:
    SadVector(unsigned int l);
    
    ~SadVector() {// destructor
        cout << "Destructor called." << endl;
        //func function was called and the SadVector was popped off the stack. This is to prevent memory leaks.
        delete[] arr;
        arr = nullptr;
    }
    
    SadVector(const SadVector<T>& originalVector) {// copy constructor
        cout << "Copy constructor called." << endl;
        
        // copy contents of original vector to array pointer
        arr = new T[originalVector.size()];
        for (int i = 0; i < originalVector.size(); i++) {
            arr[i] = originalVector.at(i);
        }
        
        length = originalVector.size();
        top = originalVector.size();
    }
    
    void push_back(int data) {
        if (top == length) {// when these two are equal, we are out of space
            cout << "Vector too small! Length: " << length << endl;
            //create bigger vector
            int* tmp = new T[length * 2];
            //copy old contents to new vector
            memcpy(tmp, arr, length * sizeof(T));
            length = length * 2;
            //dealocate old array
            delete[] arr; //use brackets for arrays
            arr = tmp;
        }
        
        arr[top] = data;
        top++;
    }
    
    T pop_back() {
        T returnVal = 0;
        if (top > 0) {
            top--;
            returnVal = arr[top];
        }
        else {
            // in future: throw exception
            cout << "Cannot pop, vector empty." << endl;
        }

        return returnVal;
    }
    
    T& at(unsigned int index) const;
    
    void print() const {
        for (int i = 0; i < top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    unsigned int size() const {
        return top;
    }
    //reference (after&)
    SadVector<T>& operator=(const SadVector<T>& objToCopy) {// special deffinition for when sv2 = sv; occurs ****
        cout << "Copy assignment override." << endl;
        
        if (&objToCopy == this) {// sv = sv; make sure we are not writing to ourself
            return this;// this is the object you are copying to
        }
        
        // copy contents of original vector to array pointer
        arr = new T[objToCopy.size()];
        for (int i = 0; i < objToCopy.size(); i++) {
            arr[i] = objToCopy.at(i);
        }
        
        length = objToCopy.size();
        top = objToCopy.size();
        
        return this;
    }
    
    private:
    //int* arr;
    T* arr;
    unsigned int top;// first unoccupied index of the array
    unsigned int length;// the space we've allocated in the heap for the array
};

template<typename T>
SadVector<T>::SadVector(unsigned int l = 10) {// constructor
    // Create array
    arr = new T[l];//int[l];
    length = l;
    top = 0;
}

template<typename T>
T& SadVector<T>::at(unsigned int index) const {
    if (index >= top) {
        // throw exception
        cout << "Index " << index << " outside vector bounds." << endl;
        return arr[0];
    }
    return arr[index];    
}

#endif
