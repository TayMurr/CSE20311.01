// Taylor Murray Lab Part 2: lifeboard.cpp
#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<fstream>
#include<string>
#include"lifeboard.h"

using namespace std;

void interactiveMode();
void batchMode(string);
//argc is the number of arguments
//argv is a vector that contains arguments at the command line
int main(int argc, char *argv[]){
  string textFile;

  if (argc == 1){
      interactiveMode();
  } else if (argc == 2){
      textFile = argv[1];
      batchMode(textFile);
  } else {
      cout << "Two many arguments" << endl;
      return 1;
  }
  return 0;
}

void interactiveMode(){
  int x, y;
  char command = 'a';
  int quit = 0;
  Life currentBoard;
  Life newBoard;


  while(!quit){
    cout << "Enter the choice(a(add), r(remove), n(advance), q(quit), p(play)): " << endl;
    cin >> command;
    switch(command){
      case 'a':
          cout << "Enter the coordinates: " << endl;
          cin >> x >> y;
          currentBoard.addCell(x, y);
          currentBoard.displayBoard();
          break;
      case 'r':
          cout << "Enter the coordinates of the cell you want to remove: " << endl;
          cin >> x >> y;
          currentBoard.removeCell(x,y);
          currentBoard.displayBoard();
          break;
      case 'n':
          currentBoard.setBoard();
          currentBoard.displayBoard();
          break;
      case 'q':
          quit = 1;
          break;
      case 'p':
          currentBoard.play();
    }

  }
}

void batchMode(string v){
  Life currentBoard;
  char c;
  string xstr, ystr;
  int x, y;
  ifstream ifs;
  string filename, command;
  filename = v;

  ifs.open(filename);
  //if ifs returns null value then the user is to
  if(!ifs) {
    cout << "Not a valid filename" << endl;
    batchMode(v);
  }
  c = ifs.peek();

  while(c != EOF){
    getline(ifs, command, ' ');
    if(!(command.compare("a"))){
      getline(ifs, xstr, ' ');
      getline(ifs, ystr, '\n');
      x = stoi(xstr); //stoi is string to interger conversion
      y = stoi(ystr);
      currentBoard.addCell(x, y);
    }
    c = ifs.peek();
    string cstr(1,c); //conversion from char to string where cstr is the string variable name
    if(!(cstr.compare("p"))){
      currentBoard.play();
    }
  }


}
