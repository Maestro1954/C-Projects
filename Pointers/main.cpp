#include <iostream> //Pointers

using namespace std;

void sort2(double* p, double* q) { //this function wants addresses, not integers
    if (*p > *q) {
        //swap
        double tempVar;
        tempVar = *p;
        *p = *q;
        *q = tempVar;
    }
}

//replace the value that p points to with x if x is greater.
//return the old value to wich p pointed
double replace_if_greater(double* p, double x) {
    double returnVal = *p;
    
    if(*p < x) {
        *p = x;
    }
    
    return returnVal;
}

//write a function that returns a pointer to the maximum value of an array
//of floating point data
double* maximum(double* b, int size) {
    double* maxPtr = b; //maxPtr is pointing to base address of b
    
    for(int i = 0; i < size; i++) {
        if(*maxPtr < *(b + i)) { //*maxPtr = 1.0
            maxPtr = b + i; //base address of b plus i our index
                            //maxPtr is equal to the location of the largest
                            //variable in the array
        }
    }
    
    return maxPtr;
}

int main() {
    
    double x = 5;
    double y = 2;
    
    cout << "x: " << x << ", y: " << y << endl;
    sort2(&x, &y); //kind of like passing by reference
    cout << "x: " << x << ", y: " << y << endl;
    
    cout << "\nreplace_if_greater:" << endl;
    cout << "x: " << x << ", y: " << y << endl;
    cout << "old x: " << replace_if_greater(&x, y) << endl;
    cout << "x: " << x << ", y: " << y << endl;
    
    //Arrays as pointers
    int a[] = {1, 2, 3}; //index starts at 0
    
    cout << "\na: " << a << endl;
    cout << "a[0]: " << a[0] << endl;
    cout << "*a: " << *a << endl;
    cout << "a[1]: " << a[1] << endl;
    cout << "*(a + 1): " << *(a + 1) << endl;
    cout << "*(a + 1) + 5: " << *(a + 1) + 5 << endl;
    
    //part 2 of arrays as pointers
    double b[] = {1.0, 5.0, 3.0};
    
    double *max = maximum(b, 3);
    
    cout << "\nb: " << b << " <--base address" << endl;
    cout << "max: " << max << endl;
    cout << "*max: " << *max << endl;
    
    return 0;
}
