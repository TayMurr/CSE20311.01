//Taylor Murray
//Lab6 Part 2
//OCt 14 2016
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main () {
    string filename;
    int acsi = 97;
    int spaces = 0; // set up to count total number of spaces
    int tot = 0; // Set up to count total number of letters
    int Numlet = 26; // Number of letters in alphabet
    int letters = 0;
    vector<int> letterfreq;

    // initializes every element in the letterfreq vector to zero
    for(int i = 1; i <= Numlet; ++i) {
        letterfreq.push_back(0);
    }
     
    cout << "Enter the name of the file: " << endl;
    cin >> filename;
    fstream ifs;
    ifs.open(filename);
    char letter;
   
    while(!ifs.eof()) {
       ifs  >> noskipws >> letter; // noskipws makes the program not skip whitespace
   
       // ignores punctuation characters and spaces
       if(!ispunct(letter) && !isspace(letter)) {
           if(isupper(letter)) {
               letter = tolower(letter); // converts upper case letters to lower case
           }
           letterfreq[(int)letter - acsi]++; // The position in the vector that corresponds to the acii value is incremented by 1
           tot++; // tot represents the total number of characters minus spaces
           letters++;
       }
       if(isspace(letter)) { 
           spaces++;// number of spaces is kept track of to get space percentage
           tot++;
       }
       if(ispunct(letter)) {
           tot++;
       }
    }

    tot--;
    spaces--;

    int k = 1;
    for (int a = 97; a < 123; ++a, ++k) {
        cout << setw(2) << char(a) << ": " << setw(5) << letterfreq[a - acsi];
        if(k%5 == 0) cout << endl;
    }
     
    cout << endl; //formatting purposes
 
    cout << "The total number of letters was : " << letters << endl;
    cout << "The total number of characters was: " << tot << endl;
    cout << "There were " << spaces << " white space characters." << endl;
    cout << "The percentage of whitespace: " << double(spaces) / (tot) * 100 << "%" << endl;
    return 0;
}

