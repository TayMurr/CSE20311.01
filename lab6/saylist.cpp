//Taylor Murray
//Lab 6 Part 1
//Oct 14 2016
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
using namespace std;

//prototypes
void alphaSort(list<string>& v);
void menuDisplay(list<string>& v);
void displayDatabase(list<string> v);
void addSaying(list<string>& v);
void subString(list<string> v);
void save(list<string> v);
void deleteSaying(list<string> v);

int main() {

  list<string> mysayings;
  alphaSort(mysayings);
  menuDisplay(mysayings); 
  return 0;
}

// Displays all the sayings in the current database with a number beside them
void menuDisplay(list<string>& mysayings) {
  int quit = 0;
  int userchoice;
  while(!quit) {
    cout << "1. Display all sayings currently in the database" << endl;
    cout << "2. Enter a new sayings in to the database." << endl;
    cout << "3. List sayings that contain a given word entered by user" << endl;
    cout << "4. Save all sayings in a new text file" << endl;
    cout << "5. Delete a sayiing from the database" << endl;
    cout << "6. Quit the program" << endl;
    cin >> userchoice;

    switch(userchoice) {
      case 1:
               displayDatabase(mysayings);
               break;
      case 2:  
               addSaying(mysayings);
               break;
      case 3:  
               subString(mysayings);
               break;
      case 4:
               save(mysayings);
               break;
      case 5:
               deleteSaying(mysayings);
               break;
      case 6:
               quit = 1;
               break;
      default: 
               cout << "Please enter valid choice" << endl;
               cin >> userchoice;
    }
  }
}


// Displays each saying in the current database with a number corresponding to it
void displayDatabase(list<string> mysayings) {
  int i = 1; // i is counter used to display number beside sayings
  for (auto it = mysayings.begin(); it != mysayings.end(); ++it, ++i) {
    cout << i << ": " << *it << endl;
  }
} 

//Looks for the substring entered by user and prints the saying its contained in
void subString(list<string> mysayings) {
  string subString;
  cout << "Enter the word you are looking for: " << endl;
  cin >> subString;
  
  // iterates through the mysayings container looking for when npos does not return null
  for(auto it = mysayings.begin(); it != mysayings.end(); ++it) {
    size_t found = (*it).find(subString);
    // it npos does not return a null value, that iteration of it is printed
    if (found != string::npos) {
      cout << *it << endl;
    }
  }
}

// Uses ofstream to create new file named by user containing all the 
// current sayings in the database
void save(list<string> mysayings) {
  string filename;
  cout << "Enter a name for the file" << endl;
  cin >> filename;
  ofstream ofs(filename);
  for(auto it = mysayings.begin(); it != mysayings.end(); ++it) {
    ofs << *it << endl;
  }
  ofs.close();
}

//uses list::erase to remove element according to position entered by user
void deleteSaying(list<string> mysayings) {
  int choice; //variable for the saying the user wants deleted
  displayDatabase(mysayings);
  cout << "Which saying do you want to delete?" << endl;
  cin >> choice;
  auto it = mysayings.begin();
  advance(it, choice-1);
  mysayings.erase(it);
  displayDatabase(mysayings);
}

// The user is prompted for a new saying and it is added alphabetically to mysayings
void addSaying(list<string>& mysayings) {
  string saying;
  cout << "Enter the saying you want to add: " << endl;

  getline(cin, saying);
  auto it = mysayings.begin();
  while(it != mysayings.end() && (*it).compare(saying) < 0) ++it;
  mysayings.insert(it, saying);  
}

// Adds each line in the file and sorts themm alphabetically
void alphaSort(list<string>& mysayings) {
  string filename, saying;
  cout << "Enter start up datafile: " << endl;
  cin >> filename;
  fstream ifs;
  ifs.open(filename);
  
  // if ifs return null then the user is shown error message and is prompted again
  if(!ifs) {
    cout << "Error: This file does not exist" << endl;
    alphaSort(mysayings);
  }

  cin.ignore();
  getline(ifs, saying);
  mysayings.push_back(saying);
  
  getline(ifs, saying);  
  while(!ifs.eof()) {
    auto it = mysayings.begin();
    while( it != mysayings.end()  && (*it).compare(saying) < 0) ++it;
    mysayings.insert(it, saying);
    getline(ifs, saying);     
  }

}


