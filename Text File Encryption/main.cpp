#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <vector>

using namespace std;

string encode(vector<char> funcCipher, const vector<char> funcAlpha, string inString) {
    for (int i = 0; i < inString.size(); i++) {
        bool charEncoded = false;
        
        if (isalpha(inString.at(i)) != 0) {// makes sure to only operate on letters
            bool wasCap = false;
            if (isupper(inString.at(i)) != 0) {// finds any uppercase letters and turns them to lowercase
                inString.at(i) = tolower(inString.at(i));
                wasCap = true;
            }
            
            for (int j = 0; j < funcAlpha.size(); j++) {
                if ((inString.at(i) == funcAlpha.at(j)) && (charEncoded == false)) {
                    inString.at(i) = funcCipher.at(j);
                    charEncoded = true;
                }
            }
            
            if (wasCap == true) {// restores capital letters
                inString.at(i) = toupper(inString.at(i));
            }
        }
    }
    
    return inString;
}

string decode(vector<char> funcCipher, const vector<char> funcAlpha, string inString) {
    for (int i = 0; i < inString.size(); i++) {
        bool charDecoded = false;
        
        if (isalpha(inString.at(i)) != 0) {// makes sure to only operate on letters
            bool wasCap = false;
            if (isupper(inString.at(i)) != 0) {// finds any uppercase letters and turns them to lowercase
                inString.at(i) = tolower(inString.at(i));
                wasCap = true;
            }
        
            for (int j = 0; j < funcCipher.size(); j++) {
                if ((inString.at(i) == funcCipher.at(j)) && (charDecoded == false)) {
                    inString.at(i) = funcAlpha.at(j);
                    charDecoded = true;
                }
            }
            
            if (wasCap == true) {// restores capital letters
                inString.at(i) = toupper(inString.at(i));
            }
        }
    }
    
    return inString;
}

int main(int argc, char* argv[]) {
    //                         { 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25};
    const vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<bool> used = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    vector<char> cipher(26);
    
    char key[] = "-k";
    char enc[] = "-e";
    char dec[] = "-d";
    
    string keyWord;
    string inFileName;
    string outFileName;
    string fileContent;
    
    int ciphIndex = 0;
    int alphaIndex = 25;
    
    bool wantsToEncode = false;
    bool wantsToDecode = false;
    
    for (int i = 0; i < argc; i++) {// how many elements are in our array argv
        cout << "   argv[" << i << "]: " << argv[i] << endl;
        
        if (strcmp(argv[i], key) == 0) {// to check if argv has "-k"
            keyWord.assign(argv[i + 1]);
            
            for (int j = 0; j < keyWord.size(); j++) {// for removing redundant characters from the keyword
                for (int k = 0; k < alpha.size(); k++) {
                    if ((keyWord.at(j) == alpha.at(k)) && (used.at(k) == false)) {
                        cipher.at(ciphIndex) = keyWord.at(j);
                        used.at(k) = true;
                        ciphIndex = ciphIndex + 1;
                    }
                }
            }
        }
        
        if (strcmp(argv[i], enc) == 0) {// to check if argv has "-e"
            wantsToEncode = true;
        }
        if (strcmp(argv[i], dec) == 0) {// to check if argv has "-d"
            wantsToDecode = true;
        }
        if (i == (argc - 2)) {// to place the input file name into a string variable
            inFileName.assign(argv[i]);
        }
        if (i == (argc - 1)) {// to place the output file name into a string variable
            outFileName.assign(argv[i]);
        }
    }
    
    if (wantsToEncode == true) {// to output if argv has "-e"
        cout << "Has \"-e\": True" << endl;
    }
    else {
        cout << "Has \"-e\": False" << endl;
    }
    
    if (wantsToDecode == true) {// to output if argv has "-d"
        cout << "Has \"-d\": True" << endl;
    }
    else {
        cout << "Has \"-d\": False" << endl;
    }
    
    cout << "inFileName: " << inFileName << endl;
    cout << "outFileName: " << outFileName << endl;
    
    for (int temp1 = alphaIndex; temp1 >= 0; temp1--) {// creating the cipher alphabet
        if (used.at(temp1) == false) {
            cipher.at(ciphIndex) = alpha.at(temp1);
            ciphIndex = ciphIndex + 1;
        }
    }
    
    for (int temp2 = 0; temp2 < cipher.size(); temp2++) {// outputs the cipher alphabet
        cout << "   cipher.at(" << temp2 << "): " << cipher.at(temp2) << endl;
    }
    
    ifstream inFile;
    inFile.open(inFileName);
    
    if (!inFile.is_open()) {
        cout << "Could not open file input.txt." << endl;
        return 1; // 1 indicates error
    }
    
    ofstream outFile;
    outFile.open(outFileName);
    
    if (!outFile.is_open()) {
        cout << "Could not open file output.txt." << endl;
        return 1; // 1 indicates error
    }
    
    while (getline(inFile, fileContent)) {
        cout << "Input file string: " << fileContent << endl;
        if (wantsToEncode == true) {
            fileContent = encode(cipher, alpha, fileContent);
            outFile << fileContent;
            cout << "Encoded input file string: " << fileContent << endl;
        }
        else if (wantsToDecode == true) {
            fileContent = decode(cipher, alpha, fileContent);
            outFile << fileContent;
            cout << "Decoded input file string: " << fileContent << endl;
        }
    }
    
    inFile.close();
    outFile.close();
    
    cout << endl;
    cout << "Project: Text File Encryption\nClass: ECGR-2104\nProgrammer: Adriel Campos" << endl;
    
    return 0;
}
