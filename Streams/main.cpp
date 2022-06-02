#include <iostream>
#include <fstream>

using namespace std; //most recent lecture watched when editing this code: 12

int main() {
    ofstream outFile;
    outFile.open("hello.txt"); //creates file of the same name if it cant find it already there
    
    outFile << "Hello, world!" << endl;
    
    outFile.close();
    
    ifstream inFile;
    inFile.open("hello.txt");
    
    if (inFile.good()) {//kinda sorta an error check
        cout << "ERROR opening file." << endl;
    }
    
    string contents;
    while (inFile >> contents) {
        cout << contents; //without while loop and keeping inFile >> contents, the output is: Hello,
    }
    cout << endl;
    
    return 0;
}
