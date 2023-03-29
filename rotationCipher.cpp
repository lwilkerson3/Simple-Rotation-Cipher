// This program encrypts plaintext in in.txt using a simple rotation cipher

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

    string myString = "Hello World!";
    string engAlphabet = "abcdefghijklmnopqrstuvwxyz";
    bool charFound = false;
    int alphaIndex = 0;


    for (int key = 0; key < 26; key++) {
        ifstream inFile("in.txt", ifstream::in);
        cout << "Key: " << key << endl;
        cout << "***********************" << endl;
        while(getline(inFile, myString)) {
            for (int i = 0; i < myString.length(); i++) {
                if (engAlphabet.find(tolower(myString[i])) != string::npos) {
                    while (!charFound) {
                        if (tolower(myString[i]) == engAlphabet[alphaIndex]) {
                            charFound = true;
                            cout << engAlphabet[(alphaIndex + key) % 26];
                        }
                        alphaIndex++;
                    }
                } else {
                    cout << myString[i];
                }

                charFound = false;
                alphaIndex = 0;
            }
        }
        cout << endl << endl;
        inFile.close();
    }
    system("pause");
    return 0;
}